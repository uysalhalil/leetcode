use std::cmp;

impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let mut sub_sum: i64 = 0;
        let mut max_sum: i64 = 0;

        for i in 0..k as usize {
            sub_sum += nums[i] as i64;
        }

        max_sum = sub_sum;
        for i in k as usize..nums.len() {
            sub_sum -= nums[i - k as usize] as i64;
            sub_sum += nums[i] as i64;
            max_sum = cmp::max(max_sum, sub_sum as i64);
        }

        return max_sum as f64 / k as f64;
    }
}
