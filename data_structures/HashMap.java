package data_structures;

import java.util.NoSuchElementException;

// can only store (int, int) pairs
// the capacity should increase to maintain load factor on 0.75
// to resolve collision a linked list shall be maintained
public class HashMap {
    private Node[] table;
    private int size;
    private static final double LOAD_FACTOR = 0.75;

    public HashMap() {
        table = new Node[100];
        size = 0;
    }

    public void put(int key, int value) {
        if ((double) size / table.length >= LOAD_FACTOR) {
            resize();    
        }

        int bucket = findBucketPos(key);

        if (table[bucket] == null) {
            table[bucket] = new Node(key, value);
            size++;
            return;
        }
        
        Node n = table[bucket];
        while (true) {
            if (n.key == key) {
                n.value = value;
                return;
            }

            if (n.next == null) {
                n.next = new Node(key, value);
                size++;
                return;
            }
            n = n.next;
        }
    }

    public int get(int key) {
        int bucket = findBucketPos(key);
        if (table[bucket] == null) {
            throw new NoSuchElementException();
        }

        Node iter = table[bucket];
        while (iter != null) {
            if (iter.key == key) {
                return iter.value;
            }
            iter = iter.next;
        }
        
        throw new NoSuchElementException();
    }

    public void remove(int key) {
        int bucket = findBucketPos(key);
        if (table[bucket] == null) return;

        Node curr = table[bucket];
        Node prev = null;

        while (curr != null) {
            if (curr.key == key) {
                if (prev == null)
                    table[bucket] = curr.next;
                else
                    prev.next = curr.next;
                size--;
                return;
            }
            prev = curr;
            curr = curr.next;
        }
    }

    private int findBucketPos(int key) {
        return (key & 0x7fffffff) % table.length;
    }

    private void resize() {
        Node[] oldTable = table;
        table = new Node[oldTable.length * 2];
        size = 0;

        for (Node head: oldTable) {
            for (Node curr = head; curr != null; curr = curr.next) {
                int bucket = findBucketPos(curr.key);
                Node n = new Node(curr.key, curr.value);
                n.next = table[bucket];
                table[bucket] = n;
                size++;
            }
        }
    }

    private static class Node {
        int key;
        int value;
        Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.next = null;
        }
    }
}
