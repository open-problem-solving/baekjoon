#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

void
solve (void)
{
	int U_R, T_R, U_O, T_O;
	cin >> U_R >> T_R >> U_O >> T_O;
	cout << (56 * U_R + 24 * T_R + 14 * U_O + 6 * T_O);
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
