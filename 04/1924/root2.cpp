#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

void
solve (void)
{
	int x, y;
	cin >> x >> y;

	int days_psum[15] = {
		0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	char day_list[7][4] = {
		"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int days_remain = days_psum[x - 1] + y;
	
	cout << day_list[days_remain % 7];
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
