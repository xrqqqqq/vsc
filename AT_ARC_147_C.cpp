#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n,m,k;
array<int,2> to[N];
int f(int x) {
    vector<int> ans;
    for(int i = 1; i <= n; ++i) {
        auto [l,r] = to[i];
        if(to[i][0] <= x) {
            ans.push_back(min(x,r));
        }
        else {
            ans.push_back(l);
        }
    }
    int res = 0;
    sort(ans.begin(),ans.end());
    int len = n;
    for(auto i : ans) {
        res -= len*i;
        res += i*(n-len+1);
        len--;
    }
    return res;
}
void solve() {
    cin>>n;
    int mi = 1e18;
    int mx = -1e18;
    for(int i = 1; i <= n; ++i) {
        int l,r;
        cin>>l>>r;
        mi = min(l,mi);
        mx = max(r,mx);
        to[i] = {l,r};
    }
    int l = mi,r = mx;
    while(l < r) {
        int lmid = l + (r -l)/3;
        int rmid = r - (r - l)/3;
        if(f(rmid) >= f(lmid)) {
            r = rmid - 1;
        }
        else {
            l = lmid + 1;
        }
    }
    cout<<min(f(l),f(r))<<"\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}