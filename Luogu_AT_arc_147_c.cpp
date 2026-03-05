
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n,m,k;

void test() {
    cin>>n;
    vector<int> te;
    for(int i = 1; i <= n; ++i) {
        int l,r;
        cin>>l>>r;
        te.push_back(l);
    }
    sort(te.begin(),te.end());
    int ans = 0;
    int sum = 0;
    for(int i = te.size() - 1; i >= 1; --i) {
        sum += te[i];
        ans += sum;
    }
    cout<<ans<<"\n";
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