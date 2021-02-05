import java.util.Scanner;

public class Q2231 {
	public static int Linesum(int n) {
		int sum = 0;
		while(n > 0) {
			sum += n % 10;
            n /= 10;
        }
		return sum;
	}
	public static int LineCount(int n) {
		int count = 0;
		int sum = 0;
		while(n > 0) {
			sum += n % 10;
            n /= 10;
            count++;
        }
		return count;
	}
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int div_value = n/10;
		int add = 0;
			
		
		if(div_value==0) {
			if(n%2==1) {
				System.out.print(0);
			}
			else {
				System.out.print(n/2);
			}
		}
		else {
			int n_LineCount = LineCount(n);
			
			for(int i=n-9*(n_LineCount); i<n ; i++) {
				add = i+Linesum(i); 
				if(add == n) {
					System.out.print(i);
					break;
				}
				else if(i==n-1) {
					System.out.print(0);
				}
			}
		}		
		scanner.close();
	}
}
