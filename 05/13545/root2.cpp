#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <algorithm>
#include <math.h>
#include <list>

#define MAX_N 100005
#define MAX_M 100005
#define SQRT_MAX_2N 500

#define MIN_CUMUL -100000

#define LEFT 0
#define RIGHT 1

int sqrt_N;

struct query {
	int l, r;
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

int cumul_A[MAX_N];
struct query Q[MAX_M];

list<int> val_dq[MAX_N << 1];
int dist_cnt[MAX_N << 1];
int sqrt_dist_cnt[SQRT_MAX_2N];

int ans_query[MAX_M];

void
query_insert_value (int i, int d)
{
	int val = cumul_A[i];
	list<int> &dq = val_dq[val];

	if (!dq.empty ()) {
		int prev = dq.back () - dq.front ();
		dist_cnt[prev]--;
		sqrt_dist_cnt[prev / sqrt_N]--;
	}

	if ((d & 1) == 0) {
		dq.push_front (i);
	}
	else {
		dq.push_back (i);
	}

	int curr = dq.back () - dq.front ();
	dist_cnt[curr]++;
	sqrt_dist_cnt[curr / sqrt_N]++;
}

void
query_erase_value (int i, int d)
{
	int val = cumul_A[i];
	list<int> &dq = val_dq[val];

	int curr = dq.back () - dq.front ();
	dist_cnt[curr]--;
	sqrt_dist_cnt[curr / sqrt_N]--;

	if ((d & 1) == 0) {
		dq.pop_front ();
	}
	else {
		dq.pop_back ();
	}

	if (!dq.empty ()) {
		int prev = dq.back () - dq.front ();
		dist_cnt[prev]++;
		sqrt_dist_cnt[prev / sqrt_N]++;
	}
}

int
query_find_answer ()
{
	for (int i = SQRT_MAX_2N - 1; i >= 0; i--) {
		if (sqrt_dist_cnt[i] == 0) {
			continue;
		}

		for (int j = (i + 1) * sqrt_N; ; j--) {
			if (dist_cnt[j] > 0) {
				return j;
			}
		}
	}

	return 0;
}

void
solve (void)
{
	int N;
	cin >> N;
	cumul_A[0] = -MIN_CUMUL;
	for (int i = 1; i <= N; i++) {
		int A_i;
		cin >> A_i;
		cumul_A[i] = cumul_A[i - 1] + A_i;
	}

	int M;
	cin >> M;
	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;
		Q[k] = { i - 1, j, k };
	}

	sqrt_N = sqrt (N);
	sort (Q, Q + M);

	int left, right;
	left = Q[0].l;
	right = Q[0].r;

	for (int i = left; i <= right; i++) {
		query_insert_value (i, RIGHT);
	}
	ans_query[Q[0].idx] = query_find_answer ();

	for (int i = 1; i < M; i++) {
		for (; Q[i].l < left; left--) {
			query_insert_value (left - 1, LEFT);
		}
		for (; right < Q[i].r; right++) {
			query_insert_value (right + 1, RIGHT);
		}
		for (; left < Q[i].l; left++) {
			query_erase_value (left, LEFT);
		}
		for (; Q[i].r < right; right--) {
			query_erase_value (right, RIGHT);
		}
		ans_query[Q[i].idx] = query_find_answer ();
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
