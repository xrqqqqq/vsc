#include <bits/stdc++.h>
using namespace std;

static inline bool is_letter(unsigned char c) { return std::isalpha(c); }
static inline bool is_alnum(unsigned char c) { return std::isalnum(c); }
static inline bool is_space(unsigned char c) { return std::isspace(c); }
static inline char upc(char c) { return (char)std::toupper((unsigned char)c); }

string remove_noise_prefix(string s) {
    const string p = "NOISE:";
    if (s.size() >= p.size()) {
        bool ok = true;
        for (size_t i = 0; i < p.size(); i++) {
            if (upc(s[i]) != p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            size_t j = p.size();
            while (j < s.size() && is_space((unsigned char)s[j])) j++;
            return s.substr(j);
        }
    }
    return s;
}

string remove_trailing_hash(string s) {
    if (s.size() >= 3 && s.compare(s.size() - 3, 3, "###") == 0) {
        s.erase(s.size() - 3);
        while (!s.empty() && s.back() == ' ') s.pop_back();  // 只去掉紧挨的空格
    }
    return s;
}

string process_brackets(const string& s) {
    string out;
    out.reserve(s.size());
    for (size_t i = 0; i < s.size();) {
        if (s[i] != '[') {
            out.push_back(s[i]);
            i++;
            continue;
        }
        size_t j = i + 1;
        while (j < s.size() && s[j] != ']') j++;
        string inside = s.substr(i + 1, j - (i + 1));
        bool all_letters = !inside.empty();
        for (unsigned char c : inside) {
            if (!is_letter(c)) {
                all_letters = false;
                break;
            }
        }
        if (all_letters) reverse(inside.begin(), inside.end());
        out += inside;  // 去掉括号
        i = j + 1;
    }
    return out;
}

string clean_line(string s) {
    s = remove_noise_prefix(std::move(s));
    s = remove_trailing_hash(std::move(s));
    s = process_brackets(s);
    return s;
}

// 在过滤串 T 上 O(N^2) 中心扩展，返回 (L,R) in T
pair<int, int> longest_pal_center_expand(const string& T) {
    int n = (int)T.size();
    int bestL = 0, bestR = 0;  // 默认长度1
    auto relax = [&](int L, int R) {
        int curLen = R - L + 1;
        int bestLen = bestR - bestL + 1;
        if (curLen > bestLen) {
            bestL = L;
            bestR = R;
        }
        // 平局“起点更靠前”：中心扩展按 i 从小到大扫描时，
        // 只要我们不在平局时更新，就天然保留更早起点。
    };

    for (int c = 0; c < n; c++) {
        // odd: L=R=c
        int L = c, R = c;
        while (L - 1 >= 0 && R + 1 < n && T[L - 1] == T[R + 1]) {
            L--;
            R++;
        }
        relax(L, R);

        // even: L=c, R=c+1
        L = c;
        R = c + 1;
        if (R < n) {
            while (L >= 0 && R < n && T[L] == T[R]) {
                L--;
                R++;
            }
            // 此时超出一格，回退
            relax(L + 1, R - 1);
        }
    }
    return {bestL, bestR};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    string S;
    while (getline(cin, line)) {
        if (line == "0") break;
        string t = clean_line(line);
        if (!t.empty()) S += t;  // 按“有效行”=非空来拼接
    }

    if (S.empty()) {
        cout << "EMPTY_SIGNAL\n";
        return 0;
    }

    string T;
    vector<int> mapTtoS;
    T.reserve(S.size());
    mapTtoS.reserve(S.size());

    for (int i = 0; i < (int)S.size(); i++) {
        unsigned char ch = (unsigned char)S[i];
        if (is_alnum(ch)) {
            T.push_back(S[i]);
            mapTtoS.push_back(i);
        }
    }

    if (T.empty()) {
        cout << "EMPTY_SIGNAL\n";
        return 0;
    }

    auto [L, R] = longest_pal_center_expand(T);

    int start = mapTtoS[L];
    int end = mapTtoS[R];
    cout << S.substr(start, end - start + 1) << "\n";
    return 0;
}