#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
vector<int> ne[N];
void solve() {
    cin>>n>>m;
    vector<int> cnt(m+1);
    vector<vector<int>> tem(n+1);
    for(int i = 1; i <= n; ++i) {
        int si;
        cin>>si;
        while(si--) {
            int x;
            cin>>x;
            cnt[x]++;
            tem[i].push_back(x);
        }
    }
    int cnt1 = 0;
    for(int i = 1; i <= m; ++i) {
        if(cnt[i] == 0) {
            cout<<"NO\n";
            return ;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(auto x : tem[i]) {
            if(cnt[x] == 1) {
                cnt1 ++;
                break;
            }
        }
    }
    if(n - cnt1 > 1) {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
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