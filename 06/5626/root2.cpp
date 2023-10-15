#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

#define MAX_N 10004
#define MAX_HEIGHT 5003
#define MODULO 1000000007

long long dp[2][MAX_HEIGHT];

void
solve (void)
{
	int N;
	cin >> N;

	int h[MAX_N] = {0};
	for (int i = 0; i < N; i++) {
		cin >> h[i];

		if (min (i, N - 1 - i) < h[i]) {
			cout << '0';
			return;
		}
	}

	dp[0][0] = 1;

	for (int i = 1; i < N; i++) {
		int dp_curr = i & 1;
		int dp_prev = (i + 1) & 1;

		for (int j = 0; j < (N >> 1); j++) {
			dp[dp_curr][j] = 0;
		}

		if (h[i] == -1) {
			for (int j = 0; j <= min (i, N - 1 - i); j++) {
				dp[dp_curr][j] = dp[dp_prev][j] + dp[dp_prev][j + 1];
				if (j > 0) {
					dp[dp_curr][j] += dp[dp_prev][j - 1];
				}
				dp[dp_curr][j] %= MODULO;
			}
		}
		else {
			int h_target = h[i];
			dp[dp_curr][h_target] = dp[dp_prev][h_target] + dp[dp_prev][h_target + 1];
			if (h_target > 0) {
				dp[dp_curr][h_target] += dp[dp_prev][h_target - 1];
			}
			dp[dp_curr][h_target] %= MODULO;
		}
	}

	cout << dp[(N - 1) & 1][0];
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
