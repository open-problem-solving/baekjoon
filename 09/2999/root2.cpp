#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <math.h>

void
solve (void)
{
	char msg[102];
	int N;
	cin >> msg;
	N = strlen (msg);

	int R, C;
	R = sqrt (N);

	while (N % R != 0) {
		R--;
	}
	C = N / R;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << msg[R * c + r];
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
