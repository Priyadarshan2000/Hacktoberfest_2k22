package codeforces;

import FastReader.FastReader;

public class YetAnotherPalindromeProblem {
    public static void main(String[] args) {
        FastReader fs = new FastReader();

        int t = fs.nextInt();

        while(t-->0){
            int n = fs.nextInt();
            int[] a = new int[n];

            for (int i = 0; i < a.length; i++) {
                a[i] = fs.nextInt();
            }
            boolean f = false;
            for (int i = 0; i < a.length; i++) {
                for (int j = i+2; j < a.length; j++) {
                    if(a[i] == a[j]){
                        f = true;
                    }
                }
            }

            if(f){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }
    }
}
