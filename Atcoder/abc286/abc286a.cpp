#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N;
	int P, Q, R, S; cin >> N >> P >> Q >> R >> S;
	P--, Q--, R--, S--;
	vector<int> a(N);
	for (int i = 0; i < N; ++i){
		cin >> a[i];
	}
	for (int i = 0; P + i <= Q; ++i){
		swap(a[P+i], a[R+i]);
	}
	for (int i = 0; i < N; ++i){
		cout << a[i] << (i == N-1 ? '\n' : ' ');
	}
}
