import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class B_5052 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = sc.nextInt();
	    StringBuilder sb = new StringBuilder();
	 
	    while (t-- > 0) {
	        int n = sc.nextInt();
	        String[] array = new String[n];
	        boolean flag = true;
	 
	        for (int i = 0; i < n; i++) {
	            array[i] = br.readLine();
	        }
	 
	        Arrays.sort(array);
	 
	        for (int i = 0; i < n - 1; i++) {
	            int current = array[i].length();
	            int next = array[i + 1].length();
	 
	            if (current < next) {
	                if (array[i + 1].indexOf(array[i]) > -1) {
	                    flag = false;
	                    break;
	                }
	            }
	        }
	 
	        if (flag) {
	            sb.append("YES\n");
	        } else {
	            sb.append("NO\n");
	        }
	 
	    }
	    System.out.println(sb.toString());
		    

	}
}
