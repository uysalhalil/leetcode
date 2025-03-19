var findMaxAverage = function (nums, k) {
  // Calculate the initial sum of the first window
  let sum = 0;
  for (let i = 0; i < k; i++) {
    sum += nums[i];
  }

  let maxAvg = sum / k;

  // Slide the window across the array
  for (let i = k; i < nums.length; i++) {
    sum += nums[i] - nums[i - k];
    maxAvg = Math.max(maxAvg, sum / k);
  }

  return maxAvg;
};
