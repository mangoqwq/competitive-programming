#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

const int MN = 50;
ll dp[MN][2][MN][MN][2][2];
bool vis[MN][2][MN][MN][2][2];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	int D; cin >> D;
	auto go = [&](auto self, int i, bool reach, int cur, int lst, bool zero, bool lim) -> ll {
		if (i == s.size()){
			return reach;
		}
		ll &d = dp[i][reach][cur][lst][zero][lim];
		bool &v = vis[i][reach][cur][lst][zero][lim];
		if (v) return d;
		v = 1;
		int r = (lim ? s[i] - '0' : 9);
		for (int c = 0; c <= r; ++c){
			int nzero = zero && (c == 0);
			int nlst = (nzero ? 0 : c);
			int ncur = (nzero ? 0 : (c == lst ? cur + 1 : 1));
			bool nreach = reach || (ncur == D);
			bool nlim = lim && (c == r);
			d += self(self, i+1, nreach, ncur, nlst, nzero, nlim);
		}
		return d;
	};
	cout << go(go, 0, 0, 0, 0, 1, 1) << '\n';
}
