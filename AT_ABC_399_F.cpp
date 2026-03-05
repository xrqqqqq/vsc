
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int mod = 998244353;
int n,m,k;
int sum[N];
int f(const int x) {
    return (x % mod + mod) % mod;
}
int a[N];
int ksm(int a,int b) {
    int res = 1;
    while(b) {
        if(b & 1)res = (res * a)%mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void test() {
    cin>>n>>k;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
        sum[i]%=mod;
    }
    for(int j = 0; j <= k; ++j) {
        int qu = 1;
        int p = k - j;
        for(int i = k,ii = 1; ii <= j; ++ii,--i) {
            qu *= i;
            qu /= ii;
        }
        int rr = 0;
        int tem = 0;
        qu %= mod;
        for(int l = n; l >= 1; --l) {
            rr = f(rr + ksm(sum[l],j));
            tem += f(ksm(sum[l-1],k-j)*rr);
            tem %= mod;
        }
        tem = f(tem*qu);
        if(p % 2 == 1) {
            ans = f(-tem + ans);
        }
        else {
            ans = f(tem + ans);
        }
    }
    cout<<ans<<"\n";
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