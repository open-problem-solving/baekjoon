#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <string.h>
#include <algorithm>

#define MAX_V 100005

struct edge {
	int u, v;

	bool operator< (edge const &o) const {
		if (u == o.u)
			return v < o.v;
		else
			return u < o.u;
	}
};

vector<int> adj_vert[MAX_V];

int order_visited[MAX_V];
vector<struct edge> ans_cut_edge;

int
find_cut_edge (int curr, int parent, int order)
{
	int order_min = order_visited[curr] = order;

	for (int next : adj_vert[curr]) {
		if (order_visited[next] != -1) {
			if (next != parent)
				order_min = min (order_min, order_visited[next]);
			continue;
		}

		int order_subtree_min = find_cut_edge (next, curr, order + 1);
		if (order < order_subtree_min)
			ans_cut_edge.push_back ({ min (curr, next), max (curr, next) });

		order_min = min (order_min, order_subtree_min);
	}

	return order_min;
}

void
solve (void)
{
	int V, E;

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;

		adj_vert[u].push_back (v);
		adj_vert[v].push_back (u);
	}

	memset (order_visited, -1, sizeof (order_visited));

	for (int vert = 1; vert <= V; vert++) {
		if (order_visited[vert] == -1)
			find_cut_edge (vert, 0, 1);
	}

	sort (ans_cut_edge.begin (), ans_cut_edge.end ());

	cout << ans_cut_edge.size () << '\n';
	for (struct edge e : ans_cut_edge) {
		cout << e.u << ' ' << e.v << '\n';
	}
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
