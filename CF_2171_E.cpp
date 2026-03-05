
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m;
int a[N];
vector<int> ne[N];
void solve() {
    cin >> n;
    set<int> s;
    set<int> ss;
    for (int i = 1; i <= n; ++i) {
        s.insert(i);
        ss.insert(i);
        ne[i].clear();
        a[i] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            if (s.count(j)) {
                s.erase(j);
                ne[i].push_back(j);
            }
        }
        if (ne[i].size() & 1) {
            int t = ne[i].back();
            ne[i].pop_back();
            s.insert(t);
        }
    }
    if (n == 3) {
        cout << 1 << " " << 2 << " " << 3 << "\n";
        return;
    }
    int id = 2;
    for (int i = 3; i <= n; i += 3) {
        if (i + 1 > n) break;
        while (id <= n && ne[id].size() == 0) id++;
        if (id == n + 1) break;
        auto t1 = ne[id].back();
        ne[id].pop_back();
        auto t2 = ne[id].back();
        ne[id].pop_back();
        a[i] = t1, a[i + 1] = t2;
        ss.erase(t1), ss.erase(t2);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            cout << (*ss.begin()) << " ";
            ss.erase(ss.begin());
        } else {
            cout << a[i] << " ";
        }
    }
    cout << "\n";
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