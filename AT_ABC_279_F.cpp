#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int p[N];
int si[N];
int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return x;
}
int down[N];
int up[N];
void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n + m; ++i) {
        down[i] = i + n;
        up[i+n] = i;
        p[i+n] = i+n;
    }
    int cnt = n;
    while(m--) {
        int op;
        cin>>op;
        if(op == 1) {
            int x,y;
            cin>>x>>y;
            if(down[y] == -1) continue;
            if(down[x] == -1) {
                up[down[y]] = x;
                down[x] = down[y];
            }
            else {
                up[down[y]] = 0;
                p[down[y]] = down[x];
            }
            down[y] = -1;
        }
        else if(op == 2) {
            cnt++;
            int x;
            cin>>x;
            if(down[x] == -1) {
                down[x] = cnt + n;
                up[cnt+n] = x;
            }
            else {
                p[cnt+n] = down[x];
            }
        }
        else {
            int x;
            cin>>x;
            x += n;
            // cout<<x<<" "<<find(x)<<"\n";
            cout<<up[find(x)]<<"\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}