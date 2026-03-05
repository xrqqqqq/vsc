
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e6 + 10;
int n, m, k;
vector<int> ne[N];
int le[N];
int b[N];
int c[N];
int a[N];
int ask(int i,int j) {
    cout<<"? "<<i<<" "<<j<<endl;
    int res;
    cin>>res;
    return res;
}
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        ne[i].clear();
        le[i] = 0;
    }
    cout<<"+ "<<n+1<<endl;
    int x;
    cin>>x;
    cout<<"+ "<<n<<endl;
    cin>>x;
    a[1] = n;
    a[2] = 1;
    for(int i = 3;i <= n; ++i) {
        if(i&1) {
            a[i] = a[i-2] - 1;
        }
        else {
            a[i] = a[i-2] + 1;
        }
    }
    int id = 1;
    int mx = 0;
    for(int i = 2; i <= n; ++i) {
        int te = ask(1,i);
        mx = max(mx,te);
        ne[te].push_back(i);
        le[i] = te;
        if(ne[te].size() == 2) {
            id++;
        }
    }
    c[1] = id;
    int t[2];
    t[0] = t[1] = 0;
    if(ne[1].size() == 2) {
        t[0] = 1;
        t[1] = 1;
        b[ne[1][0]] = 0;
        b[ne[1][1]] = 1;
    }
    else {
        b[ne[1][0]] = 0;
        t[0] = 1;
    }
    for(int i = 1; i < mx; ++i) {
        auto p = ne[i];
        auto pp = ne[i+1];
        int re = ask(p[0], pp[0]);
        if(pp.size() == 2) {
            t[0]++;
            t[1]++;
            if(re == 1) {
                b[pp[0]] = b[p[0]];
                b[pp[1]] = b[p[1]];
            }
            else {
                b[pp[0]] = b[p[1]];
                b[pp[1]] = b[p[0]];
            }
        }
        else {
            if(re == 1) {
                t[b[p[0]]]++;
                b[pp[0]] = b[p[0]];
            }
            else {
                t[b[p[1]]]++;
                b[pp[0]] = b[p[1]];
            }
        }
    }
    int v = 0;
    if(t[1] >= t[0]) v = 1;
    for(int i = 2;i <= n; ++i) {
        int f = 1;
        if(b[i] != v) f = -1;
        c[i] = c[1] + f*le[i];
    } 
    cout<<"! ";
    for(int i = 1; i <= n; ++i) {
        cout<<a[c[i]]<<" ";
    }
    for(int i = 1; i <= n; ++i) {
        cout<<a[n-c[i]+1]<<" ";
    }
    cout<<endl;
    cin>>x;
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