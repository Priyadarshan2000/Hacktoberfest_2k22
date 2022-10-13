package codeforces;

import FastReader.FastReader;

public class DoubleEndedString {
    public static void main(String[] args) {
        FastReader fs = new FastReader();

        int t = fs.nextInt();

        while(t-->0){
            String a = fs.nextLine();
            String b = fs.nextLine();
            int ans =0;
            for(int l =1;l<=Math.min(a.length(), b.length());l++){
                    for(int i=0;i+l<=a.length();i++){
                        for(int j=0;j+l<=b.length();j++){
                            try{
                                if(a.substring(i, l).compareTo(b.substring(j,l))==0){
                                    ans = Math.max(ans, l);
                                    System.out.println(a.substring(i,l));
                                    System.out.println(b.substring(j,l));
                                }
                            }catch(Exception e){
                                continue;
                            }
                        }
                    }
            }

            ans = a.length() + b.length() - 2*ans;
            System.out.println(ans);
        }
    }
}
