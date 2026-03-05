
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int n;
void solve() {
    cin>>n;
    int mx = 0; 
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        mx = max({mx,a[i]});
    }
    if(n == 1|| n >= 4) {
        cout<<mx*n<<"\n";
    }
    else if(n == 2) {
        cout<<max(2*abs(a[1] - a[2]),a[1]+a[2])<<"\n";
    }
    else if(n == 3) {
        if(a[1] == mx || a[3] == mx) {
            cout<<3*mx<<"\n";
        }
        else {
            cout<<max({a[1]+a[2]+a[3],3*a[1],3*a[3],a[3] + 2*(abs(a[1] - a[2])),a[1] + 2*abs(a[2] - a[3]),3*abs(a[2] - a[1]),3*abs(a[2] - a[3])})<<"\n";
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