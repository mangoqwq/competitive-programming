#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
consider same problem with n As, 1 B, and 2 blank spaces

if last two spaces not blank, make them blank, can always do within 2 steps
XXXXXXXX.. done
XXXXXXX..X -> ..XXXXXXXX -> XXXXXXXX.. done
XXXXXX..XX -> XXXXXXXX.. done

if B is not first, move B to the end

if B is first, consider three cases
n = 1:
BA.., impossible

n = 2:
BAA.., also impossible

n >= 3:
BAAAAA.. -> ..AAAABA -> AA..AABA -> AABAAA.. -> AAA..AAB done

for the original problem, treat all but n-1 B's as A's, then
move the single B left to the end, and repeat

watch out for the extra cases for 4 and 6 boxes, probably safer to just run bfs on those
*/
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	string s; cin >> s;

	vector<string> ans;
	auto loc = [&](char c) {
		return find(s.begin(), s.end(), c) - s.begin();
	};
	auto mov = [&](int i) {
		int j = loc('.');
		swap(s[i], s[j]);
		swap(s[i+1], s[j+1]);
		ans.push_back(s);
		debug(s);
	};

	int num = 0;
	for (int it = 2*N-1; it >= 2*N-(N-1); --it) {
		num++;
		if (s[it] == 'B') {
			num++;
			continue;
		}
		int i = loc('.');
		if (i == it-2) {
			mov(0); mov(it-1);
		}
		else if (i < it-2) {
			mov(it-1);
		}

		i = loc('B');
		if (i == 0) {
			if (N-1+(N-1)-num <= 2) {
				cout << -1 << '\n';
				return 0;
			}
			mov(0);
			mov(2);
			mov(it-1);
			mov(1);
		}
		else {
			mov(i-1);
		}
	}
	cout << ans.size() << '\n';
	for (string s : ans) {
		cout << s << '\n';
	}
}
