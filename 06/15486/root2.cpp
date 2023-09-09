#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

#define MAX_N 1500005

struct consult {
	int T, P;
};

struct consult day2consult[MAX_N];
int profit_sum[MAX_N] = {0};

void
solve (void)
{
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> day2consult[i].T >> day2consult[i].P;
	}

	for (int i = N; i >= 1; i--) {
		int day_consult_end = i + day2consult[i].T - 1;

		if (N < day_consult_end)
			profit_sum[i] = profit_sum[i + 1];
		else
			profit_sum[i] = max (profit_sum[i + 1],
					profit_sum[day_consult_end + 1] + day2consult[i].P);
	}

	cout << profit_sum[1];
}

int
main (void)
{
	fastio;

	int T = 1;
	// cin >> T;
	while (T--)
		solve ();

	return 0;
}
