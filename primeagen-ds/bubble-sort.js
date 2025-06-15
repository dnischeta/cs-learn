export function bubbleSort(arr) {
  for (let right = arr.length - 1; right > 0; right--) {
    for (let idx = 0; idx < right; idx++) {
      if (arr[idx] > arr[idx + 1]) {
        [arr[idx], arr[idx + 1]] = [arr[idx + 1], arr[idx]]
      }
    }
  }

  return arr;
}

