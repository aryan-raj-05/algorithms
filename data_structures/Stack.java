package data_structures;

import java.util.NoSuchElementException;

public class Stack<T> {
    private LinkedList<T> list;

    public Stack() {
        list = new LinkedList<>();
    }

    public void push(T item) {
        list.addFirst(item);
    }

    public T pop() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        return list.removeFirst();
    }

    public T peek() {
        return list.get(0);
    }

    public int length() {
        return list.length();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }
}
