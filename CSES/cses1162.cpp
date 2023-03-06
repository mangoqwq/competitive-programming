#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
struct Fenwick{
    vector<T> v;
    Fenwick(int N){ v.resize(N+1); }
    void ins(int i, T val){
        for (++i; i < v.size(); i += i & -i) v[i] += val;
    }
    T qry(int i){
        T ret(0);
        for (++i; i; i -= i & -i) ret += v[i];
        return ret;
    }
    T qry(int l, int r){
        return qry(r) - qry(l - 1);
    }
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i){
		cin >> a[i];
		a[i]--;
	}

	ll ans1 = [&]() -> ll {
		Fenwick<int> bit(N);
		ll ans = 0;
		for (int i = 0; i < N; ++i){
			ans += bit.qry(a[i]+1, N-1);
			bit.ins(a[i], 1);
		}
		return ans;
	}();

	ll ans2 = [&]() -> ll {
		vector<int> vis(N);
		int ans = N;
		for (int i = 0; i < N; ++i){
			if (vis[i]) continue;
			int v = i;
			while (!vis[v]){
				vis[v] = 1;
				v = a[v];
			}
			ans--;
		}
		return ans;
	}();

	ll ans3 = [&]() -> ll {
		vector<int> dp(N+1);
		int ans = 0;
		dp[0] = -1e9;
		for (int i = 0; i < N; ++i){
			int idx = --upper_bound(dp.begin(), dp.begin() + ans + 1, a[i]) - dp.begin();
			if (idx == ans) ans++;
			dp[idx+1] = a[i];
		}
		return N-ans;
	}();

	ll ans4 = [&]() -> ll {
		vector<int> idx(N);
		for (int i = 0; i < N; ++i){
			idx[a[i]] = i;
		}
		for (int i = N-2; i >= 0; --i){
			if (idx[i] > idx[i+1]) return i+1;
		}
		return 0;
	}();

	cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << '\n';

}
