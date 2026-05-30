// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> result;
        if(pairs.size() == 0) return result;
        result.push_back(pairs);
        for(int index = 1; index < pairs.size(); index++) {
            int key = pairs[index].key;
            string value = pairs[index].value;

            int prev_index = index - 1;

            while(prev_index >= 0 && pairs[prev_index].key > key) {
                pairs[prev_index + 1].key = pairs[prev_index].key;
                pairs[prev_index + 1].value = pairs[prev_index].value;
                prev_index--;
            }

            pairs[prev_index + 1].key = key;
            pairs[prev_index + 1].value = value;
            result.push_back(pairs);
        }
        return result;
    }
};
