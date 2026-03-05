#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n,m,k;
int f(int x) {
    return (x%k + k)%k;
}
void solve() {
    cin>>n>>k;
    vector<int> sum(n+1);
    for(int i  =1; i <= n; ++i) {
        int x;
        cin>>x;
        x--;
        x = f(x);
        // cout<<x<<"\n";
        sum[i] = f(sum[i-1] + x);
    }
    map<int,int> ha;
    int ans = 0;
    ha[0]++;
    for(int r = 1; r <= n; ++r) {
        if(r - k >= 0) {
            ha[f(sum[r-k])]--;
        }
        ans += ha[f(sum[r])];
        // cout<<ha[sum[r] - r)]<<"\n";
        ha[f(sum[r])]++;
    }
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