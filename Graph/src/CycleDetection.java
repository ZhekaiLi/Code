import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;

public class CycleDetection {
    private Graph G;
    private boolean hasCycle = false;
    private int s; // 环的一个起点
    private int t; // 环的一个”终点“，该“终点”与起点相邻且相连

    private int[] pre;

    public CycleDetection(Graph G){
        this.G = G;

        pre = new int[G.V()];
        for (int i = 0; i < pre.length; i++) {
            pre[i] = -1;
        }

        // 保证检测了每个联通分量
        for (int v = 0; v < G.V(); v++) {
            if(pre[v] == -1) {
                pre[v] = v; // 把源头的源头设为自己
                if(dfs(v)){
                    hasCycle = true;
                    break;
                }
            }
        }
    }

    // 从顶点 v 开始，判断图中是否有环
    private boolean dfs(int v){
        for (int w: G.adj(v)) {
            if (pre[w] == -1) {
                pre[w] = v;
                if(dfs(w)) return true;
            }else {
                if(pre[v] != w) {
                    s = w;
                    t = v;
                    return true;
                }
            }
        }
        return false;
    }

    public boolean hasCycle(){
        return hasCycle;
    }

    public Iterable<Integer> path(){
        ArrayList<Integer> res = new ArrayList<>();

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
        CycleDetection cd = new CycleDetection(g);
        System.out.println(cd.hasCycle());
        System.out.println(cd.path());
    }
}
