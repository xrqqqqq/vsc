#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
array<int,2> a[N];
int ask(char c,int x) {
    cout<<"? "<<c<<" "<<x <<endl;
    int res;
    cin>>res;
    return res; 
}
void solve() {
    cin>>n;
    int mxy = -1e18,mxx = -1e18;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i][0]>>a[i][1];
        int x = a[i][0];
        int y = a[i][1];
        mxx = max(mxx,x+y);
        mxy = max(mxy,x-y);
    }
    ask('R',1e9);
    ask('R',1e9);
    ask('U',1e9);
    int ans = ask('U',1e9);
    int x1 = ans + mxx - 4e9;
    ask('D',1e9);
    ask('D',1e9);
    ask('D',1e9);
    ans = ask('D',1e9);
    int y1 = ans + mxy - 4e9;
    int xx = (x1 + y1)/2;
    int yy = xx - y1;
    cout<<"! "<<xx<<" "<<yy<<endl;
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