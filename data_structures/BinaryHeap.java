package data_structures;

import java.util.ArrayList;
import java.util.NoSuchElementException;

public class BinaryHeap { // Max Heap Implementation
    private ArrayList<Integer> heap;
    
    public BinaryHeap() {
        heap = new ArrayList<>();
    }

    public BinaryHeap(int[] nums) {
        heap = new ArrayList<>();
        for (int num: nums) heap.add(num);

        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    public void insert(int val) {
        heap.add(val);
        siftUp(heap.size() - 1);
    }

    public int peek() {
        if (isEmpty()) throw new NoSuchElementException();
        return heap.get(0);
    }

    public int poll() {
        if (isEmpty()) throw new NoSuchElementException();

        return removeAt(0);
    }

    public boolean remove(int val) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap.get(i) == val) {
                removeAt(i);
                return true;
            }
        }

        return false;
    }

    public boolean contains(int val) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap.get(i) == val) return true;
        }
        return false;
    }

    public int size() {
        return heap.size();
    }

    public boolean isEmpty() {
        return heap.size() == 0;
    }

    private int removeAt(int index) {
        if (index >= heap.size()) throw new IndexOutOfBoundsException();

        if (index == heap.size() - 1) {
            return heap.removeLast();
        }

        int last = heap.size() - 1;
        swap(heap, index, last);
        int valToRemove = heap.removeLast();

        int parent = (index - 1) / 2;
        if (index > 0 && heap.get(parent) < heap.get(index)) {
            siftUp(index);
        } else {
            siftDown(index);
        }

        return valToRemove;
    }

    private void siftDown(int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < heap.size() && heap.get(left) > heap.get(largest)) {
                largest = left;
            }

            if (right < heap.size() && heap.get(right) > heap.get(largest)) {
                largest = right;
            }

            if (largest == i) break;

            swap(heap, i, largest);
            i = largest;
        }
    }

    private void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap.get(parent) >= heap.get(i))
                break;
            swap(heap, i, parent);
            i = parent;
        }
    }

    private void swap(ArrayList<Integer> list, int i, int j) {
        int temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    }
}
