#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n,m,k;
int a[N];
vector<array<int,2>> ne;
int L[N],R[N];
int count(int x,int l,int r) {
    auto ll = lower_bound(ne.begin(),ne.end(),array<int,2>{x,l});
    if(ll == ne.end() || (*ll)[0] != x) return 0;
    auto rr = lower_bound(ne.begin(),ne.end(),array<int,2>{x,r+1});
    return (rr - ll);
}
void solve() {
    cin>>n;
    ne.clear();
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        ne.push_back({a[i],i});
        L[i] = R[i] = 0;
    }    
    stack<int> sta;
    for(int i = 1; i <= n; ++i) {
        while(sta.size() && a[sta.top()] < a[i]) sta.pop();
        if(sta.size() == 0) L[i] = 0;
        else L[i] = sta.top();
        sta.push(i);
    }
    while(sta.size()) sta.pop();
    for(int i = n; i >= 1; --i) {
        while (sta.size() && a[sta.top()] <= a[i]) sta.pop();
        if (sta.size() == 0)
            R[i] = n+1;
        else
            R[i] = sta.top();
        sta.push(i);
    }
    sort(ne.begin(),ne.end());
    int ans = n*n;
    for(int i = 1; i <= n; ++i) {
        if(a[i] % 2 == 0) continue;
        // cout<<L[i] <<" "<<i<<" "<<R[i]<<"\n";
        if(i - L[i] < R[i] - i) {
            for(int j = L[i] + 1;j <= i; ++j) {
                int need = a[i] + 1 - a[j];
                ans -= 2*count(need,i,R[i] - 1);
            }
            if(2*a[i] == a[i] + 1) ans++;
        }
        else {
            for(int j = R[i] - 1; j >= i; --j) {
                int need = a[i] + 1 - a[j];
                ans -= 2*count(need,L[i]+1,i);
            }
            if (2 * a[i] == a[i] + 1) ans++;
        }
        // cout<<ans<<"\n";
    }
    cout<<ans<<"\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}