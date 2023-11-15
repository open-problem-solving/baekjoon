#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <vector>
#include <math.h>

long long
seg_sum_range (vector<long long> &tree, int node, int start, int end, int left, int right)
{
	if (end < left || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}

	int node_doubled = node << 1;
	int middle = (start + end) >> 1;

	long long left_child = seg_sum_range (tree, node_doubled, start, middle, left, right);
	long long right_child = seg_sum_range (tree, node_doubled + 1, middle + 1, end, left, right);

	return left_child + right_child;
}

void
seg_update_value (vector<long long> &tree, int node, int start, int end, int idx, long long diff)
{
	if (end < idx || idx < start) {
		return;
	}

	tree[node] += diff;

	if (start == end) {
		return;
	}

	int node_doubled = node << 1;
	int middle = (start + end) >> 1;

	seg_update_value (tree, node_doubled, start, middle, idx, diff);
	seg_update_value (tree, node_doubled + 1, middle + 1, end, idx, diff);
}

void
solve (void)
{
	int n;
	cin >> n;

	vector<long long> perm_one (n + 1);
	vector<long long> value2idx (n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> perm_one[i];
	}
	for (int i = 1; i <= n; i++) {
		long long perm;
		cin >> perm;
		value2idx[perm] = i;
	}

	int degree = (int) ceil (log2 (n));
	int tree_size = 1 << (degree + 1);
	vector<long long> tree (tree_size);

	long long ans_cnt = 0;

	for (int i = 1; i <= n; i++) {
		ans_cnt += seg_sum_range (tree, 1, 1, n, value2idx[perm_one[i]] + 1, n);
		seg_update_value (tree, 1, 1, n, value2idx[perm_one[i]], 1);
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
