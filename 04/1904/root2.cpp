#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define MAX_N 1000006

void
solve (void)
{
	int N;
	cin >> N;

	int tile_cnt[MAX_N] = {0};
	tile_cnt[0] = 1;
	tile_cnt[1] = 1;

	for (int i = 2; i <= N; i++) {
		tile_cnt[i] = tile_cnt[i - 1] + tile_cnt[i - 2];
		tile_cnt[i] %= 15746;
	}

	cout << tile_cnt[N];
}

int
main (void)
{
	fastio;

	int T = 1;
	// cin >> T;
	while (T--) {
		solve ();
	}

	return 0;
}
