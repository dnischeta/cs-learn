import assert from 'node:assert';
import test from 'node:test';

import { postOrderSearch } from './bt-post-order.ts';

test('postOrderSearch', () => {
  const tree = {
    value: 1,
    left: { value: 2, left: { value: 3 }, right: { value: 4 } },
    right: { value: 5, right: { value: 6 }, left: { value: 9 } },
  };

  assert.deepEqual(postOrderSearch(tree), [
    3,
    4,
    2,
    9,
    6,
    5,
    1
  ]);
});

