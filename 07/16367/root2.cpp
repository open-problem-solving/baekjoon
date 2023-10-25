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
	int k, n;
	cin >> k >> n;

	for (int i = 0; i < n; i++) {
		int lamp_val[4];
		for (int j = 0; j < 3; j++) {
			int l;
			char c;
			cin >> l >> c;

			if (c == 'B') {
				lamp_val[j] = l;
			}
			else {
				lamp_val[j] = -l;
			}
		}
		lamp_val[3] = lamp_val[0];

		for (int j = 0; j < 3; j++) {
			int a, b;
			a = lamp_val[j];
			b = lamp_val[j + 1];

			if (a > 0) {
				a = op_pos (a);
			}
			else {
				a = op_neg (a);
			}
			if (b > 0) {
				b = op_pos (b);
			}
			else {
				b = op_neg (b);
			}

			graph[op_not (a)].push_back (b);
			rev_graph[b].push_back (op_not (a));
			graph[op_not (b)].push_back (a);
			rev_graph[a].push_back (op_not (b));
		}
	}

	sat_get_scc (k);

	for (int i = 1; i <= k; i++) {
		if (scc[op_pos (i)] == scc[op_neg (-i)]) {
			cout << -1;
			return;
		}
	}

	for (int i = 1; i <= k; i++) {
		if (scc[op_pos (i)] < scc[op_neg (-i)]) {
			cout << 'R';
		}
		else {
			cout << 'B';
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
