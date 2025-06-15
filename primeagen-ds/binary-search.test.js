import assert from 'node:assert';
import test from 'node:test';

import { binarySearch } from './binary-search.js';

test('binarySearch', () => {
  assert.strictEqual(binarySearch([1,2,3], 0), false);
  assert.strictEqual(binarySearch([1,2,3], 3), true);
});
