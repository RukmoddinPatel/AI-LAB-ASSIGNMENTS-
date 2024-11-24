package Uninformed_Search_Techniques;
import java.util.*;

public class BFS {
    public static void bfs(int start,int[] visit, ArrayList<ArrayList<Integer>> ans ){
    Queue<Integer> q=new LinkedList<>();
    q.add(start);
    visit[start]=1;

    while (q.size()>0) {
        int front=q.remove();
        System.out.print(front+" ");
        for(int ele:ans.get(front)){
            if(visit[ele]!=1 ){
                q.add(ele);
                visit[ele]=1;
            }
        }
    }
    }

    public static void addEdge(int start,int dest ,ArrayList<ArrayList<Integer>> ans){
        ans.get(start).add(dest);
    }

    public static void main(String[] args) {
        int n=6;
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>();
        
        for(int i=0;i<n;i++){
            ans.add(new ArrayList<>());
        }

        int[] visit=new int[n];

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

        


        bfs(1,visit,ans);

        
    }
    
}

