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

#define MAX_N 300005
#define MAX_C 10004
#define MAX_M 10004

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

int cap_color[MAX_N];
struct query Q[MAX_M];

int cap_cnt[MAX_C];

int ans_query[MAX_M];

void
query_insert_value (int i)
{
	int cap = cap_color[i];
	cap_cnt[cap]++;
}

void
query_erase_value (int i)
{
	int cap = cap_color[i];
	cap_cnt[cap]--;
}

int
query_find_pretty_cap (int C, int K)
{
	int half = K >> 1;
	int cumul_sum = 0;

	for (int i = 1; i <= C; i++) {
		if (half < cap_cnt[i]) {
			return i;
		}
		else {
			cumul_sum += cap_cnt[i];
		}

		if (half < cumul_sum) {
			return -1;
		}
	}

	return -1;
}

void
solve (void)
{
	int N, C;
	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		cin >> cap_color[i];
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		Q[i] = { A, B, i };
	}

	sqrt_N = sqrt (N);
	sort (Q, Q + M);

	int left, right;
	left = Q[0].l;
	right = Q[0].r;

	for (int i = left; i <= right; i++) {
		query_insert_value (i);
	}
	ans_query[Q[0].idx] = query_find_pretty_cap (C, right - left + 1);

	for (int i = 1; i < M; i++) {
		for (; Q[i].l < left; left--) {
			query_insert_value (left - 1);
		}
		for (; right < Q[i].r; right++) {
			query_insert_value (right + 1);
		}
		for (; left < Q[i].l; left++) {
			query_erase_value (left);
		}
		for (; Q[i].r < right; right--) {
			query_erase_value (right);
		}
		ans_query[Q[i].idx] = query_find_pretty_cap (C, right - left + 1);
	}

	for (int i = 0; i < M; i++) {
		if (ans_query[i] != -1) {
			cout << "yes " << ans_query[i] << '\n';
		}
		else {
			cout << "no\n";
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
