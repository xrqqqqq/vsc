
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int n, m, k;

void solve() {
    vector<int> ne[2];
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin>>x;
        a[i] = x;
        ne[x%2].push_back(x);
    }
    auto f = [&](int x,int y) {
        return ((y % x) % 2) == 0;
    };
    if(ne[1].size() >= 2) {
        int len = (int)ne[1].size();
        len--;
        for(int i = 0; i <= 60; ++i) {
            if(i + 1 > len) break;
            for(int j = i+1; j <= len; ++j) {
                if(f(ne[1][i],ne[1][j])) {
                    cout<<ne[1][i]<<" "<<ne[1][j]<<"\n";
                    return ;
                }
            }
        }
    }
    if(ne[0].size() >= 2) {
        cout<<ne[0][0]<<" "<<ne[0][1]<<"\n";
        return ;
    }
    else if(ne[0].size() == 1) {
        int id = 1;
        while(id <= n&&a[id] % 2 == 1) id++;
        for(int j = 1; j <= id - 1; ++j) {
            if(f(a[j],a[id])) {
                cout<<a[j]<<" "<<a[id]<<"\n";
                return ;
            }
        }
    }   
    cout<<-1<<"\n";
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