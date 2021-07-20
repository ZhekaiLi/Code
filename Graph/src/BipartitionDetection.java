public class BipartitionDetection {

    private Graph G;
    // -1: 未访问
    // 0: 二分图的一侧
    // 1: 二分图的另一侧
    private int[] colors;
    private boolean isBipartite = true;

    public BipartitionDetection(Graph G){
        this.G = G;
        colors = new int[G.V()];
        for (int i = 0; i < colors.length; i++) {
            colors[i] = -1;
        }

        for (int v = 0; v < G.V(); v++) {
            if (colors[v] == -1) {
                dfs(v, 0);
            }
        }
    }

    // 返回值表示是否检测到了目标图不是二分图的证据
    private boolean dfs(int v, int color){
        colors[v] = color;
        for (int w: G.adj(v)) {
            if (colors[w] == -1) {
                if (dfs(w, 1-color)) return true;
            }else if(colors[w] == colors[v]){
                isBipartite = false;
                return true;
            }
        }
        return false;
    }

    public boolean isBipartite(){
        return isBipartite;
    }

    public int[] visited(){
        return colors;
    }

    public static void main(String[] args) {
        Graph g = new Graph("g.txt");
        BipartitionDetection bpd = new BipartitionDetection(g);
        System.out.println(bpd.isBipartite());
        for (int i = 0; i < bpd.visited().length; i++) {
            System.out.print(bpd.visited()[i] + " ");
        }
    }
}
