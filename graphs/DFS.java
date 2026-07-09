package graphs;

import java.util.ArrayList;
import java.util.List;

public class DFS {
    public static List<Integer> traverse(int n, int[][] edges, int startVertex) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
        }

        List<Integer> result = new ArrayList<>();

        aux(graph, new boolean[n], result, startVertex);

        return result;
    }

    private static void aux(
        List<List<Integer>> graph,
        boolean[] visited,
        List<Integer> result,
        int v
    ) {
        visited[v] = true;
        result.add(v);

        for (int nei : graph.get(v)) {
            if (!visited[nei]) 
                aux(graph, visited, result, nei);
        }
    }
}
