#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 1e3 + 10;
int n, m;
void test() {
    cin>>n>>m;
    int ans = ((1ll<<33) - 1);
    for(int i = 1;i  <= n; ++i) {
        int x;
        cin>>x;
        if((x & m) == m) {
            ans &= x;
        }
    }
    if(ans == m) {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }
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