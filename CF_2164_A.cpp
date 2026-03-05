
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int n,m,k;
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    int x;
    cin>>x;
    int c0 = 0;
    int c1 = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] < x) c0++;
        else if(a[i] > x) c1++;
        else {
            c0++;
            c1++;
        }
    }
    if(c1&&c0) {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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