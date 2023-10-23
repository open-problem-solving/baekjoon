#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <math.h>
#include <vector>
#include <algorithm>

#define MAX_N 1000006
#define MAX_Q 1000006
#define MAX_VAL 1000006

int sqrt_N;

struct query {
	int l, r;
	int idx;

	bool operator< (struct query const &o) const {
		if ((l / sqrt_N) == (o.l / sqrt_N)) {
			return r < o.r;
		}
		else {
			return (l / sqrt_N) < (o.l / sqrt_N);
		}
	}
};

vector<long long> A;
vector<long long> tmp_A;
struct query query_list[MAX_Q];

int val_cnt[MAX_VAL];
int cnt_num;

int ans_query[MAX_Q];

void
query_insert_value (int val)
{
	if (val_cnt[val] == 0) {
		cnt_num++;
	}
	val_cnt[val]++;
}

void
query_erase_value (int val)
{
	val_cnt[val]--;
	if (val_cnt[val] == 0) {
		cnt_num--;
	}
}

void
solve (void)
{
	int N;
	cin >> N;
	sqrt_N = sqrt (N);
	A.resize (N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		query_list[i] = { l, r, i };
	}

	tmp_A = A;
	sort (tmp_A.begin () + 1, tmp_A.end ());
	tmp_A.erase (unique (tmp_A.begin () + 1, tmp_A.end ()), tmp_A.end ());
	for (int i = 1; i <= N; i++) {
		A[i] = lower_bound (tmp_A.begin () + 1, tmp_A.end (), A[i]) - (tmp_A.begin () + 1);
	}

	sort (query_list, query_list + Q);

	int left, right;
	left = query_list[0].l;
	right = query_list[0].r;

	for (int i = left; i <= right; i++) {
		query_insert_value (A[i]);
	}
	ans_query[query_list[0].idx] = cnt_num;

	for (int i = 1; i < Q; i++) {
		for (; left < query_list[i].l; left++) {
			query_erase_value (A[left]);
		}
		for (; query_list[i].l < left; left--) {
			query_insert_value (A[left - 1]);
		}
		for (; right < query_list[i].r; right++) {
			query_insert_value (A[right + 1]);
		}
		for (; query_list[i].r < right; right--) {
			query_erase_value (A[right]);
		}
		ans_query[query_list[i].idx] = cnt_num;
	}

	for (int i = 0; i < Q; i++) {
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
