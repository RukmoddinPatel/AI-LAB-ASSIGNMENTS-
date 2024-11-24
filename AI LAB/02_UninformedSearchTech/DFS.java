package UninformedSearchTech;
import java.util.*;

public class DFS {

    public static void dfs(int start,int[] visit,ArrayList<ArrayList<Integer>> ans){
        visit[start]=1;
        System.out.println(start);

        for(int i:ans.get(start)){
            if(visit[i]!=1){
                dfs(i, visit, ans);
                visit[i]=1;
            }
        }
    }


    public static void addEdge(int start,int dest ,ArrayList<ArrayList<Integer>> ans){
        ans.get(start).add(dest);
    }


    public static void main(String[] args) {
        int n=6;
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>();
        int[] visit=new int[n];

        for (int i = 0; i < visit.length; i++) {
            ans.add(new ArrayList<>());
        }

        




        addEdge(0,5,ans);
        addEdge(0,1,ans);
        addEdge(0,4,ans);
        addEdge(1,0,ans);
        addEdge(1,4,ans);
        addEdge(1,2,ans);
        addEdge(2,1,ans);
        addEdge(2,3,ans);
        addEdge(3,2,ans);
        addEdge(3,4,ans);
        addEdge(4,0,ans);
        addEdge(4,1,ans);
        addEdge(4,3,ans);
        addEdge(0,5,ans);

        dfs(0,visit,ans);
    }

    
}
