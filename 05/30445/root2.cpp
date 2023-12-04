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
	string mesg;
	getline (cin, mesg);

	map<char, int> happy_alpha {
		{ 'H', 1 },
		{ 'A', 1 },
		{ 'P', 1 },
		{ 'Y', 1 }
	};
	map<char, int> sad_alpha {
		{ 'S', 1 },
		{ 'A', 1 },
		{ 'D', 1 },
	};

	int happy_score, sad_score;
	happy_score = sad_score = 0;

	for (char c : mesg) {
		happy_score += happy_alpha[c];
		sad_score += sad_alpha[c];
	}

	if (happy_score + sad_score != 0) {
		printf ("%.2f", (100.0f * happy_score / (happy_score + sad_score)) + 1e-9);
	}
	else {
		printf ("50.00");
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
