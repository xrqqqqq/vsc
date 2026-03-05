
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
#define ld long double
ld le(ld x1, ld y1, ld x2, ld y2) {
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
ld fz(ld t, ld a, ld b, ld c) { return t * t * a + t * b + c; }
ld func(ld a,ld b,ld c,ld l,ld r) {
    ld mid = -b/(2*a);
    if(l <= mid &&mid <=r) return fz(mid,a,b,c);
    else if(mid < l) return fz(l,a,b,c);
    else return fz(r,a,b,c);
}
void solve() {
    ld x1, y1, xx1, yy1;
    ld x2, y2, xx2, yy2;
    cin >> x1 >> y1 >> xx1 >> yy1;
    cin >> x2 >> y2 >> xx2 >> yy2;
    ld le1 = le(x1,y1,xx1,yy1);
    ld le2 = le(x2,y2,xx2,yy2);
    if(le1 > le2) {
        swap(x1,x2);
        swap(y1,y2);
        swap(xx1,xx2);
        swap(yy1,yy2);
        swap(le1,le2);
    }
    ld c1 = (xx1-x1)/le1;
    ld s1 = (yy1-y1)/le1;
    ld c2 = (xx2 - x2) / le2;
    ld s2 = (yy2 - y2) / le2;
    ld ans = 1e18;
    ld a = ((c1 - c2)*(c1 - c2) + (s1 - s2)*(s1 - s2));
    ld b = 2*((c1-c2)*(x1 - x2) + (s1 - s2)*(y1-y2));
    ld c = (y1-y2)*(y1-y2) + (x1-x2)*(x1-x2);
    if(a == 0) {
        ans = min({ans,fz(0,a,b,c),fz(le1,a,b,c)});
    }
    else {
        ans = min(ans,func(a,b,c,0,le1));
    }
    a = 1;
    b = 2*(c2*(x2-xx1) + s2*(y2 - yy1));
    c = (x2 - xx1)*(x2 - xx1) + (y2-yy1) *(y2-yy1);
    ans = min(ans,func(a,b,c,le1,le2));
    ans = max(ans,(ld)0.0);
    printf("%.18Lf\n",sqrtl(ans));
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
