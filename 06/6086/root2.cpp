#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>
#include <queue>

#define MAX_ARR 61
#define NUM_VERT 52

bool
bfs_in_pipe (int rc[MAX_ARR][MAX_ARR], int s, int t, int parent[MAX_ARR])
{
	queue<int> q;
	bool visited[MAX_ARR] = {0};

	q.push (s);
	visited[s] = true;

	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();

		for (int v = 0; v < NUM_VERT; v++) {
			if (visited[v])
				continue;
			if (rc[u][v] <= 0)
				continue;

			parent[v] = u;

			if (v == t)
				return true;

			q.push (v);
			visited[v] = true;
		}
	}

	return false;
}

int
get_max_flow_in_pipe (int pc[MAX_ARR][MAX_ARR], int s, int t)
{
	int u, v;
	int residual[MAX_ARR][MAX_ARR] = {0};

	for (u = 0; u < NUM_VERT; u++)
		for (v = 0; v < NUM_VERT; v++)
			residual[u][v] = pc[u][v];

	int parent[MAX_ARR] = {0};
	int max_flow = 0;
	parent[s] = -1;

	while (bfs_in_pipe (residual, s, t, parent)) {
		int path_flow = INT32_INF;

		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min (path_flow, residual[u][v]);
		}

		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			residual[u][v] -= path_flow;
			residual[v][u] += path_flow;
		}

		max_flow += path_flow;
	}

	return max_flow;
}

char
convert_char_to_int (char c)
{
	if ('A' <= c && c <= 'Z')
		return c - 'A';
	else
		return c - 'a' + 26;
}

void
solve (void)
{
	int N;
	int pipe_capacity[MAX_ARR][MAX_ARR] = {0};

	cin >> N;
	for (int i = 0; i < N; i++) {
		char u, v;
		int c;
		cin >> u >> v >> c;

		u = convert_char_to_int (u);
		v = convert_char_to_int (v);

		pipe_capacity[u][v] += c;
		pipe_capacity[v][u] += c;
	}

	cout << get_max_flow_in_pipe (pipe_capacity,
			(int) convert_char_to_int ('A'), (int) convert_char_to_int ('Z'));
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
