int countTriplet(int a[], int n)
	{
	    // Your code goes here
	    int count=0;
	    sort(a,a+n);
	    for(int k=1;k<n;k++){
	        int i=0,j=n-1;
	        while(i<j){
	            if(i==k)    i++;
	            if(j==k)    j--;
	            if(i!=j&&a[i]+a[j]==a[k]) {
	                count++;
	                   i++;j--;
	            }
	            else if(a[i]+a[j]<a[k]) i++;
	            else    j--;
	        }
	    }
	    return count;
	}
