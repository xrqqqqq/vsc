#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 10;
int n, m, k;
int a[N];
int b[N];
int p[N];
int cn = 0;
int cp = 0;
int t[N];
int sum;
int ask(int *a, int n) {
    cout << "? " << n;
    for (int i = 1; i <= n; ++i) {
        cout << " " << a[i];
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}
int ans[N];
int c[N];
void solve() {
    cn = 0;
    cp = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ans[i] = 0;
    }
    int len = 12;
    for (int i = 1; i <= len; ++i) {
        int ii = i-1;
        int le = (1 << (ii / 2)) - 1;
        for (int j = 1; j <= le; ++j) {
            b[++cn] = 1;
            b[++cn] = -1;
        }
        p[++cp] = ++cn;
        b[++cn] = -1;
        le = (1 << ((ii + 1) / 2)) - 1;
        for (int j = 1; j <= le; ++j) {
            b[++cn] = 1;
            b[++cn] = -1;
        }
        b[++cn] = -1;
    }
    // for(int i = 1;i <= cn; ++i) {
    //     cout<<b[i]<<" ";
    // }
    // cout<<"\n";
    for (int i = 1; i <= n; ++i) a[i] = i;
    int l = 1, r = n;
    bool v = 0;
    while (l < r) {
        int mid = l + r >> 1;
        int t = ask(a, mid);
        if (t >= 1)
            r = mid;
        else
            l = mid + 1;
    }
    if (ask(a, l) >= 1) v = 1;
    int x = 1, y = -1;
    if (v == 0) {
        ans[1] = -1;
        ans[n] = 1;
        x = n;
        y = 1;
    } else {
        ans[l - 1] = 1;
        ans[l] = -1;
        x = l - 1;
        y = l;
    }
    // cout<<x<<" "<<y<<endl;
    int ned = n - 2;
    for (int i = 1; i <= cn; ++i) {
        if (b[i] == 1)
            b[i] = x;
        else if (b[i] == -1)
            b[i] = y;
    }
    for (int i = 1; i <= cp; ++i) {
        b[p[i]] = x;
    }
    if (ned) sum = ask(b, cn);
    while (ned) {
        for (int i = 1; i <= cp; ++i) {
            b[p[i]] = x;
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (ans[i] == 0) {
                c[++cnt] = i;
            }
            if (cnt == 12) break;
        }
        for (int i = 1; i <= cp && i <= cnt; ++i) {
            b[p[i]] = c[i];
        }
        int res = ask(b, cn);
        int tem = sum - res;
        for (int i = 1; i <= cp && i <= cnt; ++i) {
            int t = (tem >> (i-1)) & 1ll;
            if (t) {
                ans[c[i]] = -1;
            } else {
                ans[c[i]] = 1;
            }
        }
        if (ned >= 12) {
            ned -= 12;
        } else {
            ned = 0;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == 1) {
            cout << "(";
        } else {
            cout << ")";
        }
    }
    cout << endl;
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