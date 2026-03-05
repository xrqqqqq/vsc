#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3 + 10;
int n, m, k;
int a[N];
int v[N];
int b[N];
int ne[N][N];
int id[N];
void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin>>ne[i][j];
        }
    }
    function<bool(int)> check = [&](int x) {
        for(int i = 1; i <= m; ++i) v[i] = 0;
        for(int i = 1; i <= m; ++i) b[i] = 0;
        for(int i = 1; i <= n; ++i) b[ne[i][1]]++,id[i] = 1;
        bool flag = true;
        while(flag) {
            bool ok = 1;
            for(int i = 1; i <= m; ++i) {
                if(b[i] > x) {
                    v[i] = 1;
                    ok = 0;
                }
            }
            if(ok) {
                return true;
            }
            for(int i = 1; i <= n; ++i) {
                while(id[i] <= m&&v[ne[i][id[i]]]) {
                    b[ne[i][id[i]]]--;
                    id[i]++;
                    b[ne[i][id[i]]]++;
                }
            }
            ok = 1;
            for(int i = 1; i <= m; ++i) {
                if(v[i] == 0) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                return false;
            }
        }
        return !flag;
    };
    int l = 1, r = n;
    while(l < r) {
        int m = l + r >> 1;
        if(check(m)) r = m;
        else l = m + 1;
    }
    cout<<l<<"\n";
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