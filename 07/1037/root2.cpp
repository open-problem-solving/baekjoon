#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

void
solve (void)
{
	int num;
	int divisor_list[51] = {0};

	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> divisor_list[i];

	sort (divisor_list, divisor_list + num);

	cout << (divisor_list[0] * divisor_list[num - 1]);
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
