import assert from 'node:assert';
import test from 'node:test';

import { quickSort } from './quick-sort.js';

test('quickSort', () => {
  const arr1 = [1,2,3,4];
  quickSort(arr1);
  assert.deepEqual(arr1, [1,2,3,4]);

  const arr2 = [4, 2, -1, 150, 99];
  quickSort(arr2);
  assert.deepEqual(arr2, [-1, 2, 4, 99, 150]);
});
