#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <set>
#include <string.h>

void
solve (void)
{
	set<string> promise_set {
		"Never gonna give you up",
		"Never gonna let you down",
		"Never gonna run around and desert you",
		"Never gonna make you cry",
		"Never gonna say goodbye",
		"Never gonna tell a lie and hurt you",
		"Never gonna stop" };

	int N;
	cin >> N;
	cin.ignore ();

	bool flag = false;
	string S;

	for (int i = 0; i < N; i++) {
		getline (cin, S);

		if (flag) {
			continue;
		}

		if (promise_set.count (S) == 0) {
			flag = true;
		}
	}

	if (flag) {
		cout << "Yes";
	}
	else {
		cout << "No";
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
