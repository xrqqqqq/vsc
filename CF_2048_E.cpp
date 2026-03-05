
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 10;
int n, m, k;
int f[N*2][N];
int p[N*2];
void solve() {
    cin>>n>>m;
    if(2*n <= m) {
        cout<<"NO\n";
        return ;
    }    
    cout<<"YES\n";
    int cnt = 1;
    for(int i = 1; i <= n*2; ++i) {
        p[i] = cnt;
        if(i % 2 == 0) {
            cnt++;
        }
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= 2*n; ++j) {
            f[j][i] = p[j];
        }
        int t = p[2*n];
        for(int j = 2*n; j >= 2; --j) {
            p[j] = p[j-1];
        }
        p[1] = t;
    }
    for(int i = 1; i <= 2*n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout<<f[i][j]<<" ";
        }
        cout<<"\n";
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