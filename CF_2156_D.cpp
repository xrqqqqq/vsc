#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
int ask(int id,int x) {
    cout<<"? "<<id<<" "<<x<<endl;
    int res;
    cin>>res;
    return res;
}
void solve() {
    cin>>n;
    set<int> s;
    vector<int> now;
    for(int i = 1; i <= n; ++i) {
        s.insert(i);
        if(i <= n - 1)
        now.push_back(i);
    }
    int ad = 1;
    while(s.size() > 1) {
        int t0 = 0,t1 = 0;
        vector<int> temp;
        for(auto i : s) {
            temp.push_back(i);
            if(i&ad) {
                t1++;
            }
            else {
                t0++;
            }
        }
        vector<int> v;
        vector<int> nw;
        int tt0 = 0,tt1 = 0;
        for(auto i : now) {
            int re = ask(i,ad);
            if(re) {
                tt1++;
                v.push_back(1);
            }
            else {
                tt0++;
                v.push_back(0);
            }
        }
        int mo = 0;
        if(tt0 != t0) mo = 1;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i] != mo) {
                nw.push_back(now[i]);
            }
        }
        now = nw;
        for(auto i : temp) {
            int t = i&ad;
            if(t > 0) t = 1;
            if(t == mo) {
                s.erase(i);
            } 
        } 
        ad <<= 1;
    }
    cout<<"! "<<*(s.begin())<<endl;
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