package codeforces;

import FastReader.FastReader;

public class PingPong {
    public static void main(String[] args) {
        FastReader fs = new FastReader();

        int t = fs.nextInt();

        while(t-->0){
            int a = fs.nextInt();
            int b = fs.nextInt();

            System.out.println(a-1 + " " + b);
        }
    }
}
