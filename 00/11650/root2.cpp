#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <vector>
#include <algorithm>

struct coord {
	int x, y;

	bool operator< (struct coord const &o) const {
		if (x == o.x) {
			return y < o.y;
		}
		else {
			return x < o.x;
		}
	}
};

void
solve (void)
{
	int N;
	cin >> N;

	vector<struct coord> coord_list (N);

	for (int i = 0; i < N; i++) {
		cin >> coord_list[i].x >> coord_list[i].y;
	}

	sort (coord_list.begin (), coord_list.end ());

	for (struct coord c : coord_list) {
		cout << c.x << ' ' << c.y << '\n';
	}
}

int
main (void)
{
	fastio;

	int T = 1;
	// cin >> T;
	while (T--) {
		solve ();
	}

	return 0;
}
