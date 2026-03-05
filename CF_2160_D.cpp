#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int b[N];
int ask(vector<int> v) {
    cout<<"? "<<v.size();
    for(auto x:v) cout<<" "<<x;
    cout<<endl;
    int res;
    cin>>res;
    return res;
}
void solve() {
    cin>>n;
    vector<int> v(2*n+1);
    vector<int> a(2*n+1);
    vector<int> p;
    p.push_back(1);
    for(int i = 2; i <= n*2; ++i) {
        p.push_back(i);
        int res = ask(p);
        if(res != 0) {
            v[i] = 1;
            a[i] = res; 
            p.pop_back();
        }
    }
    p.clear();
    for(int i = 1; i <= n*2; ++i) {
        if(v[i]) p.push_back(i);
    }
    for(int i = 1; i <= n*2; ++i) {
        if(!v[i]) {
            p.push_back(i);
            int res = ask(p);
            a[i] = res;
            p.pop_back();
        }
    }
    cout<<"!";
    for(int i = 1; i <= n*2; ++i) {
        cout<<" "<<a[i];
    }
    cout<<endl;
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