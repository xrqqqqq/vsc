#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin>>n>>k;
    string s;
    cin>>s;
    int last = -1;
    int len = 0;
    for(int i = 0; i < n; ++i) {
        int t = s[i] - '0';
        if(t != last) {
            last = t;
            len = 1;
        }
        else len++;
        if(len >= k && last == 1) {
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
    vector<int> ans(n+1);
    int cnt = 1;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1') {
            ans[i] = cnt;
            cnt++;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            ans[i] = cnt;
            cnt++;
        }
    }
    for(int i = 0; i < n; ++i) {
        cout<<ans[i] <<" ";
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