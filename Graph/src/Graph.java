import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;


public class Graph {

    private int V;
    private int E;
    private TreeSet<Integer>[] adj;

    public Graph(String filename){
        File file = new File(filename);

        try (Scanner scanner = new Scanner(file)){
            V = scanner.nextInt();
            if (V < 0) throw new IllegalArgumentException("V must be non-negative");
            adj = new TreeSet[V];
            for (int i = 0; i < V; i++) {
                adj[i] = new TreeSet<Integer>();
            }

            E = scanner.nextInt();
            if (E < 0) throw new IllegalArgumentException("E must be non-negative");
            for (int i = 0; i < E; i++) {
                int a = scanner.nextInt();
                validateVertex(a);
                int b = scanner.nextInt();
                validateVertex(b);
                // 判断是否存在自环边、平行边
                if (a == b) throw new IllegalArgumentException("Self Loop is Detected!");
                if (adj[a].contains(b)) throw new IllegalArgumentException("Parallel Edge is Detected!");

                adj[a].add(b);
                adj[b].add(a);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void validateVertex(int v){
        if (v < 0 || v >= V) throw new IllegalArgumentException("vertex " + v + " is invalid");
    }

    public int V(){
        return V;
    }
    public int E(){
        return E;
    }
    public boolean hasEdge(int v, int w){
        validateVertex(v);
        validateVertex(w);
        return adj[v].contains(w);
    }
    // 返回顶点的邻边
    // 这里没有使用 TreeSet，而是选用了其接口 Iterable
    // 这样可以便利用户，使其不需要知道具体的数据类型就可以读取内容
    public Iterable<Integer> adj(int v)
    {
        validateVertex(v);
        return adj[v];
    }

    public int degree(int v){
        validateVertex(v);
        return adj[v].size();
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(String.format("V = %d, E = %d\n", V, E));
        for (int v = 0; v < V; v++) {
            sb.append(String.format("%d : ", v));
            for (int w: adj[v]) {
                sb.append(String.format("%d ", w));
            }
            sb.append('\n');
        }
        return sb.toString();
    }

    public static void main(String[] args){
        Graph graph = new Graph("g.txt"); // 相对地址在工程文件夹下
        System.out.println(graph);
    }
}