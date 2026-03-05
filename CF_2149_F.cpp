#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int h,d;
bool check(int x) {
    int t = x - d;
    if(t == 0) {
        if(h > d*(d+1)/2) {
            return 1;
        }
        return 0;
    }
    else {
        int le1 = d/ (t + 1);
        int t2 = d - le1*(t+1);
        int t1 = t + 1 - t2;
        int le2 = le1 + 1;
        int hh = h;
        if(hh - (t2)*(le2*(le2 + 1)/2 - 1) < 2) return 0;
        hh -= (t2)*(le2 *(le2 + 1)/2 - 1);
        if(hh - (t1-1)*(le1*(le1+1)/2 - 1) < 2) return 0;
        hh -= (t1-1)*(le1 *(le1 + 1)/2 - 1);
        return hh > (le1*(le1 + 1)/2);
    }
}
void solve() {
    cin>>h>>d;
    int l = d,r = 2*d;
    while(l < r) {
        int m = l + r >> 1;
        if(check(m)) {
            r = m;
        }
        else l = m + 1;
    }
    // cout<<check(l)<<"\n";
    cout<<l<<"\n";
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