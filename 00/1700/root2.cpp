#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <queue>

#define MAX_K 102

int N, K;
vector<int> multitap;
queue<int> elec2schedule[MAX_K];

bool
multitap_already_connected (int elec)
{
	for (int e : multitap) {
		if (elec == e)
			return true;
	}
	return false;
}

int
multitap_connect_elec (int elec)
{
	if (multitap_already_connected (elec)) {
		return 0;
	}
	else if (multitap.size () < N) {
		multitap.push_back (elec);
		return 0;
	}

	int multitap_idx;
	int schedule_latest = -1;

	for (int i = 0; i < N; i++) {
		int multitap_elec = multitap[i];
		if (elec2schedule[multitap_elec].empty ()) {
			multitap_idx = i;
			break;
		}

		int sched = elec2schedule[multitap_elec].front ();
		if (schedule_latest < sched) {
			schedule_latest = sched;
			multitap_idx = i;
		}
	}

	multitap[multitap_idx] = elec;
	return 1;
}

void
solve (void)
{
	int schedule[MAX_K];

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> schedule[i];
		elec2schedule[schedule[i]].push (i);
	}

	int ans_cnt = 0;

	for (int i = 0; i < K; i++) {
		int elec_use = schedule[i];
		elec2schedule[elec_use].pop ();

		ans_cnt += multitap_connect_elec (elec_use);
	}

	cout << ans_cnt;
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
