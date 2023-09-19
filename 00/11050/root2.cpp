#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

void
solve (void)
{
	int N, K;
	cin >> N >> K;
	K = min (K, N - K);

	int ans = 1;
	for (int i = 0; i < K; i++) {
		ans *= (N - i);
		ans /= (i + 1);
	}
	
	cout << ans;
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
