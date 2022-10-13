package codeforces;

import FastReader.FastReader;

public class StrangeFunctions {
    public static void main(String[] args) {
        FastReader fs = new FastReader();

        int t = fs.nextInt();

        while(t-->0){
            String s = fs.nextLine();
            System.out.println(s.length());
        }
    }
}
