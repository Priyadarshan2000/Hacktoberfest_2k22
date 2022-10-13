import java.util.Scanner;

public class DefangingAnIPAddress {
    public static String defangIPaddr(String address) {
        String ans="";
        for(int i=0 ; i<address.length() ; i++){
            if(address.charAt(i)!='.'){
                ans += address.charAt(i);
            }
            else{
                ans += "[.]";
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(defangIPaddr(s));
    }
}
