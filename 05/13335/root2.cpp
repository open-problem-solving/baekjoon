#include <iostream>
#include <vector>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void
solve (void)
{
	int n, w, L;
	cin >> n >> w >> L;

	int a[1003] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int curr_weight = 0;
	vector<int> bridge (w, 0);
	int min_time = 0;

	for (int i = 1; i <= n; min_time++) {
		curr_weight -= bridge.front ();
		bridge.erase (bridge.begin ());

		int next_weight;
		if (curr_weight + a[i] <= L) {
			next_weight = a[i];
			i++;
		} else {
			next_weight = 0;
		}
		bridge.push_back (next_weight);
		curr_weight += next_weight;
	}
	min_time += w;

	cout << min_time;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
