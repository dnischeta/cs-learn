export class MinHeap {
  private data: number[];
  private length: number;

  constructor() {
    this.data = [];
    this.length = 0;
  }

  public insert(value: number): void {
    this.data[this.length] = value;
    this.heapifyUp(this.length);
    this.length++;
  }

  public delete(): number | undefined {
    if (this.length === 0) {
      return undefined;
    }

    const out = this.data[0];
    if (this.length === 1) {
      this.length--;
      return out;
    }

    this.data[0] = this.data[this.length - 1];
    this.length--;
    this.heapifyDown(0);
    return out;
  }

  private parentIdx(idx: number): number {
    return Math.floor((idx - 1) / 2);
  }

  private leftChildIdx(idx: number): number {
    return 2 * idx + 1;
  }

  private rightChildIdx(idx: number): number {
    return 2 * idx + 2;
  }

  private heapifyUp(idx: number) {
    if (idx === 0) {
      return;
    }

    const parentIdx = this.parentIdx(idx);
    const parent = this.data[parentIdx];

    if (this.data[idx] < parent) {
      this.data[parentIdx] = this.data[idx];
      this.data[idx] = parent;
      this.heapifyUp(parentIdx);
    }
  }

  private heapifyDown(idx: number) {
    if (idx >= this.length) {
      return;
    }

    const lIdx = this.leftChildIdx(idx);
    const rIdx = this.rightChildIdx(idx);

    if (lIdx >= this.length) {
      return;
    }

    const v = this.data[idx];
    const lV = this.data[lIdx];
    const rV = this.data[rIdx];

    if (lV < rV && lV < v) {
      this.data[lIdx] = v;
      this.data[idx] = lV;
      this.heapifyDown(lIdx);
    } else if (rV < lV && rV < v) {
      this.data[rIdx] = v;
      this.data[idx] = rV;
      this.heapifyDown(rIdx);
    }
  }
}
