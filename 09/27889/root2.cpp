#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <map>
#include <string.h>

void
solve (void)
{
	map<string, string> school_map {
		{"NLCS", "North London Collegiate School"},
		{"BHA", "Branksome Hall Asia"},
		{"KIS", "Korea International School"},
		{"SJA", "St. Johnsbury Academy"}
	};

	string school;
	cin >> school;
	cout << school_map[school];
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
