var runningSum = function (nums) {
  return (
    nums
      // mapping function creates a copy of the array
      .map(
        // outer function that returns the manipulated version
        ((sum) => {
          (value) => {
            sum += value;
          };
        })(0)
      )
  );
};
