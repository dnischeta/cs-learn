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
  walk(node.right, path);

  // post
  path.push(node.value);
}

export function postOrderSearch(head: Node<number>): number[] {
  const path: number[] = [];

  walk(head, path);

  return path;
}

