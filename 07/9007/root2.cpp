#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <vector>
#include <algorithm>
#include <math.h>

int
find_closest_sum (int target, int opt_sum, int new_sum)
{
	int opt_diff = target - opt_sum;
	int new_diff = target - new_sum;

	if (abs (opt_diff) < abs (new_diff)) {
		return opt_sum;
	}
	else if (abs (opt_diff) == abs (new_diff)) {
		return min (opt_sum, new_sum);
	}

	return new_sum;
}

void
solve (void)
{
	int k, n;
	vector<int> class2weight[5];

	cin >> k >> n;
	for (int c = 1; c <= 4; c++) {
		class2weight[c].resize (n);
		for (int i = 0; i < n; i++) {
			cin >> class2weight[c][i];
		}
	}

	vector<int> sum_class_12;
	vector<int> sum_class_34;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum_class_12.push_back (class2weight[1][i] + class2weight[2][j]);
			sum_class_34.push_back (class2weight[3][i] + class2weight[4][j]);
		}
	}

	sort (sum_class_12.begin (), sum_class_12.end ());
	sort (sum_class_34.begin (), sum_class_34.end ());

	int ans_optimal = sum_class_12[0] + sum_class_34[0];
	int target, idx;

	for (int class_12 : sum_class_12) {
		target = k - class_12;
		idx = lower_bound (sum_class_34.begin (), sum_class_34.end (), target) - sum_class_34.begin ();

		if (idx != sum_class_34.size ()) {
			ans_optimal = find_closest_sum (k, ans_optimal, class_12 + sum_class_34[idx]);
		}
		if (idx != 0) {
			ans_optimal = find_closest_sum (k, ans_optimal, class_12 + sum_class_34[idx - 1]);
		}
	}

	cout << ans_optimal << '\n';
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
