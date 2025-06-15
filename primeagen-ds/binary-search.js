// [left, right) - always
export function binarySearch(haystack, needle) {
  let left = 0;
  let right = haystack.length;

  while (left < right) {
    const middleIdx = left + Math.floor((right - left) / 2);
    const middle = haystack[middleIdx];

    if (middle === needle) {
      return true;
    } else if (needle < middle) {
      right = middleIdx;
    } else {
      left = middleIdx + 1;
    }
  }

  return false;
}

