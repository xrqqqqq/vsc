#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
void solve() {
    cin>>n>>m;
    string s;
    cin>>s;
    bool v = 0;
    vector<array<int,2>> te(n+1);
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'B') v = 1;
    } 
    if(v == 0) {
        while(m--) {
            int x;
            cin>>x;
            cout<<x<<"\n";
        }
    }
    else {
        while(m--) {
            int x;
            cin>>x;
            int id = 0;
            int ans = 0;
            while(x) {
                ans++;
                if(s[id] == 'A') x--;
                else x >>= 1;
                id++;
                if(id == n) id = 0;
            }
            cout<<ans<<"\n";
        }
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