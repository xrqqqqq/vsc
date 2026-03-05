
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int mod = 999999937;
int n;
int ksm(int a,int b) {
    int res = 1;
    while(b & 1) {
        res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void test() {
    // cout<<"Yes\n";
    cin>>n;
    if(n == 1) {
        cout<<"Yes\n";
        cout<<1<<"\n";}
    else if(n == 2) {
        cout<<"No\n";
    }
    else {
        cout<<"Yes\n";
        map<int,int> ha;
        ha[2] = ha[3] = ha[6] = 1;
        int cnt = 3;
        if(cnt < n)
        for(int i = 3;;++i) {
            int t = i + 1,tt = i*(i+1);
            if(ha[t] == 0&&ha[tt] == 0) {
                cnt++;
                ha[i]--;
                ha[t]++;
                ha[tt]++;
            }
            if(cnt == n) break;
        }
        for(auto [x,y] : ha) {
            if(y == 1) {
                cout<<x<<" ";
            }
        }
        cout<<"\n";
    }
}   
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        test();
    }
    return 0;
}