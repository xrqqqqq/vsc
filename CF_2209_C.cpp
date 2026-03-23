#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 11;
int n, m, k;
int a[N];
int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();

    int x;
    cin>>x;

    return x;
}
void ok(int i) {
    
        cout << "! " << i << endl;
        cout.flush();
    
}
void solve() {
    cin>>n;
    int t = ask(1,2);
    if(t == 1){
    ok(1);
    return ;
    }
    t = ask(1,3);
    if (t == 1) {
        ok(1);
        return;
    }
    t = ask(2,3);
    if(t == 1) {
        ok(2);
        return ;
    }
    for(int i = 5;  i + 1<= 2*n; i += 2) {
        t = ask(i,i+1);
        if (t == 1) {
            ok(i);
            return;
        }
    }
    cout<<"! "<<4<<endl;
    cout.flush();
}

signed main() {
   
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}