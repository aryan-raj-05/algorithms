package data_structures;

import java.util.NoSuchElementException;

public class Queue {
    private int[] q;
    private int head;
    private int tail;
    private int size;
    private int capacity;

    public Queue() {
        q = new int[8];
        capacity = 8;
        head = tail = 0;
        size = 0;
    }

    public void enqueue(int item) {
        if (isFull()) resize();

        q[tail] = item;
        tail = next(tail);
        size++;
    }

    public int dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }

        int temp = q[head];
        head = next(head);
        size--;
        return temp;
    }

    public int peek() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        return q[head];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    private boolean isFull() {
        return size == capacity;
    }

    private int next(int x) {
        return (x + 1) % capacity;
    }

    private void resize() {
        int[] temp = q;
        int oldCapacity = capacity;

        capacity *= 2;
        q = new int[capacity];

        for (int i = 0; i < size; i++) {
            q[i] = temp[(head + i) % oldCapacity];
        }

        head = 0;
        tail = size;
    }
}
