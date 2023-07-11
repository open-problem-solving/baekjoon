#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void
solve (void)
{
	int N;
	cin >> N;

	int num = N;

	for (int i = 1; 1; i++) {
		int left = num % 10;
		int right = ((num / 10) + (num % 10)) % 10;

		num = left * 10 + right;

		if (num == N) {
			cout << i;
			break;
		}
	}
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
