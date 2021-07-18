import java.util.ArrayList;

public class GraphDFS {

    private Graph G;
    private boolean[] visited;
    private ArrayList<Integer> preOrder = new ArrayList<Integer>();  // 先序遍历结果
    private ArrayList<Integer> postOrder = new ArrayList<Integer>(); // 后序遍历结果

    public GraphDFS(Graph G){
        this.G = G;
        visited = new boolean[G.V()];

        // 外层 for 循环可以实现对非连通图所有结点的遍历
        // 如果直接使用 dfs(0)，则无法遍历到与结点0不相通的节点
        for (int v = 0; v < G.V(); v++) {
            if (!visited[v])
                dfs(v);
        }
    }

    private void dfs(int v){
        visited[v] = true;
        preOrder.add(v);
        for (int w: G.adj(v)) {
            if (!visited[w])
                dfs(w);
        }
        postOrder.add(v);
    }

    public Iterable<Integer> preOrder(){
        return preOrder;
    }

    public Iterable<Integer> postOrder(){
        return postOrder;
    }

    public static void main(String[] args) {
        Graph g = new Graph("g.txt");
        GraphDFS graphDFS = new GraphDFS(g);
        System.out.println(graphDFS.preOrder());
        System.out.println(graphDFS.postOrder());
    }
}
