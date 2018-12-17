public class Network {
    private Vertex[] vertices;
    private Edge[] edges;
    private int[][] cap_f;

    private int n;
    private int m;

    public Network(int n, int m, int[] vertex_demand, int[][] edge_info) {
        this.n = n;
        this.m = m;

        vertices = new Vertex[n];
        edges = new Edge[m];
        cap_f = new int[n][n];

        for (int i = 0; i < n; i++) {
            vertices[i] = new Vertex(vertexz_demand[i]);
        }

        for (int i = 0; i < m; i++) {
            edges[i] = new Edge(edge_info[i][0], edge_info[i][1], edge_info[i][2], edge_info[i][3], edge_info[i][2]);
        }
    }

    public int hasEdge(int u, int v) {
        for (int i = 0; i < m; i++) {
            if ((edges[i].getHead() == u) && (edges[i].getTail() == v)) {
                return i;
            }
        }
        return -1;
    }

    public void residual() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((hasEdge(i, j) != -1) && (hasEdge(j, i) == -1)) {
                    cap_f[i][j] = edges[hasEdge(i, j)].getCapacity() - edges[hasEdge(i, j)].getFlow();
                } else if ((hasEdge(i, j) == -1) && (hasEdge(j, i) != -1)) {
                    cap_f[i][j] = edges[hasEdge(j, i)].getFlow();
                } else if ((hasEdge(i, j) == -1) && (hasEdge(j, i) == -1)) {
                    cap_f[i][j] = 0;
                }
                
            }
        }
    }
}