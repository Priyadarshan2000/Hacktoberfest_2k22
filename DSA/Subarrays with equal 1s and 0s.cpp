class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        for(int i=0;i<n;i++) arr[i]=(!arr[i])?-1:arr[i];
        long long int c=0;
        long long int px=0;
        map<int,long long int > mp;
        for(int i=0;i<n;i++){
            px+=arr[i];
            if(mp.find(px)!=mp.end()) c+=mp[px];
            if(px==0) c++;
            mp[px]++;
        }
        return c;
    }
};
int main(void){
	int n;//size of array
	cin>>n
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	Solution o;
	cout<<o.countSubarrWithEqualZeroAndOne(arr,n);
	 
}
