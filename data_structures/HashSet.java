package data_structures;

// only store int values
public class HashSet {
    private Node[] table;
    private int size;
    private static final double LOAD_FACTOR = 0.75;

    public HashSet() {
        table = new Node[32];
        size = 0;
    }

    public void put(int x) {
        if ((double) size / table.length >= LOAD_FACTOR) {
            resize();
        }

        int bucket = findBucketPos(x);
        if (table[bucket] == null) {
            table[bucket] = new Node(x);
            size++;
            return;
        }

        Node n = table[bucket];
        while (true) {
            if (n.item == x) return;
            if (n.next == null) {
                n.next = new Node(x);
                size++;
                return;
            }
            n = n.next;
        }
    }

    public boolean contains(int x) {
        int bucket = findBucketPos(x);
        if (table[bucket] == null) return false;

        Node iter = table[bucket];
        while (iter != null) {
            if (iter.item == x) {
                return true;
            }
            iter = iter.next;
        }

        return false;
    }

    public void remove(int x) {
        int bucket = findBucketPos(x);

        if (table[bucket] == null) return;

        Node prev = null, curr = table[bucket];
        while (curr != null) {
            if (curr.item == x) {
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

    private void resize() {
        Node[] oldTable = table;
        table = new Node[oldTable.length * 2];
        size = 0;

        for (Node head : oldTable) {
            for (Node curr = head; curr != null; curr = curr.next) {
                int bucket = findBucketPos(curr.item);
                Node n = new Node(curr.item, table[bucket]);
                table[bucket] = n;
                size++;
            }
        }
    }

    private int findBucketPos(int x) {
        return (x & 0x7fffffff) % table.length;
    }

    private static class Node {
        int item;
        Node next;

        Node(int item) {
            this.item = item;
        }

        Node(int item, Node next) {
            this.item = item;
            this.next = next;
        }
    }
}
