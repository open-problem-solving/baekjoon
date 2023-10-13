#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define MAX_N 100005

void
solve (void)
{
	int N;
	cin >> N;

	int docs2interview[MAX_N] = {0};

	for (int i = 0; i < N; i++) {
		int docs, interview;
		cin >> docs >> interview;

		docs2interview[docs] = interview;
	}

	int ans_cnt = 1;
	int interview_min = docs2interview[1];

	for (int i = 2; i <= N; i++) {
		if (docs2interview[i] < interview_min) {
			ans_cnt++;
			interview_min = docs2interview[i];
		}
	}

	cout << ans_cnt << '\n';
}

int
main (void)
{
	fastio;

	int T = 1;
	cin >> T;
	while (T--) {
		solve ();
	}

	return 0;
}
