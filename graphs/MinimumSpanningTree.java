package graphs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import data_structures.UnionFind;

public class MinimumSpanningTree {
    // edges[][] is a n x 3 array
    // containing values (edge1, edge2, weight)
    public static List<int[]> kruskals(int n, int[][] edges) {
        Arrays.sort(
            edges, 
            (e1, e2) -> Integer.compare(e1[2], e2[2])
        );

        UnionFind uf = new UnionFind(n);
        List<int[]> mst = new ArrayList<>();

        for (int[] e : edges) {
            int u = e[0], v = e[1];

            if (!uf.isConnected(u, v)) {
                uf.union(u, v);
                mst.add(e);
            }
        }

        return mst;
    }

    // TODO
    public static List<int[]> prims(int n, int[][] edges) {

    }
}
