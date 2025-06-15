export class Queue {
  #head = null;
  #tail = null;

  constructor() {
    this.length = 0;
  }

  peek() {
    if (!this.#head) {
      return undefined;
    }
    return this.#head.value;
  }

  enqueue(value) {
    this.length++;
    if (!this.#tail) {
      this.#head = this.#tail = { value, next: null };
    } else {

      this.#tail.next = { value, next: null };
      this.#tail = this.#tail.next;
    }
  }

  deque() {
    if (!this.#head) {
      return undefined;
    }
    const head = this.#head;
    this.#head = this.#head.next;
    head.next = null;
    this.length--;
    if (this.#tail === head) {
      this.#tail = null;
    }
    return head.value;
  }
}

