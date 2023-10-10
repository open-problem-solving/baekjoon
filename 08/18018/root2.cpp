#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <vector>

#define NUM_ALPHA 26

void
solve (void)
{
	string word_first;
	int n;
	vector<string> alpha2words[NUM_ALPHA];

	cin >> word_first;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string word_next;
		cin >> word_next;

		int alpha_start = word_next[0] - 'a';
		alpha2words[alpha_start].push_back (word_next);
	}

	int alpha_last = word_first[word_first.length () - 1] - 'a';
	if (alpha2words[alpha_last].size () == 0){
		cout << '?';
		return;
	}

	for (int i = 0; i < alpha2words[alpha_last].size (); i++) {
		string word_next = alpha2words[alpha_last][i];
		int alpha_next = word_next[word_next.length () - 1] - 'a';

		int flag;
		if (alpha_last == alpha_next) {
			flag = 1;
		}
		else {
			flag = 0;
		}

		if (alpha2words[alpha_next].size () == flag) {
			cout << alpha2words[alpha_last][i] << '!';
			return;
		}
	}

	cout << alpha2words[alpha_last][0];
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
