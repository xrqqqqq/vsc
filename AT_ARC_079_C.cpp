#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin >> n;
    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum >= n * (n - 1)) {
        sum = sum - n * (n - 1);
        ans += sum;
        int get = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] += sum;
            if (a[i] >= 2 * (n + 1)) {
                int p = (a[i] - 2 * (n + 1)) / (n + 1);
                get += p;
                a[i] = a[i] - p * (n + 1);
            }
        }
        priority_queue<int> q;
        for (int i = 1; i <= n; ++i) q.push(a[i]);
        sum -= get;
        while (sum) {
            auto p = q.top();
            q.pop();
            q.push(p - (n + 1));
            sum--;
        }
        int ad = 0;
        while (q.top() + ad >= n) {
            auto p = q.top();
            q.pop();
            ans++;
            ad++;
            q.push(p - (n + 1));
        }
        cout << ans << "\n";
    } else {
        priority_queue<int> q;
        for (int i = 1; i <= n; ++i) q.push(a[i]);
        int ad = 0;
        while (q.top() + ad >= n) {
            auto p = q.top();
            q.pop();
            ans++;
            ad++;
            q.push(p - (n + 1));
        }
        cout << ans << "\n";
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