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
	int L_psum[MAX_N] = {0};

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int L_i;
		cin >> L_i;
		L_psum[i] += L_psum[i - 1] + L_i;
	}

	if ((L_psum[N] & 1) == 1) {
		cout << 'N';
		return;
	}

	int L_half_sum = L_psum[N] >> 1;
	int cnt_half_sum = 0;

	for (int i = 1; i <= N; i++) {
		int target_sum = L_psum[i] + L_half_sum;
		int result_sum = *lower_bound (L_psum + 1, L_psum + N + 1, target_sum);

		if (target_sum == result_sum) {
			cnt_half_sum++;
		}
	}

	cout << (1 < cnt_half_sum ? 'Y' : 'N');
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
