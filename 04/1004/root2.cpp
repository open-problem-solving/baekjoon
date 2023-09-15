#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define SQUARE(x) ((x) * (x))

struct coord {
	int x, y;
};

bool
point_within_system (struct coord p, struct coord s, int r)
{
	double dist_points = SQUARE (p.x - s.x) + SQUARE (p.y - s.y);
	return dist_points <= (double) r * r;
}

void
solve (void)
{
	struct coord src, dst;
	cin >> src.x >> src.y >> dst.x >> dst.y;

	int n;
	cin >> n;

	int ans_cnt = 0;

	for (int i = 0; i < n; i++) {
		struct coord planet_system;
		int radius;
		cin >> planet_system.x >> planet_system.y >> radius;

		if (point_within_system (src, planet_system, radius) ^ point_within_system (dst, planet_system, radius))
			ans_cnt++;
	}

	cout << ans_cnt << '\n';
}

int
main (void)
{
	fastio;

	int T = 1;
	cin >> T;
	while (T--)
		solve ();

	return 0;
}
