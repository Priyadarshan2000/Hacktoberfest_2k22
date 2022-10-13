package Matrices;

import java.util.Arrays;

// remeber this logic as this helps in binary search in 2d array
public class PrintMatrixInOneLoop {
    public static void main(String[] args) {
        int[][] arr = {
                {1,2,3,4},
                {5,3,2,1},
                {4,2,3,5}
        };
        System.out.println(Arrays.toString(arr[1]));
    }
}