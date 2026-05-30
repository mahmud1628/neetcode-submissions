class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0 ) return "";
        string res = "";
        for(int i =0;i<strs.size();i++) {
            res += strs[i] + "----";
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s.size() == 0) return {};
        vector<string> res;
        string del = "----";
        int start, end = -1*del.size();
        do {
            start = end + del.size();
            end = s.find(del, start);
            res.push_back(s.substr(start, end - start));
        } while (end != -1);
        res.pop_back();
        return res;
    }
};
