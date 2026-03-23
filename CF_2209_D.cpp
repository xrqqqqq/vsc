#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 11;
int n, m, k;
int a[N];
char c[] = {'R','G','B'};
void solve() {
    vector<array<int,2>> te;
    int sum = 0;
    for(int i = 0; i <= 2; ++i) {
        int x;
        cin>>x;
        sum += x;
        a[i] = x;
        te.push_back({x,i});
    }
    sort(te.begin(),te.end());
    int mi = te[0][0];
    int mx = te[2][0];
    if(sum - mx <= mx) {
        while(a[te[0][1]]) {
            a[te[0][1]]--;
            a[te[2][1]]--;
            cout<<c[te[2][1]]<<c[te[0][1]];
        }
        while(a[te[1][1]]) {
            a[te[1][1]]--;
            a[te[2][1]]--;
            cout<<c[te[2][1]]<<c[te[1][1]];
        }
        if(a[te[2][1]]) {
            cout<<c[te[2][1]];
        }
        cout<<endl;
    }
    else {
        while(a[te[1][1]] != a[te[0][1]]) {
            a[te[2][1]]--;
            a[te[1][1]]--;
            cout<<c[te[2][1]]<<c[te[1][1]];
        }
        while(abs(a[te[1][1]] - a[te[2][1]]) > 1) {
            a[te[0][1]]--;
            a[te[1][1]]--;
            a[te[2][1]]-=2;
            cout<<c[te[2][1]]<<c[te[0][1]];
            cout<<c[te[2][1]]<<c[te[1][1]];
        }
        auto get = [&](int t1,int t2,int t3,int x) {
            int tt1 = t1,tt2 = t2,tt3 = t3;
            while(x--) {
                cout<<c[t1]<<c[t2]<<c[t3];
                swap(t1,t3);
                swap(t1,t2);
            }
        };
        if (abs(a[te[1][1]] - a[te[2][1]]) == 1) {
            // cout<<"df\n";
            cout<<c[te[2][1]];
            get(te[1][1],te[2][1],te[0][1],a[te[1][1]]);
        }
        else {
            int need = a[te[1][1]];
            get(te[2][1],te[1][1],te[0][1],need);
        }
        cout<<endl;
    }
}

signed main() {
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}