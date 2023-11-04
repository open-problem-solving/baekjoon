#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <algorithm>
#include <vector>
#include <math.h>

#define MAX_N 101010
#define MAX_M 101010
#define MAX_VAL 101010

int sqrt_N;

struct query {
	int l, r, k;
	int idx;

	bool operator < (struct query const &o) const {
		if ((l / sqrt_N) == (o.l / sqrt_N)) {
			return r < o.r;
		}
		else {
			return l < o.l;
		}
	}
};

void
fenwick_update_value (vector<long long> &tree, int idx, long long diff)
{
	int i = idx;
	while (i < tree.size ()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

long long
fenwick_sum_to_idx (vector<long long> &tree, int idx)
{
	int i = idx;
	long long sum = 0;
	while (0 < i) {
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}

long long
fenwick_sum_range (vector<long long> &tree, int left, int right)
{
	return fenwick_sum_to_idx (tree, right) - fenwick_sum_to_idx (tree, left - 1);
}

void
mos_insert_value (vector<long long> &tree, vector<long long> &arr, int idx)
{
	int val = arr[idx];
	fenwick_update_value (tree, val, 1);
}

void
mos_erase_value (vector<long long> &tree, vector<long long> &arr, int idx)
{
	int val = arr[idx];
	fenwick_update_value (tree, val, -1);
}

long long
mos_find_answer (vector<long long> &tree_A, vector<long long> &tree_B, int k)
{
	long long ret = 0;
	int sqrt_k = sqrt (k);

	for (int i = 1; i <= sqrt_k; i++) {
		ret += fenwick_sum_range (tree_A, i, i) * fenwick_sum_range (tree_B, 1, k / i);
		ret += fenwick_sum_range (tree_B, i, i) * fenwick_sum_range (tree_A, sqrt_k + 1, k / i);
	}

	return ret;
}

void
solve (void)
{
	int N;
	cin >> N;

	vector<long long> A (N + 1);
	vector<long long> B (N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
	}

	int M;
	cin >> M;

	vector<struct query> Q (M);
	for (int i = 0; i < M; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		Q[i] = { l, r, k, i };
	}

	sqrt_N = sqrt (N);
	sort (Q.begin (), Q.end ());

	vector<long long> tree_A (MAX_VAL);
	vector<long long> tree_B (MAX_VAL);
	vector<long long> ans_query (M);

	int left, right;
	left = Q[0].l;
	right = Q[0].r;

	for (int i = left; i <= right; i++) {
		mos_insert_value (tree_A, A, i);
		mos_insert_value (tree_B, B, i);
	}
	ans_query[Q[0].idx] = mos_find_answer (tree_A, tree_B, Q[0].k);

	for (int i = 1; i < M; i++) {
		for (; Q[i].l < left; left--) {
			mos_insert_value (tree_A, A, left - 1);
			mos_insert_value (tree_B, B, left - 1);
		}
		for (; right < Q[i].r; right++) {
			mos_insert_value (tree_A, A, right + 1);
			mos_insert_value (tree_B, B, right + 1);
		}
		for (; left < Q[i].l; left++) {
			mos_erase_value (tree_A, A, left);
			mos_erase_value (tree_B, B, left);
		}
		for (; Q[i].r < right; right--) {
			mos_erase_value (tree_A, A, right);
			mos_erase_value (tree_B, B, right);
		}
		ans_query[Q[i].idx] = mos_find_answer (tree_A, tree_B, Q[i].k);
	}

	for (int i = 0; i < M; i++) {
		cout << ans_query[i] << '\n';
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
