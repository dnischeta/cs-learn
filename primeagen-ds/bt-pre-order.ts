type Node<T> = {
  value: T,
  left?: Node<T>,
  right?: Node<T>,
};

function walk<T>(node: Node<T> | undefined, path: T[]): void {
  if (!node) {
    return;
  }

  // pre
  path.push(node.value);

  // recurse
  walk(node.left, path);
  walk(node.right, path);

  // post
}

export function preOrderSearch(head: Node<number>): number[] {
  const path: number[] = [];

  walk(head, path);

  return path;
}

