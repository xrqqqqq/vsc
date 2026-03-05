#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin >> n;
    int mx = 0;
    int mi = 1e18;
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        mx = max(mx, a[i]);
        mi = min(mi, a[i]);
    }
    if (abs(mx - mi) > 1) {
        cout << "No\n";
        return;
    }
    int ne = mx;
    if (mx != mi) {
        n -= cnt[mi];
        ne -= cnt[mi];
        // cout<<n<<" "<<ne<<"\n";
        if (ne <= 0) {
            cout << "No";
            return;
        }
        else if(ne * 2 <= n) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        if (ne * 2 <= n || ne + 1 == n) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
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