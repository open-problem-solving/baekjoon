#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <queue>
#include <algorithm>
#include <utility>

#define MAX_N 1003
#define MAX_M 1003

#define pii pair<int, int>

void
solve (void)
{
	int N, M;
	int ability_list[MAX_N][MAX_M] = {0};

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int ability_max = -1;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ability_list[i][j];
		}
		sort (ability_list[i], ability_list[i] + M);
		pq.push ({ ability_list[i][0], i });
		ability_max = max (ability_max, ability_list[i][0]);
	}

	int class2ptr[MAX_N] = {0};
	int ans_min_diff = INT32_INF;

	while (true) {
		int ability_min = pq.top ().first;
		int class_min = pq.top ().second;
		int &class_ptr = class2ptr[class_min];
		pq.pop ();

		ans_min_diff = min (ans_min_diff, ability_max - ability_min);

		class_ptr++;
		if (class_ptr == M) {
			break;
		}

		ability_max = max (ability_max, ability_list[class_min][class_ptr]);
		pq.push ({ ability_list[class_min][class_ptr], class_min });
	}

	cout << ans_min_diff;
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
