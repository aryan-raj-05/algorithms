package graphs;

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

// Adjacency List implementation of Graph
// only works for positive vertex
// from 0 to v specified at initialization
public class GraphAL implements Graph {
    private final List<List<Integer>> list;
    private final int v;
    private final boolean isDirected;

    public GraphAL(int v, boolean isDirected) {
        this.v = v;
        this.isDirected = isDirected;

        list = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            list.add(new ArrayList<>());
        }
    }

    public void join(int v0, int v1) {
        if (v0 < 0 || v0 >= v || v1 < 0 || v1 >= v)
            throw new NoSuchElementException();

        if (!list.get(v0).contains(v1))
            list.get(v0).add(v1);

        if (!isDirected && !list.get(v1).contains(v0))
            list.get(v1).add(v0);
    }

    public void removeEdge(int v0, int v1) {
        if (v0 < 0 || v0 >= v || v1 < 0 || v1 >= v)
            throw new NoSuchElementException();

        list.get(v0).remove(Integer.valueOf(v1));

        if (!isDirected) {
            list.get(v1).remove(Integer.valueOf(v0));
        }
    }

    @Override
    public int vertexCount() {
        return v;
    }

    @Override
    public List<Integer> neighbors(int v) {
        return List.copyOf(list.get(v));
    }

    public String toString() {
        StringBuilder s = new StringBuilder();

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).isEmpty()) continue;
            s.append(i).append(": ");
            for (int j = 0; j < list.get(i).size(); j++)
                s.append(list.get(i).get(j)).append(" ");
            s.append("\n");
        }

        return s.toString();
    }
}
