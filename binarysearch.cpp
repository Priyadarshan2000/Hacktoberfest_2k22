class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int r=m.size();
        int s=m[0].size();
        int start=0;
        int end=r*s-1;
        int mid=start+(end-start)/2;
        int e=0;
         while(start<=end){
             e=m[mid/s][mid%s];
             
             if(e==target){
                 return 1;
             }
             if(e<target){
                start=mid+1; 
             }
             else{
                 end=mid-1;
             }
         
        mid=start+(end-start)/2;
         }
        return 0;
    }
};
