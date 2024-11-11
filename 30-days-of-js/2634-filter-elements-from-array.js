var filter = function (arr, fn) {
  let i = 0;
  let newArr = [];
  while (i < arr.length) {
    if (fn(arr[i], i)) {
      newArr.push(arr[i]);
    }
    ++i;
  }
  return newArr;
};
