// segment tree implementation


#include<bits/stdc++.h>
using namespace std;

int create(int s[],int i,int a[],int l,int r,int &m)
{
    if(l==r)
    {
        if(a[l]>m){
            s[i]=1;
            m=a[l];
        }
        else
        {
            s[i]=0;
        }
        return s[i];
    }
    else{
        int mid=(l+r)/2;
        s[i]=create(s,2*i+1,a,l,mid,m)+create(s,2*i+2,a,mid+1,r,m);
        return s[i];
    }
}

int sum(int s[],int i,int ql,int qr,int l,int r)
{
    if(l>=ql && qr>=r)
    {
        return s[i];
    }
    else if(r<ql || l>qr)
    {
        return 0;
    }
    else
    {
        int mid=(l+r)/2;
        return sum(s,2*i+1,ql,qr,l,mid)+sum(s,2*i+2,ql,qr,mid+1,r);
    }
}
void update(int s[],int pos,int diff,int i,int l,int r)
{
    if(pos>=l && pos<=r)
    {
        s[i]=s[i]+diff;
        if(l!=r)
        {
            int mid=(l+r)/2;
            update(s,pos,diff,2*i+1,l,mid);
            update(s,pos,diff,2*i+2,mid+1,r);
        }
    }
    return ;
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int d=0;
    while(d<n)
    {
        cin>>arr[d];
        d++;
    }
    int x=int(ceil(log2(n)));
    int size=2*(int)pow(2, x) - 1;
    cout<<size<<endl;
    int S[size]={0};
    int m=0;
    create(S,0,arr,0,n-1,m);
    print(S,size);

    cout<<sum(S,0,0,n-1,0,n-1)<<endl;


}



