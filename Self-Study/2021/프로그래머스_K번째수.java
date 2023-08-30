class Solution {
	public int[] solution(int[] array, int[][] commands) {
        int[] answer = {};
        
        int[] arr;
		
        int i=0, j=0, k=0;
        int t=0;
        answer = new int[commands.length];
        
        for(int z=0; z<commands.length; z++) {
        	i = commands[z][t];
        	j = commands[z][t+1];
        	k = commands[z][t+2];
        	int arrSize = j-i+1;
        	arr = new int[arrSize];
        	for(int x=0; x<arrSize; x++) {
        		arr[x] = array[i-1];
        		i++;
        	}
        	Arrays.sort(arr);
        	answer[z] = arr[k-1];
        	System.out.println(answer[z]);
        }
        
        return answer;
    }
}
