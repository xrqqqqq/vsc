#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
array<int,3> a[N];
int p[N];
int find(int x) {
    if(p[x] != x) return p[x] = find(p[x]);
    return x;
}
void solve() {
    cin>>n;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i][0] >> a[i][1];
        a[i][2] = i;
        p[i] = i;
    }
    sort(a + 1,a + n + 1);
    priority_queue<array<int,3>,vector<array<int,3>>,greater<>> q;
    for(int i = 2; i <= n; ++i) {
        q.push({a[i][0] - a[i-1][0],a[i][2],a[i-1][2]});
    }
    sort(a + 1, a + n + 1,[](const array<int,3> &x,const array<int,3> &y) {
        return x[1] < y[1];
    });
    for(int i = 2; i <= n; ++i) {
        q.push({a[i][1] - a[i-1][1],a[i][2],a[i-1][2]});
    }
    int cnt = 0;
    while(q.size()) {
        auto [x,y,z] = q.top();
        q.pop();
        y = find(y) , z = find(z);
        if(y != z) {
            ans += x;
            cnt++;
            if(cnt == n - 1) break;
            p[y] = z;
        }
    }
    cout<<ans;
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