
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int f[N][50][2];
int n;
int m;
int a[N];
int b[N];
int aa[N];
int bb[N];
int ff[N][50][2];
void init(int a[], int n, int c) {
    for (int j = 0; j <= (int)log2(n); j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            if (!j)
                f[i][j][c] = a[i];
            else
                f[i][j][c] =
                    __gcd(f[i][j - 1][c], f[i + (1 << (j - 1))][j - 1][c]);
}
int ask(int l, int r, int c) {
    if (l == r) {
        return 0;
    }
    r--;
    int len = (int)log2(r - l + 1);
    return __gcd(f[l][len][c], f[r - (1 << len) + 1][len][c]);
}
void init1(int a[], int n, int c) {
    for (int j = 0; j <= (int)log2(n); j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            if (!j)
                ff[i][j][c] = a[i];
            else
                ff[i][j][c] =
                    min(ff[i][j - 1][c], ff[i + (1 << (j - 1))][j - 1][c]);
}
int ask1(int l, int r, int c) {
    int len = (int)log2(r - l + 1);
    return min(ff[l][len][c], ff[r - (1 << len) + 1][len][c]);
}
void test() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for(int i = 1; i <= n - 1; ++i) {
        aa[i] = abs(a[i] - a[i+1]);
        bb[i] = abs(b[i] - b[i+1]);
        // cout<<aa[i]<<"\m";
    }
    init(aa,n-1,0);
    init(bb,n-1,1);
    init1(a,n,0);
    init1(b,n,1);
    // cout<<ask(1,2,0)<<"\n";
    while (m--) {
        int h1,w1,h2,w2;
        cin>>h1>>h2>>w1>>w2;
        int t1 = ask(h1,h2,0);
        int t2 = ask(w1,w2,1);
        int su = ask1(h1,h2,0) + ask1(w1,w2,1);
        // cout<<su<<"\n";
        // cout<<t1<<" "<<t2<<"\n";
        cout<<__gcd(su,__gcd(t1,t2))<<"\n";
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        test();
    }
    return 0;
}