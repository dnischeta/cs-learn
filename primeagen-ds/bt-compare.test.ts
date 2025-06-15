import assert from 'node:assert';
import test from 'node:test';

import { compare } from './bt-compare.ts';

test('compare', () => {
  assert.strictEqual(compare({ value: 1, left: null, right: null }, { value: 1, left: null, right: null }), true);
  assert.strictEqual(compare({ value: 1, left: null, right: null }, { value: 2, left: null, right: null }), false);
});

