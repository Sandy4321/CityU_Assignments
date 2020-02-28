import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.function.IntConsumer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections; 

class Main {


	static void range(int lo, int hi, IntConsumer consumer) {
		for (int i = lo; i < hi; i++) {
			consumer.accept(i);
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner s;
		if (System.getenv("vscode") != null) {
			File fs = new File("./in.txt");
			PrintStream ofs = new PrintStream(new File("./out.txt"));
			s = new Scanner(fs);
			System.setOut(ofs);
		}else{
			s = new Scanner(System.in);
		}

		mainFunc(s);
		s.close();
	}


	public static void mainFunc(Scanner s)
	{
		int t = s.nextInt();

		for (int T = 0 ; T < t ; T++){
			int n = s.nextInt();
			if (n == 0){
				System.out.println(0);
				continue;
			}
			int[] coins = new int[n];
			int totalSum =0;
			for (int i  = 0 ;i <n ;i++){
				coins[i] = s.nextInt();
				totalSum += coins[i];
			}
			int pot1 =0;
			int pot2=0;
			boolean possibilitySum[][] = new boolean[totalSum+1][n];
			for(int sum = 0; sum <=totalSum;sum++ ){
				possibilitySum[sum][0] = false;
			}
			possibilitySum[0][0] = true;
			possibilitySum[coins[0]][0] = true;
			for (int i =1 ;i<n ; i++) {
				for(int sum = 0; sum <=totalSum;sum++ ){
					possibilitySum[sum][i] = false;
				}
				for (int sum = 0;  sum <= totalSum - coins[i] ; sum ++){
					if (possibilitySum[sum][i -1]){
						possibilitySum[sum][i] = true;
						possibilitySum[sum+coins[i]][i] = true;
					}
				}
			}
			// 	for(int sum = 0;sum <= totalSum ; sum ++ ){
			// 		if (possibilitySum[sum][n-1]){
			// 			System.out.println(sum);						
			// 		}
			// 	}
			// // System.out.println(pot1);
			// System.out.println(pot2);
			int k = totalSum / 2;
			while (!possibilitySum[k][n-1]){
				k--;
			}
			System.out.println( totalSum - 2*k );
		}

	}



}