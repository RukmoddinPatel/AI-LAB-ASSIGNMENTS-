import java.util.*;


public class CSP {
    private int[][] graph;
    private int numColors;
    private int[] colors;

    public CSP(int[][] graph,int numColors){
        this.graph=graph;
        this.numColors=numColors;
        this.colors=new int[graph.length];
        Arrays.fill(colors,-1);
    }

    private boolean isSafe(int vertex,int color){
        for (int i = 0; i < colors.length; i++) {
            if(graph[vertex][i]==1 && colors[i]==color){
                return false;
            }
        }
        return true;
    }


    public boolean solve(int vertex){
        if(vertex==graph.length) return true;

        for(int i=0;i<numColors;i++){
            if(isSafe(vertex, i)){
                colors[vertex]=i;

                if(solve(vertex+1)) return true;
                colors[vertex]=-1;
            }
        }
        return false;
    }

    public boolean colorGraph(){
        return solve(0);
    }


    public void printColors(){
        System.out.println("");
    }
    public static void main(String[] args) {
        int[][] graph={
            {0,1,1,1},
            {1,0,0,1},
            {1,0,0,1},
            {1,1,1,0}
        };
        int numColors=3;

        CSP csp=new CSP(graph, numColors);
        if(csp.colorGraph()){
            csp.colorGraph();
        }
        else{
            System.out.println("No solution Exist");
        }
    }
}