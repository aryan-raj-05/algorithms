package data_structures;

import java.util.NoSuchElementException;

public class Stack {
    private int[] arr;
    private int top;

    public Stack() {
        arr = new int[8];
        top = -1;
    }

    public Stack(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException();
        }

        arr = new int[capacity];
        top = -1;
    }

    public void push(int item) {
        if (top + 1 == arr.length) {
            resize();
        }

        arr[++top] = item;
    }

    public int pop() {
        if (top == -1) {
            throw new NoSuchElementException();
        }

        return arr[top--];
    }

    public int peek() {
        if (top == -1) {
            throw new NoSuchElementException();
        }

        return arr[top];
    }

    public int size() {
        return top + 1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    private void resize() {
        int[] newArr = new int[arr.length * 2];
        System.arraycopy(arr, 0, newArr, 0, top + 1);
        arr = newArr;
    }
}
