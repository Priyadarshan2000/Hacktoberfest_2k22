#include<bits/stdc++.h>
using namespace std;

// i/p : {1,2,2,3,1,}
// o/p : 3

void unique(int arr[],int size){
    for(int i=0;i<size;i++){
        int count = 0;
        for(int k=0;k<size;k++){
            if(arr[i]==arr[k]){
                count++;
            }
        }
        if(count==1){
            cout<<arr[i];
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;

    int arr[100];
    cout<<"Enter an array : \n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    unique(arr,n);

return 0;
}