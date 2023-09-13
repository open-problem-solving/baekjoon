#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>

#define MAX_LEN 81

void
solve (void)
{
	int M;
	char word[MAX_LEN] = {0};

	cin >> M;
	cin >> word;

	for (int i = 0; i < strlen (word); i++) {
		if (i == M - 1)
			continue;
		cout << word[i];
	}
	cout << '\n';
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
