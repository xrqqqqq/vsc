#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    int l,r;
    cin>>l>>r;
     if (r < 2 * l) {
        if((r - l + 1) % 2 == 1) {
            cout << "Alice\n";
        }
        else {
            cout << "Bob\n";
        }
    }
    else {
        if((r % l)%2 == 0) {
            cout<<"Alice\n";
        }
        else {
            if(l&1) {
                cout<<"Alice\n";
            }
            else {
                cout << "Bob\n";
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin>>T;
    while (T--) {
        solve();
    }
}