import java.util.Scanner;
import java.io.File;

public class Circ {
    private Graph G;

    public Circ() throws Exception {
        File file = new File("input.txt");
        Scanner sc = new Scanner(file);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] vertex_demand = new int[n];
        int[][] edge_info = new int[m][4];

        for (int i = 0; i < n; i++) {
            vertex_demand[i] = sc.nextInt();
        }

        for (int i = 0; i < m; i++) {
            edge_info[i][0] = sc.nextInt();
            edge_info[i][1] = sc.nextInt();
            edge_info[i][2] = sc.nextInt();
            edge_info[i][3] = sc.nextInt();
        }

        G = new Graph(n, m, vertex_demand, edge_info);
        sc.close();
    }

    public static void main(String[] args) throws Exception {
        Circ max = new Circ();
    }
}