#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>

typedef pair<int, int> pii;

#define IN(x)				(x << 1)
#define OUT(x)				(IN(x) + 1)
#define COORD2INT(M,r,c)	((r - 1) * M + c)

vector<vector<int>> adj_list;
map<pii, int> capacity, flow;
vector<int> parent;
int src, sink;

void
insert_edge (int u, int v, int cap)
{
	adj_list[u].push_back (v);
	capacity[{ u, v }] = cap;

	adj_list[v].push_back (u);
	capacity[{ v, u }] = 0;
}

inline int
get_residual (int u, int v)
{
	return capacity[{ u, v }] - flow[{ u, v }];
}

bool
find_shortest_path_bfs (void)
{
	queue<int> q;
	q.push (src);
	fill (parent.begin (), parent.end (), -1);

	while (!q.empty ()) {
		int curr = q.front ();
		q.pop ();

		for (int next : adj_list[curr]) {
			if (parent[next] != -1) {
				continue;
			}
			if (get_residual (curr, next) <= 0) {
				continue;
			}

			parent[next] = curr;
			if (next == sink) {
				return true;
			}

			q.push (next);
		}
	}

	return false;
}

int
get_max_flow (void)
{
	int u, v;
	int max_flow = 0;

	while (find_shortest_path_bfs ()) {
		for (v = sink; v != src; v = parent[v]) {
			u = parent[v];
			flow[{ u, v }]++;
			flow[{ v, u }]--;
		}
		max_flow++;
	}

	return max_flow;
}

void
solve (void)
{
	int N, M;
	cin >> N >> M;

	vector<vector<char>> city (N + 1);
	int dohyeon, school;
	int dh_r, dh_c, sc_r, sc_c;
	dohyeon = school = -1;
	dh_r = dh_c = sc_r = sc_c = 0;

	for (int r = 1; r <= N; r++) {
		city[r].resize (M + 1);

		for (int c = 1; c <= M; c++) {
			cin >> city[r][c];

			if (city[r][c] == 'K') {
				dh_r = r, dh_c = c;
				dohyeon = COORD2INT (M, r, c);
			}
			else if (city[r][c] == 'H') {
				sc_r = r, sc_c = c;
				school = COORD2INT (M, r, c);
			}
		}
	}

	if (dohyeon == -1 || school == -1) {
		cout << -1;
		return;
	}
	if (abs (dh_r - sc_r) + abs (dh_c - sc_c) == 1) {
		cout << -1;
		return;
	}

	int num_vert = ((N * M) << 1) + 1;
	src = OUT (dohyeon);
	sink = IN (school);
	adj_list.resize (num_vert + 1);
	parent.resize (num_vert + 1);

	int curr = 1, next;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++, curr++) {
			if (city[r][c] == '#') {
				continue;
			}

			if (r < N && city[r + 1][c] != '#') {
				next = curr + M;
				insert_edge (OUT (curr), IN (next), INT32_INF);
				insert_edge (OUT (next), IN (curr), INT32_INF);
			}
			if (c < M && city[r][c + 1] != '#') {
				next = curr + 1;
				insert_edge (OUT (curr), IN (next), INT32_INF);
				insert_edge (OUT (next), IN (curr), INT32_INF);
			}

			insert_edge (IN (curr), OUT (curr), 1);
		}
	}

	cout << get_max_flow ();
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
