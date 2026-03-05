#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
vector<int> ne[N];
void solve() {
    cin>>n;
    // vector<int> si;
    for(int i = 0; i <= n; ++i) ne[i].clear();
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        ne[a[i]].push_back(i);
    }
    int id = -1;
    for(int i = 0;i <= n; ++i) {
        if(ne[i].size() && i == 0) {
            id = 0;
            break;
        }
        else if(ne[i].size() >= 2) {
            id = i;
            break;
        }
    }
   
    vector<array<int,2>> ans(n+1);
    vector<int> p(n+1);
    vector<int> se(n+1);
    if(id == 0) {
        cout << "YES\n";
        id = ne[0].back();
        ans[id] = {1,1};
        p[id] = id;
        se[1] = id;
        int i = 2;
        for(int j = 1; j <= n; ++j) {
            if(j == id) continue;
            int t = a[j];
            if(t == 0) {
                p[j] = j;
                ans[j] = {i,1};
                se[i] = j;
                i++;
                continue;
            }
            if((i-1) <= t) {
                p[j] = se[1];
                ans[j] = {i,t - i + 2};
                se[i] = j;
            }
            else {
                int ii = i - t;
                int id = se[ii];
                p[j] = id;
                ans[j] = {i,ans[id][1]};
                se[i] = j;
            }
            i++;
        }
        for(int i = 1; i <= n; ++i) {
            cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
        }
        for(int i = 1;i  <= n; ++i) {
            cout<<p[i]<<" ";
        }
        cout<<"\n";
    }
    else if(id != -1){
        cout << "YES\n";
        int p1,p2;
        p1 = ne[id].back();
        ne[id].pop_back();
        p2 = ne[id].back();
        p[p1] = p2;
        p[p2] = p1;
        // cout<<p1<<" "<<p2<<"\n";
        int i = 3;
        ans[p1] = {1,1};
        ans[p2] = {2,a[p2]};
        se[1] = p1;
        se[2] = p2;
        for(int j = 1;j <= n; ++j) {
            if(j == p1 ||j == p2) continue;
            int t = a[j];
            if (t == 0) {
                p[j] = j;
                ans[j] = {i, 1};
                se[i] = j;
                i++;
                continue;
            }
            if ((i - 1) <= t) {
                p[j] = se[1];
                ans[j] = {i, t - i + 2};
                se[i] = j;
            } else {
                int ii = i - t;
                int id = se[ii];
                p[j] = id;
                ans[j] = {i, ans[id][1]};
                se[i] = j;
            }
            i++;
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i][0] << " " << ans[i][1] << "\n";
        }
        for (int i = 1; i <= n; ++i) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    else if(n >= 3) {
        cout << "YES\n";
        int t1 = ne[1].back();
        int t2 = ne[2].back();
        int t3 = ne[3].back();
        // cout<<p1<<" "<<p2<<"\n";
        int i = 4;
        se[1] = t3;
        se[2] = t2;
        se[3] = t1;
        ans[t1] = {3,2};
        ans[t2] = {2,2};
        ans[t3] = {1,1}; 
        p[t3] = t1;
        p[t2] = t3;
        p[t1] = t2;
        for (int j = 1; j <= n; ++j) {
            if (j == t1 || j == t2 || j == t3) continue;
            int t = a[j];
            if (t == 0) {
                p[j] = j;
                ans[j] = {i, 1};
                se[i] = j;
                i++;
                continue;
            }
            if ((i - 1) <= t) {
                p[j] = se[1];
                ans[j] = {i, t - i + 2};
                se[i] = j;
            } else {
                int ii = i - t;
                int id = se[ii];
                p[j] = id;
                ans[j] = {i, ans[id][1]};
                se[i] = j;
            }
            i++;
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i][0] << " " << ans[i][1] << "\n";
        }
        for (int i = 1; i <= n; ++i) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout<<"NO\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    // init(1e5);
    while (T--) {
        solve();
    }
}