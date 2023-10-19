#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <string.h>

#define MAX_N 10004

vector<int> graph[MAX_N << 1];
vector<int> rev_graph[MAX_N << 1];

bool visited[MAX_N << 1];
stack<int> dfn;
int scc[MAX_N << 1];
int cnt = 1;

int
op_not (int x)
{
	return x ^ 1;
}

int
op_pos (int x)
{
	return x << 1;
}

int
op_neg (int x)
{
	return (-x) << 1 | 1;
}

void
sat_dfs (int v)
{
	visited[v] = true;
	
	for (int u : graph[v]) {
		if (!visited[u]) {
			sat_dfs (u);
		}
	}

	dfn.push (v);
}

void
sat_rev_dfs (int v)
{
	visited[v] = true;
	scc[v] = cnt;

	for (int u : rev_graph[v]) {
		if (!visited[u]) {
			sat_rev_dfs (u);
		}
	}
}

void
sat_get_scc (int N)
{
	for (int i = op_pos (1); i <= op_neg (-N); i++) {
		if (!visited[i]) {
			sat_dfs (i);
		}
	}

	memset (visited, 0, sizeof (visited));

	while (!dfn.empty ()) {
		int i = dfn.top ();
		dfn.pop ();
		if (!visited[i]) {
			sat_rev_dfs (i);
			cnt++;
		}
	}
}

void
solve (void)
{
	int N, M;
	cin >> N >> M;

	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;

		if (i > 0) {
			i = op_pos (i);
		}
		else {
			i = op_neg (i);
		}
		if (j > 0) {
			j = op_pos (j);
		}
		else {
			j = op_neg (j);
		}

		graph[op_not (i)].push_back (j);
		rev_graph[j].push_back (op_not (i));
		graph[op_not (j)].push_back (i);
		rev_graph[i].push_back (op_not (j));
	}

	sat_get_scc (N);

	for (int i = 1; i <= N; i++) {
		if (scc[op_pos (i)] == scc[op_neg (-i)]) {
			cout << 0;
			return;
		}
	}

	cout << "1\n";
	for (int i = 1; i <= N; i++) {
		if (scc[op_pos (i)] < scc[op_neg (-i)]) {
			cout << "0 ";
		}
		else {
			cout << "1 ";
		}
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
