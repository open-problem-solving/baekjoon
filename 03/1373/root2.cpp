#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <map>

void
solve (void)
{
	map<string, int> binary2oct {
		{ "000", 0 },
		{ "001", 1 },
		{ "010", 2 },
		{ "011", 3 },
		{ "100", 4 },
		{ "101", 5 },
		{ "110", 6 },
		{ "111", 7 } };
	
	string binary;
	cin >> binary;

	int first_idx = binary.length () % 3;
	if (first_idx != 0) {
		string tmp = "000";
		for (int i = 0; i < first_idx; i++) {
			tmp[3 - first_idx + i] = binary[i];
		}
		cout << binary2oct[tmp];
	}

	for (int i = first_idx; i < binary.length (); i += 3) {
		string tmp = "000";
		tmp[0] = binary[i + 0];
		tmp[1] = binary[i + 1];
		tmp[2] = binary[i + 2];
		cout << binary2oct[tmp];
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
