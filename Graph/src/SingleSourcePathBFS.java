import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class SingleSourcePathBFS {

    private Graph G;
    private boolean[] visited;
    private int s;
    private int[] pre;

    public SingleSourcePathBFS(Graph G, int s){
        this.G = G;
        this.s = s;
        visited = new boolean[G.V()];
        pre = new int[G.V()];

        for (int i = 0; i < G.V(); i++) {
            pre[i] = -1;
        }

        bfs(s);
    }

    private void bfs(int s){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        visited[s] = true;
        pre[s] = s;
        while(!queue.isEmpty()){
            int v = queue.remove();

            for(int w: G.adj(v)){
                if(!visited[w]){
                    queue.add(w);
                    visited[w] = true;
                    pre[w] = v;
                }
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

    public static void main(String[] args)
    {
        Graph g = new Graph("g.txt");
        SingleSourcePathBFS ssPathBFS = new SingleSourcePathBFS(g, 0);
        System.out.println(ssPathBFS.path(6));
    }
}
