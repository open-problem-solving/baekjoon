#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int x, y;
	cin >> x >> y;
	cout << x + y << '\n';
}

int
main (void)
{
	fastio;

	int T = 1;
	cin >> T;
	while (T--) {
		solve ();
	}

	return 0;
}
