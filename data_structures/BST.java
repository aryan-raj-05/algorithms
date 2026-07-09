package data_structures;

public class BST {
    private Node head;

    public BST() {}

    public void insert(int x) {
        head = auxInsert(head, x);
    }

    public boolean search(int x) {
        Node iter = head;
        while (iter != null) {
            if (iter.item == x) 
                return true;
            else if (iter.item > x)
                iter = iter.left;
            else
                iter = iter.right;
        }

        return false;
    }

    public void delete(int x) {
        head = auxRemove(head, x);
    }

    private Node auxInsert(Node n, int x) {
        if (n ==  null) {
            return new Node(x);
        }

        if (x == n.item)
            return n;
        else if (x > n.item) 
            n.right = auxInsert(n.right, x);
        else 
            n.left = auxInsert(n.left, x);
        return n;
    }

    private Node auxRemove(Node n, int x) {
        if (n == null) return n;

        if (n.item > x)
            n.left = auxRemove(n.left, x);
        else if (n.item < x)
            n.right = auxRemove(n.right, x);
        else {
            if (n.left == null)
                return n.right;
            if (n.right == null)
                return n.left;
            Node successor = getSuccessor(n);
            n.item = successor.item;
            n.right = auxRemove(n.right, successor.item);
        }
        return n;
    }

    private Node getSuccessor(Node curr) {
        curr = curr.right;
        while (curr != null && curr.left != null) {
            curr = curr.left;
        }
        return curr;
    }

    private static class Node {
        int item;
        Node left;
        Node right;

        Node(int item) {
            this.item = item;
        }
    }
}
