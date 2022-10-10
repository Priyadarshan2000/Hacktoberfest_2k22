import java.util.Scanner;
 import java.io.*; 
 public class CRCsender{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter message bits: ");
    String message = sc.nextLine();
    System.out.println("Enter generator: "); 
    String generator = sc.nextLine();
     int data[] = new int[message.length() + generator.length() - 1];
      int divisor[] = new int[generator.length()];
       for(int i=0;i<message.length();i++)
        data[i] = Integer.parseInt(message.charAt(i)+"");
    for(int i=0;i<generator.length();i++)
     divisor[i] = Integer.parseInt(generator.charAt(i)+"");
    for(int i=0;i<message.length();i++)
    { if(data[i]==1)
       for(int j=0;j<divisor.length;j++) 
       data[i+j] ^= divisor[j];
    }
    System.out.println("The Transmitted code is: ");
     for(int i=0;i<message.length();i++)
      data[i] = Integer.parseInt(message.charAt(i)+"");
    for(int i=0;i<data.length;i++)
    System.out.print(data[i]);
    System.out.println();
    }
    }
    