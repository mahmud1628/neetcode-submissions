class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int i : nums) {
            freq[i]++;
        }

        priority_queue<pair<int, int>> p;

        for(auto i : freq) {
            p.push({i.second, i.first});
        }

        vector<int> res;

        while(k--) {
            res.push_back(p.top().second);
            p.pop();
        }

        return res;
    }
};
