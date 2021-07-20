import java.io.*;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		int[][] arr = new int[19][19];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			arr[x-1][y-1] = 1;
		}
		
		for(int i=0; i<19; i++) {
			for(int j=0; j<19; j++)
				bw.write(arr[i][j]+" ");
			bw.write("\n");
		}
		
		bw.flush();
		bw.close();
		br.close();
		
	}
	
}
