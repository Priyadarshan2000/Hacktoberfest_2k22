package codeforces;

import FastReader.FastReader;

public class BalancedRemainders {
    public static void main(String[] args) {
        FastReader fs = new FastReader();

        int t = fs.nextInt();

        while(t-->0){
            int n = fs.nextInt();

            int c[]  = new int[3];

            for(int i =0; i<n;i++){
                int x = fs.nextInt();

                c[x%3]++;
            }

            int r =0;

            while(fs.min(c) != n/3){

                for(int i=0;i<3;i++){
                    if(c[i] > n/3){
                        r++;
                        c[i]--;
                        c[(i+1)%3]++;
                    }
                }
            }

            System.out.println(r);
        }
    }
}
