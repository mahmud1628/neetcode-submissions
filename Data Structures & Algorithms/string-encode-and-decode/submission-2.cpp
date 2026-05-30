class Solution {
public:

    string encode(vector<string>& strs) {
        string flag = "----";
        string encoded_string = "";

        for(string s : strs) {
            encoded_string += s + flag;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        string flag = "----";
        vector<string> decoded_strs;
        int start, end = -1 * flag.size();
        while(end != -1) {
            start = end + flag.size();
            end = s.find(flag, start);
            decoded_strs.push_back(s.substr(start, end - start));
        }

        decoded_strs.pop_back();

        return decoded_strs;
    }
};
