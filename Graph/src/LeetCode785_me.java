import java.util.LinkedList;
import java.util.Queue;

public class LeetCode785_me {

    public LeetCode785_me(){ }

    private Queue<Integer> queue;
    private int[] visited;
    private int[][] graph;

    public boolean isBipartite(int[][] graph){
        this.graph = graph;

        int V = graph.length;
        visited = new int[V];

        for (int i = 0; i < V; i++) {
            visited[i] = -1;
        }

        for (int i = 0; i < V; i++) {
            if(visited[i] == -1){
                if(bfs(i)) return false;
            }
        }
        return true;
    }

    // 是否存在不是二分图的证据
    public boolean bfs(int s){
        queue = new LinkedList<>();
        queue.add(s);
        visited[s] = 0;
        while(!queue.isEmpty()){
            int v = queue.remove();
            for (int w: graph[v]) {
                if(visited[w] == -1){
                    queue.add(w);
                    visited[w] = 1 - visited[v];
                }else if(visited[w] == visited[v]){
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args)
    {
        LeetCode785_me leetCode785 = new LeetCode785_me();
        int[][] temp = new int[][]{
                {1,3},{0,2},{1,3},{0,2}
        };
        System.out.println(leetCode785.isBipartite(temp));
    }
}
