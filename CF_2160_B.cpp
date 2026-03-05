#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int b[N];
void solve() {
    cin>>n;
    for(int i = 1; i <= n ; ++i) {
        cin>>b[i];
    }
    int c = 1;
    for(int i = 1; i <= n; ++i) {
        if(i == 1) cout<<1<<" ",a[i] = 1;
        else {
            int t = b[i] - b[i-1];
            t--;
            if(i - t - 1 <= 0) {
                a[i] = ++c;
                cout<<a[i]<<" ";
            }
            else {
                a[i] = a[i - t - 1];
                cout<<a[i]<<" ";
            }
        }
    }
    cout<<"\n";
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