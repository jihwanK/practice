import java.util.Scanner;
import java.io.FileInputStream;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	public static void main(String args[]) throws Exception
	{
		/*
		   아래의 메소드 호출은 앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
		   여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
		   이 코드를 프로그램의 처음 부분에 추가하면 이후 입력을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
		   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 메소드를 사용하셔도 좋습니다.
		   단, 채점을 위해 코드를 제출하실 때에는 반드시 이 메소드를 지우거나 주석 처리 하셔야 합니다.
		 */
		//System.setIn(new FileInputStream("res/input.txt"));

		/*
		   표준입력 System.in 으로부터 스캐너를 만들어 데이터를 읽어옵니다.
		 */
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
        */
        
        double[] digits = new double[T];
        String[][] units = new String[T][2];

        int[] units_power = new int[T];

		for(int test_case = 0; test_case < T; test_case++)
		{
            digits[test_case] = sc.nextDouble();
            for (int i = 0; sc.hasNext(); i++) {
                units[test_case][i] = sc.next();
            }
        }
        
        for (int test_case = 0; test_case < T; test_case++) {
            if (units.length == 2) {
                switch (units[test_case][0]) {
                    case 'yotta':
                    units_power[test_case] = 24;
                    break;
                    case 'zetta':
                    units_power[test_case] = 21;
                    break;
                    case 'exa':
                    units_power[test_case] = 18;
                    break;
                    case 'peta':
                    units_power[test_case] = 15;
                    break;
                    case 'tera':
                    units_power[test_case] = 12;
                    break;
                    case 'giga':
                    units_power[test_case] = 9;
                    break;
                    case 'mega':
                    units_power[test_case] = 6;
                    break;
                    case 'kilo':
                    units_power[test_case] = 3;
                    break;
                    case 'hecto':
                    units_power[test_case] = 2;
                    break;
                    case 'deca':
                    units_power[test_case] = 1;
                    break;
                    case 'deci':
                    units_power[test_case] = -1;
                    break;
                    case 'centi':
                    units_power[test_case] = -2;
                    break;
                    case 'milli':
                    units_power[test_case] = -3;
                    break;
                    case 'micro':
                    units_power[test_case] = -6;
                    break;
                    case 'nano':
                    units_power[test_case] = -9;
                    break;
                    case 'pico':
                    units_power[test_case] = -12;
                    break;
                    case 'femto':
                    units_power[test_case] = -15;
                    break;
                    case 'ato':
                    units_power[test_case] = -18;
                    break;
                    case 'zepto':
                    units_power[test_case] = -21;
                    break;
                    case 'yocto':
                    units_power[test_case] = -24;
                    break;

                }
            }
        }
	}
}