import java.util.Scanner;

public class Q7568 {
	
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int num = scanner.nextInt();
		int[][] array = new int[num][3]; 
		array[0][2] = num;
		int[] count = new int[num];
		int min = array[0][2];
		
		for(int i=0 ; i<num ; i++) {
			array[i][0] = scanner.nextInt();
			array[i][1] = scanner.nextInt();
		}
		
		for(int i=0 ; i<num ; i++) {
			for(int j=0 ; j<num ; j++)
				if(array[i][0] < array[j][0] && array[i][1] < array[j][1]) {
					count[i] = count[i] + 1;
				}	
			System.out.print(count[i]+1+" ");	
		}
		scanner.close();
	}
}
