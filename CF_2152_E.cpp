#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 10;
int n, m, k;
int a[N];
vector<int> ask(vector<int> p) {
    cout << "? " << p.size();
    for (auto i : p) {
        cout << " " << i;
    }
    cout << endl;
    int x;
    cin >> x;
    vector<int> res;
    for (int i = 1; i <= x; ++i) {
        int t;
        cin >> t;
        res.push_back(t);
    }
    return res;
}
void re(vector<int> p) {
    cout<<"!";
    for(int i = 0; i < n + 1; ++i) {
        cout<<" "<<p[i];
    }
    cout<<endl;
}
void solve() {
    cin >> n;
    int len = n*n + 1;
    for(int i = 1; i <= len ; ++i ) a[i] = 0;
    for(int i = n; i >= 1; --i) {
        vector<int> tem;
        for(int j = 1; j <= len; ++j) if(a[j] == 0) tem.push_back(j);
        auto p = ask(tem);
        if(p.size() >= n + 1) {
            re(p);
            return ;
        }
        for(auto j : p) {
            a[j] = i;
        }
    }
    vector<int> te;
    int now = 0;
    for(int i = len; i >= 1; --i) {
        if(now == n + 1) break;
        if(a[i] == now) {
            te.push_back(i);
            now++;
        }
    }
    reverse(te.begin(),te.end());
    re(te);
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