#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
int ask(int id, int x) {
    cout << "? " << id << " " << x << endl;
    int res;
    cin >> res;
    return res;
}
void solve() {
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]] = i;
    }
    for (int j = 1; j <= n; ++j) {
        vector<array<int,2>> te;
        for(int i = 1; i <= n; ++i) {
            te.push_back({a[i],i});
        }
        sort(te.begin(),te.end(),greater<>());
        for(int k = n - 1; k >= 0; --k) {
            int i = te[k][1];
            if (a[i] > 2) {
                int t1 = cnt[a[i] - 1], t2 = cnt[a[i] - 2];
                if (t1 < i || t2 < i) continue;
                a[i] -= 2;
                cnt[a[i]] = i;
                a[t1] += 1;
                cnt[a[t1]] = t1;
                a[t2] += 1;
                cnt[a[t2]] = t2;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
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