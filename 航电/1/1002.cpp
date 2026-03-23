#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;

void solve() {
    int n,k;cin>>n>>k;
    if(n>=k){
        cout<<-1<<'\n';
        return;
    }
    set<int>s;
    for(int i=1;i<=k-1;i++){
        s.insert(i);
    }
    int ss=0;
    int now=0;
    for(int i=1;i<=n;i++){
        int res=ss+now+1;
        res%=k;
        if(res==0)res++;
        auto it=s.lower_bound(res);
        if(it==s.end())it=s.begin();
        int tt=*it;
        s.erase(it);
        int tmp=(now+1)/k*k;
        tmp+=tt-ss%k;
        if(tmp<=now)tmp+=k;
        cout<<tmp<<' ';
        now=tmp;
        ss+=tmp;
    }
    cout<<'\n';
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