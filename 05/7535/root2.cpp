#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <string.h>

int testcase = 1;

int num_bugs, num_intract;
vector<int> intract_bugs_list[2003];

int bugs_gender[2003];

void
init_global ()
{
	for (int i = 1; i <= num_bugs; i++)
		intract_bugs_list[i].clear ();
	memset (bugs_gender, -1, sizeof (bugs_gender));
}

bool
bugs_setup_gender (int bug_num)
{
	int intract_bugs_gender = (bugs_gender[bug_num] + 1) & 1;

	for (int intract_bug_num : intract_bugs_list[bug_num]) {
		if (bugs_gender[intract_bug_num] != -1) {
			if (bugs_gender[bug_num] ^ bugs_gender[intract_bug_num])
				continue;
			else
				return false;
		}

		bugs_gender[intract_bug_num] = intract_bugs_gender;
		if (bugs_setup_gender (intract_bug_num) == false)
			return false;
	}

	return true;
}

void
solve (void)
{
	init_global ();

	cin >> num_bugs >> num_intract;
	for (int i = 0; i < num_intract; i++) {
		int A, B;
		cin >> A >> B;

		intract_bugs_list[A].push_back (B);
		intract_bugs_list[B].push_back (A);
	}

	bool flag = false;
	for (int i = 1; i <= num_bugs; i++) {
		if (bugs_gender[i] == -1) {
			bugs_gender[i] = 0;
			if (bugs_setup_gender (i) == false) {
				flag = true;
				break;
			}
		}
	}

	cout << "Scenario #" << testcase << ":\n";
	cout << (flag ? "Suspicious bugs found!\n\n" : "No suspicious bugs found!\n\n");
	testcase++;
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
