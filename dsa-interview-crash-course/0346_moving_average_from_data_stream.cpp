#include <queue>

class MovingAverage {
    int n_size = 0;
    double current_sum = 0.0;
    std::queue<int> vals;

   public:
    MovingAverage(int size) : n_size(size) {}

    double next(int val) {
        this->current_sum += static_cast<double>(val);
        if (this->vals.size() == this->n_size) {
            this->current_sum -= static_cast<double>(this->vals.front());
            this->vals.pop();
        }
        this->vals.push(val);
        return this->current_sum / this->vals.size();
    }
};
