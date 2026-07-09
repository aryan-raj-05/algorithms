package graphs;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class TopologicalSort {
    // Time: O(V + E)
    // Space: O(V + E)
    public static int[] kahns(int n, int[][] edges) { // directed
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        int[] res = new int[n];
        int rp = 0;
        
        Queue<Integer> queue = new ArrayDeque<>();
        int[] indeg = new int[n];

        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            indeg[e[1]]++;
        }

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                queue.offer(i);
            }
        }

        while (!queue.isEmpty()) {
            int v = queue.poll();
            res[rp++] = v;

            for (int nei : graph.get(v)) {
                if (--indeg[nei] == 0) {
                    queue.offer(nei);
                }
            }
        }

        if (rp != n) {
            throw new IllegalArgumentException("Graph is cyclic");
        }

        return res;
    }
}
