package codeforces;

import FastReader.FastReader;

public class DifferentDivisors {
    public static void main(String[] args) {
        FastReader fs = new FastReader();

        int t = fs.nextInt();

        while(t-->0){
            int d = fs.nextInt();

            long x = (d+1)*(2*d + 1);

            System.out.println(x);
        }
    }
}
