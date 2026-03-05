
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
map<string, int> ha = {{"Ocelot", 1}, {"Serval", 2}, {"Lynx", 3}};
int n, m, k;
int a[N];
void solve() {
    string a, b;
    cin >> a >> b;
    if (ha[a] >= ha[b]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}