#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

struct problem_frame {
	int N;
	int A[20];
	int operator_cnt[5];

	int ans_min;
	int ans_max;
};

void
ans_find_min_max (struct problem_frame *pf, int curr_value, int index)
{
	if (pf->N < index) {
		pf->ans_min = min (pf->ans_min, curr_value);
		pf->ans_max = max (pf->ans_max, curr_value);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (pf->operator_cnt[i] <= 0)
			continue;

		pf->operator_cnt[i]--;
		if (i == 0)
			ans_find_min_max (pf, curr_value + pf->A[index], index + 1);
		else if (i == 1)
			ans_find_min_max (pf, curr_value - pf->A[index], index + 1);
		else if (i == 2)
			ans_find_min_max (pf, curr_value * pf->A[index], index + 1);
		else if (i == 3)
			ans_find_min_max (pf, curr_value / pf->A[index], index + 1);
		pf->operator_cnt[i]++;
	}
}

void
solve (void)
{
	struct problem_frame pf;
	cin >> pf.N;
	for (int i = 1; i <= pf.N; i++) 
		cin >> pf.A[i];
	for (int i = 0; i < 4; i++)
		cin >> pf.operator_cnt[i];

	pf.ans_min = INT32_INF;
	pf.ans_max = -INT32_INF;
	ans_find_min_max (&pf, pf.A[1], 2);

	cout << pf.ans_max << '\n' << pf.ans_min;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
