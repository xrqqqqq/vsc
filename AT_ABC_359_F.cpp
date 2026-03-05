#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
void solve() {
    auto cmp = [&](const array<int,2> a,const array<int,2> b) {
        return (2*a[0] + 1)*a[1] > (2*b[0] + 1)*b[1];
    };
    priority_queue<array<int,2>,vector<array<int,2>>,decltype(cmp)> q(cmp);
    int ans = 0;
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin>>x;
        q.push({1,x});
    }
    n = 2*(n-1) - n;
    while(n--) {
        auto t = q.top();
        q.pop();
        t[0]++;
        q.push(t);
    }
    while(q.size()) {
        auto t = q.top();
        q.pop();
        ans += t[0]*t[0]*t[1];
    }
    cout<<ans<<"\n";
}   
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}