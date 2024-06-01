/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var longestOnes = function (nums, k) {
  let l = 0,
    max_length = 0;

  for (let i = 0; i < nums.length; ++i) {
    if (nums[i] === 0) {
      --k;
    }

    if (k < 0) {
      if (nums[l] === 0) {
        ++k;
      }
      ++l;
    }

    max_length = Math.max(max_length, i - l + 1);
  }
  return max_length;
};
