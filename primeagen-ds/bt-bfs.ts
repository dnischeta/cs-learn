type BinaryNode<T> = {
  value: T,
  left?: BinaryNode<T>,
  right?: BinaryNode<T>,
};

export function bfs(head: BinaryNode<number>, needle: number): boolean {
  const queue: Array<BinaryNode<number>> = [head];

  while (queue.length > 0) {
    const current = queue.shift()!;

    if (current.value === needle) {
      return true;
    }

    if (current?.left) {
      queue.push(current.left);
    }

    if (current?.right) {
      queue.push(current.right);
    }
  }

  return false;
}

