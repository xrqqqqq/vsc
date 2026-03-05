#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;

int a[] = {0,1,2,2,3,3,4};
void solve() {
    cin >> n;
    if(n <= 6) {
        cout<<a[n]<<"\n";
        for(int i = 1; i <= n; ++i) {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    else {
        cout<<4<<"\n";
        for(int i = 1; i <= n; ++i) {
            int t = i % 4;
            if(t == 0) t = 4;
            cout<<t<<"\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    // init(1e5);
    while (T--) {
        solve();
    }
}