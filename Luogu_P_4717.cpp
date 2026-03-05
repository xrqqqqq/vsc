#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1 << 19;
const ll P = 998244353;

// 快速幂求逆元
ll pow_mod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

// 2的逆元，用于XOR变换
const ll inv2 = pow_mod(2, P - 2);

template <class T>
void and_fwt(T f[], int ldn, int is = 1) {
    int n = 1 << ldn;
    for (int ldm = 1; ldm <= ldn; ++ldm) {
        int m = 1 << ldm, mh = m >> 1;
        for (int r = 0; r < n; r += m) {
            for (int j = 0; j < mh; ++j) {
                int t1 = r + j, t2 = r + j + mh;
                T u = f[t1], v = f[t2];
                if (is == 1) {
                    f[t1] = (u + v) % P;
                    f[t2] = v;
                } else {
                    f[t1] = (u - v + P) % P;
                    f[t2] = v;
                }
            }
        }
    }
}

template <class T>
void or_fwt(T f[], int ldn, int is = 1) {
    int n = 1 << ldn;
    for (int ldm = 1; ldm <= ldn; ++ldm) {
        int m = 1 << ldm, mh = m >> 1;
        for (int r = 0; r < n; r += m) {
            for (int j = 0; j < mh; ++j) {
                int t1 = r + j, t2 = r + j + mh;
                T u = f[t1], v = f[t2];
                if (is == 1) {
                    f[t1] = u;
                    f[t2] = (v + u) % P;
                } else {
                    f[t1] = u;
                    f[t2] = (v - u + P) % P;
                }
            }
        }
    }
}

template <class T>
void xor_fwt(T f[], int ldn, int is = 1) {
    int n = 1 << ldn;
    for (int ldm = 1; ldm <= ldn; ++ldm) {
        int m = 1 << ldm, mh = m >> 1;
        for (int r = 0; r < n; r += m) {
            for (int j = 0; j < mh; ++j) {
                int t1 = r + j, t2 = r + j + mh;
                T u = f[t1], v = f[t2];
                if (is == 1) {
                    f[t1] = (u + v) % P;
                    f[t2] = (u - v + P) % P;
                } else {
                    f[t1] = (u + v) * inv2 % P;
                    f[t2] = (u - v + P) * inv2 % P;
                }
            }
        }
    }
}

template <class T>
void andf(T f[], T g[], int n) {
    int ldn = __lg(n);
    and_fwt(f, ldn);
    and_fwt(g, ldn);
    for (int i = 0; i < n; ++i) f[i] = f[i] * g[i] % P;
    and_fwt(f, ldn, -1);
}

template <class T>
void orf(T f[], T g[], int n) {
    int ldn = __lg(n);
    or_fwt(f, ldn);
    or_fwt(g, ldn);
    for (int i = 0; i < n; ++i) f[i] = f[i] * g[i] % P;
    or_fwt(f, ldn, -1);
}

template <class T>
void xorf(T f[], T g[], int n) {
    int ldn = __lg(n);
    xor_fwt(f, ldn);
    xor_fwt(g, ldn);
    for (int i = 0; i < n; ++i) f[i] = f[i] * g[i] % P;
    xor_fwt(f, ldn, -1);
}

ll a[MAXN], b[MAXN];
ll aa[MAXN], bb[MAXN];

int main() {
    int n;
    cin >> n;
    int size = 1 << n;  // 实际数组大小应为2的n次方

    // 读取2^n个元素
    for (int i = 0; i < size; ++i) cin >> a[i];
    for (int i = 0; i < size; ++i) cin >> b[i];

    // 进行三种卷积运算
    for (int i = 0; i < 3; ++i) {
        // 每次操作前复制原始数组
        copy(a, a + size, aa);
        copy(b, b + size, bb);

        if (i == 0) {
            orf(aa, bb, size);
        } else if (i == 1) {
            andf(aa, bb, size);
        } else {
            xorf(aa, bb, size);
        }

        // 输出结果
        for (int j = 0; j < size; ++j) {
            cout << aa[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}