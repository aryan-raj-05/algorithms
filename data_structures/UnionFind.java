package data_structures;

public class UnionFind {
    int[] parent;
    int[] size;
    int maxElement;

    public UnionFind(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("n must be greater than 0");
        }

        parent = new int[n];
        size = new int[n];
        maxElement = n - 1;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public void union(int p, int q) {
        validate(p);
        validate(q);

        int r1 = find(p);
        int r2 = find(q);

        if (r1 == r2) return;

        if (size[r1] > size[r2]) {
            parent[r2] = r1;
            size[r1] += size[r2];
        } else {
            parent[r1] = r2;
            size[r2] += size[r1];
        }
    }

    public boolean isConnected(int p, int q) {
        validate(p);
        validate(q);

        return find(p) == find(q);
    }

    private int find(int p) {
        if (parent[p] != p) {
            parent[p] = find(parent[p]);
        }

        return parent[p];
    }

    private void validate(int p) {
        if (p < 0 || p > maxElement) {
            throw new IllegalArgumentException();
        }
    }
}
