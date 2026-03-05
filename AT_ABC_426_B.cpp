#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
map<string, int> ha = {{"Ocelot", 1}, {"Serval", 2}, {"Lynx", 3}};
int n, m, k;
int a[N];
void solve() {
    map<char,int> ha;
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); ++i) ha[s[i]]++;
    for(auto [x,y] : ha) {
        if(y == 1) {
            cout<<x<<"\n";
            return ;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}