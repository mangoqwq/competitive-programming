#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N; ll Z; cin >> N >> Z; Z++;
		vector<ll> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		a.push_back(1e18);
		const int L = 18;
		vector<vector<int>> nxt(N + 1, vector<int>(L));
		for (int i = 0; i < N; ++i) {
			nxt[i][0] = ranges::lower_bound(a, a[i] + Z) - a.begin();
		}
		ranges::fill(nxt[N], N);
		for (int l = 1; l < L; ++l) {
			for (int i = 0; i < N; ++i) {
				nxt[i][l] = nxt[nxt[i][l - 1]][l - 1];
			}
		}
		auto get_nxt = [&](int i, int jmp) {
			for (int l = L - 1; l >= 0; --l) {
				if ((1 << l) <= jmp) {
					jmp -= 1 << l;
					i = nxt[i][l];
				}
			}
			return i;
		};
		vector<vector<int>> nxt_meet(N + 1, vector<int>(L));
		vector<vector<int>> nxt_uniq(N + 1, vector<int>(L));
		for (int i = 0; i < N; ++i) {
			if (nxt[i][0] == i + 1){
				nxt_meet[i][0] = i + 1;
				nxt_uniq[i][0] = 1;
				continue;
			}
			int lo = 1, hi = N;
			while (lo < hi) {
				int mi = (lo + hi) >> 1;
				int target = get_nxt(i, mi);
				int at = i + 1;
				for (int l = L - 1; l >= 0; --l) {
					if (nxt[at][l] < target) {
						at = nxt[at][l];
					}
				}
				at = nxt[at][0];
				if (at == target) {
					hi = mi;
				}
				else {
					lo = mi + 1;
				}
			}
			int target = get_nxt(i, lo);
			int jmp = 0, at = i + 1;
			for (int l = L - 1; l >= 0; --l) {
				if (nxt[at][l] < target) {
					at = nxt[at][l];
					jmp += 1 << l;
				}
			}
			jmp += 1;
			at = nxt[at][0];
			assert(at == target);
			nxt_uniq[i][0] = lo + jmp;
			nxt_meet[i][0] = target;
		}
		ranges::fill(nxt_meet[N], N);
		for (int l = 1; l < L; ++l) {
			for (int i = 0; i < N; ++i) {
				nxt_meet[i][l] = nxt_meet[nxt_meet[i][l - 1]][l - 1];
				nxt_uniq[i][l] = nxt_uniq[i][l - 1] + nxt_uniq[nxt_meet[i][l - 1]][l - 1];
			}
		}
		int Q; cin >> Q;
		while (Q--) {
			int ql, qr; cin >> ql >> qr; ql--;
			int idx = ql;
			int uniq = 0;
			for (int l = L - 1; l >= 0; --l) {
				if (nxt_meet[idx][l] < qr) {
					uniq += nxt_uniq[idx][l];
					idx = nxt_meet[idx][l];
				}
			}
			if (idx == qr - 1) {
				uniq++;
				cout << uniq << '\n';
				continue;
			}
			int idx2 = idx + 1;
			uniq += 2;
			for (int l = L - 1; l >= 0; --l) {
				if (nxt[idx][l] < qr) {
					uniq += 1 << l;
					idx = nxt[idx][l];
				}
				if (nxt[idx2][l] < qr) {
					uniq += 1 << l;
					idx2 = nxt[idx2][l];
				}
			}
			cout << uniq << '\n';
		}
	}();
}

