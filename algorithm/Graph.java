public class Graph {
    private Vertex[] vertices;
    private Edge[] edges;

    public Graph(int n, int m, int[] vertex_demand, int[][] edge_info) {
        vertices = new Vertex[n];
        edges = new Edge[m];

        for (int i = 0; i < n; i++) {
            vertices[i] = new Vertex(vertexz_demand[i]);
        }

        for (int i = 0; i < m; i++) {
            edges[i] = new Edge(edge_info[i][0], edge_info[i][1], edge_info[i][2], edge_info[i][3], edge_info[i][2]);
        }
    }
}