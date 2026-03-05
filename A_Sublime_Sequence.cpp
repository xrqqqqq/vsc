// ==========================================
// 1. Windows 核心头文件
// ==========================================
#include <windows.h>

// ==========================================
// 2. SQL Server ODBC 头文件
// ==========================================
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

// ==========================================
// 3. C++ 标准库
// ==========================================
#include <cstdio>
#include <cstring>  // 用于 memset
#include <iostream>
#include <string>


using namespace std;

// ---------------------------------------------------------
// 辅助函数：安全打印字符串
// 如果数据库返回 NULL (空值)，则打印 "(空)"，防止程序崩溃
// ---------------------------------------------------------
const char* safe_str(SQLLEN len, char* buffer) {
    if (len == SQL_NULL_DATA) return "(空)";
    return buffer;
}

// 错误显示函数
void show_error(unsigned int handletype, const SQLHANDLE& handle) {
    SQLCHAR sqlState[1024];
    SQLCHAR message[1024];
    if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlState, NULL,
                                     message, 1024, NULL))
        cout << "SQL 错误: " << message << endl;
}

int main() {
    // 设置控制台防止乱码
    system("chcp 65001");

    SQLHANDLE envHandle = NULL;
    SQLHANDLE connHandle = NULL;
    SQLHANDLE stmtQuery = NULL;
    SQLHANDLE stmtUpdate = NULL;
    SQLRETURN retCode;

    // 1. 初始化环境
    if (SQL_SUCCESS !=
        SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &envHandle))
        return -1;
    SQLSetEnvAttr(envHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3,
                  0);
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, envHandle, &connHandle))
        return -1;

    // 2. 连接数据库
    cout << "正在连接数据库..." << endl;
    string connStr =
        "DRIVER={ODBC Driver 17 for SQL "
        "Server};SERVER=DELL;DATABASE=test;Trusted_Connection=Yes;"
        "TrustServerCertificate=Yes;";
    SQLCHAR retConString[1024];

    // 强制类型转换 (SQLHWND)NULL 避免警告
    retCode = SQLDriverConnectA(connHandle, (SQLHWND)NULL,
                                (SQLCHAR*)connStr.c_str(), SQL_NTS,
                                retConString, 1024, NULL, SQL_DRIVER_NOPROMPT);

    if (retCode != SQL_SUCCESS && retCode != SQL_SUCCESS_WITH_INFO) {
        cout << "连接失败！" << endl;
        show_error(SQL_HANDLE_DBC, connHandle);
        return -1;
    }
    cout << "连接成功！\n" << endl;

    // 3. 用户交互
    char targetDept[50];  // 输入缓冲区
    cout << "请输入系名 (例如 32, CS): ";
    cin >> targetDept;

    // --- 关键修复：构造模糊查询字符串 ---
    // 输入 "32" -> 变成 "32%"，这样可以忽略数据库里的尾随空格
    string searchPattern = string(targetDept) + "%";

    SQLAllocHandle(SQL_HANDLE_STMT, connHandle, &stmtQuery);
    SQLAllocHandle(SQL_HANDLE_STMT, connHandle, &stmtUpdate);

    // ------------------------------------------
    // 步骤 A: 查询 (使用 LIKE 来解决空格问题)
    // ------------------------------------------
    // 注意这里用了 WHERE Sdept LIKE ?
    string querySQL =
        "SELECT Sno, Sname, Ssex, Sage FROM Student WHERE Sdept LIKE ?";
    SQLPrepareA(stmtQuery, (SQLCHAR*)querySQL.c_str(), SQL_NTS);

    // 绑定参数
    SQLLEN lenPattern = SQL_NTS;
    SQLBindParameter(stmtQuery, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 20, 0,
                     (SQLCHAR*)searchPattern.c_str(), 0, &lenPattern);

    retCode = SQLExecute(stmtQuery);

    if (retCode != SQL_SUCCESS && retCode != SQL_SUCCESS_WITH_INFO) {
        cout << "查询失败！" << endl;
        show_error(SQL_HANDLE_STMT, stmtQuery);
    } else {
        // --- 关键修复：加大缓冲区，防止崩溃 ---
        SQLCHAR sNo[100], sName[100], sSex[50];
        SQLINTEGER sAge;
        SQLLEN lenNo, lenName, lenSex, lenAge;

        // 初始化内存为0，防止乱码
        memset(sNo, 0, sizeof(sNo));
        memset(sName, 0, sizeof(sName));
        memset(sSex, 0, sizeof(sSex));

        SQLBindCol(stmtQuery, 1, SQL_C_CHAR, sNo, sizeof(sNo), &lenNo);
        SQLBindCol(stmtQuery, 2, SQL_C_CHAR, sName, sizeof(sName), &lenName);
        SQLBindCol(stmtQuery, 3, SQL_C_CHAR, sSex, sizeof(sSex), &lenSex);
        SQLBindCol(stmtQuery, 4, SQL_C_LONG, &sAge, 0, &lenAge);

        int count = 0;
        char yn;

        while (SQLFetch(stmtQuery) == SQL_SUCCESS) {
            if (count++ == 0) {
                printf("\n%-10s %-20s %-10s %-10s\n", "学号", "姓名", "性别",
                       "年龄");
                printf(
                    "------------------------------------------------------\n");
            }

            // 处理年龄的 NULL 情况
            string ageDisplay =
                (lenAge == SQL_NULL_DATA) ? "(空)" : to_string((int)sAge);

            // 使用 safe_str 防止打印 NULL 字符串导致崩溃
            printf("%-10s %-20s %-10s %-10s\n", safe_str(lenNo, (char*)sNo),
                   safe_str(lenName, (char*)sName),
                   safe_str(lenSex, (char*)sSex), ageDisplay.c_str());

            cout << "是否更新该学生的年龄? (y/n): ";
            cin >> yn;

            if (yn == 'y' || yn == 'Y') {
                int newAge;
                cout << "请输入新年龄: ";
                cin >> newAge;

                string updateSQL = "UPDATE Student SET Sage = ? WHERE Sno = ?";
                SQLFreeStmt(stmtUpdate, SQL_RESET_PARAMS);

                SQLLEN lenNewAge = 0, lenSnoArg = SQL_NTS;

                SQLBindParameter(stmtUpdate, 1, SQL_PARAM_INPUT, SQL_C_LONG,
                                 SQL_INTEGER, 0, 0, &newAge, 0, &lenNewAge);
                SQLBindParameter(stmtUpdate, 2, SQL_PARAM_INPUT, SQL_C_CHAR,
                                 SQL_CHAR, 20, 0, sNo, 20, &lenSnoArg);

                if (SQLExecDirectA(stmtUpdate, (SQLCHAR*)updateSQL.c_str(),
                                   SQL_NTS) == SQL_SUCCESS) {
                    cout << ">>> 更新成功！" << endl;
                } else {
                    cout << ">>> 更新失败。" << endl;
                    show_error(SQL_HANDLE_STMT, stmtUpdate);
                }
            }
        }

        if (count == 0) {
            cout << "在该系 [" << targetDept << "] 没有找到学生。" << endl;
            cout << "(提示：已尝试自动忽略尾部空格匹配)" << endl;
        }
    }

    // 清理资源
    if (stmtQuery) SQLFreeHandle(SQL_HANDLE_STMT, stmtQuery);
    if (stmtUpdate) SQLFreeHandle(SQL_HANDLE_STMT, stmtUpdate);
    if (connHandle) {
        SQLDisconnect(connHandle);
        SQLFreeHandle(SQL_HANDLE_DBC, connHandle);
    }
    if (envHandle) SQLFreeHandle(SQL_HANDLE_ENV, envHandle);

    // 暂停
    system("pause");
    return 0;
}