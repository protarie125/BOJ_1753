#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pair<int, int>>;
using Nbd = map<int, vii>;

constexpr auto inf = int{ 987'654'321 };

void dijk(int v, int e, int beg, Nbd& nbd) {
	auto dist = vi(v, inf);
	dist[beg - 1] = 0;

	auto q = priority_queue<pair<int, int>, vii, greater<pair<int, int>>>{};
	q.push({ 0, beg });

	while (!q.empty()) {
		auto f = q.top();
		q.pop();

		const auto& x = f.second;

		for (const auto& yw : nbd[x]) {
			const auto& y = yw.first;
			const auto& w = yw.second;
			const auto& newDist = dist[x - 1] + w;

			if (newDist < dist[y - 1]) {
				dist[y - 1] = newDist;
				q.push({ newDist, y });
			}
		}
	}

	for (const auto& d : dist) {
		if (inf != d) {
			cout << d << '\n';
		}
		else {
			cout << "INF\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int v, e;
	cin >> v >> e;

	int beg;
	cin >> beg;

	auto nbd = Nbd{};
	for (auto i = 1; i <= v; ++i) {
		nbd[i] = vii{};
	}

	for (auto i = 0; i < e; ++i) {
		int x, y, w;
		cin >> x >> y >> w;

		nbd[x].push_back({ y, w });
	}

	dijk(v, e, beg, nbd);

	return 0;
}