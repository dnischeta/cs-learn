type Node<T> = { value: T; prev?: Node<T>; };

export class Stack<T> {
  public length = 0;
  private head?: Node<T>;

  constructor() { }

  peek(): T | undefined {
    return this.head?.value;
  }

  push(value: T) {
    this.head = { value, prev: this.head };
    this.length++;
  }

  pop(): T | undefined {
    if (!this.head) {
      return undefined;
    }

    const head = this.head;
    this.length--;
    this.head = head.prev;
    return head.value;
  }
}
