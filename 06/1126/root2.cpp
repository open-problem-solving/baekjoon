#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <algorithm>
#include <math.h>

#define MAX_DIFF 250000

void
solve (void)
{
	int N;
	cin >> N;

	int cnt_dp[2][MAX_DIFF + 1] = {0};
	int prev = 1, curr;
	int height;

	memset (cnt_dp[prev], -1, (MAX_DIFF + 1) * sizeof (int));
	cnt_dp[prev][0] = 0;

	while (N--) {
		cin >> height;
		curr = prev ^ 1;

		memset (cnt_dp[curr], -1, (MAX_DIFF + 1) * sizeof (int));

		for (int d = 0; d <= MAX_DIFF; d++) {
			int prev_height = cnt_dp[prev][d];

			if (prev_height < 0) {
				continue;
			}

			int diff_one, diff_two;
			diff_one = d + height;
			diff_two = abs (d - height);

			cnt_dp[curr][d] = max (cnt_dp[curr][d], prev_height);
			if (diff_one <= MAX_DIFF) {
				cnt_dp[curr][diff_one] = max (cnt_dp[curr][diff_one], prev_height + height);
			}
			if (diff_two <= MAX_DIFF) {
				cnt_dp[curr][diff_two] = max (cnt_dp[curr][diff_two],
						prev_height + (d < height ? diff_two : 0));
			}
		}
		
		prev = curr;
	}

	if (cnt_dp[curr][0] > 0) {
		cout << cnt_dp[curr][0];
	}
	else {
		cout << -1;
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
