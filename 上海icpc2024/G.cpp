#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
auto& operator>>(istream& it, __int128_t& j) {
    string val;
    if (!(it >> val)) return it;  // 输入失败
    bool neg = false;
    int pos = 0;
    if (val[0] == '-') {
        neg = true;
        pos = 1;
    }
    __int128 ans = 0;
    for (; pos < (int)val.size(); pos++) {
        char c = val[pos];
        if (c < '0' || c > '9') break;
        ans = ans * 10 + (c - '0');
    }
    j = neg ? -ans : ans;
    return it;
}

auto& operator<<(ostream& os, const __int128_t& j) {
    string ans;
    function<void(__int128_t)> write = [&](__int128_t x) {
        if (x < 0) ans += '-', x = -x;
        if (x > 9) write(x / 10);
        ans += x % 10 + '0';
    };
    write(j);
    return os << ans;
}
#define int i128
const int N = 2e5 + 10;
int n, m, k;
int a[N];
int b[N];
int c[N];
int v[N];
int vv[N];
// int cmp1(int a,int b) {
//     if()
// }
int find_r(array<int,2> g[], int nn) {
    int l = 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (vv[i] == 0) {
            while (l <= nn && (g[l][0] < c[i]*g[l][1])) {
                l++;
            }
            if (l <= nn) {
                cnt++;
                vv[i] = 1;
                l++;
            }
        }
    }
    return cnt;
}
int find_l(array<int,2> g[], int nn) {
    int r = nn;
    int cnt = 0;
    for (int i = n; i >= 1; --i) {
        if (vv[i] == 0) {
            while (r >= 1 && (g[r][0] > c[i]*g[r][1])) {
                r--;
            }
            if (r >= 1) {
                cnt++;
                vv[i] = 1;
                r--;
            }
        }
    }
    return cnt;
}
array<int,2> ll[N];
array<int,2> rr[N];
bool check(int x) {
    int ned = 0;
    if(n % 2 == 0) ned = n / 2;
    else ned = n/2 + 1;
    int tem = 0;
    int ln = 0, rn = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            if (b[i] >= x) tem++;
        } else if (a[i] > 0) {

            rr[++rn] = {x - b[i],a[i]};
            // rr[++rn] = (x - b[i] + 0.0) / a[i];
        } else {
            ll[++ln] = {-x+b[i],-a[i]};
            // ll[++ln] = (x - b[i] + 0.0) / a[i];
        }
    }
    auto cmp = [&](array<int,2> a,array<int,2> b) {
        // if(a[1] < 0&&b[1] < 0) {
        //     return (a[0]) * -b[1] < (b[0]) * -a[1];
        // }
        return (a[0])*b[1] < (b[0])*a[1];
    };
    sort(rr+1,rr+1+rn,cmp);
    sort(ll+1,ll+1+ln,cmp);
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        vv[i] = 0;
    }
    mx = max(find_l(rr, rn) + find_r(ll, ln), mx);
    for (int i = 1; i <= n; ++i) {
        vv[i] = 0;
    }
    mx = max(find_r(ll, ln) + find_l(rr, rn), mx);
    return mx + tem >= ned;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    sort(c+1,c+1+n);
    int l = -2e18,r = 2e18;
    while(l < r) {
        int m = l + r + 1>> 1;
        if(check(m)) l = m;
        else r = m - 1;
    }
    cout<<l<<"\n";
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