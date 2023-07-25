#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INF32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>

void
solve (void)
{
	int N;
	cin >> N;

	short cow_location[102] = {0};
	int min_cnt = 0;
	memset (cow_location, -1, sizeof (cow_location));

	for (int i = 0; i < N; i++) {
		int cow_num, cow_loc;
		cin >> cow_num >> cow_loc;

		short &cur_loc = cow_location[cow_num];

		if (cur_loc == -1) {
			cur_loc = cow_loc;
			continue;
		}

		if (cur_loc != cow_loc)
			min_cnt++;

		cur_loc = cow_loc;
	}

	cout << min_cnt;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
