
import java.util.*;
public class MinimizeTheHeightsII {
    static int getMinDiff(int[] arr, int n, int k) {


            Arrays.sort(arr);
            if(n==1) return 0;

            int diff = arr[n-1] - arr[0];
            int min,max;

            for(int i=1 ; i<n ; i++) {

                if(arr[i]-k<0) continue;

                max=Math.max(arr[n-1]-k,arr[i-1]+k);
                min= Math.min(arr[0]+k,arr[i]-k);

                diff=Math.min(diff,max-min);
            }
            return diff;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k =  sc.nextInt();
        int n =  sc.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i]=sc.nextInt();
        }
        System.out.println(getMinDiff(arr,n,k));

    }
}
