pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k){
    int s=0,e=n-1,firstindex=-1,lastindex=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]<k){
			s=mid+1;
		}
		else if(arr[mid]>k){
			e=mid-1;
		}
		else{
			firstindex=mid;
			e=mid-1;
		}
	}
	s=0;e=n-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]<k){
			s=mid+1;
		}
		else if(arr[mid]>k){
			e=mid-1;
		}
		else{
			lastindex=mid;
			s=mid+1;
		}
	}
	
	pair<int, int> res;
	res.first=firstindex;
	res.second=lastindex;
	return res;
}
