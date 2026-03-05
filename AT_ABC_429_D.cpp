
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin >> n >> m >> k;
    map<int, int> ha;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin>>x;
        ha[x]++;
    }
    int ans = 0;
    int last = 0;
    int su = n;
    vector<int> sum(2*n+2);
    int id = 0;
    for(auto [x,y] : ha) {
        sum[++id] = y;
    }
    for(int i = id + 1; i <= 2*id; ++i) {
        sum[i] = sum[i-id];
    }
    for(int i = 1; i <= 2*id; ++i) {
        sum[i] += sum[i-1];
    }
    int t = 0;
    for(auto [x,y] : ha) {
        t++;
        int len = x - last;
        int l = t,r = 2*id;
        while(l < r) {
            int m = l + r >> 1;
            if(sum[m] - sum[t-1] >= k) r = m;
            else l = m + 1;
        }
        // cout<<x<<" "<<last<<" "<<(sum[l] - sum[t-1])<<"\n";
        ans += (sum[l] - sum[t-1]) * len;
        su -= y;
        last = x;
    }
    t++;
    int len = m - 1 - last + 1;
    int l = t, r = 2 * id;
    while (l < r) {
        int m = l + r >> 1;
        if (sum[m] - sum[t - 1] >= k)
            r = m;
        else
            l = m + 1;
    }
    ans += (sum[l] - sum[t - 1]) * len;
    cout<<ans;
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