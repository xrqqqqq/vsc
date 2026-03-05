#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
map<string, int> ha = {{"Ocelot", 1}, {"Serval", 2}, {"Lynx", 3}};
int n, m, k;
int a[N];
void solve() {
    cin>>n;
    string s;
    cin>>s;
    vector<int> sum(n+1);
    int su = 0;
    int last = 0;
    int ans = 1e18;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '0') {
            last += 2;
        }
        else {
            last++;
            sum[i] = last;
            last = 0;
        }
        if(i)
        sum[i] += sum[i-1];
    }
    last = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        if(s[i] == '0') {
            last += 2;
        }
        else {
            last++;
            su += last;
            last = 0;
        }
        int t = 0;
        if(i - 1 >= 0) {
            t = sum[i-1];
        }
        ans = min(ans,t + su);
    }
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }
    sum.assign(n+1,0);
    su = 0;
    last = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            last += 2;
        } else {
            last++;
            sum[i] = last;
            last = 0;
        }
        if (i) sum[i] += sum[i - 1];
    }
    last = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            last += 2;
        } else {
            last++;
            su += last;
            last = 0;
        }
        int t = 0;
        if (i - 1 >= 0) {
            t = sum[i - 1];
        }
        ans = min(ans, t + su);
    }
    cout<<ans<<"\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin>>T;
    while (T--) {
        solve();
    }
}