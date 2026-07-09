package graphs;

import java.util.ArrayList;
import java.util.List;

public class CycleDetection {
    public static boolean find(int[][] edges) { // directed graph
        // 1. build adj list
        List<List<Integer>> graph = new ArrayList<>();

        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];

            while (u >= graph.size() || v >= graph.size()) {
                graph.add(new ArrayList<>());
            }

            graph.get(u).add(v);
        }

        int n = graph.size();
        int[] state = new int[n];

        for (int i = 0; i < n; i++) {
            if (state[i] == 0 && dfs(graph, state, i)) {
                return true;
            }
        }

        return false;
    }

    private static boolean dfs(
        List<List<Integer>> graph, 
        int[] state, 
        int v
    ) {
        if (state[v] == 1) {
            return true;
        }

        state[v] = 1;
        for (int nei : graph.get(v)) {
            if (state[nei] != 2 && dfs(graph, state, nei)) {
                return true;
            }
        }

        state[v] = 2;
        return false;
    }
}
