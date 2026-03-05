#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    map<int,int> ha;
    int ans = 0;
    int l,r;
    cin>>l>>r;
    if(r == 0) {
        cout<<0<<"\n";
        cout<<0<<"\n";
        return ;
    }
    vector<int> a(r + 1);
    int ans1 = 0;
    for(int i = r; i >= 0; --i) {
        int now = i;
        int t = (int)log2(i) + 1;
        t = 1 << t;
        t--;
        int tem = t - i;
        if(ha.count(now) == 0) {
            while(ha.count(tem)) tem++;
            ans += now + tem;
            ha[tem] = now;
            ha[now] = tem;
            a[i] = tem;
            ans1 += (now|tem);
        }
        else {
            ans += ha[i] + i;
            a[i] = ha[i];
            ans1 += (i | ha[i]);
        }
    }
    cout<<ans<<"\n";
    for(int i = 0; i <= r; ++i) {
        cout<<a[i]<<" ";
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