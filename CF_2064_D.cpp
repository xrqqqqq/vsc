#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
int sum[N][40];
int xo[N];
void solve() {
    cin>>n >>m;
    for(int i = 1; i <= n + 1; ++i) {
        for(int j = 0; j <= 29; ++j) {
            sum[i][j] = 0;
        }
        xo[i] = 0;
    }
    for(int i = 1;i<= n; ++i) {
        cin>>a[i];
        xo[i] = xo[i-1] ^ a[i];
    }
    for(int i = 29; i >= 0; --i) {
        for(int j = 1; j <= n; ++j) {
            sum[j][i] = (a[j] >> i) & 1ll;
        }
        for(int j = n; j >= 1; --j) {
            sum[j][i] += sum[j+1][i];
        }
    }

    while(m--) {
        int x;
        cin>>x;
        int ll = 1;
        int rr = n;
        int ans = 0;
        for(int i = 29; i >= 0; --i) {
            int t = (x >> i)&1ll;
            // cout<<t<<" "<<x<<" "<<i<<"t\n";
            if(ll > rr) break;
            int l = ll,r = rr;
            // cout<<ll<<" "<<rr<<"llrr\n";
            while(l < r) {
                int m = l + r + 1 >>1;
                if(sum[m][i] - sum[rr+1][i] >= 1) l = m;
                else r = m - 1;
            }
            // cout<<sum[l][i] - sum[rr+1][i]<<"\n";
            // cout<<l<<" "<<t<<"\n";
            if(sum[l][i] - sum[rr+1][i] < 1) {
                if(t) {
                    ans += rr - ll + 1;
                    break;
                }
                else {
                    if(i == 0) ans += rr - ll + 1;
                    continue;
                }
            } 
            else {
                if(t) {
                    ans += (rr - l);
                    x ^= xo[rr]^xo[l];
                    if(a[l] > x) {
                        break;
                    }
                    else {
                        ans++;
                        x ^= a[l];
                        rr = l - 1;
                        int l1 = ll, r1 = rr;
                        while (l1 < r1) {
                            int m = l1 + r1 + 1 >> 1;
                            if (sum[m][i] - sum[rr + 1][i] >= 1)
                                l1 = m;
                            else
                                r1 = m - 1;
                        }
                        if (sum[l1][i] - sum[rr + 1][i] < 1) {
                            if (i == 0) ans += rr - ll + 1;
                            continue;
                        }
                        else {
                            ll = l1 + 1;
                            if (i == 0) ans += rr - ll + 1;
                            continue;
                        }
                    }
                }
                else {
                    ll = l + 1;
                    if (i == 0) ans += rr - ll + 1;
                    continue;
                }
            }
        }
        cout<<ans<<" ";
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