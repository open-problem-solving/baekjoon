#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <math.h>

void
tower_of_hanoi (int num, int from, int through, int to)
{
	if (num == 1)
		cout << from << ' ' << to << '\n';
	else {
		tower_of_hanoi (num - 1, from, to, through);
		cout << from << ' ' << to << '\n';
		tower_of_hanoi (num - 1, through, from, to);
	}
}

void
solve (void)
{
	int N;
	cin >> N;

	string K = to_string (pow (2, N));
	K = K.substr (0, K.find ('.'));
	K[K.length () - 1]--;

	cout << K << '\n';

	if (20 < N)
		return;

	tower_of_hanoi (N, 1, 2, 3);
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
