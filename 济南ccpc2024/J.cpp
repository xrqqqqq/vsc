#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
    int x, y, z;
};

void solve() {
    int n;
    cin >> n;
    map<int,int> mp[3];
    vector<node> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        mp[0][a[i].x]++;
        mp[1][a[i].y]++;
        mp[2][a[i].z]++;
    }
    vector<int> b;
    b.push_back(-1e9);
    for (int i = 1; i <= n; i++) {
        int tmp = max({mp[0][a[i].x], mp[1][a[i].y], mp[2][a[i].z]}) - 1;
        b.push_back(tmp);
        // cout << tmp << endl;
    }
    sort(b.begin(),b.end());
    int i = 1;
    for (int k = 0; k < n; k++) {
        while (i <= n && b[i] < k) {
            i++;
        }
        cout << i - 1 << ' ';
    }
    cout << '\n';
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