class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto a: nums) {
            if(m.size() == 0) m[a] = 1;
            else if(m.find(a) == m.end())
                m[a] = 1;
            else return true;
        }
        return false;
    }
};
