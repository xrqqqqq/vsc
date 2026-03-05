
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
string s;
int ask(int x) {
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
}
int ans;
void solve() {
    cin>>n>>k;
    if(k > n) {
        cout<<"NO\n";
        return ;
    }
    if(k <= (n+1)/2) {
        cout<<"YES\n";
        cout<<2<<"\n";
        cout<<n - k + 1<<" "<<1<<"\n";
        // int t = n / (n - k + 1);
        // cout<<1<<"\n";
    }
    else {
        if(n == 2*k - 1) {
            cout<<"YES\n";
            cout<<2<<"\n";
            cout<<k<<" "<<1<<"\n";
            return ;
        }
        if(n == k) {
            cout<<"YES\n";
            cout<<1<<"\n";
            cout<<1<<"\n";
            return ;
        }
        cout<<"NO\n";
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