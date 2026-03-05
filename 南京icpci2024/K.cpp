#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    set<int> st;
    vector<int> a(n + 1);
    st.insert(0);
    st.insert(w + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    vector<int> ans;
    sort(a.begin() + 1, a.end());

    auto fd = [&](int i) -> pair<int, int> {
        int r = *st.upper_bound(a[i]);
        int l = *prev(st.lower_bound(a[i]));
        int R = min(r - 1, a[i] + k - 1);
        int L = max(l + k, a[i]);
        return make_pair(L,R);
    };

    for (int i = n; i >= 1;) {
        auto [L,R] = fd(i);
        if (L > R) {
            cout << -1 << '\n';
            return;
        }

        int tmp = i - 1;
        for (int j = i - 1; j >= 1; j--) {
            tmp = j;
            auto [l,r] = fd(j);
            if (L > r) {
                break;
            }
            tmp = j - 1;
            L = max(r,L);
            R = min(R,r);
        }
        
        ans.push_back(R - k + 1);
        st.insert(R - k +1);
        i = tmp;
    }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << " ";
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