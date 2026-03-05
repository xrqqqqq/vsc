#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
char c[] = {'B','W','R'};
map<char,int> ha = {{'B',0},{'W',1},{'R',2}};
int mod = 3;
int ksm(int a,int b) {
    int res = 1;
    while(b) {
        res = (res * a)%mod;
        a = (a * a)%mod;
        b>>=1;
    }
    return res;
}
int f[10][10];
int C(int a,int b) {
    if(b > a) return 0;
    if(a <= 2&&b <= 2) {
        if(b > a) return 0;
        if(a == 0) return 1;
        int res = 1;
        for(int j = a,i = 1; j >= 1&&i<=b;j--,i++) res = res*j/i;
        return res;
    }
    return C(a/3,b/3)*C(a%3,b%3)%3;
}
void solve() {
    cin>>n;
    string s;
    cin>>s;
    int res = 1;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans = (ans + C(n-1,i)*ha[s[i]]%mod)%mod;
    }
    if(n % 2 == 0) ans = (-ans%3 + 3)%mod;
    cout<<c[ans]<<"\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}