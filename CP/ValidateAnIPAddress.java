import java.util.*;

public class ValidateAnIPAddress {
    public static boolean isValid(String s) {
            // Write your code here
            int c=0;
            for(int i=0 ; i<s.length() ; i++) {
                if(s.charAt(i)=='.') c++;
            }

            if(c!=3) return false;

            HashSet<String> set = new HashSet<>();

            for(Integer i=0 ; i<=255 ;i++) {
                set.add(i.toString());
            }

            String temp="";
            int count=0;

            for(int i=0 ; i<s.length() ; i++) {
                if(s.charAt(i) != '.'){
                    temp += s.charAt(i);
                }

                else {
                    if(set.contains(temp)) {
                        count++;
                        temp="";

                    }
                }
            }
            if(set.contains(temp)) count++;

            if(count==4) return true;
            else return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s  = sc.next();

        System.out.println(isValid(s));
    }


}