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
	int n;
	cin >> n;

	bool contain, divisible;
	contain = divisible = false;

	if (n % 7 == 0) {
		divisible = true;
	}

	while (n > 0) {
		if (n % 10 == 7) {
			contain = true;
			break;
		}
		n /= 10;
	}

	cout << (2 * contain + divisible);
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
