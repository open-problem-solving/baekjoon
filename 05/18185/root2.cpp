#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define MAX_N 10004

void
solve (void)
{
	int N;
	int A[MAX_N] = {0};

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int ans_min_cost = 0;

	for (int i = 1; i <= N; i++) {
		if (A[i + 1] > A[i + 2]) {
			int cnt_two = A[i + 1] - A[i + 2];
			cnt_two = min (cnt_two, A[i]);
			A[i] -= cnt_two;
			A[i + 1] -= cnt_two;
			ans_min_cost += cnt_two * 5;

			int cnt_three = min (A[i], A[i + 1]);
			cnt_three = min (cnt_three, A[i + 2]);
			A[i] -= cnt_three;
			A[i + 1] -= cnt_three;
			A[i + 2] -= cnt_three;
			ans_min_cost += cnt_three * 7;
		}
		else {
			int cnt_three = min (A[i], A[i + 1]);
			A[i] -= cnt_three;
			A[i + 1] -= cnt_three;
			A[i + 2] -= cnt_three;
			ans_min_cost += cnt_three * 7;
		}

		int cnt_one = A[i];
		A[i] -= cnt_one;
		ans_min_cost += cnt_one * 3;
	}

	cout << ans_min_cost;
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
