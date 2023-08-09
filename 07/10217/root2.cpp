#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

struct ticket {
	int dest;
	int cost;
	int time;

    bool operator< (const ticket &o) const {
        return time < o.time;
    }
	bool operator> (const ticket &o) const {
		return time > o.time;
	}
};

vector<struct ticket> air2ticket[102];
int air2cost2time[102][10004];

void
ticket_dijkstra (int origin, int destination, int max_cost)
{
	priority_queue<struct ticket, vector<struct ticket>, greater<struct ticket>> pq;
	pq.push ({origin, 0, 0});
	air2cost2time[origin][0] = 0;

	while (!pq.empty ()) {
		struct ticket curr = pq.top ();
		pq.pop ();

        if (curr.dest == destination)
            continue;
		if (air2cost2time[curr.dest][curr.cost] < curr.time)
			continue;

		for (struct ticket next : air2ticket[curr.dest]) {
			next.cost = curr.cost + next.cost;
			next.time = curr.time + next.time;
            int *next_cost2time = air2cost2time[next.dest];
            
			if (max_cost < next.cost)
				continue;
			if (next_cost2time[next.cost] <= next.time)
				continue;

			for (int cost = next.cost; cost <= max_cost; cost++) {
                if (next_cost2time[cost] <= next.time)
                    break;
                next_cost2time[cost] = next.time;
            }
			pq.push(next);
		}
	}
}

void
solve (void)
{
	int T;
	int N, M, K;

	cin >> T;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int airport;
		struct ticket t;
		cin >> airport >> t.dest >> t.cost >> t.time;
		air2ticket[airport].push_back (t);
	}
    
    for (int i = 1; i <= N; i++)
        sort (air2ticket[i].begin (), air2ticket[i].end ());

	memset (air2cost2time, 0x3f, sizeof (air2cost2time));
	ticket_dijkstra (1, N, M);

	int min_time = INT32_INF;
    int *dest_cost2time = air2cost2time[N];
    for (int i = 0; i <= M; i++)
        min_time = min (min_time, dest_cost2time[i]);
	
	if (min_time != INT32_INF)
		cout << min_time;
	else
		cout << "Poor KCM";
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
