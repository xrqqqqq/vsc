#include <bits/stdc++.h>
using namespace std;
int ned[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
struct A {
    vector<int> a;
    A() : a(10, -1e9) {}
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    vector<int> dp(n + 1,-1e9);
    dp[0] = 0;
    for(int i = 0; i <= n; ++i) {
        for(auto x : d) {
            if(i + ned[x] <= n) {
                dp[i + ned[x]] = max(dp[i + ned[x]], dp[i] + 1);
            }
        }
    }
    sort(d.begin(), d.end(), greater<int>());
    int last = n;
    while(last > 0) {
        for(auto x : d) {
            if(last - ned[x] >= 0&& dp[last] == dp[last - ned[x]] + 1) {
                cout<<x;
                last -= ned[x];
                break;
            }
        }
    }
}
