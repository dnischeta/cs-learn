type BinaryNode<T> = {
  value: T,
  left: BinaryNode<T> | null,
  right: BinaryNode<T> | null,
};

export function compare(left: BinaryNode<number> | null, right: BinaryNode<number> | null): boolean {
  if (left === null && right === null) {
    return true;
  }

  if (left === null || right === null) {
    return false;
  }

  if (left.value !== right.value) {
    return false;
  }

  return compare(left.left, right.left) && compare(left.right, right.right);
}

