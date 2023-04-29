#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;
	int m = (N-1) / 2;

	auto act = [&](string s){
		cout << s;
	};

	if (K == m){
		act("DL");
	}
	else if (K < m){
		act("L");
		for (int i = 0; i < K-1; ++i){
			act("DRUL");
		}
	}
	else if (K > m){
		act("R");
		for (int i = 0; i < N-2-K; ++i){
			act("DLUR");
		}
		act("ULDL");
		for (int i = 0; i < N; ++i){
			act("ULDL");
		}
		act("RDL");
		// get piece to right side
		// ULDL
		// ULDL repeat
		// RDL
	}
	cout << '\n';
}
