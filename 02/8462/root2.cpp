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

#define MAX_N 100005
#define MAX_T 100005
#define MAX_A 1000006

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
struct query Q[MAX_T];

int val_cnt[MAX_A];
long long sum_power;

long long ans_query[MAX_T];

void
query_insert_value (int i)
{
	int val = a[i];

	int prev = val_cnt[val];
	sum_power -= (long long) prev * prev * val;

	val_cnt[val]++;

	int curr = prev + 1;
	sum_power += (long long) curr * curr * val;
}

void
query_erase_value (int i)
{
	int val = a[i];

	int prev = val_cnt[val];
	sum_power -= (long long) prev * prev * val;

	val_cnt[val]--;

	int curr = prev - 1;
	sum_power += (long long) curr * curr * val;
}

inline long long
query_find_power ()
{
	return sum_power;
}

void
solve (void)
{
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < t; i++) {
		int l, r;
		cin >> l >> r;
		Q[i] = { l, r, i };
	}

	sqrt_N = sqrt (n);
	sort (Q, Q + t);

	int left, right;
	left = Q[0].l;
	right = Q[0].r;

	for (int i = left; i <= right; i++) {
		query_insert_value (i);
	}
	ans_query[Q[0].idx] = query_find_power ();

	for (int i = 1; i < t; i++) {
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
		ans_query[Q[i].idx] = query_find_power ();
	}

	for (int i = 0; i < t; i++) {
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
