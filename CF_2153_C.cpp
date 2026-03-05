#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    map<int,int> cnt;
    int ans = 0;
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin>>x;
        cnt[x]++; 
    }
    int su = 0;
    for(auto [x,y] : cnt) {
        if(y >= 2) {
            su+=(y/2);
            ans += x*(y/2)*2;
        }
        cnt[x] %= 2;
    }
    if(ans == 0) {
        cout<<0<<"\n";
        return ;
    }
    vector<int> te;
    te.push_back(0);
    for(auto [x,y] : cnt) {
        if(y) {
            te.push_back(x);
        }
    }
    sort(te.begin(),te.end());
    int mx = te[te.size()-1];
    int res = 0;
    if(su >= 2) res = ans;
    for(int i = 0; i < te.size(); ++i) {
        int t = te[i] + ans;
        auto p = lower_bound(te.begin(),te.end(),t);
        if(p != te.begin()) {
            p--;
            int tt = *p;
            if(tt > te[i]&& tt < t) {
                res = max(res ,  t + tt);
            }
        } 
    }
    cout<<res<<"\n";
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