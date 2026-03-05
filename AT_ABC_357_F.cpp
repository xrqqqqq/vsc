#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int mod = 998244353;
int n, m, k;
int f(__int128 x) { return (x % mod + mod) % mod; }
int a[N];
int b[N];
struct node {
    int suma[N << 2], sumb[N << 2], res[N << 2], taga[N << 2], tagb[N << 2];
#define ls (u << 1)
#define rs (u << 1 | 1)
    void up(int u) {
        res[u] = f(res[ls] + res[rs]);
        suma[u] = f(suma[ls] + suma[rs]);
        sumb[u] = f(sumb[ls] + sumb[rs]);
    }
    void down(int u, int l, int r) {
        int mid = l + r >> 1;
        if (taga[u]) {
            res[ls] = f(res[ls] + sumb[ls] * taga[u]%mod);
            taga[ls] = f(taga[ls] + taga[u]);
            suma[ls] = f(suma[ls] + taga[u] * (mid - l + 1) % mod);
            res[rs] = f(res[rs] + sumb[rs] * taga[u]%mod);
            taga[rs] = f(taga[rs] + taga[u]);
            suma[rs] = f(suma[rs] + taga[u] * (r - mid) % mod);
            taga[u] = 0;
        }
        if (tagb[u]) {
            res[ls] = f(res[ls] + suma[ls] * tagb[u]%mod);
            tagb[ls] = f(tagb[ls] + tagb[u]);
            sumb[ls] = f(sumb[ls] + tagb[u] * (mid - l + 1) % mod);
            res[rs] = f(res[rs] + suma[rs] * tagb[u]%mod);
            tagb[rs] = f(tagb[rs] + tagb[u]);
            sumb[rs] = f(sumb[rs] + tagb[u] * (r - mid) % mod);
            tagb[u] = 0;
        }
    }
    void build(int u, int l, int r) {
        if (l == r) {
            res[u] = f(a[l] * b[l]);
            suma[u] = a[l];
            sumb[u] = b[l];
            return;
        }
        int mid = l + r >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        up(u);
    }
    void change(int u, int l, int r, int L, int R, int c, int op) {
        if (L <= l && r <= R) {
            if (op == 1) {
                taga[u] = f(taga[u] + c);
                res[u] = f(res[u] + sumb[u] * c%mod);
                suma[u] = f(suma[u] + c * (r - l + 1) % mod);
            } else {
                tagb[u] = f(tagb[u] + c);
                res[u] = f(res[u] + suma[u] * c%mod);
                sumb[u] = f(sumb[u] + c * (r - l + 1) % mod);
            }
            return;
        }
        int mid = l + r >> 1;
        down(u, l, r);
        if (mid >= L) change(ls, l, mid, L, R, c, op);
        if (mid < R) change(rs, mid + 1, r, L, R, c, op);
        up(u);
    }
    int ask(int u, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return res[u];
        }
        int ans = 0;
        int mid = l + r >> 1;
        down(u, l, r);
        if (L <= mid) ans = f(ans + ask(ls, l, mid, L, R));
        if (mid < R) ans = f(ans + ask(rs, mid + 1, r, L, R));
        up(u);
        return f(ans);
    }
} tr;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    tr.build(1, 1, n);
    while (m--) {
        int op, l, r, x;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
            tr.change(1, 1, n, l, r, x, op);
        } else if (op == 2) {
            cin >> x;
            tr.change(1, 1, n, l, r, x, op);
        } else {
            cout << tr.ask(1, 1, n, l, r)%mod << "\n";
        }
    }
}