#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <algorithm>

#define MAX_N 1003

bool
string_int_compare (string a, string b)
{
	if ((a + b).compare (b + a) <= 0) {
		return false;
	}
	else {
		return true;
	}
}

void
solve (void)
{
	int N;
	string int_list[MAX_N];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> int_list[i];
	}

	sort (int_list, int_list + N, string_int_compare);

	if (int_list[0].compare ("0") == 0) {
		cout << 0;
		return;
	}

	for (int i = 0; i < N; i++) {
		cout << int_list[i];
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
