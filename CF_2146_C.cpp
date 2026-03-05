#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin>>n;
    string s;
    cin>>s;
    int len = 0;
    int last = -1;
    s = " " + s;
    vector<int> v(n+10);
    for(int i = 1; i <= n; ++i) v[i] = i;
    for(int i = 1; i <= n; ++i) {
        if(s[i] -'0' != last) {
            if(len == 1&&last == 0) {
                cout<<"NO\n";
                return ;
            }
            if(last == 0) {
                int tem = v[i-1];
                for(int j = i - 1; j > i - len; --j) {
                    v[j] = v[j-1];
                }
                v[i-len] = tem;
            }
            last = s[i] - '0';
            len = 1;
        }
        else {
            len++;
        }
    }
    if (len == 1 && last == 0) {
        cout << "NO\n";
        return;
    }
    if (last == 0) {
        int i = n + 1;
        int tem = v[i - 1];
        for (int j = i - 1; j > i - len; --j) {
            v[j] = v[j - 1];
        }
        v[i - len] = tem;
    }
    cout<<"YES\n";
    for(int i = 1; i <= n; ++i) {
        cout<<v[i]<<" ";
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