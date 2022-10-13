/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int i=1;i<=T;i++)
		{
		    float A,B,X,Y;
		    A=sc.nextFloat();
		    B=sc.nextFloat();
		    X=sc.nextFloat();
		    Y=sc.nextFloat();
		    float time1=A/X;
		    float time2=B/Y;
		    if(time2<time1)
		    {
		        System.out.println("Chefina");
		    }
		    else if(time1<time2)
		    {
		        System.out.println("Chef");
		    }
		    else if(time1==time2)
		    {
		        System.out.println("Both");
		    }
		}
	}
}
