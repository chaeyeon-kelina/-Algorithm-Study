import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

		String line[];
		FenwickTree fenwickTree;
		StringBuilder res = new StringBuilder();
		int i, n, m, k, t = Integer.parseInt(in.readLine()), pos[];

		while (t-- > 0) {
			line = in.readLine().split(" ");
			n = Integer.parseInt(line[0]);
			m = Integer.parseInt(line[1]);
			pos = new int[n + 1];
			
			fenwickTree = new FenwickTree(n + m + 1);

			for (i = 1; i <= n; i++) {
				pos[i] = i + m;
				fenwickTree.add(pos[i], 1);
			}

			line = in.readLine().split(" ");
			for (i = 0; i < m; i++) {
				k = Integer.parseInt(line[i]);
				res.append((fenwickTree.sum(pos[k]) - 1) + " "); 

				fenwickTree.add(pos[k], -1); 
				pos[k] = m - i; 
				fenwickTree.add(pos[k], 1);
			}
			res.append("\n");
		}
		out.write(res.toString());
		out.close();
		in.close();
	}
}


class FenwickTree {
	private int n, tree[];

	public FenwickTree(int n) {
		this.n = n;
		tree = new int[n];
	}

	public int sum(int pos) {
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	public void add(int pos, int val) {
		while (pos < n) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
}
