#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
void solve() {
    cin>>n;
    int ans = 0;
    while(n) {
        if(n <= 2) {
         
            break;
        }
        ans += n/3;
        n -= 2*(n/3);
    }
    cout<<ans<<"\n";
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