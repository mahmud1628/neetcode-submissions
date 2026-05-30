class Solution {
    vector<pair<int, int>> twoSum(vector<int> nums, int index) {
        unordered_map<int, int> m;
        int target = -1 * nums[index];

        vector<pair<int,int>> pairs;

        for(int i = 0; i < nums.size(); i++) {
            if(i == index) continue;
            if(m.find(target - nums[i]) == m.end()) {
                m[nums[i]] = i;
            }
            else pairs.push_back({m[target - nums[i]], i});
        }

        return pairs;
    }

    vector<int> make_triplet(int a, int b, int c) {
        vector<int> t = {a, b, c};
        sort(t.begin(), t.end());
        return t;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;

        for(int i = 0; i < nums.size(); i++) {
            vector<pair<int, int>> ts = twoSum(nums, i);
            for(auto p : ts) {
                vector<int> triplet = make_triplet(nums[i], nums[p.first], nums[p.second]);
                res.insert(triplet);
            }
        }
        vector<vector<int>> r;
        for(auto i : res) r.push_back(i);
        return r;
    }
};
