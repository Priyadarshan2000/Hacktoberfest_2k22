class Solution {
public:
    int myAtoi(string s) {
        long long val=0;
        bool ok=0;
        int i=0,n=s.size();
        while(i<n && s[i]==' '){i++;}
        if(i==n){return 0;}
        if(s[i]=='-'){ok=1;i++;}
        else if(s[i]=='+'){ok=0;i++;}
        while(i<n && isdigit(s[i])){
            val=10*val + (s[i]-'0');i++;
            if(val>1e10){break;}
        }
        if(ok){val=-val;}
        if(val>=INT_MAX){val=INT_MAX;}
        if(val<=INT_MIN){val=INT_MIN;}
        return (int)val;
    }
};
