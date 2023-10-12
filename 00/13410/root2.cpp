#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <algorithm>

void
solve (void)
{
	int N, K;
	cin >> N >> K;

	int ans_max = 0;

	for (int i = 1; i <= K; i++) {
		int val = N * i;
		string val_str = to_string (val);

		reverse (val_str.begin (), val_str.end ());
		int reverse_val = stoi (val_str);

		ans_max = max (ans_max, reverse_val);
	}

	cout << ans_max;
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
