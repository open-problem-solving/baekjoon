#include <iostream>
#include <algorithm>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

struct ps_thread {
	int start;
	int end;

	bool operator< (const ps_thread &o) const {
		if (start == o.start) {
			return end < o.end;
		} else {
			return start < o.start;
		}
	}
};

int n;
struct ps_thread T[100005];

int
check_knot (int dist)
{
	int curr_knot = T[0].start;
	for (int i = 1; i < n; i++) {
		int next_knot = curr_knot + dist;

		if (next_knot <= T[i].end) {
			if (T[i].start <= next_knot) {
				curr_knot = next_knot;
			} else {
				curr_knot = T[i].start;
			}
		} else {
			return 0;
		}
	}

	return 1;
}	

void
solve (void)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, l;
		cin >> x >> l;
		T[i].start = x;
		T[i].end = x + l;
	}
	sort (T, T + n);

	ll left, right;
	left = 0;
	right = 2000000000;

	while (left <= right) {
		int middle = (left + right) >> 1;

		if (check_knot (middle)) {
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}

	cout << right;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
