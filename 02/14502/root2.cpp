#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 10
#define MAX_M 10
#define NUM_WALL 3

struct coord {
	int r, c;
};

int N, M;
int map[MAX_N][MAX_M];

vector<struct coord> virus_list;
bool map_wall[MAX_N][MAX_M];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int
map_virus_spread ()
{
	queue<struct coord> q;
	int virus_cnt;
	bool visited[MAX_N][MAX_M] = {0};

	virus_cnt = virus_list.size ();
	for (struct coord virus : virus_list) {
		q.push ({ virus.r, virus.c });
		visited[virus.r][virus.c] = true;
	}

	while (!q.empty ()) {
		struct coord curr = q.front ();
		q.pop ();

		for (int i = 0; i < 4; i++) {
			struct coord next = { curr.r + dr[i], curr.c + dc[i] };

			if (next.r < 1 || N < next.r || next.c < 1 || M < next.c) {
				continue;
			}
			else if (visited[next.r][next.c]) {
				continue;
			}
			else if (map[next.r][next.c] == 1 || map_wall[next.r][next.c]) {
				continue;
			}

			q.push (next);
			visited[next.r][next.c] = true;
			virus_cnt++;
		}
	}

	return virus_cnt;
}

bool
wall_build (int rc)
{
	int r = rc / M + 1;
	int c = rc % M + 1;

	if (map[r][c] != 0) {
		return false;
	}
	else {
		map_wall[r][c] = true;
		return true;
	}
}

void
wall_demolish (int rc)
{
	int r = rc / M + 1;
	int c = rc % M + 1;

	map_wall[r][c] = false;
}

void
solve (void)
{
	int map_not_wall_cnt = 0;

	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> map[r][c];

			if (map[r][c] != 1) {
				map_not_wall_cnt++;
			}
			
			if (map[r][c] == 2) {
				virus_list.push_back ({ r, c });
			}
		}
	}

	int ans_max_cnt = 0;

	for (int i = 0; i < N * M; i++) {
		if (!wall_build (i)) {
			continue;
		}

		for (int j = i + 1; j < N * M; j++) {
			if (!wall_build (j)) {
				continue;
			}

			for (int k = j + 1; k < N * M; k++) {
				if (!wall_build (k)) {
					continue;
				}

				ans_max_cnt = max (ans_max_cnt, map_not_wall_cnt - map_virus_spread () - 3);

				wall_demolish (k);
			}
			wall_demolish (j);
		}
		wall_demolish (i);
	}

	cout << ans_max_cnt;
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
