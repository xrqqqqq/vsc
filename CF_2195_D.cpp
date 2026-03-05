#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N = 1e6 + 10;
int a[N];int b[N];
int c[N];
void solve() {
    cin>>n;
    int P = 0;
    for(int i = 1; i <= n; ++i) cin>>b[i];
    for(int i = 1; i <= n; ++i) c[i] = b[i];
    for(int i = 1;i <= n-1; ++i) {
        c[i] = c[i+1] - c[i];
        if(i == 1) P = c[1];
    }
    for(int i = 1; i <= n - 2; ++i) c[i] = c[i+1] - c[i],a[i+1] = c[i]/(2);
    int G = 0;
    for(int i = 1; i <= n - 2; ++i) G += i*(a[i+1]);
    a[n] = (b[1] - G)/(n-1);
    G = 0;
    for(int i = 2; i <= n; ++i) G += a[i];
    a[1] = P + G;
    for(int i = 1; i <= n; ++i) cout<<a[i]<<" ";
    cout<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin>>T;
    while(T--) {
        solve();
    }
}