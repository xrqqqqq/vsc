#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, k;
int a[N];
int tt = -1;
int b[N];
int te[N];
bool check(int x) {
    int kk = 0;
    for(int i = 1; i <= n; ++i) {
        if(2*a[i] < x) {
            b[i] = 1e9;
            kk++;
        }
        else {
            b[i] = a[i];
        }
    }
    if(k < kk) return 0;
    kk = k - kk;
    int ned = 2;
    for(int i = 1; i < n; ++i) {
        int cnt = 2;
        if(b[i] >= x) cnt--;
        if(b[i+1] >= x) cnt--;
        ned = min(ned,cnt);
    }
    return ned <= kk;
}
void solve() {
    cin >> n >> k;
    int ans = 0;
    for(int i  = 1; i <= n; ++i) {
        cin>>a[i];
    }
    if(k >= n) {
        cout<<(int)1e9<<"\n";
    }
    else {
        int l = 1,r = 1e9;
        while(l < r) {
            int m = l + r + 1>> 1;
            if(check(m)) l = m;
            else r = m - 1;
        }
        cout<<l<<"\n";
    }
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