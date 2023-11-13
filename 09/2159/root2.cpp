#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <algorithm>
#include <math.h>
#include <string.h>

struct coord {
	int x, y;

	struct coord operator+ (struct coord const &o) const {
		return { x + o.x, y + o.y };
	}
};

inline int
calc_dist_two_point (struct coord a, struct coord b)
{
	return abs (a.x - b.x) + abs (a.y - b.y);
}

void
solve (void)
{
	int N;
	cin >> N;

	struct coord bona;
	cin >> bona.x >> bona.y;

	struct coord pos[2] = { bona };
	long long min_dist[2][5] = { { 0, 1, 1, 1, 1 }, { 0 } };
	struct coord delta[] = { { 0, 0 }, { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
	
	for (int i = 1; i <= N; i++) {
		int prev = (i + 1) & 1;
		int curr = i & 1;

		cin >> pos[curr].x >> pos[curr].y;

		memset (min_dist[curr], 0x3f, sizeof (min_dist[curr]));

		for (int curr_d = 0; curr_d < 5; curr_d++) {
			for (int prev_d = 0; prev_d < 5; prev_d++) {
				long long dist = calc_dist_two_point (pos[prev] + delta[prev_d], pos[curr] + delta[curr_d]);
				min_dist[curr][curr_d] = min (min_dist[curr][curr_d], min_dist[prev][prev_d] + dist);
			}
		}
	}

	long long ans_min_dist = INT64_INF;
	for (int i = 0; i < 5; i++) {
		ans_min_dist = min (ans_min_dist, min_dist[N & 1][i]);
	}
	cout << ans_min_dist;
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
