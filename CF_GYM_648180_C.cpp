#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 1e3 + 10;
int n, m;
int a[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void test() {
    cin>>n>>m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin>>a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 2) {
                for(int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x < 1 || x > n || y < 1 || y > m || a[x][y] != 0) continue;
                    a[x][y] = 1;
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        test();
    }
    return 0;
}