import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;

public class Path {
    private Graph G;
    private int s; // 遍历的起始点
    private int t;

    private int[] pre;

    public Path(Graph G, int s, int t){
        G.validateVertex(s);
        G.validateVertex(t);

        this.G = G;
        this.s = s;
        this.t = t;

        pre = new int[G.V()];
        for (int i = 0; i < pre.length; i++) {
            pre[i] = -1;
        }

        pre[s] = s; // 把源头的源头设为自己
        dfs(s);
    }

    private boolean dfs(int v){
        if(v == t) return true;

        for (int w: G.adj(v)) {
            if (pre[w] == -1) {
                pre[w] = v;
                if(dfs(w)) return true;
            }
        }
        return false;
    }

    public boolean isConnetedTo(){
        return pre[t] != -1;
    }

    public Iterable<Integer> path(){
        ArrayList<Integer> res = new ArrayList<>();
        if(!isConnetedTo()) return res;

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
        Path p = new Path(g, 0, 6);
        System.out.println(p.path());
    }
}
