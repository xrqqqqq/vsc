#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int r[N];
int f[N][50];

void init() {
    for (int j = 0; j <= (int)log2(n); j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            if (!j)
                f[i][j] = r[i];
            else
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}
int ask(int l, int r) {
     int len = (int)log2(r - l + 1);

    return max(f[l][len], f[r - (1 << len) + 1][len]);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        r[i] = 0;
    }
    stack<int> s;
    vector<int> rr(n+1,1e18);
    vector<int> ll(n+1,1e18);
    for(int i = n; i >= 1; --i) {
        while(s.size() && a[s.top()] > a[i]) s.pop();
        if(s.size()) rr[i] = s.top();
        s.push(i);
    }
    while(s.size()) s.pop();
    for(int i = 1; i <= n; ++i) {
        while(s.size() && a[s.top()] < a[i]) s.pop();
        if(s.size()) ll[i] = s.top();
        s.push(i);
    }
    for(int i = 1; i <= n; ++i) {
        if(rr[i] != 1e18&& ll[i] != 1e18) {
            r[rr[i]] = max(r[rr[i]],ll[i]);
        }
    }
    init();
    while (m--) {
        int l, r;
        cin >> l >> r;
        int t = ask(l,r);
        if (t >= l) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}