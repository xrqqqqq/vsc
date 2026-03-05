
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int b[N];
int c[N];
int n, m, k;
void solve() {
    cin>>n>>k;
    string s, t;
    cin>>s>>t;
    vector<int> v(n);
    if(s[0] != t[0]) {
        cout<<-1<<"\n";
        return ;
    }
    int mx = n;
    vector<int> cnt[30];
    for(int i = 0; i < s.size(); ++i) {
        cnt[s[i] - 'a'].push_back(i);
    }
    int tem = 0;
    for(int i = n - 1; i >= 1; --i) {
        int now = t[i] - 'a';
        while(cnt[now].size()&&cnt[now].back() >= mx) cnt[now].pop_back();
        if(cnt[now].size() == 0) {
            cout<<-1<<"\n";
            return ;
        }
        auto p = upper_bound(cnt[now].begin(),cnt[now].end(),i);
        if(p == cnt[now].begin()) {
            cout<<-1<<"\n";
            return ;
        }
        --p;
        int tt = *p;
        v[tt] = max(v[tt],i - tt);
        tem = max(v[tt],tem);
        mx = tt + 1;
    }
    if(k < tem) {
        cout<<-1<<"\n";
        return ;
    }
    cout<<tem<<"\n";
    while(tem--) {
        string ss = s;
        for(int i = n - 1; i >= 1; --i) {
            if(v[i-1]) {
                ss[i] = s[i-1];
            }
        } 
        cout<<ss<<"\n";
        s = ss;
        for(int i = n-2; i >= 0; --i) {
            if(v[i]) {
                v[i] --;
                if(v[i] == 0) continue;
                swap(v[i],v[i+1]);
            }
        }
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