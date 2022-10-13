package codeforces;

import FastReader.FastReader;

public class PuzzleFromFuturea {
    public static void main(String[] args) {
        FastReader fs = new FastReader();

        int t = fs.nextInt();
        while(t-->0){
            int n = fs.nextInt();

            String b = new String();
            b = fs.nextLine();

            StringBuilder s = new StringBuilder();
            s.append(1);
            for(int i=1;i<n;i++){
                if('1' + b.charAt(i) == b.charAt(i-1) + s.charAt(i-1)){
                   s.append('0');
                }else{
                    s.append('1');
                }
            }
            
            System.out.println(s.toString());
        }
    }
}
