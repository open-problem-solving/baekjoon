#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int T;
	cin >> T;

	if (T % 10 != 0) {
		cout << -1;
		return;
	}

	int button_time[3] = { 5 * 60, 1 * 60, 10 };

	for (int i = 0; i < 3; i++) {
		cout << T / button_time[i] << ' ';
		T %= button_time[i];
	}
}

int
main (void)
{
	fastio;

	int T = 1;
	// cin >> T;
	while (T--)
		solve ();

	return 0;
}
