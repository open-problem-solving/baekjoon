#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int N;
	cin >> N;
	cout << ((N & 1) ? "SK" : "CY");
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
