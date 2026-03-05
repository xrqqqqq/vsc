
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30 + 10;
int n, m, k;
string p [101][N];
vector<vector<int>> ans;
vector<array<int,2>> tem;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int f(string a[]) {
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i == 0 ||i == n -1 ||j == 0 || j == m - 1) continue;
            bool v = 0;
            char c = a[i][j];
            for(int k = 0; k < 4; ++k) {
                int ii = i + dx[k],jj = j + dy[k];
                if(a[ii][jj] == c) 
                {
                    v  = 1;
                    break;
                }
            }
            if(!v) cnt++;
        }
    }
    return cnt;
}
void solve() {
    cin>>n>>m>>k;
    for(int i = 0; i <= k; ++i) {
        for(int j = 0; j < n; ++j) {
            cin>>p[i][j];
        }
        tem.push_back({f(p[i]), i});
    }
    sort(tem.begin(),tem.end());
    cout<<tem[tem.size() - 1][1] + 1<<"\n";
    for(int i = tem.size() - 1; i >= 1; --i) {
        auto p1 = p[tem[i][1]],p2 = p[tem[i-1][1]];
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < m; ++k) {
                if(p1[j][k] != p2[j][k]) {
                    ans.push_back({1,j + 1,k + 1});
                }
            }
        }
        ans.push_back({2,tem[i-1][1] + 1});
    }
    cout<<ans.size()<<"\n";
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<"\n";
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