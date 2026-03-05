#include <bits/stdc++.h>
using namespace std;
#define int long long
map<char, int> mp = {{'D', 0}, {'C', 1}, {'H', 2}, {'S', 3}};

int st[50][4];
int vis[5][5][5][5][2][2][2][2][3];

void solve() {
    int n;
    cin >> n;
    int tot = 0;
    vector<int> a(4), b(5);
    memset(vis,0,sizeof(vis));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a[mp[s[1]]]++;
    }
    for (int i = 1; i <= 6; i++) {
        int x;
        cin >> x;
        if (i >= 5) {
            b[4] += x;
        } else {
            b[i - 1] += x;
        }
    }

    for (int i = 0; i < 4; i++) {
        while (a[i] >= 5) {
            tot++;
            a[i] -= 5;
        }
    }

    int ans = tot;
    
    // cout << ans << endl;

    // for (int i = 0; i < 4; i++) {
    //     cout << a[i] << endl;
    // }
    int tt = 1;
    auto dfs = [&](auto&& self) -> void {
        if (vis[a[0]][a[1]][a[2]][a[3]][b[0]][b[1]][b[2]][b[3]][b[4]]) {
            return;
        }
        vis[a[0]][a[1]][a[2]][a[3]][b[0]][b[1]][b[2]][b[3]][b[4]] = 1;
        ans = max(ans, tot);
        // for (int i = 0; i < 4; i++) {
        //     cout << a[i] << " ";
        // }
        
        // for (int i = 0; i < 5; i++) {
        //     cout << b[i] << " ";
        // }

        // cout << endl;
        // if (++tt > 1000) {
        //     return;
        // }

        // int cal = 0;
        // for (int i = 0; i < 5; i++) {
        //     cal += (b[i] > 0);
        //     // cout << a[i];
        // }
        // // cout << endl;

        // if (cal == 0) return;
        
        if (b[4] >= 1) {
            for (int i = 0; i < 4; i++) {  //  i -> j
                if (a[i] == 0) continue;
                for (int j = 0; j < 4; j++) {
                    // if (j == i) continue; //i -> i 表示不用
                    a[i]--;
                    b[4]--;  // 消耗
                    if (a[j] == 4) {
                        tot++;
                        a[j] = 0;
                        self(self);
                        tot--;
                        a[j] = 4;
                    } else {
                        a[j]++;
                        self(self);
                        a[j]--;
                    }
                    a[i]++;
                    b[4]++;
                }
            }
        }

        // bool f = 0;
        for (int i = 0; i < 4; i++) {
            if (b[i] == 0) continue;
            for (int j = 1; j <= 40; j++) {
                if (!(a[(i + 1) % 4] >= st[j][0] &&
                      a[(i + 2) % 4] >= st[j][1] && a[(i + 3) % 4] >= st[j][2]))
                    continue;
                int tmp = st[j][0] + st[j][1] + st[j][2];
                a[(i + 1) % 4] -= st[j][0];
                a[(i + 2) % 4] -= st[j][1];
                a[(i + 3) % 4] -= st[j][2];
                a[i] += tmp;
                bool f = 0;
                if (a[i] >= 5) {
                    a[i] -= 5;
                    tot++;
                    f = 1;
                }
                b[i]--;
                self(self);
                b[i]++;
                a[i] -= tmp;
                if (f) {
                    a[i] += 5;
                    tot--;
                }
                a[(i + 1) % 4] += st[j][0];
                a[(i + 2) % 4] += st[j][1];
                a[(i + 3) % 4] += st[j][2];
            }
        }

        // if (f == 0) {
        //     ans = max(ans, tot);
        // }
    };

    dfs(dfs);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(st, 0, sizeof(st));
    int cnt = 1;

    for (int i = 0; i < 3; i++) {
        st[cnt][i]++;
        cnt++;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            st[cnt][i]++;
            st[cnt][j]++;
            cnt++;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                st[cnt][i]++;
                st[cnt][j]++;
                st[cnt][k]++;
                cnt++;
            }
        }
    }

    // for (int i = 1; i <= 40; i++) {
    //     cout << st[i][0] << " " << st[i][1] << " " << st[i][2] << endl;
    // }

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}