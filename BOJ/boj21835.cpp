#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; double P;
	cin >> N >> K >> P;
	P = 1 - P;
	vector<double> pows(10*K+1);
	pows[0] = 1;
	for (int i = 1; i <= 10*K; ++i){
		pows[i] = pows[i-1] * P;
	}

	vector<double> dp(10*K+1);
	for (int i = 1; i <= 10*K; ++i){
		dp[i] = i;
		for (int k = 2; i-k >= 0 && k <= K; ++k){
			dp[i] = min(dp[i], dp[i-k] + 1 + k*(1-pows[k]));
		}
	}

	double ans = N;
	for (int i = 1; i <= 10*K; ++i){
		ans = min(ans, N/i * dp[i] + dp[N%i]);
	}
	cout << fixed << setprecision(14) << ans << '\n';
}
