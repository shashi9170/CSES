#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_DAYS = 4e5 + 1;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    // Each project = {startDay, endDay, reward}
    vector<vector<int>> projects(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];

    // Step 1: Coordinate Compression (since days go up to 1e9)
    set<int> unique_days;
    for (auto& project : projects) {
        unique_days.insert(project[0]);  // start day
        unique_days.insert(project[1]);  // end day
    }

    // Compress days: map actual day → compressed day index
    map<int, int> compressed_day;
    int compressed_index = 0;
    for (int day : unique_days)
        compressed_day[day] = ++compressed_index;

    // Step 2: Group projects by their ending day
    vector<vector<pair<int, int>>> projects_ending_on_day(MAX_DAYS);
    for (auto& project : projects) {
        int start = compressed_day[project[0]];
        int end = compressed_day[project[1]];
        int reward = project[2];
        projects_ending_on_day[end].push_back({start, reward});
    }

    // Step 3: Dynamic Programming
    vector<int> max_reward_until_day(MAX_DAYS);

    for (int day = 1; day < MAX_DAYS; day++) {
        // Option 1: Don’t take any project ending today
        max_reward_until_day[day] = max_reward_until_day[day - 1];

        // Option 2: Try taking projects ending today
        for (auto& [start_day, reward] : projects_ending_on_day[day]) {
            max_reward_until_day[day] = max(
                max_reward_until_day[day],
                max_reward_until_day[start_day - 1] + reward
            );
        }
    }

    // Final answer: max reward up to the last day
    cout << max_reward_until_day[MAX_DAYS - 1] << "\n";
}
