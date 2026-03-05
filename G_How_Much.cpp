#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int mod = 998244353;
int a[N];
struct node {
    int s[N << 2], tagc[N << 2], tagd[N << 2];

#define ls (u << 1)

#define rs (u << 1 | 1)

    void up(int u) { s[u] = (s[ls] % mod + s[rs] % mod) % mod; }

    void down(int u, int l, int r) {
        int mid = l + r >> 1;

        int le1 = mid - l + 1;

        int le2 = r - mid;

        s[ls] = (s[ls] * tagc[u] % mod + tagd[u] * (le1) % mod) % mod;

        tagc[ls] = (tagc[ls] * tagc[u]) % mod;

        tagd[ls] = (tagd[ls] * tagc[u] % mod + tagd[u]) % mod;

        s[rs] = (s[rs] * tagc[u] % mod + tagd[u] * (le2) % mod) % mod;

        tagc[rs] = (tagc[rs] * tagc[u]) % mod;

        tagd[rs] = (tagd[rs] * tagc[u] % mod + tagd[u]) % mod;

        tagd[u] = 0;

        tagc[u] = 1;
    }

    void build(int u, int l, int r) {
        s[u] = tagd[u] = 0;

        tagc[u] = 1;

        if (l == r) {
            s[u] = a[l];

            return;
        }

        int mid = l + r >> 1;

        build(ls, l, mid), build(rs, mid + 1, r);

        up(u);
    }

    void change(int u, int l, int r, int L, int R, int c, int d) {
        if (L <= l && r <= R) {
            s[u] = (s[u] * c % mod + d * (r - l + 1)) % mod;

            tagc[u] = (tagc[u] * c) % mod;

            tagd[u] = (tagd[u] * c + d) % mod;

            return;
        }

        int mid = l + r >> 1;

        down(u, l, r);

        if (L <= mid) change(ls, l, mid, L, R, c, d);

        if (mid < R) change(rs, mid + 1, r, L, R, c, d);

        up(u);
    }

    int ask(int u, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return s[u];
        }

        int res = 0;

        int mid = l + r >> 1;

        down(u, l, r);

        if (L <= mid) res += ask(ls, l, mid, L, R);

        if (mid < R) res += ask(rs, mid + 1, r, L, R);

        up(u);

        return res % mod;
    }

} tr;
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void solve() {
    cin>>n;
    if(n ==0) {
        cout<<0<<" "<<0<<"\n";
        return ;
    }
    cout<<1<<" ";
    int cnt = 0;
    int x = n;
    while(x) {
        if(x & 1ll) cnt++;
        x >>= 1;
    }
    cout<<cnt<<"\n";
}
signed main() {
    int T = 1;
    // cin >> T;
    // getchar();
    while (T--) {
        solve();
    }
}