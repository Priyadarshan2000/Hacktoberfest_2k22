 #include<bits/stdc++.h>
 using namespace std;
 
 vector<bool>prime(int n+1,true);
 {
        
        prime[0]=prime[1]=false;
        
        for(int i=2;i<n;i++){
            if(prime[i]){
                cnt++;
                
                for(int j=2*i;j<n;j=j+i){
                    prime[j]=0;
                }
            }
        }
        return cnt;
    }

 int main()
 {
     int n;
     cin>>n;

 return 0;
 }