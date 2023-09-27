#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

#define MAX_S 102

struct slot {
	int num_soda;
	int index;

	bool operator< (slot const &o) const {
		return num_soda < o.num_soda;
	}
};

void
solve (void)
{
	int n, m, s, d;
	struct slot fridge[MAX_S];

	cin >> n >> m >> s >> d;
	for (int i = 0; i < s; i++) {
		cin >> fridge[i].num_soda;
		fridge[i].index = i;
	}

	sort (fridge, fridge + s);

	int soda_left = n;
	int student_left = m;
	int ans_soda_refill[MAX_S] = {0};

	for (int i = 0; i < s; i++) {
		if (soda_left > 0) {
			int soda_refill = d - fridge[i].num_soda;
			soda_refill = min (soda_refill, soda_left);

			soda_left -= soda_refill;
			ans_soda_refill[fridge[i].index] = soda_refill;
		}
		else if (student_left > 0) {
			student_left -= fridge[i].num_soda;
		}
	}

	if (student_left > 0) {
		cout << "impossible";
	}
	else {
		for (int i = 0; i < s; i++) {
			cout << ans_soda_refill[i] << ' ';
		}
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
