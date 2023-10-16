#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <algorithm>

void
solve (void)
{
	double h, w;
	cin >> h >> w;

	if (w < h) {
		int tmp = w;
		w = h;
		h = tmp;
	}

	double ans_max_length = max (h / 2,
			min (w / 3, h));

	printf ("%.3lf", ans_max_length);
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
