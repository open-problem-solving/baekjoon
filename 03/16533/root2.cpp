#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int N;
	cin >> N;

	int prev_num, ans_cnt;
	cin >> prev_num;
	ans_cnt = 1;

	for (int i = 1; i < N; i++) {
		int curr_num;
		cin >> curr_num;

		if (prev_num < curr_num) {
			ans_cnt++;
		}
		prev_num = curr_num;
	}

	cout << ans_cnt;
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
