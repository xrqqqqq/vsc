#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 10;
int n, m, k;
int a[N];
int dp[N][N];
array<int,2> f[N][N];
array<int,3> te[N];
void solve() {
    cin>>n;
    int len = 2*n;
    for(int i = 1;i <= len; ++i) {
        cin>>a[i];
    }
    vector<int> v(len+1);
    for(int i = 1; i <= len; ++i) {
        bool vv = 1;
        for(int j = 1; j <= i; ++j) {
            if(a[j] > a[i]) {
                vv = 0;
                break;
            }
        }
        v[i] = vv;
    }
    int su = -1;
    int cn = 0;
    for(int i = 1; i <= len;++i) {
        if(v[i]) {
            if(su == -1) {
                su = 1;
            }
            else {
                te[++cn] = {su,i-1-su+1,i-1};
                su = 1;
            }
        }
        else su++;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= cn; ++i) {
        int si = te[i][0];
        for(int j = 0; j <= len; ++j) {
            if(dp[i-1][j]) {
                dp[i][j] = 1;
                f[i][j] = {i-1,j};
            }
            if(j - si >= 0) {
                if(dp[i-1][j-si]) {
                    dp[i][j] =  1;
                    f[i][j] = {i-1,j-si};
                }
            }
        }
    }
    if(!dp[cn][len/2]) {
        cout<<-1;
    }
    else {
        vector<int> vis(len + 1);
        int ni = cn,nj = len/2;
        while(ni) {
            auto [i,j] = f[ni][nj];
            if(j != nj) {
                for(int k = te[ni][1];k <= te[ni][2];++k) {
                    vis[k] = 1;
                }
            }
            ni = i;
            nj = j;
        }
        for(int i = 1; i <= len; ++i) {
            if(vis[i]) {
                cout<<a[i]<<" ";
            }
        }
        cout<<"\n";
        for(int i = 1;i <= len; ++i) {
            if(!vis[i]) {
                cout<<a[i]<<" ";
            }
        }
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