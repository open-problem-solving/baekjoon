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
	string slogans;
	map<string, string> cheers_map {
		{ "SONGDO", "HIGHSCHOOL" },
		{ "CODE", "MASTER" },
		{ "2023", "0611" },
		{ "ALGORITHM", "CONTEST" } };

	cin >> slogans;
	cout << cheers_map[slogans];
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
