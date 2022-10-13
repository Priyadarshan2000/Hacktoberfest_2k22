package codeforces;

import FastReader.FastReader;

public class AlmostRectangle {
    public static void main(String[] args) {
        //Scanner fs = new Scanner(System.in);
        FastReader fs = new FastReader();

        int t = fs.nextInt();
        while(t-->0){
            int n = fs.nextInt();
            char[][] a = new char[n][n];
            boolean f = true;
            int i1=0,i2=0,j1=0,j2=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                {
                    char s = fs.next().charAt(0);
                    a[i][j] = s;
                }
                
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                {
                   if(a[i][j] == '*'){
                       if(f){
                        i1=i;
                        j1=j;
                        f = false;
                       }
                       else{
                           i2 = i;
                           j2 = j;
                       }
                   }
                }
            }

            if(i1 == i2 && i1 != n-1){
                a[i1+1][j1] = '*';
                a[i2+1][j2] = '*';
                continue;

            }
            if(i1 == i2 && i1 == n-1){
                a[i1-1][j1+1] = '*';
                a[i2-1][j2+1] = '*';
                continue;
            }
            if(j1==j2 && j1 !=n-1){
                a[i1][j1+1] = '*';
                a[i2][j2+1] = '*';
                continue;
            }
            if(j1==j2 && j1 ==n-1){
                a[i1][j1-1] = '*';
                a[i2][j2-1] = '*';
                continue;
            }

            a[i1][j2] = '*';
            a[i2][j1] = '*';

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                {
                    System.out.print(a[i][j] + " ");
                }

                System.out.println();
                
            }


            
           
        }
    }
}
