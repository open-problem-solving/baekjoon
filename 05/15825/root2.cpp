#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <math.h>
#include <limits>

inline int
div_ceiling_to_int (int a, int b)
{
	return ((a / b) + (a % b ? 1 : 0));
}

void
solve (void)
{
	int N;
	cin >> N;

	vector<int> F (N);
	int T;

	for (int i = 0; i < N; i++) {
		cin >> F[i];
	}
	cin >> T;

	vector<long long> K2cnt (5e5 + 1, 0);
	int f, sqrt_f;
	int calc_k;

	for (int i = 0; i < N; i++) {
		f = F[i];
		sqrt_f = (int) ceil (sqrt (f));

		for (int j = 1; j <= sqrt_f; j++) {
			calc_k = div_ceiling_to_int (f, j);
			if (calc_k <= sqrt_f) {
				K2cnt[calc_k] += (div_ceiling_to_int (f, calc_k - 1) - div_ceiling_to_int (f, calc_k));
			}
			else {
				K2cnt[calc_k]++;
			}
		}
		for (int j = calc_k - 1; j > 1; j--) {
			K2cnt[j] += (div_ceiling_to_int (f, j - 1) - div_ceiling_to_int (f, j));
		}
		K2cnt[1]++;
	}

	long long ans_min_time = numeric_limits<long long>::max(), time;
	int ans_k;
	long long cumul_cnt = N;

	for (int k = 5e5; k > 0; k--) {
		if (K2cnt[k] == 0) {
			continue;
		}

		time = cumul_cnt * (T + k);
		if (time <= ans_min_time) {
			ans_min_time = time;
			ans_k = k;
		}

		cumul_cnt += K2cnt[k];
	}

	cout << ans_min_time << ' ' << ans_k;
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
