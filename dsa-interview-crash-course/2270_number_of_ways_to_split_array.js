var waysToSplitArray = function (nums) {
  // computes the total sum of the array (basically end of prefix sum)
  const total_sum = nums.reduce((acc, num) => acc + num, 0);

  // variable for number of ways to split
  let num_ways = 0;
  // prefix running sum
  let prefix_sum = 0;
  nums
    // .slice creates a copy of the array starting from 0 to end-1
    .slice(0, -1)
    // for each iterates over the newly created sliced array to check if the prefix sum is greater than the left sum
    .forEach((num) => {
      prefix_sum += num;
      if (prefix_sum >= total_sum - prefix_sum) {
        ++num_ways;
      }
    });
  return num_ways;
};
