#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    int x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    int t = abs(x1 - x2) + abs(y1-y2);
    if(t == 0) {
        cout<<1<<"\n";
        return ;
    }
    else if(t == 1) {
        if(y1 == y2) {
            int ans = 0;
            if (x2 >= x1)
                ans = max(ans, x2);
            else
                ans = max(ans, n - x2);
            cout<<max(1ll,ans)<<"\n";
        }
        else {
            int ans = 0;
            if (y2 >= y1)
                ans = max(ans, y2);
            else
                ans = max(ans, n - y2);
            cout<<max(1ll,ans)<<"\n";
        }
        return ;
    }
    if (y1 == y2) {
        int ans = 0;
        if (x2 >= x1)
            ans = max(ans, x2);
        else
            ans = max(ans, n - x2);
        cout << max(1ll, ans) << "\n";
        return ;
    } else if(x1 == x2){
        int ans = 0;
        if (y2 >= y1)
            ans = max(ans, y2);
        else
            ans = max(ans, n - y2);
        cout << max(1ll, ans) << "\n";
        return ;
    }
  
    int ans = 0;
    if(x2>=x1) ans = max(ans,x2);
    else ans = max(ans,n-x2);
    if(y2 >= y1) ans = max(ans,y2);
    else ans = max(ans,n-y2);
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