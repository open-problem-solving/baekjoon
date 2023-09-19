#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <map>
#include <string.h>

struct resistance {
	int value;
	int product;
};

void
solve (void)
{
	map<string, struct resistance> resistance_map {
		{ "black", { 0, 1 } },
		{ "brown", { 1, 10 } },
		{ "red", { 2, 100 } },
		{ "orange", { 3, 1000 } },
		{ "yellow", { 4, 10000 } },
		{ "green", { 5, 100000 } },
		{ "blue", { 6, 1000000 } },
		{ "violet", { 7, 10000000 } },
		{ "grey", { 8, 100000000 } },
		{ "white", { 9, 1000000000 } } };

	string color;
	long long resist_value = 0;

	for (int i = 0; i < 2; i++) {
		cin >> color;
		resist_value *= 10;
		resist_value += resistance_map[color].value;
	}
	cin >> color;
	resist_value *= resistance_map[color].product;

	cout << resist_value;
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
