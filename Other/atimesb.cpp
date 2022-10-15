#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
typedef complex<double> cd;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;
const double PI = acos(-1);

void fft(vector<cd> &a, bool inv){
    int N = a.size();
    for (int i = 1, j = 0; i < N; ++i){
        int bit = N >> 1;
        for (; j & bit; bit >>= 1){
            j ^= bit;
        }
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int sz = 2; sz <= N; sz <<= 1){
        double deg = 2 * PI / sz * (inv ? -1 : 1);
        cd w1 = {cos(deg), sin(deg)};
        for (int i = 0; i < N; i += sz){
            cd w = {1};
            for (int j = 0; j < (sz >> 1); ++j){
                cd y0 = a[i + j], y1 = a[i + j + (sz >> 1)];
                if (inv) y0 /= 2, y1 /= 2;
                a[i + j] = y0 + w * y1;
                a[i + j + (sz >> 1)] = y0 - w * y1;
                w *= w1;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string A, B; cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int SZ = 1 << (__lg(A.size() + B.size()) + 1);
    vector<cd> a(SZ), b(SZ);
    for (int i = 0; i < A.size(); ++i) a[i] = A[i] - '0';
    for (int i = 0; i < B.size(); ++i) b[i] = B[i] - '0';
    fft(a, 0); fft(b, 0);
    for (int i = 0; i < SZ; ++i) a[i] *= b[i];
    fft(a, 1);
    int carry = 0;
    string ans = "";
    for (cd &y : a){
        carry += (int)round(y.real());
        cout << fixed << setprecision(15) << y.real() << '\n';
        ans += (carry % 10) + '0';
        carry /= 10;
    }
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
