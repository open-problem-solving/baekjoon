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

#define IN(x)	((x) << 1)
#define OUT(x)	(IN(x) + 1)

typedef pair<int, int> pii;

struct shark {
	int size, speed, intell;
};

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
	int N;
	cin >> N;

	vector<struct shark> shark_list (N + 1);

	for (int i = 1; i <= N; i++) {
		struct shark &s = shark_list[i];
		cin >> s.size >> s.speed >> s.intell;
	}

	int num_vert = ((N + 1) << 1) + 1;
	src = IN (N + 1);
	sink = OUT (N + 1);
	adj_list.resize (num_vert + 1);
	parent.resize (num_vert + 1);

	for (int i = 1; i <= N; i++) {
		insert_edge (src, IN (i), 2);
		insert_edge (OUT (i), sink, 1);
	}

	for (int i = 1; i <= N; i++) {
		struct shark a = shark_list[i];

		for (int j = i + 1; j <= N; j++) {
			struct shark b = shark_list[j];

			if ((a.size >= b.size) && (a.speed >= b.speed) && (a.intell >= b.intell)) {
				insert_edge (IN (i), OUT (j), 1);
			}
			else if ((a.size <= b.size) && (a.speed <= b.speed) && (a.intell <= b.intell)) {
				insert_edge (IN (j), OUT (i), 1);
			}
		}
	}

	cout << N - get_max_flow ();
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
