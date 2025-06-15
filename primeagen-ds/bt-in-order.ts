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

  // recurse
  walk(node.left, path);
  path.push(node.value);
  walk(node.right, path);

  // post
}

export function inOrderSearch(head: Node<number>): number[] {
  const path: number[] = [];

  walk(head, path);

  return path;
}

