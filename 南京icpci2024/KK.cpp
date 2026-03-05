#include<bits/stdc++.h>
using namespace std;
#define int long long
void test(){
    int n,m,k,w;cin>>n>>m>>k>>w;
    vector<int>a(n+1),b(m+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    b.push_back(w + 1);
    vector<array<int,2>>v;
    for(int i=1;i<=n;i++)v.push_back({a[i],0});
    for(int i=1;i<=m+1;i++)v.push_back({b[i],1});   
    sort(v.begin(),v.end());
    sort(b.begin(),b.end());
    vector<int>ans;
    int tem=0;
    for(auto [u,col]:v){
        if(col==0){
            if(tem==0||u-tem>=k){
                ans.push_back(u);
                tem=u;
            }
        }else{
            if(u-tem<k&&tem!=0){
                int res=u;
                for(int i=ans.size()-1;i>=0;i--){
                    if(res-ans[i]>=k)break;
                    int t1=lower_bound(b.begin(),b.end(),ans[i])-b.begin();
                    int t2 =lower_bound(b.begin(), b.end(), res-k)-b.begin();
                    if(t1!=t2){
                        cout<<-1<<'\n';
                        return;
                    } 
                    ans[i]=res-k;
                    res=ans[i];
                }
            }
            tem=0;
        }
    }
    if(ans[0]<=0){
        cout<<-1<<'\n';
        return;
    }
    cout<<ans.size()<<'\n';
    for(int i:ans)cout<<i<<' ';
    cout<<'\n';

}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        test();
    }
    return 0;
}