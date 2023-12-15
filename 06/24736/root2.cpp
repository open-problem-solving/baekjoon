#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int T, F, S, P, C;
	cin >> T >> F >> S >> P >> C;
	cout << (6 * T + 3 * F + 2 * S + 1 * P + 2 * C) << ' ';
	cin >> T >> F >> S >> P >> C;
	cout << (6 * T + 3 * F + 2 * S + 1 * P + 2 * C);
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
