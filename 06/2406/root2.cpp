#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <algorithm>

struct edge {
	int u, v;
	long long cost;

	bool operator< (struct edge const &o) const {
		return cost < o.cost;
	}
};

class KruskalMST {
private:
	int num_vert;
	vector<struct edge> edge_list;
	vector<int> parent;
public:
	KruskalMST (int _n) {
		num_vert = _n;
		parent.resize (_n + 1);
		for (int i = 1; i <= _n; i++) {
			parent[i] = i;
		}
	}

	void
	insert_edge (int u, int v, long long cost) {
		edge_list.push_back ({ min (u, v), max (u, v), cost });
	}

	int
	find_parent (int node) {
		if (parent[node] == node) {
			return node;
		}
		parent[node] = find_parent (parent[node]);
		return parent[node];
	}

	inline bool
	check_same_parent (int node_one, int node_two) {
		return (find_parent (node_one) == find_parent (node_two));
	}

	void
	union_nodes (int node_one, int node_two) {
		int parent_one = find_parent (node_one);
		int parent_two = find_parent (node_two);
		if (parent_one != parent_two) {
			parent[parent_one] = parent_two;
		}
	}

	vector<struct edge>
	find_mst_list (void) {
		sort (edge_list.begin (), edge_list.end ());

		vector<struct edge> res;

		for (struct edge e : edge_list) {
			int u = e.u;
			int v = e.v;

			if (check_same_parent (u, v)) {
				continue;
			}

			res.push_back (e);
			union_nodes (u, v);

			if (res.size () == num_vert - 1) {
				return res;
			}
		}

		return res;
	}
};

void
solve (void)
{
	int n, m;
	cin >> n >> m;

	KruskalMST mst (n - 1);
	vector<vector<bool>> connected (n);
	for (int i = 1; i < n; i++) {
		connected[i].resize (n, false);
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		mst.union_nodes (x, y);
		connected[min (x, y)][max (x, y)] = true;
	}
	
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			long long cost;
			cin >> cost;

			if (x == 1) {
				continue;
			}
			else if (y < x) {
				continue;
			}

			mst.insert_edge (x - 1, y - 1, cost);
		}
	}

	vector<struct edge> mst_list;
	mst_list = mst.find_mst_list ();

	vector<struct edge> ans_list;
	long long ans_cost = 0;

	for (struct edge e : mst_list) {
		if (connected[e.u][e.v]) {
			continue;
		}
		ans_list.push_back (e);
		ans_cost += e.cost;
	}

	cout << ans_cost << ' ' << ans_list.size () << '\n';
	for (struct edge e : ans_list) {
		cout << e.u + 1 << ' ' << e.v + 1 << '\n';
	};
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
