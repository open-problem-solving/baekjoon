#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

bool
check_multiply_two_divisors (long long n, long long m, long long a)
{
	long long i;

	for (i = 1; i <= n; i++) {
		if (a % i == 0 && a / i <= m) {
			return true;
		}
	}

	for (i = 1; i <= m; i++) {
		if (a % i == 0 && a / i <= n) {
			return true;
		}
	}

	return false;
}

void
solve (void)
{
	long long n, m, a;
	cin >> n >> m >> a;

	if (a % n == 0 || a % m == 0) {
		cout << 1;
	}
	else if (check_multiply_two_divisors (n, m, a)
			|| check_multiply_two_divisors (n, m, n * m - a)) {
		cout << 2;
	}
	else {
		cout << 3;
	}
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
