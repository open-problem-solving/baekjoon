#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>

void
solve (void)
{
	while (true) {
		string line;
		getline (cin, line);

		if (line[0] == '#') {
			break;
		}

		char letter = line[0];
		int ans_cnt = 0;

		for (int i = 2; i < line.length (); i++) {
			if (letter == line[i]) {
				ans_cnt++;
			}
			else if (letter == line[i] + 0x20) {
				ans_cnt++;
			}
		}

		cout << letter << ' ' << ans_cnt << '\n';
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
