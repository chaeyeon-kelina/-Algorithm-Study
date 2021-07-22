import java.io.*;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		
		int[] answers = {1,3,2,4,2};

		Solution sol = new Solution();
		sol.solution(answers);
		
		bw.flush();
		bw.close();
		br.close();
		
	}
	
}

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        int a=0;
        int b=0;
        int c=0;
        int max = 0;
        int n = answers.length;
        int[] one = {1,2,3,4,5};
        int[] two = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        System.out.println(a);
        for(int i=0; i<n; i++){
            if(answers[i]==one[i%5])
            	a++;
            if(answers[i]==two[i%8])
                b++;
            if(answers[i]==three[i%10])
                c++;
        }
        
        if(a==b && b==c) {
        	answer[0]=a;
        	answer[1]=b;
        	answer[2]=c;
        }
        else if(a==b) {
        	if(a>c) {
        		answer[0]=a;
            	answer[1]=b;
        	}
        	else
        		answer[0]=c;
        }
        else if(a==c) {
        	if(a>b) {
        		answer[0]=a;
            	answer[1]=c;
        	}
        	else
        		answer[0]=b;
        }
        else if(b==c) {
        	if(a<b) {
        		answer[0]=b;
            	answer[1]=c;
        	}
        	else
        		answer[0]=a;
        }
        else {
        	if(a>b)
            	max = a;
            else
            	max = b;
            if(max<c)
            	max = c;
            answer[0]=max;
        }
        
        System.out.println(answer[0]);
        return answer;
    }
}
