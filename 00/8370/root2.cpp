#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int n1, k1, n2, k2;
	cin >> n1 >> k1 >> n2 >> k2;
	cout << n1 * k1 + n2 * k2;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
