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
	int b, w;
	cin >> b >> w;

	int cnt_min, cnt_max;
	int color_start;
	cnt_min = min (b, w);
	cnt_max = max (b, w);
	color_start = (cnt_min == b) ? 1 : 0;

	char ans_tiles[5][5003] = {0};
	char color2symbol[] = ".@";
	int const color_max_start = 2 * (cnt_min - 1) + 1;

	for (int i = 0; i < cnt_min - 1; i++) {
		ans_tiles[0][2 * i] = ans_tiles[1][2 * i] = color2symbol[color_start];
		ans_tiles[0][2 * i + 1] = ans_tiles[1][2 * i + 1] = color2symbol[(color_start + 1) & 1];
	}
	for (int i = 2 * (cnt_min - 1); i < 5000; i++) {
		ans_tiles[0][i] = ans_tiles[1][i] = color2symbol[color_start];
	}
	for (int i = 0; i < cnt_max - cnt_min + 1; i++) {
		ans_tiles[0][color_max_start + 2 * i] = color2symbol[(color_start + 1) & 1];
	}

	cout << "2 5000\n";
	for (int i = 0; i < 2; i++) {
		cout << ans_tiles[i] << '\n';
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
