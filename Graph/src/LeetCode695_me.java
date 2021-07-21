import java.sql.Array;
import java.util.*;

public class LeetCode695_me {

    private int[][] grid;
    private int rows;
    private int lines;
    private int V;
    private int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 四连通
    private HashMap<Integer, ArrayList<Integer>> adj; // 邻接表
    private HashMap<Integer, Boolean> visitedMap; // 结点是否被访问
    private ArrayList<Integer> counts; // 各连通图内的结点数量

    public LeetCode695_me(){ }

    public int maxAreaOfIsland(int[][] grid) {
        this.grid = grid;
        if(grid.length == 0) return 0;
        if(grid[0].length == 0) return 0; // 检查是否为空数组

        rows = grid.length;
        lines = grid[0].length;

        V = 0;
        for (int i = 0; i < rows; i++)
            V += Arrays.stream(grid[i]).sum();
        if(V == 0) return 0; // 检查是否存在结点

        adj = new HashMap<>();
        visitedMap = new HashMap<>();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < lines; j++) {
                if(grid[i][j] == 1){
                    ArrayList<Integer> aL = new ArrayList();
                    for (int[] dir: dirs) {
                        try{
                            if(grid[i+dir[0]][j+dir[1]] == 1)
                                aL.add(loc2int(i+dir[0], j+dir[1]));
                        }catch (Exception e){ }
                    }
                    // 添加邻接表，初始化访问信息
                    adj.put(loc2int(i, j), aL);
                    visitedMap.put(loc2int(i, j), false);
                }
            }
        }

        counts = new ArrayList();
        for (int v: visitedMap.keySet()) {
            if(!visitedMap.get(v))
                counts.add(dfs(v, 0));
        }

        return Collections.max(counts);
    }

    private int dfs(int v, int sum){
        visitedMap.put(v, true);
        sum ++;
        for (int w: adj.get(v)) {
            if(!visitedMap.get(w)){
                sum = dfs(w, sum);
            }
        }
        return sum;
    }

    private int loc2int(int rowNumber, int lineNumber){
        return rowNumber * lines + lineNumber;
    }

    public void printAdj(){
        for (int v: adj.keySet()) {
            System.out.print(v + " : ");
            for (int i = 0; i < adj.get(v).size(); i++) {
                System.out.print(adj.get(v).get(i) + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        LeetCode695_me leetCode695_me = new LeetCode695_me();
        int[][] gg = {
                {1, 0 , 0, 0},
                {1, 1, 0, 0},
                {0, 0 , 0, 1},
                {1, 1 , 1, 1},
                {0, 1 , 0, 0}
        };
        System.out.println(leetCode695_me.maxAreaOfIsland(gg));
    }
}
