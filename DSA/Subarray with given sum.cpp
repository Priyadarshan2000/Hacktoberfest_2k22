public:
    vector<int> subarraySum(int arr[], int n, long long s)
    {  vector<int> v;
        int i=0;
        int j=1;
        int sum=arr[0];
        while(i<n-1 && j<n)
        {   if(arr[i]==s)
            {
                v.push_back(i+1);
                v.push_back(i+1);
                return v;
            }
            sum+=arr[j];
            if(sum==s)
            {
               v.push_back(i+1);
               v.push_back(j+1);
               return v;
            }
            if(j==n-1 || sum>s)
            {
                i++;
                j=i+1;
                sum=arr[i];
            }
            else{
                j++;
            }
        }
        if(arr[n-1]==s)
        {
            v.push_back(n);
            v.push_back(n);
            return v;
        }
        v.push_back(-1);
        return v;
    }
