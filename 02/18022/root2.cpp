#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <vector>

#define MAX_N 102

void
solve (void)
{
	string rhyme;
	getline (cin, rhyme);

	int word_cnt = 1;
	for (char c : rhyme) {
		if (c == ' ') {
			word_cnt++;
		}
	}

	int n;
	cin >> n;

	vector<string> kids_name(n);
	for (int i = 0; i < n; i++) {
		cin >> kids_name[i];
	}

	int kids_idx = 0;
	int word_curr = 1;
	int flag = 0;
	vector<string> member_a, member_b;

	while (!kids_name.empty ()) {
		if (kids_name.size () == 1) {
			if ((flag & 1) == 0) {
				member_a.push_back (kids_name[0]);
			}
			else {
				member_b.push_back (kids_name[0]);
			}
			break;
		}

		if (word_curr == word_cnt) {
			if ((flag & 1) == 0) {
				member_a.push_back (kids_name[kids_idx]);
			}
			else {
				member_b.push_back (kids_name[kids_idx]);
			}
			kids_name.erase (kids_name.begin () + kids_idx);

			word_curr = 1;
			flag++;
		}
		else {
			kids_idx++;
			word_curr++;
		}

		kids_idx %= kids_name.size ();
	}
	
	cout << member_a.size () << '\n';
	for (string name : member_a) {
		cout << name << '\n';
	}
	cout << member_b.size () << '\n';
	for (string name : member_b) {
		cout << name << '\n';
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
