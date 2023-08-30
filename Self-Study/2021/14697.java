import java.util.*;
public static void Main(String[] args) {
        Scanner scan = new Scanner(System.in);
 
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        int n = scan.nextInt();
        int ans = 0;
        
        for(int i=0; i<=50; i++)
            for(int j=0; j<=50; j++)
                for(int k=0; k<=50; k++)
                    if((a*i) + (b*j) + (c*k) == n)
                        ans=1;
        
        System.out.println(ans);
    }
