#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin>>n>>m;
    vector<int> sum1(n+1);
    vector<int> sum0(n+1);
    vector<int> o1(n+1);
    vector<int> o0(n+1);
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        if(a[i]) {
            sum1[i] = 1;
        }
        else {
            sum0[i] = 1;
        }
        sum1[i]  += sum1[i-1];
        sum0[i] += sum0[i-1];
        if(i % 2 == 0) {
            if(a[i]) o1[i]++;
            else o0[i]++;
        }
        o1[i] += o1[i-1];
        o0[i] += o0[i-1];
    } 
    while(m--) {
        int l,r;
        cin>>l>>r;
        int t1 = sum1[r] - sum1[l-1];
        int t0 = sum0[r] - sum0[l-1];
        if(t1%3 == 0 && t0 %  3 == 0) {
            bool v = 0;
            int get1 = o1[r] - o1[l-1];
            int get0 = o0[r] - o0[l-1];
            if(get1&&get1 == t1&&t1 == t0) {
                v = 1;
            }
            if(get0&&get0 == t0&&t1 == t0) {
                v = 1;
            }
            cout<<t1/3+t0/3+v<<"\n";
        }
        else {
            cout<<-1<<"\n";
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