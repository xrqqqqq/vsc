#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string t = "nanjing";
void solve() {
    cin>>n>>m;
    m = min(m,n);
    string s;
    cin>>s;
    vector<int> sum(n + m + 1);
    string p = s.substr(0,m);
    s += p;
    s = " " + s;
    int ans = 0;
    for(int i = 1; i <= n + m; ++i) {
        bool v = 1;
        if(i + 6 <= n + m) {
            for(int j = 0; j < 7; ++j) {
                if(s[i + j] != t[j]) v = 0;
            }
        }
        if(v) sum[i] = 1;
        sum[i] += sum[i-1];
        if(i - 6 >= 1&&i - n >= 0)
        ans = max(sum[i-6] - sum[i-n],ans);
    }
    cout<<ans<<"\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin>>T;
    while(T--) {
        solve();
    }
}