class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i : nums) {
            if(m.find(i) == m.end()) m[i] = 1;
            else m[i]++;
        }
        priority_queue<pair<int,int>> p;
        auto it = m.begin();
        while(it != m.end()) {
            p.push(make_pair(it->second,it->first));
            it++;
        }
        vector<int> res;
        while(k--) {
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};