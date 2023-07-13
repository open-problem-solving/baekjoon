#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INF32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>
#include <stdlib.h>

struct coord {
	ll x, y;

	bool operator< (struct coord const &o) const {
		if (x == o.x) {
			return y < o.y;
		} else {
			return x < o.x;
		}
	}
};

struct coord points[4];
ll min_value, side_length;

long long
value_calculate (ll p)
{
	ll ret = INT64_INF;
	struct coord targets[4] = { {-p, -p}, {-p, p}, {p, -p}, {p, p} };

	do {
		ll tmp = 0;
		for (int i = 0; i < 4; i++) {
			tmp += abs (points[i].x - targets[i].x) + abs (points[i].y - targets[i].y);
		}
		ret = min (ret, tmp);
	} while (next_permutation (targets, targets + 4));

	return ret;
}

void
value_change (ll p, ll value, ll *ptr, int flag, ll q)
{
	if (value < min_value) {
		min_value = value;
		side_length = p;
	} else if (value == min_value) {
		side_length = max (side_length, p);
	}

	if (flag == 1) {
		*ptr = q - 1;
	} else if (flag == 2) {
		*ptr = q + 1;
	}
}

void
solve (void)
{
	for (int i = 0; i < 4; i++) {
		cin >> points[i].x >> points[i].y;
		points[i].x <<= 1;
		points[i].y <<= 1;
	}

	ll left, right;
	left = 1;
	right = 2000000000;
	min_value = INT64_INF;

	while (left <= right) {
		ll diff = (right - left) / 3;
		ll p = left + diff;
		ll q = right - diff;

		ll p_value = value_calculate (p);
		ll q_value = value_calculate (q);

		if (p_value < q_value) {
			value_change (p, p_value, &right, 1, q);
		} else {
			value_change (q, q_value, &left, 2, p);
		}
	}

	cout << side_length;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
