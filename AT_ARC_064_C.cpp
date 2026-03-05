#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
#define ld long double
struct A {
    int x,y;
    int r;
};
int v[N];
vector<pair<int,ld>> ne[N];
ld f(A a,A b) {
    int len = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    int rr = (a.r + b.r)*(a.r + b.r);
    if(rr >= len) return 0.0;
    else {
        return sqrt(len) - (a.r + b.r);
    }
}
int sx,sy,tx,ty;
int n;
ld d[N];
void test() {
    cin>>sx>>sy>>tx>>ty;
    cin>>n;
    vector<A> ad;
    ad.push_back({sx,sy,0});
    for(int i = 1; i <= n; ++i) {
        d[i] = 1e18;
        int x,y,r;
        cin>>x>>y>>r;
        ad.push_back({x,y,r});
    }
    ad.push_back({tx,ty,0});
    d[0] = d[n+1] = 1e18;
    for(int i = 0; i <= n + 1; ++i) {
        for(int j = i + 1; j <= n + 1; ++j) {
            ld get = f(ad[i],ad[j]);
            ne[i].push_back({j,get});
            ne[j].push_back({i,get});
        }
    }
    d[0] = 0;
    priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<>> q;
    q.push({0,0});
    while(q.size()) {
        auto [w,u] = q.top();
        q.pop();
        if(v[u]) continue;
        v[u] = 1;
        for(auto [vv,wv] : ne[u]) {
            if(d[vv] > wv + w) {
                d[vv] = wv + w;
                if(v[vv] == 0) {
                    q.push({d[vv],vv});
                }
            }
        }
    }
    printf("%.10Lf",d[n+1]);
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        test();
    }
    return 0;
}