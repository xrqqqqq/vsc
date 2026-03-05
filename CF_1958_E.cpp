#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
void solve() {
    cin >> n >> k;
    vector<int> a(n+1);
    int ed = 0;
    int len = n;
    vector<int> tem;
    for(int i = 1; i <= n; ++i) tem.push_back(i);
    while(k) {
        if(k == 1) {
            for(auto i : tem) {
                a[i] = ++ed;
            }
            break;
        }
        vector<int> p;
        for(int i = 0; i < tem.size(); ++i) {
            if(i&1) {
                a[tem[i]] = ++ ed;
            }
            else {
                p.push_back(tem[i]);
            }
        }
        tem = p;
        k--;
        if(tem.size() == 1&&k) {
            cout<<-1<<"\n";
            return ;
        }
    }
    for(int i = 1;i  <= n; ++i) cout<<a[i]<<" ";
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