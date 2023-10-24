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

vector<int> A;
vector<long long> tree;
vector<long long> lazy;

void
lazy_update (int node, int start, int end)
{
	if (lazy[node] == 0) {
		return;
	}

	tree[node] += (end - start + 1) * lazy[node];
	if (start != end) {
		int node_doubled = node << 1;
		lazy[node_doubled] += lazy[node];
		lazy[node_doubled + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void
tree_update_range (int node, int start, int end, int left, int right, int diff)
{
	lazy_update (node, start, end);

	if (end < left || right < start) {
		return;
	}

	int node_doubled = node << 1;

	if (left <= start && end <= right) {
		tree[node] += (end - start + 1) * diff;
		if (start != end) {
			lazy[node_doubled] += diff;
			lazy[node_doubled + 1] += diff;
		}
		return;
	}

	int middle = (start + end) >> 1;

	tree_update_range (node_doubled, start, middle, left, right, diff);
	tree_update_range (node_doubled + 1, middle + 1, end, left, right, diff);

	tree[node] = tree[node_doubled] + tree[node_doubled + 1];
}

long long
tree_sum_range (int node, int start, int end, int left, int right)
{
	lazy_update (node, start, end);

	if (end < left || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}

	int node_doubled = node << 1;
	int middle = (start + end) >> 1;

	long long left_child = tree_sum_range (node_doubled, start, middle, left, right);
	long long right_child = tree_sum_range (node_doubled + 1, middle + 1, end, left, right);

	return left_child + right_child;
}

void
solve (void)
{
	int N;
	cin >> N;
	A.resize (N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int degree = (int) ceil (log2 (N));
	int tree_size = 1 << (degree + 1);
	tree.resize (tree_size);
	lazy.resize (tree_size);

	int Q;
	int opt, a, b;
	cin >> Q;
	while (Q--) {
		cin >> opt;
		if (opt == 1) {
			cin >> a >> b;
			tree_update_range (1, 1, N, a, b, 1);
			tree_update_range (1, 1, N, b + 1, b + 1, -(b - a + 1));
		}
		else {
			cin >> a;
			cout << A[a] + tree_sum_range (1, 1, N, 1, a) << '\n';
		}
	}
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
