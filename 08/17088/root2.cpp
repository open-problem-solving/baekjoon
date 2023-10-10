#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>
#include <math.h>

#define MAX_N 100005

int
transform_count (int diff, int seq_len, int seq_start, int seq[MAX_N])
{
	int next_val = seq_start;
	int ret_cnt = 0;

	for (int i = 1; i <= seq_len; i++) {
		if (seq[i] - next_val == 0) {
			next_val += diff;
		}
		else if (abs (seq[i] - next_val) == 1) {
			ret_cnt++;
			next_val += diff;
		}
		else {
			return INT32_INF;
		}
	}

	return ret_cnt;
}

void
solve (void)
{
	int N;
	int B[MAX_N] = {0};

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
	}

	int operation[] = { -1, 0, 1 };
	int ans_min_cnt = INT32_INF;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ans_min_cnt = min (ans_min_cnt,
					transform_count ((B[2] + operation[j]) - (B[1] + operation[i]), N, B[1] + operation[i], B));
		}
	}

	cout << (ans_min_cnt != INT32_INF ? ans_min_cnt : -1);
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
