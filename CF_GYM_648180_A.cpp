#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 1e3 + 10;
void test() {
    int x,y,q;
    cin>>x>>y>>q;
    if(x > y) {
        cout<<0;
    }
    else {
        cout<<(y + 1 - x + q - 1)/q;
    }
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