
import java.util.Scanner;

public class MaximumSubArraySum {
    static long maxSubarraySum(int arr[], int n){
        int localSum = 0;
        int maxi = arr[0];

        for(int i = 0 ; i<n ; i++){

            localSum = Math.max(arr[i],arr[i]+localSum);

            if(localSum > maxi){
                maxi = localSum;
            }
        }

        return maxi;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i]= sc.nextInt();
        }

        System.out.println(maxSubarraySum(arr,n));
    }
}
