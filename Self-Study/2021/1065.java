import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner kbd = new Scanner(System.in);
		
		int N=kbd.nextInt();
		int count=0;
		
		if(N<100) {
			count=N;
		}
		else
			count=99;
			for(int i=100; i<=N; i++) {
				int a=i/100;	//100의 자리
				int b=(i%100)/10;	//10의 자리
				int c=(i%100)%10;	//1의 자리
				if(a-b == b-c)
					count++;
			}
		System.out.println(count);
		
	}

}
