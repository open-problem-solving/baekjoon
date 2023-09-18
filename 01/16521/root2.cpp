#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <math.h>

void
solve (void)
{
	double R;
	cin >> R;

	int R2int = round(R * 100);

	for (int num_slices = 1; ; num_slices++) {
		if (num_slices * R2int % 36000 == 0) {
			cout << num_slices;
			break;
		}
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
