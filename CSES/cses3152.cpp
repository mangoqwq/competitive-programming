#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

template <typename T>
struct Fenwick {
	std::vector<T> v;
	Fenwick(int N) { v.resize(N + 1); }
	void ins(int i, T val) {
		for (++i; i < (int)v.size(); i += i & -i) v[i] += val;
	}
	T qry(int i) {
		T ret(0);
		for (++i; i; i -= i & -i) ret += v[i];
		return ret;
	}
	T qry(int l, int r) { return qry(r - 1) - qry(l - 1); }
};

struct Node {
	Node *l = 0, *r = 0;
	int val, y, c = 1;
	Node(int val) : val(val), y(rand()) {}
	void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; }

template<class F> void each(Node* n, F f) {
	if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int k) {
	if (!n) return {};
	if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
		auto pa = split(n->l, k);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split(n->r, k - cnt(n->l) - 1); // and just "k"
		n->r = pa.first;
		n->recalc();
		return {n, pa.second};
	}
}

Node* merge(Node* l, Node* r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y > r->y) {
		l->r = merge(l->r, r);
		l->recalc();
		return l;
	} else {
		r->l = merge(l, r->l);
		r->recalc();
		return r;
	}
}

Node* ins(Node* t, Node* n, int pos) {
	auto pa = split(t, pos);
	return merge(merge(pa.first, n), pa.second);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<int> ord(N);
	iota(ord.begin(), ord.end(), 0);
	ranges::sort(ord, [&](int i, int j) {
		return tie(a[i], i) > tie(a[j], j);
	});
	Fenwick<int> bit(N);
	vector<int> mov(N);
	vector<vector<int>> elems(N);
	for (int i : ord) {
		mov[i] = min(K, bit.qry(0, i));
		bit.ins(i, 1);
	}

	Node* rt = 0;
	for (int i = 0; i < N; ++i) {
		rt = ins(rt, new Node(a[i]), i - mov[i]);
	}

	vector<int> ans;
	each(rt, [&](int x) { ans.push_back(x); });
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << (i == N - 1 ? '\n' : ' ');
	}
}
