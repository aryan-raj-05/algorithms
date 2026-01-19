package data_structures;

public class PriorityQueue {
    private final BinaryHeap heap;

    public PriorityQueue() {
        heap = new BinaryHeap();
    }

    public void insert(int elem) {
        heap.insert(elem);
    }

    public int poll() {
        return heap.poll();
    }

    public int peek() {
        return heap.peek();
    }

    public boolean remove(int elem) {
        return heap.remove(elem);
    }

    public boolean contains(int elem) {
        return heap.contains(elem);
    }

    public int size() {
        return heap.size();
    }

    public boolean isEmpty() {
        return heap.isEmpty();
    }
}
