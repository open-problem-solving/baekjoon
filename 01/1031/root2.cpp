#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <algorithm>
#include <queue>

#define MAX_N 50
#define MAX_M 50
#define MAX_ARR 102

bool
net_bfs_shortest_path (int cap[MAX_ARR][MAX_ARR], int flow[MAX_ARR][MAX_ARR],
		int parent[MAX_ARR], int src, int sink)
{
	queue<int> q;
	bool visited[MAX_ARR] = {0};

	q.push (src);
	visited[src] = true;

	while (!q.empty ()) {
		int curr = q.front ();
		q.pop ();

		for (int next = 0; next < MAX_ARR; next++) {
			if (visited[next]) {
				continue;
			}
			if (cap[curr][next] - flow[curr][next] <= 0) {
				continue;
			}

			parent[next] = curr;
			if (next == sink) {
				return true;
			}

			visited[next] = true;
			q.push (next);
		}
	}

	return false;
}

int
net_get_max_flow (int cap[MAX_ARR][MAX_ARR], int flow[MAX_ARR][MAX_ARR], int src, int sink)
{
	int u, v;
	int max_flow = 0;
	int parent[MAX_ARR] = {0};
	parent[src] = -1;

	while (net_bfs_shortest_path (cap, flow, parent, src, sink)) {
		for (v = sink; v != src; v = parent[v]) {
			u = parent[v];
			flow[u][v]++;
			flow[v][u]--;
		}
		max_flow++;
	}

	return max_flow;
}

bool
net_bfs_dict_order (int cap[MAX_ARR][MAX_ARR], int flow[MAX_ARR][MAX_ARR],
		int parent[MAX_ARR], int src, int sink)
{
	queue<int> q;
	bool visited[MAX_ARR] = {0};

	q.push (src);
	visited[src] = true;

	while (!q.empty ()) {
		int curr = q.front ();
		q.pop ();

		if (0 < curr && curr < src) {
			continue;
		}

		for (int next = 0; next < MAX_ARR; next++) {
			if (curr == src && next <= sink) {
				continue;
			}
			if (visited[next]) {
				continue;
			}
			if (cap[curr][next] - flow[curr][next] <= 0) {
				continue;
			}

			parent[next] = curr;
			if (next == sink) {
				return true;
			}

			visited[next] = true;
			q.push (next);
		}
	}

	return false;
}

void
net_update_flow (int cap[MAX_ARR][MAX_ARR], int flow[MAX_ARR][MAX_ARR], int src, int sink)
{
	int u, v;
	int max_flow = 0;
	int parent[MAX_ARR] = {0};
	parent[src] = -1;

	if (!net_bfs_dict_order (cap, flow, parent, src, sink)) {
		return;
	}

	flow[src][sink] = flow[src][sink] = 0;
	for (v = sink; v != src; v = parent[v]) {
		u = parent[v];
		flow[u][v]++;
		flow[v][u]--;
	}
}

void
solve (void)
{
	int N, M;
	cin >> N >> M;

	int net_capacity[MAX_ARR][MAX_ARR] = {0};
	int net_flow[MAX_ARR][MAX_ARR] = {0};

	int const src = 0;
	int const sink = 101;

	int sum_jimin, sum_hansu;
	sum_jimin = sum_hansu = 0;

	for (int i = 1; i <= N; i++) {
		cin >> net_capacity[src][i];
		sum_jimin += net_capacity[src][i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			net_capacity[i][MAX_N + j] = 1;
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> net_capacity[MAX_N + i][sink];
		sum_hansu += net_capacity[MAX_N + i][sink];
	}

	if (sum_jimin != sum_hansu) {
		cout << -1;
		return;
	}

	if (net_get_max_flow (net_capacity, net_flow, src, sink) != sum_jimin) {
		cout << -1;
		return;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (net_flow[i][MAX_N + j] == 0) {
				continue;
			}
			net_update_flow (net_capacity, net_flow, i, MAX_N + j);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << net_flow[i][MAX_N + j];
		}
		cout << '\n';
	}
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
