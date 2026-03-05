
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
string s;
int ask(int x) {
    cout<<"? "<<x<<endl;
    int res;
    cin>>res;
    return res;
}
int ans;
void solve() {
    cin>>n>>k;
    ans = 0;
    int r = n%k;
    int last = 0;
    int id = id = (n / k) * k + 1 - k;
    for(int i = 1;i <= n-r; i += k) {
        int t = ask(i);
        if (i != id) ans ^= t;
        last = t;
    }
    int ad = 1;
    while(r) {
        if(r & ad) {
            r -= ad;
            int t = ask(ad/2 + id);
            ans ^= (t^last);
            int re = ask(ad + id);
            last = re;
            id += ad;
        }
        ad<<=1;
    }
    cout<<"! "<<(ans ^ last)<<endl;
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