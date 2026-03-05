#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n,m,k;
int dp[N];
int last[N];
int su[N];
int a[N];
int t[N];
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    dp[1] = n;
    set<int> s;
    int cnt = 0;
    for(int i = n; i >= 1; --i) {
        s.insert(a[i]);
        t[n - i + 1] = s.size();
    }
    for(int i = 1; i <= n; ++i) {
        int len = i - last[a[i]];
        su[len]++;
        last[a[i]] = i;
    }
    for(int i = n; i >= 1; --i) {
        su[i] += su[i+1];
    }
    for(int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] - t[i-1] + su[i];
    }
    cin>>m;
    while(m--) {
        int x;
        cin>>x;
        cout<<dp[x]<<"\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}