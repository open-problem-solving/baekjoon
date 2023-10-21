#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <math.h>

void
solve (void)
{
	int n;
	cin >> n;

	int left, right;
	left = right = 0;

	for (int i = 1; i <= n; i++) {
		int w;
		cin >> w;

		if (left == right) {
			left += w;
		}
		else if (left < right) {
			left += w;
		}
		else {
			right += w;
		}
	}

	int weight[] = { 100, 50, 20, 10, 5, 2, 1 };
	int diff = abs (left - right);
	int ans_cnt = 0;

	for (int i = 0; i < 7; i++) {
		ans_cnt += diff / weight[i];
		diff %= weight[i];
	}

	cout << ans_cnt;
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
