#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>

void
solve (void)
{
	double weight;
	char unit[5];

	cin >> weight >> unit;

	if (strcmp (unit, "kg") == 0)
		printf ("%.4lf lb\n", weight * 2.2046);
	else if (strcmp (unit, "lb") == 0)
		printf ("%.4lf kg\n", weight * 0.4536);
	else if (strcmp (unit, "l") == 0)
		printf ("%.4lf g\n", weight * 0.2642);
	else if (strcmp (unit, "g") == 0)
		printf ("%.4lf l\n", weight * 3.7854);
}

int
main (void)
{
	fastio;

	int T = 1;
	cin >> T;
	while (T--)
		solve ();

	return 0;
}
