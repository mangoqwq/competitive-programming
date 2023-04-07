#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	for (char c : s){
		if (c == '0') cout << '1';
		else cout << '0';
	}
	cout << '\n';
}
