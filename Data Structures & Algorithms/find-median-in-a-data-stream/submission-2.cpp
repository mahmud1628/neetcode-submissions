class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int pos = 0;
        int size = nums.size();
        while(pos < size && nums[pos] <= num) {
            pos++;
        }
        nums.push_back(num);
        for(int i = size; i > pos; i--) {
            nums[i] = nums[i - 1];
        }
        nums[pos] = num;
    }
    
    double findMedian() {
        int mid = nums.size() / 2;
        if(nums.size() % 2 == 0) {
            int median1 = nums[mid - 1];
            int median2 = nums[mid];
            return 1.0 * (median1 + median2) / 2;
        }
        else {
            return nums[mid];
        }  
    }
};
