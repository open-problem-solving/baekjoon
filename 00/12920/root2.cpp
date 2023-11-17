#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <vector>
#include <algorithm>

void
solve (void)
{
	int N, M;
	cin >> N >> M;

	int V, C, K;
	vector<int> backpack (M + 1);

	for (int i = 0; i < N; i++) {
		cin >> V >> C >> K;

		for (int num = 1; K > 0; num <<= 1) {
			num = min (num, K);
			for (int j = M; j >= V * num; j--) {
				backpack[j] = max (backpack[j], backpack[j - V * num] + C * num);
			}
			K -= num;
		}
	}

	cout << backpack[M];
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
