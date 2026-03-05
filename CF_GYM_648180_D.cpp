#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 1e3 + 10;
int n,m;
void test() {
    cin>>n;
    cout<<n-1<<"\n";
    for(int i = 2; i <= n; ++i) {
        cout<<1<<" "<<i<<'\n';
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