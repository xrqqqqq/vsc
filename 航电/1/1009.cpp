#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;

void solve() {
    int n;cin>>n;
    vector<int>x(n+1),y(n+1);
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    map<array<int,2>,int>mp;
    queue<array<int,2>>q;
    for(int i=1;i<=n;i++){
        mp[{x[i],y[i]}]=1;
        q.push({x[i],y[i]});
    }
    while(q.size()){
        auto [xx,yy]=q.front();
        q.pop();
        int tmp=mp[{xx,yy}];
        for(int i=1;i<=n;i++){
            int x0=xx+x[i];
            int y0=yy+y[i];
            if(x0<-100||x0>100||y0<-100||y0>100)continue;
            // if(mp[x0][y0]==0)mp[x0][y0]=1e9;
            if(mp[{x0,y0}])continue;
            mp[{x0,y0}]=tmp+1;
            q.push({x0,y0});
        }
    }
    int ans=mp[{0,0}];
    if(ans)cout<<ans<<'\n';
    else cout<<-1<<'\n';
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