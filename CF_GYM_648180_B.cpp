#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 1e6 + 10;
int n,m;
int a[N];
void test() {
    cin>>n>>m;
    int cnt0 = 0;
    int ans = 0;
    int id = 0;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    for(int i = 1; i <= n; ++i) {
        id += a[i];
        if(a[i] == 0) id += m;
        ans = max(ans,abs(id));
    }
    id = 0;
    for(int i = 1; i <= n; ++i) {
        id += a[i];
        if(a[i] == 0) id -= m;
        ans = max(ans,abs(id));
    }
    cout<<ans;
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