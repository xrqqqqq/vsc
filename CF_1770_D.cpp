
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int mod = 998244353;
int ksm(int a,int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a)%mod;
        b>>=1;
        a = (a * a) % mod;
    }
    return res;
}
int n;
int p[N];
int si[N];
int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]); 
    return x;
}
int a[N];
int b[N];
int cnt[N];
void solve() {
    cin>>n;
    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        p[i] = i;
        si[i] = 1;
        cin>>a[i];
        cnt[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        cin>>b[i];
    }
    for(int i = 1; i <= n; ++i) {
        int aa = find(a[i]),bb = find(b[i]);
        if(aa > bb) swap(aa,bb); 
        if(aa != bb) {
            si[aa] += si[bb];
            p[bb] = aa;
        }
    }
    vector<int> cntv(n+1);
    for(int i = 1; i <= n; ++i) {
        int t = find(a[i]);
        cnt[t]++;
        if(a[i] == b[i]) cntv[t] = 1;
    }
    set<int> s;
    for(int i = 1; i <= n; ++i) {
        int ii = find(i);
        if(s.count(ii) == 0) {
            s.insert(ii);
            if(si[ii] != cnt[ii]) {
                ans = 0;
            }
            else {
                if(cntv[ii]) ans=ans*n%mod;
                else ans = ans * 2%mod;
            }
        }
    }
    cout<<ans<<"\n";
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