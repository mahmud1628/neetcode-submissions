class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int min_size = min_heap.size();
        int max_size = max_heap.size();

        if(min_size == 0 && max_size == 0) {
            min_heap.push(num);
            return;
        }

        if(num >= min_heap.top()) {
            min_heap.push(num);
            min_size++;
        }
        else {
            max_heap.push(num);
            max_size++;
        }
        
        if(min_size == max_size + 2) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if(max_size == min_size + 2) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()) return 1.0 * (min_heap.top() + max_heap.top()) / 2;
        if(min_heap.size() > max_heap.size()) return min_heap.top();
        return max_heap.top();
    }
};
