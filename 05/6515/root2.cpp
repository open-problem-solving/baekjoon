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
#include <string.h>

#define MAX_N 101010
#define MAX_Q 101010
#define MAX_VAL 101010

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

int a[MAX_N];
struct query Q[MAX_Q];

int val_cnt[MAX_VAL << 1];
int max_cnt[MAX_N];
int max_ptr;

int ans_query[MAX_Q];

void
query_insert_value (int i)
{
	int val = a[i];

	max_cnt[val_cnt[val]]--;
	val_cnt[val]++;
	max_cnt[val_cnt[val]]++;
	max_ptr = max (max_ptr, val_cnt[val]);
}

void
query_erase_value (int i)
{
	int val = a[i];

	max_cnt[val_cnt[val]]--;
	if (val_cnt[val] == max_ptr
			&& max_cnt[val_cnt[val]] == 0) {
		max_ptr--;
	}
	val_cnt[val]--;
	max_cnt[val_cnt[val]]++;
}

int
query_find_answer ()
{
	return max_ptr;
}

void
solve (void)
{
	while (true) {
		memset (a, 0, sizeof (a));
		memset (Q, 0, sizeof (Q));
		memset (val_cnt, 0, sizeof (val_cnt));
		memset (max_cnt, 0, sizeof (max_cnt));
		max_ptr = 0;

		int n, q;
		cin >> n;
		if (n == 0) {
			break;
		}
		else {
			cin >> q;
		}

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] += MAX_VAL;
		}
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			Q[i] = { l, r, i };
		}

		sqrt_N = sqrt (n);
		sort (Q, Q + q);

		int left, right;
		left = Q[0].l;
		right = Q[0].r;

		for (int i = left; i <= right; i++) {
			query_insert_value (i);
		}
		ans_query[Q[0].idx] = query_find_answer ();

		for (int i = 1; i < q; i++) {
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
			ans_query[Q[i].idx] = query_find_answer ();
		}

		for (int i = 0; i < q; i++) {
			cout << ans_query[i] << '\n';
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
