package data_structures;

import java.util.NoSuchElementException;

public class LinkedList<T> {
    private Node<T> head;
    private Node<T> tail;
    private int size;

    public LinkedList() {
        head = tail = null;
        this.size = 0;
    }

    public void addFirst(T item) {
        if (isEmpty()) {
            head = tail = new Node<>(item);
        } else {
            var newHead = new Node<>(item, head, null);
            head.prev = newHead;
            head = newHead;
        }

        size++;
    }

    public T removeFirst() {
        if (isEmpty()) throw new NoSuchElementException();

        if (size == 1) {
            var tmp = head;
            head = tail = null;
            size = 0;
            return tmp.item;
        }

        var tmp = head;
        head = head.next;
        head.prev = null;
        tmp.next = null;
        size--;
        return tmp.item;
    }

    public void addLast(T item) {
        if (isEmpty()) {
            head = tail = new Node<>(item);
        } else {
            var newTail = new Node<>(item, null, tail);
            tail.next = newTail;
            tail = newTail;
        }

        size++;
    }

    public T removeLast() {
        if (isEmpty()) throw new NoSuchElementException();

        if (size == 1) {
            var tmp = head;
            head = tail = null;
            size = 0;
            return tmp.item;
        }

        var tmp = tail;
        tail = tail.prev;
        tail.next = null;
        tmp.prev = null;
        size--;
        return tmp.item;
    }

    public T get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }

        if (index == 0) return head.item;
        if (index == size - 1) return tail.item;

        var current =  head;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }

        return current.item;
    }

    public int length() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public String toString() {
        if (isEmpty()) return "[]";
        StringBuilder s = new StringBuilder("[");

        var i = head;
        while (i.next != null) {
            s.append(i.item).append(", ");
            i = i.next;
        }

        return s.append(i.item).append("]").toString();
    }

    private static class Node<T> {
        T item;
        Node<T> next;
        Node<T> prev;

        Node(T item) {
            this.item = item;
            this.next = this.prev = null;
        }

        Node(T item, Node<T> next, Node<T> prev) {
            this.item = item;
            this.next = next;
            this.prev = prev;
        }
    }
}
