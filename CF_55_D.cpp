#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
const int M = 49;
int dp[N][M][2521];
int n, m;
int a[N];
int len;
void calc(int x) {
    while (x) {
        a[++len] = x % 10;
        x /= 10;
    }
}
int t = 0;
vector<int> tem;
void dfs(int u, int now) {
    if (u == 10) {
        tem.push_back(now);
        return;
    }
    dfs(u + 1, now);
    dfs(u + 1, now * u / __gcd(now, u));
}
int ne[2521];
// 48
int nee[M][M];
int mod = 2520;
vector<array<int,3>> tt;
int f(int u, int x, int sum, bool flag) { 
    if (u == 0) return sum % tem[x] == 0;
    if (flag && dp[u][x][sum] != -1) return dp[u][x][sum];
    int maxi = flag ? 9 : a[u];
    int ans = 0;
    for (int i = 0; i <= maxi; ++i) {
        int lc = i == 0 ? x : nee[x][i];
        ans += f(u - 1,lc,(sum * 10 + i) % mod,flag || (i < maxi));
    }
    if (flag) dp[u][x][sum] = ans;
    return ans;
}
void solve() {
    int l, r;
    cin >> l >> r;
    l--;
    len = 0;
    calc(r);
    int ans = 0;
    ans += f(len, 0, 0, 0);
    len = 0;
    calc(l);
    ans -= f(len,0,0,0);
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dfs(1, 1);
    sort(tem.begin(), tem.end());
    tem.erase(unique(tem.begin(), tem.end()), tem.end());
    for (int i = 0; i < tem.size(); ++i) {
        ne[tem[i]] = i;
    }
    for(int i = 0; i < tem.size(); ++i) {
        for(int j = 0; j <= 9; ++j) {
            int lc = j == 0 ? tem[i]: tem[i] / __gcd(tem[i],j) * j;
            if(lc <= tem[tem.size() - 1]) {
                nee[i][j] = ne[lc];
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}