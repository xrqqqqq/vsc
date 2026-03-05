#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int a[N];
void solve() {
    cin >> n >> k;
    multiset<int> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= k;
        s.insert(a[i]);
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    priority_queue<array<int, 3>> q;
    auto t = s.find(a[1]);
    s.erase(t);
    function<array<int, 2>(int x)> get = [&](int x) {
        if (s.size() == 0) return array<int, 2>{-1, -1};
        auto it = s.lower_bound(k - x);
        vector<array<int,2>>res;
        if (it == s.end()) {
            it--;
            res.push_back({(*(it) + x) % k, *it});

        } else if (it == s.begin()) {
            res.push_back({(*(it) + x) % k, *it});
        } else {
            res.push_back({(*(it) + x) % k, *it});
            it--;
            res.push_back({(*(it) + x) % k, *it});
        }
        it = s.begin();
        res.push_back({(*(it) + x) % k, *it});
        sort(res.begin(),res.end());
        return res[0];
    };
    auto p = get(a[1]);
    q.push({-p[0], a[1], p[1]});
    int ans = 0;
    while (q.size()) {
        auto [val, x, y] = q.top();
        q.pop();
        // if(!s.count(y)) continue;
        if (s.size() == 0) {
            break;
        }
        if (s.count(y) == 0) {
            auto p = get(y);
            if (p[0] != -1) {
                q.push({-p[0], y, p[1]});
            }
            continue;
        }
        ans += -val;
        s.erase(s.find(y));
        if (s.size() == 0) {
            break;
        }
        auto p = get(y);
        if (p[0] != -1) {
            q.push({-p[0], y, p[1]});
        }
        p = get(x);
        if (p[0] != -1) {
            q.push({-p[0], x, p[1]});
        }
    }
    cout << ans << "\n";
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