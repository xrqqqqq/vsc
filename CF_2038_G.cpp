#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int a[N];
vector<int> ne[N];
int si;
int ask(string p) {
    cout<<"1 "<<p<<endl;
    int x;
    cin>>x;
    return x;
}
void pt(int x) {
    cout<<0<<" "<<1<<" "<<x<<endl;
    int t;
    cin>>t;
    return ;
}
void solve() {
    cin>>n;
    int t1 = ask("11");
    int t2 = ask("00");
    n -= (t1 + t2);
    if(n % 2 == 0) {
        int res = ask("10");
        if(res == n / 2) {
            pt(1);
        }
        else {
            pt(0);
        }
    }   
    else {
        int res = ask("1");
        res -= t1;
        if(res > n / 2) {
            pt(1);
        }
        else {
            pt(0);
        }
    }
}
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}