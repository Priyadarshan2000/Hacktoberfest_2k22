package codeforces;

import FastReader.FastReader;

public class StrangeTable {
    public static void main(String[] args) {
        FastReader fs = new FastReader();

        int t = fs.nextInt();

        while(t-->0){
            long n = fs.nextLong();
            long m = fs.nextLong();
            long x = fs.nextLong();
            long r,c;
           x--;
            c = x/n;
            r = x%n;
            
            System.out.println(m*r + c +1);
            

        }
    }
}
