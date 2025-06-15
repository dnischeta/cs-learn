import assert from 'node:assert';
import test from 'node:test';

import { preOrderSearch } from './bt-pre-order.ts';

test('preOrderSearch', () => {
  const tree = {
    value: 1,
    left: { value: 2, left: { value: 3 }, right: { value: 4 } },
    right: { value: 5, right: { value: 6 }, left: { value: 9 } },
  };

  assert.deepEqual(preOrderSearch(tree), [
    1,
    2,
    3,
    4,
    5,
    9,
    6
  ]);
});

