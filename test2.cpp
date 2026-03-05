#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int mod = 998244353;
const int N = 1e5 + 10;
ll f[N], invf[N];
ll pows(ll a, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
void init() {
    f[1] = 1;
    invf[1] = pows(f[1], mod - 2);
    for (int i = 2; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        invf[i] = pows(f[i], mod - 2);
    }
}
ll c(ll a, ll b) {
    if(b>a)return 0; 
    return f[a] * invf[a - b] % mod * invf[b] % mod; 
}
void test() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n + 1);
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (int)(s[i] - '0');
    }
    int ss;
    for (ss = 1; ss <= n; ss++) {
        if (a[ss] >= k) {
            break;
        }
    }
    if (a[ss] < k) {
        cout << 0 << '\n';
        return;
    }
    int ans = c(ss, k);
    for (int i = ss + 1; i <= n; i++) {
        int l = 1, r = i;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (a[i] - a[ss - mid] >= k)
                l = mid;
            else
                r = mid - 1;
        }
        if (s[i] == '1') {
            ans = (ans + (k > l - 1 ? 0 : c(l - 1, k))) % mod;
        } else {
            ans = (ans + (k - 1 > l - 1 ? 0 : c(l - 1, k - 1))) % mod;
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    init();
    while (T--) {
        test();
    }
    return 0;
}