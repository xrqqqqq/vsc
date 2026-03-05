#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 1e3 + 10;
int ask(int x, int y, int c) {
    cout << "? " << x << " " << y << " " << c << endl;
    int res;
    cin >> res;
    return res;
}
int n;
void test() {
    cin >> n;
    int mx = 0;
    int mxid = 0;
    map<int, int> ha;
    map<int, int> si;
    bool v = 0;
    int tem = 0;
    for (int i = 3; i <= n; ++i) {
        int res = ask(1, 2, i);
        ha[res] = i;
        si[res]++;
        mx = max(mx, res);
    }
    if (si[mx] == n - 2) {
        v = 1;
        tem = mx;
    }
    mxid = ha[mx];
    mx = 0;
    // map<int, int> si;
    si.clear();
    ha.clear();
    for (int i = 2; i <= n; ++i) {
        if (i == mxid) continue;
        int res = ask(1, mxid, i);
        si[res]++;
        ha[res] = i;
        mx = max(res, mx);
    }
    if(v && tem == mx) {
        cout<<"! "<<1<<" "<<2<<endl;
        return ;
    }
    if (si[mx] == n - 2) {
        cout << "! " << 1 << " " << mxid << endl;
        return;
    } else {
        cout << "! " << mxid << " " << ha[mx] << endl;
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