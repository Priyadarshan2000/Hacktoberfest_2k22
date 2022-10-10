import java.util.*;
class HammingSender{
int power(int base, int exp){ 
    int ans = 1;
     while(exp > 0){ 
        if(exp%2 ==1){ 
            exp--; ans *= base;
}  
else {
     exp /= 2; 
     base *= base;
}
}
return ans;
}
String sender(String data){ int m = data.length();
     int r = 1; 
     while(power(2, r) < m+r+1)
      r++;
int[] codeword = new int[m+r+1];
 for(int i = 0; i < r; i++){ 
    if(power(2, i) < m+r+1) 
    codeword[power(2, i)] = -1;
}
int idx = m-1;
 for(int i = 1; i < m+r+1; i++){ 
    if(codeword[i] != -1){ 
        codeword[i] = data.charAt(idx)-'0';
         idx--;
}
}
 int parity = 0;
  while(parity < r){ 
    int start = power(2, parity);
     parity++; 
     int countOne = 0, cnt = 0;
for(int i = start; i < m+r+1;)
{ if(cnt%2 == 0){
     int limit = Math.min(m+r+1, i+start);
      for(int j = i; j < limit; j++){
if(codeword[j] == 1) 
    countOne++;
}
int it = start; 
while(it-- > 0) i++;
}  else { 
    int it = start;
     while(it-- > 0)
      i++;
}
cnt++;
}
codeword[start] = (countOne % 2 == 1)? 1 : 0;
}
String ans = "";
 for(int i = m+r; i >=1; i--)
  ans += (char)('0'+codeword[i]);
return ans;
}
}
class Sender{ public static void main(String args[]){
String user_data;
System.out.println("Enter the user data : ");
 Scanner sc = new Scanner(System.in); user_data = sc.next();
HammingSender obj = new HammingSender();
String codeWord = obj.sender(user_data);
System.out.println("Sender is sending the code word : " + codeWord);
}
}
