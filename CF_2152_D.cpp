#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin>>n>>m;
    vector<int> ne(n+1);
    vector<int> sum(n+1);
    for(int  i = 1; i <= n; ++i) {
        cin>>a[i];
        int t = log2(a[i]);
        if((1<<t) == a[i]) {
            sum[i] = t;
        }
        else if((1<<t) == a[i] - 1) {
            sum[i] = t;
            ne[i] = 1;
        }
        else {
            sum[i] = t + 1;
        }
        sum[i] += sum[i-1];
        ne[i] += ne[i-1];
    }
    while(m--) {
        int l,r;
        cin>>l>>r;
        cout<<sum[r] - sum[l-1] + (ne[r] - ne[l-1])/2<<"\n";
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