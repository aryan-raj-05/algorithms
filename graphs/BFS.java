package graphs;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class BFS {
    public static List<Integer> traverse(Graph g, int startVertex) {
        if (startVertex < 0 || startVertex >= g.vertexCount()) {
            throw new IllegalArgumentException();
        }

        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[g.vertexCount()];
        Queue<Integer> q = new ArrayDeque<>();

        visited[startVertex] = true;
        q.add(startVertex);

        while (!q.isEmpty()) {
            int vertex = q.poll();
            result.add(vertex);

            for (int neighbor: g.neighbors(vertex)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.add(neighbor);
                }
            }
        }

        return result;
    }
}
