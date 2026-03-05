
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n,m,k;
int a[N];
void solve() {
    cin>>n;
    string s;
    cin>>s;
    int cnt1 = 0,cnt0 = 0;
    for(int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
        if(a[i]) cnt1++;
        else cnt0++;
    }
    
    if(cnt0&&cnt1 % 2 == 0&&cnt1) {
        cout<<"YES\n";
        int id = 0;
        for(int i = 0;i < n; ++i) {
            int j = (i + 1) % n;
            if(a[i] == 1&&a[j] == 0) {
                id = j;
                break;
            }
        }
        int last = -1;
        for(int i = 1; i < n; ++i) {
            int now = (i + id)% n;
            if(a[now] == 0) {
                if(last == -1) last = now;
                cout<<now + 1<<" "<<(now+1)%n + 1<<"\n";
            }
            else {
                if(last == -1) {
                    cout<<id + 1<<" "<<now + 1<<"\n";
                }
                else {
                    cout<<id + 1<<" "<<last + 1<<"\n";
                }
                last = -1;
            }
        }
    }
    else {
        if(cnt1 == n&&cnt1 % 2 == 0) {
            cout<<"Yes\n";
            for(int i = 2; i <= n; ++i) {
                cout<<1<<" "<<i<<"\n";    
            }
            return ;
        }
        cout<<"NO\n";
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