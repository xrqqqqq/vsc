#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int ask(int a,int b) {
    cout<<"? "<<a<<" "<<b<<endl;
    int x;
    cin>>x;
    return x;
}
void re(int x) {
    cout<<"! "<<x<<endl;
    return ;
}
void solve() {
    cin >> n;
    if(n % 2 == 0) {
        int v = 0;
        for (int i = 1; i + 3 <= n; i += 2) {
            if (ask(i, i + 1) != ask(i + 1, i)) {
                v = i;
                break;
            }
        }
        if(v == 0) v = n - 1;
        int tem = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == v || i == v + 1) continue;
            tem = i;
            break;
        }
        if (ask(tem, v) != ask(v, tem)) {
            re(v);
        } else {
            re(v + 1);
        }
    }
    else if( n == 3) {
        int v = 0;
        for (int i = 1; i + 2 <= n; i += 2) {
            if (ask(i, i + 1) != ask(i + 1, i)) {
                v = i;
                break;
            }
        }
        if (v == 0) {
            re(n);
            return ;
        }
        int tem = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == v || i == v + 1) continue;
            tem = i;
            break;
        }
        if (ask(tem, v) != ask(v, tem)) {
            re(v);
        } else {
            re(v + 1);
        }
    }
    else {
        map<int,map<int,int>> ha;
        ha[1][2] = ask(1,2);
        ha[2][3] = ask(2,3);
        ha[3][1] = ask(3,1);
        int t = 0;
        if(ha[1][2]) t++;
        if(ha[2][3]) t++;
        if(ha[3][1]) t++;
        if(t == 2 || t == 0) {
            if(ask(2,1) != ha[1][2]) {
                if(ask(3,2) != ha[2][3]) {
                    re(2);
                }
                else {
                    re(1);
                }
            }
            else {
                re(3);
            }
        } 
        else {
            int v = 0;
            for (int i = 4; i + 3 <= n; i += 2) {
                if (ask(i, i + 1) != ask(i + 1, i)) {
                    v = i;
                    break;
                }
            }
            if (v == 0) v = n - 1;
            int tem = 0;
            for (int i = 1; i <= n; ++i) {
                if (i == v || i == v + 1) continue;
                tem = i;
                break;
            }
            if (ask(tem, v) != ask(v, tem)) {
                re(v);
            } else {
                re(v + 1);
            }
        }
    }
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    // init(1e5);
    while (T--) {
        solve();
    }
}