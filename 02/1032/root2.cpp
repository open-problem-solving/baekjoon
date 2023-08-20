#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int N;
	char file_name[51][51];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> file_name[i];

	for (int i = 0; file_name[0][i] != 0; i++) {
		char first_file_value = file_name[0][i];
		bool flag = true;

		for (int f = 1; f < N; f++) {
			if (first_file_value != file_name[f][i]) {
				flag = false;
				break;
			}
		}

		if (flag)
			cout << first_file_value;
		else
			cout << '?';
	}
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
