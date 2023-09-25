#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>

void
solve (void)
{
	string val2binary[] = {
		"000", "001", "010", "011",
		"100", "101", "110", "111" };
	
	string octal;
	cin >> octal;

	cout << stoi (val2binary[octal[0] - '0']);
	for (int i = 1; i < octal.length (); i++) {
		cout << val2binary[octal[i] - '0'];
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
