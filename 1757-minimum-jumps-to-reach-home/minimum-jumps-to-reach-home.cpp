class Solution {
public:
    int minimumJumps(vector<int>& f, int a, int b, int pos) {
        priority_queue<pair<int, pair<int, bool>>, vector<pair<int, pair<int, bool>>>, greater<pair<int, pair<int, bool>>>> pq;
        pq.push({0, {0, false}}); // {jumps, {current_position, previous_move_was_backward}}
        map<int, int> mp;
        for (auto i : f)
            mp[i]++;
        map<pair<int, bool>, int> vis;
        vis[{0, false}] = 1;
        if(pos==0)
        return 0;
        if(mp[pos])
        return -1;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            int jumps = x.first;
            int current_pos = x.second.first;
            bool prev_was_backward = x.second.second;
            
            // If we reach the target position
            if (current_pos + a == pos || (current_pos - b == pos && !prev_was_backward))
                return jumps + 1;

            // Forward move
            if (!vis[{current_pos + a, false}] && !mp[current_pos + a] && current_pos + a<=6000) {
                vis[{current_pos + a, false}] = 1;
                pq.push({jumps + 1, {current_pos + a, false}});
            }

            // Backward move (only if the previous move was not backward)
            if (!prev_was_backward && current_pos - b > 0 && !vis[{current_pos - b, true}] && !mp[current_pos - b]) {
                vis[{current_pos - b, true}] = 1;
                pq.push({jumps + 1, {current_pos - b, true}});
            }
        }
        return -1;
    }
};
