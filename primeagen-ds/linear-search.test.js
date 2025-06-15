import assert from 'node:assert';
import test from 'node:test';

import { linearSearch } from './linear-search.js';

test('linearSearch', () => {
  assert.strictEqual(linearSearch([1,2,3], 0), false);
  assert.strictEqual(linearSearch([1,2,3], 3), true);
});
