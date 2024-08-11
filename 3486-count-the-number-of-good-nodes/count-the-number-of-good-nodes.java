import java.util.ArrayList;

class Solution {
    private ArrayList<Integer>[] sizeOf; // Global variable

    private void sizeMake(ArrayList<Integer>[] adj, boolean[] visit, int st, int[] numberOfChild, int par) {
        numberOfChild[st]++;
        for (int i : adj[st]) {
            if (i != par) {
                sizeMake(adj, visit, i, numberOfChild, st);
                numberOfChild[st] += numberOfChild[i];
                sizeOf[st].add(numberOfChild[i]);
            }
        }
    }

    public int countGoodNodes(int[][] edges) {
        int n = edges.length + 1;

        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }

        sizeOf = new ArrayList[n]; // Initialize the global variable
        for (int i = 0; i < n; i++) {
            sizeOf[i] = new ArrayList<>();
        }

        int[] numberOfChild = new int[n];
        boolean[] visit = new boolean[n];

        sizeMake(adj, visit, 0, numberOfChild, -1);

        int re = 0;
        for (int i = 0; i < n; i++) {
            boolean x = true;
            for (int j = 0; j < sizeOf[i].size() - 1; j++) {
                if (!sizeOf[i].get(j).equals(sizeOf[i].get(j + 1))) {
                    x = false;
                    break;
                }
            }
            if (x) {
                re++;
            }
        }

        return re;
    }
}
