class MedianFinder {
    priority_queue<int> pq;

    double findMedianOdd() { // returns the kth largest element in the priority queue (k = queue size / 2)
        int k = pq.size() / 2;
        vector<int> removed_nums;
        while(k--) {
            int n = pq.top();
            removed_nums.push_back(n);
            pq.pop();
        }
        int median = pq.top();
        for(int i : removed_nums) {
            pq.push(i);
        }
        return median;
    }

    double findMedianEven() {
        int k = pq.size() / 2 - 1;
        vector<int> removed_nums;
        while(k--) {
            int n = pq.top();
            removed_nums.push_back(n);
            pq.pop();
        }
        int median1 = pq.top();
        pq.pop();
        removed_nums.push_back(median1);
        int median2 = pq.top();
        for(int i : removed_nums) {
            pq.push(i);
        }
        return 1.0 * (median1 + median2) / 2;
    }
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        if(pq.size() % 2 == 0) 
            return findMedianEven();
        else 
            return findMedianOdd();
    }
};
