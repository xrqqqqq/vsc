#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
vector<int> ne[N];
int tr[N];
void add(int u,int c) {
    for(;u;u -= u&-u) tr[u] = max(tr[u],c);
}
int ask(int u) {
    int res = 0;
    for(;u <= n;u += u & -u) res = max(res,tr[u]);
    return res;
}
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) tr[i] = 0;
    vector<int> cnt(n+1);
    int g = 0;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin>>x;
        g = __gcd(x,g);
        for(auto ii : ne[x]) {
            cnt[ii]++;
            add(ii,cnt[ii]);
        }
        cout<<ask(g+1)<<" ";
    }
    cout<<"\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 2e5;
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            ne[j].push_back(i);
        }
    }
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}