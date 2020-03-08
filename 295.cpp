class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(big.size() == small.size()){
            if(big.size() == 0){
                small.push(num);
            }else if(small.top() >= num){
                small.push(num);
            }else{
                big.push(num);
            }
        }else if(big.size() > small.size()){
            if(big.top() >= num){
                small.push(num);
            }else{
                small.push(big.top());
                big.pop();
                big.push(num);
            }
        }else{
            if(small.top() > num){
                big.push(small.top());
                small.pop();
                small.push(num);
            }else{
                big.push(num);
            }
        }
    }
    
    double findMedian() {
        if(big.size() == small.size()){
            return (big.top() + small.top()) / 2.0;
        }else if(big.size() > small.size()){
            return big.top();
        }else{
            return small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */