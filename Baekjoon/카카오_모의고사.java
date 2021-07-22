import java.util.ArrayList;
class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        int a=0, b=0, c=0;
        int n = answers.length;
        int[] one = {1,2,3,4,5};
        int[] two = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

        for(int i=0; i<n; i++){
            if(answers[i]==one[i%5])
            	a++;
            if(answers[i]==two[i%8])
                b++;
            if(answers[i]==three[i%10])
                c++;
        }
        
        int max = Math.max(Math.max(a, b), c);
        ArrayList <Integer> list = new ArrayList<Integer>();
        if(max==a)	list.add(1);
        if(max==b)	list.add(2);
        if(max==c)	list.add(3);
        
        answer = new int[list.size()];
        
        for(int i=0; i<answer.length; i++)
        	answer[i] = list.get(i);
        
        return answer;
    }
}
