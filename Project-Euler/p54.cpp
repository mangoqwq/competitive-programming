#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

template<std::ranges::forward_range R>
auto counts(R&& range) {
	using T = std::ranges::range_value_t<R>;
	map<T, int> freq;
	for (const auto &r : range) freq[r]++;
	vector<pair<T, int>> ret(freq.begin(), freq.end());
	// descending frequency
	ranges::sort(ret, [&](auto a, auto b) {
		return pair<int, T>{a.second, a.first} > pair<int, T>{b.second, b.first};
	});
	return ret;
}

struct Card { int rank; char suit; };
Card parse(string s) {
	Card ret;
	if (s[0] == 'T') ret.rank = 10;
	else if (s[0] == 'J') ret.rank = 11;
	else if (s[0] == 'Q') ret.rank = 12;
	else if (s[0] == 'K') ret.rank = 13;
	else if (s[0] == 'A') ret.rank = 14;
	else ret.rank = s[0] - '0';
	ret.suit = s[1];
	return ret;
}

enum Pokerhand {
	HIGH_CARD, PAIR, TWO_PAIR, TRIPLES, STRAIGHT, FLUSH, FULL_HOUSE, QUADS, STRAIGHT_FLUSH
};
Pokerhand classify(vector<Card> hand) {
	auto rank_range = hand | views::transform([&](Card c) { return c.rank; });
	vector<int> ranks(rank_range.begin(), rank_range.end());
	ranges::sort(ranks);
	auto freqs = counts(rank_range);

	auto suit_range = hand | views::transform([&](Card c) { return c.suit; });
	bool flush = (int)set<int>(suit_range.begin(), suit_range.end()).size() == 1;
	bool straight = 1;
	for (int i = 0; i < 4; ++i) straight &= ranks[i]+1 == ranks[i+1];

	if (straight && flush) return STRAIGHT_FLUSH;
	if (freqs[0].second == 4) return QUADS;
	if (freqs[0].second == 3 && freqs[1].second == 2) return FULL_HOUSE;
	if (flush) return FLUSH;
	if (straight) return STRAIGHT;
	if (freqs[0].second == 3) return TRIPLES;
	if (freqs[0].second == 2 && freqs[1].second == 2) return TWO_PAIR;
	if (freqs[0].second == 2) return PAIR;
	return HIGH_CARD;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int ans = 0;
	string line;
	while (getline(cin, line)) {
		istringstream iss(line);
		vector<Card> p1(5), p2(5);
		for (int i = 0; i < 5; ++i) {
			string card; iss >> card;
			p1[i] = parse(card);
		}
		for (int i = 0; i < 5; ++i) {
			string card; iss >> card;
			p2[i] = parse(card);
		}
		Pokerhand hand1 = classify(p1), hand2 = classify(p2);
		bool p1win = 0;
		if (hand1 > hand2) p1win = 1;
		else if (hand1 == hand2) {
			auto rank_range1 = p1 | views::transform([&](Card c) { return c.rank; });
			auto rank_range2 = p2 | views::transform([&](Card c) { return c.rank; });
			vector<int> ranks1(rank_range1.begin(), rank_range1.end());
			vector<int> ranks2(rank_range2.begin(), rank_range2.end());
			ranges::sort(ranks1); ranges::reverse(ranks1);
			ranges::sort(ranks2); ranges::reverse(ranks2);
			auto freqs1 = counts(rank_range1);
			auto freqs2 = counts(rank_range2);

			if (freqs1 > freqs2) p1win = 1;
		}
		ans += p1win;
	}
	cout << ans << '\n';
}
