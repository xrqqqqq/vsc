#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
constexpr int N = 3e5 + 5, P = 998244353;

ll fac[N], inv[N], gg[30], ig[30];

ll qpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return ret;
}
void init(int n) {
    fac[0] = 1;
    for(int i = 1; i <= n; ++i) {
        fac[i] = fac[i-1]* i % P;
    }
    inv[n] = qpow(fac[n],P-2);
    for(int i = n - 1; i >= 0; --i) {
        inv[i] = inv[i + 1] * (i  + 1) %P;
    }
    inv[0] = 1; 
    for (int i = 1; i < 30; ++i) gg[i] = qpow(3, (P - 1) / (1 << i));
    for (int i = 1; i < 30; ++i) ig[i] = qpow(gg[i], P - 2);
}
int tot, rev[N], s[N], bit;

void ntt(vector<ll> &a, int ty) {
    for (int i = 0; i < tot; ++i) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    int o = 1;
    for (int mid = 1; mid < tot; mid <<= 1, ++o) {
        ll g1 = gg[o];
        if (ty == -1) {
            g1 = ig[o];
        }
        for (int i = 0; i < tot; i += mid * 2) {
            ll gk = 1;
            for (int j = 0; j < mid; ++j, gk = gk * g1 % P) {
                ll x = a[i + j], y = a[i + j + mid];
                a[i + j] = (x + gk * y) % P;
                a[i + j + mid] = (x - gk * y) % P;
            }
        }
    }
    if (ty == -1) {
        ll tmp = qpow(tot, P - 2);
        for (int i = 0; i < tot; ++i) {
            a[i] = a[i] * tmp % P;
        }
    }
}
int n,m,k;
int a[N];
int C(int a,int b) {
    if(a < 1 || b > a) return  0;
    return fac[a] * inv[b]%P *inv[a-b]%P;
}
vector<int> f(int l,int r) {
    if(l == r) {
        vector<int> te(a[l] + 1);
        for(int i = 1; i <= a[l]; ++i) {
            te[i] = C(a[l],i);
        }
        return te;
    }
    int mid = (l + r) >> 1;
    auto a = f(l,mid),b = f(mid + 1,r);
    bit = 0;
    int n = a.size();
    int m = b.size();
    while((1 << bit) < n + m + 1) bit++;
    tot = 1 << bit;
    for(int i = 0; i < tot; ++i) {
        rev[i] = (rev[i >> 1]  >> 1) | ((i & 1) << (bit - 1));
    }
    a.resize(tot);
    b.resize(tot);
    ntt(a,1);
    ntt(b,1);
    for(int i = 0; i < tot ; ++i) {
        a[i] = a[i] * b[i] % P;
    }   
    ntt(a,-1);
    a.resize(n + m - 1);
    return a;
}
void solve() {
    cin>>n>>m>>k;
    int mx = 0;
    for(int i = 1; i <= m; ++i) {
        cin>>a[i];
        mx = max(mx,a[i]);        
    }
    init(mx);
    auto ans = f(1,m);
    cout<<ans[k]%P;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while(T -- ) {
        solve();
    }
}