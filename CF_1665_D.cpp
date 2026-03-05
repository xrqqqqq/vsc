
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int ask(int a,int b) {
    cout<<"? "<<a <<" "<<b<<endl;
    int x;
    cin>>x;
    return x;
}
void solve() {
    int ans = 0;
    for(int i = 0; i <= 29; ++i) {
        int ad = (1ll<<i) - ans;
        int res = ask(ad,ad + (1ll<<(i+1)));
        if(res % (1ll<<(i+1)) == 0) {
            ans += (1<<i);
        } 
    }
    cout<<"! "<<ans<<endl;
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