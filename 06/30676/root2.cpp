#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <string.h>

void
solve (void)
{
	string color_list[] = {
		"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet" };

	int lambda;
	cin >> lambda;

	int color = -1;
	if (lambda < 425) {
		color = 6;
	}
	else if (lambda < 450) {
		color = 5;
	}
	else if (lambda < 495) {
		color = 4;
	}
	else if (lambda < 570) {
		color = 3;
	}
	else if (lambda < 590) {
		color = 2;
	}
	else if (lambda < 620) {
		color = 1;
	}
	else {
		color = 0;
	}

	cout << color_list[color];
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
