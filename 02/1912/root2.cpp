#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

void
solve (void)
{
	int n;
	cin >> n;

	int prev_max = -INT32_INF;
	int ans_max = -INT32_INF;

	for (int i = 0; i < n; i++) {
		int seq_i;
		cin >> seq_i;

		prev_max = max (prev_max + seq_i, seq_i);
		ans_max = max (ans_max, prev_max);
	}

	cout << ans_max;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
