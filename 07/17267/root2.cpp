#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <queue>

#define MAX_NM 1003

struct state {
	int y, x;
	int l, r;
};

int N, M;

int
get_num_can_reach (char map[MAX_NM][MAX_NM], struct state s)
{
	int cnt = 1;

	queue<struct state> q;
	bool visited[MAX_NM][MAX_NM] = {false};

	q.push (s);
	visited[s.y][s.x] = true;

	while (!q.empty ()) {
		struct state curr = q.front ();
		q.pop ();

		for (int i = -1; i <= 1; i += 2) {
			struct state next = curr;
			next.y += i;

			while (0 < next.y && next.y <= N) {
				if (map[next.y][next.x] == '1')
					break;
				if (visited[next.y][next.x])
					break;

				visited[next.y][next.x] = true;
				q.push (next);
				cnt++;

				next.y += i;
			}
		}

		for (int i = -1; i <= 1; i += 2) {
			struct state next = curr;
			next.x += i;

			if (next.x <= 0 || M < next.x)
				continue;
			if (map[next.y][next.x] == '1')
				continue;
			if (visited[next.y][next.x])
				continue;

			if (i == -1) {
				if (next.l > 0)
					next.l--;
				else
					continue;
			} else if (i == 1) {
				if (next.r > 0)
					next.r--;
				else
					continue;
			} else {
				continue;
			}

			visited[next.y][next.x] = true;
			q.push (next);
			cnt++;
		}
	}

	return cnt;
}

void
solve (void)
{
	char map[MAX_NM][MAX_NM] = {0};
	struct state start_state;

	cin >> N >> M;
	cin >> start_state.l >> start_state.r;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> map[r][c];
			
			if (map[r][c] == '2') {
				start_state.y = r;
				start_state.x = c;
			}
		}
	}

	cout << get_num_can_reach (map, start_state);
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
