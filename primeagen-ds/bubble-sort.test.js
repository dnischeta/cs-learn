import assert from 'node:assert';
import test from 'node:test';

import { bubbleSort } from './bubble-sort.js';

test('binarySearch', () => {
  assert.deepEqual(bubbleSort([5, 2, 3]), [2, 3, 5]);
  assert.deepEqual(bubbleSort([3, 2, 1]), [1, 2, 3]);
});
