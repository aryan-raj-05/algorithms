package graphs;

import java.util.ArrayList;
import java.util.List;

public class DFS {
    public static List<Integer> traverse(Graph g, int startVertex) {
        if (startVertex < 0 || startVertex >= g.vertexCount()) {
            throw new IllegalArgumentException();
        }

        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[g.vertexCount()];
        dfsRecurse(g, visited, result, startVertex);
        return result;
    }

    private static void dfsRecurse(Graph g, boolean[] visited, List<Integer> result, int v) {
        result.add(v);
        visited[v] = true;

        for (int neighbor: g.neighbors(v)) {
            if (!visited[neighbor]) {
                dfsRecurse(g, visited, result, neighbor);
            }
        }
    }
}
