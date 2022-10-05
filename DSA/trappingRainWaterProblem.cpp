// 03 Trapping Rain Water

/*Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between
the blocks during the rainy season. */



#include<bits/stdc++.h>
using namespace std;


long long trappingWater(int arr[], int n){
    int left[n];
    int right[n];
    long long water=0;
    left[0]=arr[0];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }
    right[n-1]=arr[n-1];
    for(int j=n-2;j>=0;j--){
        right[j]=max(right[j+1],arr[j]);
    }
    for(int i=0;i<n;i++){
        water=water+(min(left[i],right[i])-arr[i]);
    }
    return water;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
		cout<<trappingWater(a,n)<<endl;
        
    }
    return 0;
}
