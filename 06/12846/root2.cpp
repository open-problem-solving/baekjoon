#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG_10_4 14
#define LOG_10_5 17
#define LOG_10_6 20

#include <algorithm>

#define MAX_N 100005

int n;
int wage[MAX_N];

int segtree[1 << (LOG_10_5 + 1)];

int
wage_build_segtree (int node, int left, int right)
{
	if (left == right) {
		return segtree[node] = left;
	}

	int node_doubled = node << 1;
	int mid = (left + right) >> 1;

	int left_min_day = wage_build_segtree (node_doubled, left, mid);
	int right_min_day = wage_build_segtree (node_doubled + 1, mid + 1, right);

	return segtree[node] = (wage[left_min_day] < wage[right_min_day]) ? left_min_day : right_min_day;
}

int
wage_find_min_day (int node, int left, int right, int left_target, int right_target)
{
	if (right_target < left_target) {
		return -1;
	}
	else if (left == left_target && right == right_target) {
		return segtree[node];
	}

	int node_doubled = node << 1;
	int mid = (left + right) >> 1;

	int left_min_day =
		wage_find_min_day (node_doubled, left, mid, left_target, min (right_target, mid));
	int right_min_day =
		wage_find_min_day (node_doubled + 1, mid + 1, right, max (left_target, mid + 1), right_target);

	if (left_min_day == -1) {
		return right_min_day;
	}
	else if (right_min_day == -1) {
		return left_min_day;
	}
	else {
		return (wage[left_min_day] < wage[right_min_day]) ? left_min_day : right_min_day;
	}
}

long long
wage_find_max_wage (int left, int right)
{
	if (left == right) {
		return wage[left];
	}

	int min_day = wage_find_min_day (1, 1, n, left, right);

	if (min_day == -1) {
		return 0;
	}

	long long max_wage;

	max_wage = (long long) (right - left + 1) * wage[min_day];
	max_wage = max (max_wage, wage_find_max_wage (left, min_day - 1));
	max_wage = max (max_wage, wage_find_max_wage (min_day + 1, right));

	return max_wage;
}

void
solve (void)
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wage[i];
	}

	wage_build_segtree (1, 1, n);

	cout << wage_find_max_wage (1, n);
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
