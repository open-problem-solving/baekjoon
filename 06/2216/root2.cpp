#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <algorithm>

#define MAX_LEN 3003

int A, B, C;
string X, Y;

int dp[MAX_LEN][MAX_LEN];

int
calc_max_score (int X_index, int Y_index)
{
	if (X_index == X.length () && Y_index == Y.length ()) {
		return 0;
	}
	else if (X_index == X.length () && Y_index < Y.length ()) {
		return B * (int) (Y.length () - Y_index);
	}
	else if (X_index < X.length () && Y_index == Y.length ()) {
		return B * (int) (X.length () - X_index);
	}

	int &ret = dp[X_index][Y_index];

	if (ret != 0xc0c0c0c0) {
		return ret;
	}

	ret = max (ret, (X[X_index] == Y[Y_index] ? A : C) + calc_max_score (X_index + 1, Y_index + 1));
	ret = max (ret, B + calc_max_score (X_index + 1, Y_index));
	ret = max (ret, B + calc_max_score (X_index, Y_index + 1));

	return ret;
}

void
solve (void)
{
	cin >> A >> B >> C;
	cin >> X >> Y;

	memset (dp, 0xc0, sizeof (dp));

	cout << calc_max_score (0, 0);
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
