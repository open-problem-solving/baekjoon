#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>

void
solve (void)
{
	int N;
	char password[30];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> password;
		int pw_len = strlen (password);
		cout << ((6 <= pw_len && pw_len <= 9) ? "yes\n" : "no\n");
	}
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
