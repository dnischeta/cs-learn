export function linearSearch(haystack, needle) {
  for (let idx = 0; idx < haystack.length; idx++) {
    if (haystack[idx] === needle) {
      return true;
    }
  }

  return false;
}

