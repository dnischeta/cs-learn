function qs(arr, lo, hi) {
  if (hi - lo < 1) {
    return;
  }

  const pivotIdx = partition(arr, lo, hi);

  qs(arr, lo, pivotIdx - 1);
  qs(arr, pivotIdx + 1, hi);
}

function partition(arr, lo, hi) {
  const pivotIdx = lo + Math.floor((hi - lo) / 2);
  const pivot = arr[pivotIdx];

  // Swap pivot with arr[hi] to make further iteration simplier
  arr[pivotIdx] = arr[hi];
  arr[hi] = pivot;

  let idx = lo - 1;

  for (let i = lo; i < hi; i++) {
    if (arr[i] <= pivot) {
      idx++;
      const tmp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = tmp;
    }
  }

  idx++;
  arr[hi] = arr[idx];
  arr[idx] = pivot;

  return idx;
}

export function quickSort(arr) {
  qs(arr, 0, arr.length - 1);
}

