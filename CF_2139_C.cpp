#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    int k, x;
    cin >> k >> x;
    if ((1ll << k) == x) {
        cout << 0 << "\n";
        cout << "\n";
        return;
    }
    vector<int> ans;
    while(x != (1ll << k)) {
        int te = (1ll<<(k+1)) - x;
        if(x < te) {
            ans.push_back(1);
            te -= x;
            x = 2*x;
        }
        else {
            ans.push_back(2);
            x -= te;
            te = 2*te;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<"\n";
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