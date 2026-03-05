// ==========================================
// 1. 必须包含的头文件
// ==========================================
// Windows 头文件必须放在最前面
#include <windows.h>

// 必须添加 winternl.h，它定义了 NTSTATUS
#include <winternl.h>

// 现在可以安全包含 bcrypt 了
#include <bcrypt.h>

// ODBC 数据库相关
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

// 标准库
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
// ==========================================
// 2. 辅助函数
// ==========================================
// 安全打印字符串，防止 NULL 导致崩溃
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

// ==========================================
// 3. 主函数
// ==========================================
int main() {
    // 设置控制台编码，防止乱码
    system("chcp 65001");

    SQLHANDLE envHandle = NULL;
    SQLHANDLE connHandle = NULL;
    SQLHANDLE stmtQuery = NULL;
    SQLHANDLE stmtUpdate = NULL;
    SQLRETURN retCode;

    // --- 初始化环境 ---
    if (SQL_SUCCESS !=
        SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &envHandle))
        return -1;
    SQLSetEnvAttr(envHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3,
                  0);
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, envHandle, &connHandle))
        return -1;

    // --- 连接数据库 ---
    cout << "正在连接数据库..." << endl;
    // ⚠️注意：如果你的服务器名不是 DELL，请在这里修改 SERVER=...
    string connStr =
        "DRIVER={ODBC Driver 17 for SQL "
        "Server};SERVER=DELL;DATABASE=test;Trusted_Connection=Yes;"
        "TrustServerCertificate=Yes;";
    SQLCHAR retConString[1024];

    retCode = SQLDriverConnectA(connHandle, (SQLHWND)NULL,
                                (SQLCHAR*)connStr.c_str(), SQL_NTS,
                                retConString, 1024, NULL, SQL_DRIVER_NOPROMPT);
    if (retCode != SQL_SUCCESS && retCode != SQL_SUCCESS_WITH_INFO) {
        cout << "连接失败！" << endl;
        show_error(SQL_HANDLE_DBC, connHandle);
        return -1;
    }
    cout << "连接成功！\n" << endl;

    // --- 用户交互：输入系名 ---
    char targetDept[50];
    cout << "请输入系名 (例如 32 或 CS): ";
    cin >> targetDept;
    string searchPattern = string(targetDept) + "%";  // 加上 % 进行模糊匹配

    SQLAllocHandle(SQL_HANDLE_STMT, connHandle, &stmtQuery);

    // --- 第一步：查询并列出该系所有学生 ---
    string querySQL =
        "SELECT Sno, Sname, Ssex, Sage FROM Student WHERE Sdept LIKE ?";
    SQLPrepareA(stmtQuery, (SQLCHAR*)querySQL.c_str(), SQL_NTS);

    SQLLEN lenPattern = SQL_NTS;
    SQLBindParameter(stmtQuery, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 20, 0,
                     (SQLCHAR*)searchPattern.c_str(), 0, &lenPattern);

    retCode = SQLExecute(stmtQuery);

    SQLCHAR sNo[100], sName[100], sSex[50];
    SQLINTEGER sAge;
    SQLLEN lenNo, lenName, lenSex, lenAge;

    // 绑定结果列
    SQLBindCol(stmtQuery, 1, SQL_C_CHAR, sNo, sizeof(sNo), &lenNo);
    SQLBindCol(stmtQuery, 2, SQL_C_CHAR, sName, sizeof(sName), &lenName);
    SQLBindCol(stmtQuery, 3, SQL_C_CHAR, sSex, sizeof(sSex), &lenSex);
    SQLBindCol(stmtQuery, 4, SQL_C_LONG, &sAge, 0, &lenAge);

    int count = 0;
    cout << "\n>>> [" << targetDept << "] 系学生列表: \n";
    printf("%-15s %-20s %-10s %-10s\n", "学号", "姓名", "性别", "年龄");
    printf("-------------------------------------------------------------\n");

    // 循环打印所有找到的学生
    while (SQLFetch(stmtQuery) == SQL_SUCCESS) {
        count++;
        string ageDisplay =
            (lenAge == SQL_NULL_DATA) ? "(空)" : to_string((int)sAge);
        printf("%-15s %-20s %-10s %-10s\n", safe_str(lenNo, (char*)sNo),
               safe_str(lenName, (char*)sName), safe_str(lenSex, (char*)sSex),
               ageDisplay.c_str());
    }
    SQLFreeStmt(stmtQuery, SQL_CLOSE);  // 关闭查询，准备下一步

    if (count == 0) {
        cout << "未找到该系学生。\n";
    } else {
        // --- 第二步：询问是否要修改 ---
        char yn;
        cout << "\n是否需要修改某个学生的年龄? (y/n): ";
        cin >> yn;

        if (yn == 'y' || yn == 'Y') {
            char targetSno[50];
            int newAge;

            cout << "请输入要修改的【学号】: ";
            cin >> targetSno;

            cout << "请输入新年龄: ";
            cin >> newAge;

            SQLAllocHandle(SQL_HANDLE_STMT, connHandle, &stmtUpdate);

            // 使用 LIKE 匹配学号，防止尾部空格问题
            string updateSQL = "UPDATE Student SET Sage = ? WHERE Sno LIKE ?";
            string snoPattern = string(targetSno) + "%";

            SQLLEN lenNewAge = 0, lenSnoArg = SQL_NTS;
            SQLBindParameter(stmtUpdate, 1, SQL_PARAM_INPUT, SQL_C_LONG,
                             SQL_INTEGER, 0, 0, &newAge, 0, &lenNewAge);
            SQLBindParameter(stmtUpdate, 2, SQL_PARAM_INPUT, SQL_C_CHAR,
                             SQL_CHAR, 20, 0, (SQLCHAR*)snoPattern.c_str(), 0,
                             &lenSnoArg);

            if (SQLExecDirectA(stmtUpdate, (SQLCHAR*)updateSQL.c_str(),
                               SQL_NTS) == SQL_SUCCESS) {
                // 检查是否真的更新了
                SQLLEN rows = 0;
                SQLRowCount(stmtUpdate, &rows);
                if (rows > 0) {
                    cout << ">>> 更新成功！已修改 " << rows << " 行。" << endl;
                } else {
                    cout << ">>> 更新执行了，但没有找到匹配的学号 "
                            "(可能学号输错了)。"
                         << endl;
                }
            } else {
                cout << ">>> 更新失败。" << endl;
                show_error(SQL_HANDLE_STMT, stmtUpdate);
            }
            SQLFreeHandle(SQL_HANDLE_STMT, stmtUpdate);
        }
    }

    // --- 清理资源 ---
    if (stmtQuery) SQLFreeHandle(SQL_HANDLE_STMT, stmtQuery);
    if (connHandle) {
        SQLDisconnect(connHandle);
        SQLFreeHandle(SQL_HANDLE_DBC, connHandle);
    }
    if (envHandle) SQLFreeHandle(SQL_HANDLE_ENV, envHandle);

    system("pause");
    return 0;
}