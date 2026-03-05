#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 10;
int n, m, k;
int a[N][N];
int B;
int sg(vector<int> v) {
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int i = 0,j = 0;
    for(;;++j) {
        if(i < v.size()&&v[i] == j) i++;
        else {
            break;
        }
    }
    return j;
}
void solve() {
    // a[0][0] = 0;
    // a[0][1] = 0;
    // a[1][1] = 0;
    // a[0][2] = 1;
    // for(int i = 3; i <= 30; ++i) {
    //     for(int j = 0; j <= i; ++j) {
    //         int jj = i - j;
    //         if(j <= jj) {
    //             vector<int> tem;
    //             for(int ii = 1; 2*ii <= j; ++ii) {
    //                 int t1 = j - 2*ii,t2 = jj + ii;
    //                 if(t1 > t2) swap(t1,t2);
    //                 tem.push_back(a[t1][t2]);
    //             }
    //             for(int ii = 1; 2*ii <= jj; ++ii) {
    //                 int t1 = j + ii,t2 = jj - 2*ii;
    //                 if(t1 > t2) swap(t1,t2);
    //                 tem.push_back(a[t1][t2]);
    //             }
    //             a[j][jj] = sg(tem);
    //         }
    //     }
    // }
    // for(int i = 0; i <= 10; ++i) {
    //     for(int j = 0; j <= i; ++j) {
    //         cout<<a[j][i]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int a,b;
    cin>>a>>b;
    if(abs(a - b) <= 1) {
        cout<<"Brown";
    }
    else {
        cout<<"Alice";
    }
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