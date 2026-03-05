
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int dp[N];
int sum[N];
array<int,2> to[N];
vector<array<int,2>> ans;
void to0(int l,int r) {
    bool v = 0;
    for(int i = l;i <= r; ++i) {
        if(a[i] == 0) v = 1;
    }
    if(v) {
        ans.push_back({l,r});
        ans.push_back({l,r});
    }
    else {
        ans.push_back({l,r});
    }
}
void sh(int l,int r) {
    if(l == r) {
        return ;
    }
    else if(l + 1== r) {
        ans.push_back({l,r});
        ans.push_back({l+1,r});
        return ;
    }
    sh(l,r-1);
    ans.push_back({l,r-1});
    ans.push_back({l+1,r});
    ans.push_back({l+1,r});
    sh(l+1,r);
}
void f(int l,int r) {
    to0(l,r);
    sh(l,r);
    ans.push_back({l,r});
}
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1;j <= i; ++j) {
            if(dp[i] < dp[j-1] + sum[i] - sum[j-1]) {
                dp[i] = dp[j-1] + sum[i] - sum[j-1];
                to[i] = {j-1,0};
            }
            if(dp[i] < dp[j-1] + (i-j+1)*(i-j+1)) {
                dp[i] = dp[j-1] + (i-j+1)*(i-j+1);
                to[i] = {j-1,1};
            }
        }
    }
    cout<<dp[n]<<" ";
    int id = n;
    while(id >= 1) {
        auto [l,v] = to[id];
        if(v) {
            f(l+1,id);
        }
        id = l;
    }
    cout<<ans.size()<<"\n";
    for(auto [i,j] : ans) {
        cout<<i<<" "<<j<<"\n";
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