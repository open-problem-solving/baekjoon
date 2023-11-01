#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <map>
#include <string.h>

void
solve (void)
{
	map<string, string> seminar2room = {
		{ "Algorithm", "204" },
		{ "DataAnalysis", "207" },
		{ "ArtificialIntelligence", "302" },
		{ "CyberSecurity", "B101" },
		{ "Network", "303" },
		{ "Startup", "501" },
		{ "TestStrategy", "105" } };
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		cout << seminar2room[s] << '\n';
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
