//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
import java.util.*;

 public class Main {
 public static int[] solution(int[] numbers) {
	 int[] answer = new int[7];
	 ArrayList<Integer> list = new ArrayList<Integer>();
	 int all = 0;
	 int a=0, b=0;
	 for(int i=0; i<9; i++){
		 all += numbers[i];
	 	 list.add(numbers[i]);
	 }
	 for(int i=0; i<9; i++){
		 for(int j=i+1; j<9; j++){
			 if(all-numbers[i]-numbers[j]==100){
				 list.remove(Integer.valueOf(numbers[i]));  //이거 주의해야함. remove()!!
				 list.remove(Integer.valueOf(numbers[j]));
				 for(int k=0; k<7; k++){
					 answer[k] = list.get(k);
				 }
				 return answer;
			 }
		 }
	 }

	return answer;
	 
 }
	
	public static void main(String [] args){
		int [] numbers=new int[9];
		int r[];
		Scanner input= new Scanner(System.in);
		
		for (int i = 0; i < 9; i++) {
			numbers[i]=input.nextInt();
		}
	
	r = solution(numbers);
	for (int i = 0; i < 7; i++) {
		System.out.printf("%d ", r[i]);
	}
		
		
	}
}
