import assert from 'node:assert';
import test from 'node:test';

import { inOrderSearch } from './bt-in-order.ts';

test('inOrderSearch', () => {
  const tree = {
    value: 1,
    left: { value: 2, left: { value: 3 }, right: { value: 4 } },
    right: { value: 5, right: { value: 6 }, left: { value: 9 } },
  };

  assert.deepEqual(inOrderSearch(tree), [
    3,
    2,
    4,
    1,
    9,
    5,
    6
  ]);
});

