#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 35 + 10;
int n, m, k;
int a[N];
bool dp[N][N*N];
int ldp[N][N*N];
vector<int> ne[N];
int d[N];
int ans[N];
void solve() {
    cin>>n>>k;
    int mx = (n*(n-1))/2;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= mx; ++j) {
            dp[i][j] = 0;
        }
        d[i] = 0;
        ne[i].clear();
    }
    dp[1][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= mx; ++j) {
            if(dp[i][j] == 1) {
                for(int ii = i + 1; ii <= n; ++ii) {
                    int jj = j + (ii - i)*(n-ii+1);
                    if(dp[ii][jj] == 0) {
                        dp[ii][jj] = 1;
                        ldp[ii][jj] = i;
                    }
                }
                if(dp[n][j] == 0) {
                    dp[n][j] = 1;
                    ldp[n][j] = i;
                }
            }
        }
    }
    if(dp[n][k] == 0) {
        cout<<0<<"\n";
        return ;
    }
    vector<int> te(n+1);
    int ii = n;
    int kk = k;
    while(ii > 1) {
        int get = ldp[ii][kk];
        if(dp[get][kk]) {
            ii = get;
        }
        else {
            te[ii] = 1;
            kk -= (ii - get) * (n - ii + 1);
            ii = get;
        }
    }
    for(int i = 2; i <= n; ++i) {
        if(te[i]) {
            ne[i-1].push_back(i);
            d[i]++;
        }   
        else {
            ne[i].push_back(i-1);
            d[i-1]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) if(d[i] == 0) q.push(i);
    int nn =  n;
    while(q.size()) {
        auto t = q.front();
        ans[t] = nn;
        nn--;
        q.pop();
        for(auto i : ne[t]) {
            d[i]--;
            if(d[i] == 0) {
                q.push(i);
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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