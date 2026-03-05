#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
string s;
vector<array<int,2>> ad;
int now;
void dfs(int u) {
    if(now <= 0) return ;
    while(now >= 1&&s[now] == '0') {
        ad.push_back({u,now});
        now--;
    }
    if(now <= 0) return ;
    ad.push_back({u,now});
    now--;
    dfs(now + 1);
}
void solve() {
    cin>>s;
    n = s.size();
    s = " " + s;
    if(s[n] == '1'||s[1] == '0' ||s[n-1] == '0') {
        cout<<-1<<"\n";
        return ;
    }
    for(int i = 1; i <= n - 1; ++i) {
        if(s[i] != s[n-i]) {
            cout<<-1<<"\n";
            return ;
        }
    }
    int root = n - 1;
    int rt = root+1;
    ad.push_back({rt,root});
    now = root - 1;
    dfs(root);
    for(auto [x,y] : ad) {
        cout<<x<<" "<<y<<"\n";
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