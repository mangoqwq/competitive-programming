#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int BSZ = 500;
const int MN = 2e5 + 1;
const int BLKS = MN/BSZ + 1;
ll B[MN];
ll dp[BLKS][2][2];
ll nxt[2][2];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	N--;
	for (int i = 0; i < N; ++i){
		B[i] = i / BSZ;
	}

	vector<int> a(N);
	ll tot = 0;
	for (int i = 0; i < N; ++i){
		cin >> a[i];
		tot += a[i];
	}

	auto recalc = [&](int b){
		dp[b][0][0] = dp[b][0][1] = dp[b][1][0] = dp[b][1][1] = 0;
		dp[b][1][1] = a[b*BSZ];
		for (int i = b*BSZ + 1; i < min(N, b*BSZ + BSZ); ++i){
			nxt[0][0] = max(dp[b][0][0], dp[b][0][1]);
			nxt[0][1] = dp[b][0][0] + a[i];
			nxt[1][0] = max(dp[b][1][0], dp[b][1][1]);
			nxt[1][1] = dp[b][1][0] + a[i];
			swap(nxt, dp[b]);
		}

		ll ans[2];
		ans[0] = dp[0][0][0];
		ans[1] = dp[0][0][1];
		for (int i = 1; i * BSZ < N; ++i){
			
			ll tmp0 = max({ans[0] + dp[i][1][0], ans[1] + dp[i][0][0], ans[0] + dp[i][0][0]});
			ll tmp1 = max({ans[0] + dp[i][1][1], ans[1] + dp[i][0][1], ans[0] + dp[i][0][1]});
			ans[0] = tmp0;
			ans[1] = tmp1;
		}
		return ans[0];
	};

	for (int i = 0; i * BSZ < N; ++i){
		recalc(i);
	}

	int Q; cin >> Q;
	while (Q--){
		int i; cin >> i;
		i--;
		tot -= a[i];
		cin >> a[i];
		tot += a[i];
		cout << tot*2 - recalc(B[i])*2 << '\n';
	}
}
