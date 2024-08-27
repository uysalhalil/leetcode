#include <queue>
#include <vector>

class KthLargest {
   private:
    int _size;
    int _k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> _pq;

    void keepSizeConstK() {
        while (_size > _k) {
            _pq.pop();
            --_size;
        }
    }

   public:
    KthLargest(int k, std::vector<int>& nums)
        : _size(nums.size()), _k(k), _pq(nums.begin(), nums.end()) {
        keepSizeConstK();
    }

    int add(int val) {
        _pq.push(val);
        ++_size;
        keepSizeConstK();
        return _pq.top();
    }
};