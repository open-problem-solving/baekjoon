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
	int time[2] = { 0 };
	int type2min[] = { 3, 20, 120 };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp;
			cin >> tmp;
			time[i] += type2min[j] * tmp;
		}
	}

	string ans = "";
	if (time[0] == time[1]) {
		ans = "Draw";
	}
	else if (time[0] < time[1]) {
		ans = "Mel";
	}
	else {
		ans = "Max";
	}
	cout << ans;
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
