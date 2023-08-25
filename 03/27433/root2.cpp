#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

long long
factorial_calc (int N)
{
	if (N == 0)
		return 1;

	long long f = 1;
	for (int i = 1; i <= N; i++)
		f *= i;
	return f;
}

void
solve (void)
{
	int N;
	cin >> N;
	cout << factorial_calc (N);
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
