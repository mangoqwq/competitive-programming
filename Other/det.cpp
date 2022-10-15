#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int inf=0x3f3f3f3f, MAXN=0;

const ll mod = 1000000007;
ll det(vector<vector<ll>>& a) {
	int n = a.size(); ll ans = 1;
    for (int i=0;i<n;++i) {
        for (int j=i+1;j<n;++j) {
			while (a[j][i] != 0) { // gcd step
				ll t = a[i][i] / a[j][i];
				if (t) for (int k=i;k<n;++k) 
					a[i][k] = (a[i][k] - a[j][k] * t) % mod;
				swap(a[i], a[j]);
				ans *= -1;
			}
		}
		ans = ans * a[i][i] % mod;
		if (!ans) return 0;
	}
	return (ans + mod) % mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<ll>> a(n,vector<ll>(n+1));
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin >> a[i][j];
    cout << det(a) << '\n';
}