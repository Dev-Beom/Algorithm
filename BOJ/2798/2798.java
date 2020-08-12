import java.util.Scanner;

public class BlackJack {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int max = 0;
		int num = 0;
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		int[] input_arr = new int[n];
		int[] sum = new int[n*n*n];
		
		for(int i=0 ;i<n ;i++) {
			input_arr[i] = scanner.nextInt(); 
		}
		
		
		for(int j=0; j<n ; j++) {
			for(int i=0; i<n-1 ; i++){
				if(input_arr[i] > input_arr[i+1]) {
					max = input_arr[i];
					input_arr[i] = input_arr[i+1];
					input_arr[i+1] = max;
				}
			}
		}
				
		for(int i=0; i<n-3; i++) {
			for(int j=1 ; j<n-2; j++) {
				for(int k=2 ; k<n-1 ; k++) {
					if(i!=j && i!=k && j!=k && input_arr[i]+input_arr[j]+input_arr[k] <= m) {
						sum[num] = input_arr[i]+input_arr[j]+input_arr[k];
						num++;
						
					}
					
				}
			}
		}
				
		for(int j=0; j<num ; j++) {
			for(int i=0; i<num-1 ; i++){
				if(sum[i] > sum[i+1]) {
					max = sum[i];
					sum[i] = sum[i+1];
					sum[i+1] = max;
				}
			}
		}
		
		System.out.print(sum[num-1]);
				
		scanner.close();
	}
}
