import java.util.Scanner;
import java.io.FileInputStream;

class Solution {
  public static void main(String args[]) throws Exception {
    Scanner sc = new Scanner(System.in);
    
    int T = 0;
    int N = 0;
    int Q = 0;

    int[] productNumbers;
    int[][] result;

    int start;
    int end;

    T = sc.nextInt();

    for (int test_case = 1; test_case <= T; test_case++) {
      N = sc.nextInt();
      Q = sc.nextInt();

      productNumbers = new int[N];
      result = new int[Q][3];

      for (int i = 0; i < N; i++) {
        productNumbers[i] = sc.nextInt();
      }

      for (int i = 0; i < Q; i++) {
        start = sc.nextInt();
        end = sc.nextInt();

        for (int j = start-1; j < end; j++) {
          result[i][productNumbers[j]-1] += 1;
        }
      }

      System.out.println("#" + test_case);
      for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 3; j++) {
          System.out.print(result[i][j] + " ");
        }
        System.out.println();
      }
    }

    sc.close();
  }
}