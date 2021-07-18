import java.util.ArrayList;

public class CC {

    private Graph G;
    private int[] visited;
    private int ccount = 0;

    public CC(Graph G){
        this.G = G;
        visited = new int[G.V()];
        for (int i = 0; i < visited.length; i++) {
            visited[i] = -1;
        }

        // 外层 for 循环可以实现对非连通图所有结点的遍历
        // 如果直接使用 dfs(0)，则无法遍历到与结点0不相通的节点
        for (int v = 0; v < G.V(); v++) {
            if (visited[v] == -1) {
                dfs(v, ccount);
                ccount++;
            }
        }
    }

    //
    public ArrayList<Integer>[] components(){
        ArrayList<Integer>[] res = new ArrayList[ccount];
        for (int i = 0; i < ccount; i++) {
            res[i] = new ArrayList<>();
        }
        for (int v = 0; v < G.V(); v++) {
            res[visited[v]].add(v);
        }
        return res;
    }

    public boolean isConnected(int v, int w)
    {
        G.validateVertex(v);
        G.validateVertex(w);
        return visited[v] == visited[w];
    }

    private void dfs(int v, int ccid){
        visited[v] = ccid;
        for (int w: G.adj(v)) {
            if (visited[w] == -1)
                dfs(w, ccid);
        }
    }

    public int ccount(){
        return ccount;
    }

    public static void main(String[] args) {
        Graph g = new Graph("g.txt");
        CC cc = new CC(g);
        System.out.println(cc.ccount());
        ArrayList<Integer>[] comp = cc.components();
        for (int ccid = 0; ccid < comp.length; ccid++) {
            System.out.print(ccid + " : ");
            for(int w: comp[ccid])
                System.out.print(w + " ");
            System.out.println();
        }
    }
}
