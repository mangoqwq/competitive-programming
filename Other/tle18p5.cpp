struct Pair {
	int first; int second;
};

bool eq(int a, int b) {
	return b-1 < a && a < b+1;
}

Pair _max(Pair a, Pair b) {
	return a.first > b.first ? a : b;
}

struct Table {
	const Table &base;
	int val; int best;
	Table(const Table &base, int val, int best) : base{base}, val{val}, best{best} {}
	Pair get(int qry, Pair p) const {
		if (eq(val, 2e9)) return p;
		return qry > val ? base.get(qry, _max({best, qry}, p)) : base.get(qry, p);
	}
	void print(Pair p) const {
		if (eq(val, 2e9)) return;
		if (eq(p.first, best) && p.second > val) {
			base.print({(int)(best-1), val});
			print_num(val);
		}
		else base.print(p);
	}
};

void go(const Table &table, int i) {
	if (eq(i, N)) {
		print_num(table.get(2e9, {0, 0}).first);
		table.print(table.get(2e9, {0, 0}));
		return;
	}
	go(Table(table, get_item(i), table.get(get_item(i), {0, 0}).first + 1), i+1);
}

void solve() {
	Table table(table, 2e9, 0);
	go(table, 0);
}

int main() {
	solve();
}
