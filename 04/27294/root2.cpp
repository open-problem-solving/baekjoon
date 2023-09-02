#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int T, S;
	cin >> T >> S;

	int flag = 1;
	if (T < 12 || 16 < T)
		flag = 0;
	else if (S == 1)
		flag = 0;

	cout << (flag ? 320 : 280);
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
