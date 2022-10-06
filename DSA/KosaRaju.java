import java.util.*;

class KosaRaju
{
    private static void dfs(int node, Stack<Integer> st, ArrayList<ArrayList<Integer>> adj, int vis[]) {
        vis[node] = 1;
        for(Integer it : adj.get(node)) {
            if(vis[it] == 0) {
                dfs(it, st, adj, vis);
            }
        }

        st.push(node);
    }

    private static void revDfs(int node, ArrayList<ArrayList<Integer>> transpose, int vis[]) {
        vis[node] = 1;
        System.out.print(node + " ");
        for(Integer it : transpose.get(node)) {
            if(vis[it] == 0) {
                revDfs(it, transpose, vis);
            }
        }
    }

   static void kosaRajus(ArrayList<ArrayList<Integer>> adj, int n)
    {
        int vis[] = new int[n];
        Stack<Integer> st = new Stack<Integer>();
        for(int i = 0;i<n;i++) {
            if(vis[i] == 0) {
                dfs(i, st, adj, vis);
            }
        }

        ArrayList<ArrayList<Integer> > transpose = new ArrayList<ArrayList<Integer> >();

        for (int i = 0; i < n; i++)
            transpose.add(new ArrayList<Integer>());

        for(int i = 0;i<n;i++) {
            vis[i] = 0;
            for(Integer it: adj.get(i)) {
                transpose.get(it).add(i);
            }
        }

        while(st.size() > 0) {
            int node = st.peek();
            st.pop();
            if(vis[node] == 0) {
                System.out.print("SCC: ");
                revDfs(node, transpose, vis);
                System.out.println();
            }
        }

    }
    public static void main(String args[])
    {
        int n = 7;
        ArrayList<ArrayList<Integer> > adj = new ArrayList<ArrayList<Integer> >();

        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<Integer>());

        adj.get(1).add(3);
        adj.get(2).add(1);
        adj.get(3).add(2);
        adj.get(3).add(5);
        adj.get(4).add(6);
        adj.get(5).add(4);
        adj.get(6).add(5);



        kosaRajus(adj, n);

    }
}
