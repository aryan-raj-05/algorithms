package graphs;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class BFS {
    public static List<Integer> traverse(int n, int[][] edges, int startVertex) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
        }

        Queue<Integer> queue = new ArrayDeque<>();
        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[n];

        queue.offer(startVertex);
        visited[startVertex] = true;

        while (!queue.isEmpty()) {
            int v = queue.poll();
            result.add(v);

            for (int nei : graph.get(v)) {
                if (!visited[nei]) {
                    queue.offer(nei);
                    visited[nei] = true;
                }
            }
        }

        return result;
    }
}
