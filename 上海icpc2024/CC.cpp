#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int l,r;
    cin>>l>>r;
    int res=r-l+1;
    if(l&1){
        if(2*l<=r){
            cout<<"Alice"<<'\n';
            return;
        }
        if(res%2){
            cout<<"Alice"<<'\n';
            return;
        }else{
            cout<<"Bob"<<'\n';
            return;
        }
    }else{
        if((l+1)*2<=r){
            cout<<"Bob"<<'\n';
            return;
        }
        if(res%2){
            cout<<"Alice"<<'\n';
            return;
        }else{
            cout<<"Bob"<<'\n';
            return;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin>>T;
    while (T--) {
        solve();
    }
}