/*
 * programming 
 * DP example
 */

import java.util.Scanner;

public class P1932 {
    private static Scanner sc;

    private static int max(String[] arr) {
        int res = 0;
        for(String cur : arr) 
            if (res < Integer.parseInt(cur))
                res = Integer.parseInt(cur);
        return res;
    }

    private static int goDown(int n) {
        if (n == 0)
            return max(sc.nextLine().split(" "));
        else 
            return goDown(n-1);
    }

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        
        /* to store the inputs  */
        int N = sc.nextInt();
        int[][] map = new int[N][N];

        for (int row = 0; row < N; row++) {
            for (int col = 0; col <= row; col++) {
                map[row][col] = sc.nextInt();
            }
        }
        
        System.out.println(map[3][2]);
        
        int result = 0;
        // result = goDown(N);
        System.out.println(result);
    }
}