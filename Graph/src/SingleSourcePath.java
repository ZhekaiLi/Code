import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;

public class SingleSourcePath {
    private Graph G;
    private int s; // 遍历的起始点

    private boolean[] visited;
    private int[] pre;

    public SingleSourcePath(Graph G, int s){
        G.validateVertex(s);

        this.G = G;
        this.s = s;

        visited = new boolean[G.V()];
        pre = new int[G.V()];
        for (int i = 0; i < pre.length; i++) {
            pre[i] = -1;
        }

        pre[s] = s; // 把源头的源头设为自己
        dfs(s);
    }

    private void dfs(int v){
        visited[v] = true;
        for (int w: G.adj(v)) {
            if (!visited[w]) {
                pre[w] = v;
                dfs(w);
            }
        }
    }

    public boolean isConnectedTo(int t){
        G.validateVertex(t);
        return visited[t];
    }

    public Iterable<Integer> path(int t){
        ArrayList<Integer> res = new ArrayList<>();
        if(!isConnectedTo(t)) return res;

        int cur = t;
        while(cur != s){
            res.add(cur);
            cur = pre[cur];
        }
        res.add(s);
        Collections.reverse(res);
        return res;
    }

    public static void main(String[] args) {
        Graph g = new Graph("g.txt");
        SingleSourcePath singleSourcePath = new SingleSourcePath(g, 0);
        System.out.println(singleSourcePath.path(6));
    }
}
