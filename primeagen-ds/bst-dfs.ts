type BinaryNode<T> = {
  value: T,
  left: BinaryNode<T> | null,
  right: BinaryNode<T> | null,
};

function walk(node: BinaryNode<number> | null, needle: number): boolean {
  if (!node) {
    return false;
  }

  if (node.value === needle) {
    return true;
  }

  if (node.value < needle) {
    return walk(node.right, needle);
  }

  return walk(node.left, needle);
}

// O(h), where h - tree height.
//  - O(logN) for perfectly balanced bst tree
//  - O(N) for totally impalanced tree (literally linked list)
export function search(head: BinaryNode<number>, needle: number): boolean {
  return walk(head, needle);
}

