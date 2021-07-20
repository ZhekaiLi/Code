import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class CCBFS {

    private Graph G;
    private int[] visited;
    private int ccount = 0;

    private ArrayList<Integer> order = new ArrayList<>();

    public CCBFS(Graph G){
        this.G = G;
        visited = new int[G.V()];

        for (int i = 0; i < G.V(); i++) {
            visited[i] = -1;
        }

        for (int v = 0; v < G.V(); v++) {
            if(visited[v] == -1) {
                bfs(v, ccount);
                ccount++;
            }
        }
    }

    private void bfs(int s, int ccid){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        visited[s] = ccid;
        while(!queue.isEmpty()){
            int v = queue.remove();
            order.add(v);

            for(int w: G.adj(v)){
                if(visited[w] == -1){
                    queue.add(w);
                    visited[w] = ccid;
                }
            }
        }
    }

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

    public boolean isConnected(int v, int w){
        G.validateVertex(v);
        G.validateVertex(w);
        return visited[v] == visited[w];
    }

    public int ccount(){
        return ccount;
    }


    public static void main(String[] args)
    {
        Graph g = new Graph("g.txt");
        CCBFS ccbfs = new CCBFS(g);
        System.out.println(ccbfs.ccount());
        ArrayList<Integer>[] comp = ccbfs.components();
        for (int ccid = 0; ccid < comp.length; ccid++) {
            System.out.print(ccid + " : ");
            for(int w: comp[ccid])
                System.out.print(w + " ");
            System.out.println();
        }
    }
}
