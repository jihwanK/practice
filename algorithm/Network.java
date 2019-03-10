import java.util.ArrayList;
import java.util.Stack;

import com.sun.javafx.application.PlatformImpl.FinishListener;

public class Network {
    private Vertex[] vertices;
    private Edge[][] edges; // edges[head][tail]
    private Edge[][] cap_f;

    private int n;
    private int m;

    public Network(int n, int m, int[] vertex_demand, int[][] edge_info) {
        this.n = n;
        this.m = m;

        vertices = new Vertex[n];
        edges = new Edge[n][n];
        cap_f = new Edge[n][n];

        for (int i = 0; i < n; i++) {
            vertices[i] = new Vertex(vertex_demand[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                edges[i][j] = new Edge(0, 0, 0);
                for (int k = 0; k < m; k++) {
                    if ((edge_info[k][0] == i) && (edge_info[k][1] == j)) {
                        edges[edge_info[k][0]][edge_info[k][1]] = new Edge(edge_info[k][2], edge_info[k][3], edge_info[k][2]);
                    }
                }
            }
        }
    }

    public int findSource() {
        for (int i = 0; i < n; i++) {
            if (vertices[i].getDemand() < 0) {
                return i;
            }
        }
        return -1;
    }

    public int findSink() {
        for (int i = 0; i < n; i++) {
            if (vertices[i].getDemand() > 0) {
                return i;
            }
        }
        return -1;
    }

    public void residual() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cap_f[i][j].setCapacity(0);
                if (edges[i][j].getFlow() < edges[i][j].getCapacity()) {
                    cap_f[i][j].setCapacity(edges[i][j].getCapacity() - edges[i][j].getFlow());
                    cap_f[i][j].setType('f');
                }
                if (edges[i][j].getFlow() > 0) {
                    cap_f[j][i].setCapacity(edges[i][j].getFlow());
                    cap_f[i][j].setType('b');
                }
            }
        }
    }

    public void augmented(int[][] path, int flow) {
        int b = 987_654_321;

        for (int i = 0; i < path.length; i++) {
            if (b > cap_f[path[i][0]][path[i][1]].getCapacity()) {
                b = cap_f[path[i][0]][path[i][1]].getCapacity();
            }
        }
        for (int i = 0; i < path.length; i++) {
            if (cap_f[path[i][0]][path[i][1]].getType() == 'f') {
                edges[path[i][0]][path[i][1]].setFlow(edges[path[i][0]][path[i][1]].getFlow() + b);
            }
        }
    }

    public ArrayList<Integer> DFS() { 
        ArrayList<Integer> path = new ArrayList<Integer>();
        int[] visited = new int[n];
        Stack<Integer> s = new Stack<Integer>();
        int source = findSource();
        int sink = findSink();

        s.push(source);
        path.add(source);
        visited[source] = 1;

        while(s.peek() != sink) {
            int cur = s.pop();
            for (int i = 0; i < n; i++) {
                if ((visited[i] != 1) && (cap_f[cur][i].getCapacity() != 0)) {
                    s.push(i);
                    path.add(i);
                    visited[i] = 1;

                    if (i == sink) {
                        break;
                    }
                }
            }
        }

        if (path.size() == 0) {
            return null;
        } else {
            return path;   
        }
    }

    public void increaseFlow() {
        ;
    }

    public boolean checkVertexDemand() {
        int[] demand = new int[n];
        int source = findSource();
        int sink = findSink();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (edges[i][j].getCapacity() != 0) {
                    demand[i] = demand[i] - edges[i][j].getFlow();
                    demand[j] = demand[j] + edges[i][j].getFlow();
                }
            }
        }

        if ((demand[source] == vertices[source].getDemand()) && (demand[sink] == vertices[sink].getDemand())) {
            return false;
        } else {
            return true;
        }
    }

    public int[] start() {
        int[] res = null;
        return res;
    }
}