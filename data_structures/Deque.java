package data_structures;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<T> implements Iterable<T> {
    T[] array;
    int head;
    int tail;
    int size;

    @SuppressWarnings("unchecked")
    public Deque() {
        array = (T[])new Object[8];
        head = tail = 0;
        size = 0;
    }
    
    public T getFirst() {
        if (isEmpty()) throw new NoSuchElementException();
        return array[next(head)];
    }

    public T getLast() {
        if (isEmpty()) return null;
        return array[tail];
    }

    public T get(int index) {
        return array[mapPublicToInternalIndex(index)];
    }

    public void set(int index, T elem) {
        array[mapPublicToInternalIndex(index)] = elem;
    }

    public void addFirst(T elem) {
        if (isFull()) resize();
        array[head] = elem;
        head = prev(head);
        size++;
    }

    public void addLast(T elem) {
        if (isFull()) resize();
        tail = next(tail);
        array[tail] = elem;
        size++;
    }

    public T removeFirst() {
        if (isEmpty()) throw new NoSuchElementException();
        
        head = next(head);
        T val = array[head];
        array[head] = null;
        size--;
        return val;
    }

    public T removeLast() {
        if (isEmpty()) throw new NoSuchElementException();

        T val = array[tail];
        array[tail] = null;
        tail = prev(tail);
        size--;
        return val;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public String toString() {
        if (isEmpty()) return "";

        StringBuilder s = new StringBuilder("[");

        for (int i = next(head); i != next(tail); i = next(i)) {
            s.append(array[i].toString()).append(',');
        }

        s.setLength(s.length() - 1);
        s.append(']');

        return s.toString();
    }

    private int next(int x) {
        return (x + 1) % array.length;
    }

    private int prev(int x) {
        return x == 0 ? array.length - 1 : x - 1;
    }

    private boolean isFull() {
        return size == array.length;
    }

    private int mapPublicToInternalIndex(int idx) {
        if (idx >= size || idx < 0) {
            throw new IndexOutOfBoundsException();
        }

        int actualIndex = next(head) + idx;

        return (actualIndex >= array.length) 
            ? actualIndex - array.length 
            : actualIndex;
    }

    @SuppressWarnings("unchecked")
    private void resize() {
        int newCapacity = array.length * 2;
        T[] newArray = (T[]) new Object[newCapacity];

        int j = next(head);
        for (int i = 0; i < size; i++) {
            newArray[i] = array[j];
            j = next(j);
        }

        array = newArray;
        head = newCapacity - 1;
        tail = size - 1;
    }

    @Override
    public Iterator<T> iterator() {
        return new DequeIterator();
    }

    private class DequeIterator implements Iterator<T> {
        private int i = 0;

        @Override
        public boolean hasNext() {
            return i < size;
        }

        @Override
        public T next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }

            return get(i++);
        }
    }
}
