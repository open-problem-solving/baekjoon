#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

class EdmondsKarp {
private:
	int num_vert;
	vector<vector<int>> adj_list;
	int src, sink;
	vector<vector<int>> flow, capacity;
	vector<int> parent;
public:
	EdmondsKarp (int _n, int _s, int _e) {
		num_vert = _n;
		src = _s;
		sink = _e;

		adj_list.resize (_n + 1);
		flow.resize (_n + 1);
		capacity.resize (_n + 1);
		parent.resize (_n + 1);
		for (int i = 1; i <= _n; i++) {
			flow[i].resize (_n + 1);
			capacity[i].resize (_n + 1);
		}
	}

	void
	insert_edge (int u, int v, int cap, bool directed) {
		adj_list[u].push_back (v);
		adj_list[v].push_back (u);
		capacity[u][v] += cap;
		if (!directed) {
			capacity[v][u] += cap;
		}
	}

	bool
	find_shortest_path_bfs (void) {
		queue<int> q;
		vector<bool> visited (num_vert + 1);

		q.push (src);
		visited[src] = true;

		while (!q.empty ()) {
			int curr = q.front ();
			q.pop ();

			for (int next : adj_list[curr]) {
				if (visited[next]) {
					continue;
				}
				if (capacity[curr][next] - flow[curr][next] <= 0) {
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
	get_max_flow (void) {
		int u, v;
		int max_flow = 0;
		parent[src] = -1;

		while (find_shortest_path_bfs ()) {
			int path_flow = INT32_INF;
			for (v = sink; v != src; v = parent[v]) {
				u = parent[v];
				path_flow = min (path_flow, capacity[u][v] - flow[u][v]);
			}

			for (v = sink; v != src; v = parent[v]) {
				u = parent[v];
				flow[u][v] += path_flow;
				flow[v][u] -= path_flow;
			}
			max_flow += path_flow;
		}

		return max_flow;
	}
};

int
main ()
{
	return 0;
}
