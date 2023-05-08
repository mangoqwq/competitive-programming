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
	char a[] = {'N', 'E', 'S', 'W'};
	char c; cin >> c;
	int init = 0;
	for (; init < 4; ++init){
		if (c == a[init]) break;
	}
	int L; cin >> L;
	int R; cin >> R;
	int dir = (init - L + R) % 4;
	dir = (dir + 4) % 4;
	cout << a[dir] << '\n';
}
