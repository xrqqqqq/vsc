#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    string ss;
    string like = "noise:";
    auto  zm = [&](char c) {
        bool v = 0;
        if(c <= 'z'&&c >= 'a') v = 1;
        if(c <= 'Z'&&c >= 'A') v = 1;
        return v;
    };
    auto sz = [&](char c) {
        bool v = 0;
        if(c <= '9'&&c >= '0') v = 1;
        return v;
    };
    while(getline(cin,s)) {
        if(s == "0") break;
        string temp;
        int l = 0;
        int r = s.size() - 1;
        if(s.size() >= like.size()) {
            bool ok = 1;
            for(int i = 0; i < like.size(); i++) {
                if(!(s[i] == like[i] || (s[i] == like[i] - 'a' + 'A'))) {
                    ok = 0;
                    break;
                }
            }

            if(ok) {
                l = like.size();
                while(l < s.size() 
                && isspace((unsigned char)s[l]))
                    l++;
            }
            if(l > r) continue;
        }
        if(s.size() >= 3 && s.substr(s.size() - 3) == "###") {
            r = s.size() - 4;
            while(r >= 0 && s[r] == ' ')
                r--;
        }
        if(l > r) continue;
        for(int i = l; i <= r; i++) {
            if(s[i] == '[') {
                int j = i + 1;
                while(i < s.size() &&s[j] != ']') j++;
                bool zmm = 1;
                for(int k = i + 1; k <= j - 1; ++k) {
                    if(!zm(s[k])) {
                        zmm = 0;
                        break;
                    }
                }
                if(zmm == 1) {
                    for(int k = j - 1; k >= i + 1; k--) {
                        ss.push_back(s[k]);
                    }
                }
                else {
                    for(int k = i + 1; k <= j - 1; ++k) {
                        ss.push_back(s[k]);
                    }
                }
                i = j;
            }
            else {
                ss.push_back(s[i]);
            }
        }
    }
    if(ss.size() == 0) {
        cout << "EMPTY_SIGNAL\n";
        return 0;
    }
    string get;
    vector<int> id;
    for(int i = 0; i < ss.size(); ++i) {
        if(zm(ss[i]) || sz(ss[i])) {
            get.push_back(ss[i]);
            id.push_back(i);
        }
    }
    if(get.size() == 0) {
        cout << "EMPTY_SIGNAL\n";
        return 0;
    }
    auto hw = [&](int l,int r) {
        bool v = 1;
        for(int i = l; i <= (l + r)/2; ++i) {
            if(get[i] != get[r - (i - l)]) {
                v = 0;
                break;
            }
        }
        return v;
    };
    cout << "\t";
    cout << "df\n";
    for(int len = ss.size(); len >= 1; -- len) {
        for(int i = 0; i + len - 1 <get.size(); ++i) {
            if(hw(i,i+len-1)) {
                for(int j = id[i]; j <= id[i + len - 1]; ++ j) cout<<ss[j];
                return 0;
            }
        }
    }
    
    
}