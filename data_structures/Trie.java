package data_structures;

public class Trie {
    private Node root;

    public Trie() {
        root = new Node();
    }

    public void insert(String word) {
        Node cur = root;
        
        for (char c : word.toCharArray()) {
            int i = c - 'a';

            if (cur.children[i] == null) {
                cur.children[i] = new Node();
            }

            cur = cur.children[i];
        }

        cur.isWord = true;
    }

    public boolean search(String word) {
        Node cur = root;

        for (char c : word.toCharArray()) {
            int i = c - 'a';
            if (cur.children[i] == null) return false;
            cur = cur.children[i];
        }

        return cur.isWord;
    }

    public boolean startsWith(String prefix) {
        Node cur = root;

        for (char c : prefix.toCharArray()) {
            int i = c - 'a';
            if (cur.children[i] == null) return false;
            cur = cur.children[i];
        }

        return true;
    }

    private static class Node {
        Node[] children;
        boolean isWord;

        Node() {
            children = new Node[26];
            isWord = false;
        }
    }
}