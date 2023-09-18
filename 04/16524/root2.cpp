#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <set>

void
solve (void)
{
	int N;
	cin >> N;

	set<string> email_set;

	for (int i = 0; i < N; i++) {
		string email;
		cin >> email;

		string email_modified;

		for (int j = 0; email[j] != '@'; j++) {
			if (email[j] == '+') {
				break;
			}
			else if (email[j] == '.') {
				continue;
			}
			else {
                email_modified += email[j];
            }
		}

		int provider_pos = email.find ('@');
		email_modified += email.substr (provider_pos);

		email_set.insert (email_modified);
	}

	cout << email_set.size ();
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
