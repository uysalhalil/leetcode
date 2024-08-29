#include <queue>
#include <vector>

class MedianFinder {
   private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int> maxHeap;

   public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
        } else if (minHeap.empty()) {
            minHeap.push(num);
        } else if (num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (!minHeap.empty() && !maxHeap.empty()) {
            if (minHeap.top() < maxHeap.top()) {
                int v = minHeap.top();
                minHeap.pop();
                maxHeap.push(v);
            }
        }

        if (static_cast<int>(maxHeap.size()) -
                static_cast<int>(minHeap.size()) >
            1) {
            int v = maxHeap.top();
            maxHeap.pop();
            minHeap.push(v);
        } else if (static_cast<int>(minHeap.size()) -
                       static_cast<int>(maxHeap.size()) >
                   1) {
            int v = minHeap.top();
            minHeap.pop();
            maxHeap.push(v);
        }
    }

    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        } else if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        } else {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */