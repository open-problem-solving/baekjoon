#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <vector>
#include <queue>

class EdmondsKarp {
private:
	int num_vert;
	vector<vector<int>> adj_list;
	int src, sink;
	vector<vector<int>> flow, capacity;
	vector<int> parent;
public:
	EdmondsKarp (int n, int s, int e) {
		num_vert = n;
		src = s;
		sink = e;

		adj_list.resize (n + 1);
		flow.resize (n + 1);
		capacity.resize (n + 1);
		parent.resize (n + 1);
		for (int i = 1; i <= n; i++) {
			flow[i].resize (n + 1);
			capacity[i].resize (n + 1);
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
	find_shortest_path_bfs () {
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
	get_max_flow () {
		int u, v;
		int max_flow = 0;
		parent[src] = -1;

		while (find_shortest_path_bfs ()) {
			for (v = sink; v != src; v = parent[v]) {
				u = parent[v];
				flow[u][v]++;
				flow[v][u]--;
			}
			max_flow++;
		}

		return max_flow;
	}
};

void
solve (void)
{
	int N, M, K;
	cin >> N >> M >> K;

	int const src = N + M + 1;
	int const sink = N + M + 2;
	int const bridge = N + M + 3;
	EdmondsKarp net (N + M + 3, src, sink);

	net.insert_edge (src, bridge, K, true);
	for (int i = 1; i <= N; i++) {
		net.insert_edge (src, i, 1, true);
		net.insert_edge (bridge, i, 1, true);

		int num;
		cin >> num;
		while (num--) {
			int task;
			cin >> task;
			net.insert_edge (i, N + task, 1, true);
		}
	}
	for (int i = 1; i <= M; i++) {
		net.insert_edge (N + i, sink, 1, true);
	}

	cout << net.get_max_flow ();
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
