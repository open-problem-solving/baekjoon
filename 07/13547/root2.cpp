#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <math.h>
#include <algorithm>

#define MAX_N 100005
#define MAX_VAL 1000006
#define MAX_M 100005

int sqrt_N;

struct query {
	int i, j;
	int idx;

	bool operator < (struct query const &o) const {
		if ((i / sqrt_N) == (o.i / sqrt_N)) {
			return j < o.j;
		}
		else {
			return (i / sqrt_N) < (o.i / sqrt_N);
		}
	}
};

int A[MAX_N];
struct query Q[MAX_M];

int val_cnt[MAX_VAL];
int cnt_num;

int ans_query[MAX_M];

void
query_insert_value (int v)
{
	if (val_cnt[v] == 0) {
		cnt_num++;
	}
	val_cnt[v]++;
}

void
query_erase_value (int v)
{
	val_cnt[v]--;
	if (val_cnt[v] == 0) {
		cnt_num--;
	}
}

void
solve (void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int M;
	cin >> M;
	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;
		Q[k] = { i, j, k };
	}

	sqrt_N = sqrt (N);
	sort (Q, Q + M);

	int left, right;
	left = Q[0].i;
	right = Q[0].j;

	for (int i = left; i <= right; i++) {
		query_insert_value (A[i]);
	}
	ans_query[Q[0].idx] = cnt_num;

	for (int i = 1; i < M; i++) {
		for (; left < Q[i].i; left++) {
			query_erase_value (A[left]);
		}
		for (; Q[i].i < left; left--) {
			query_insert_value (A[left - 1]);
		}
		for (; right < Q[i].j; right++) {
			query_insert_value (A[right + 1]);
		}
		for (; Q[i].j < right; right--) {
			query_erase_value (A[right]);
		}
		ans_query[Q[i].idx] = cnt_num;
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
