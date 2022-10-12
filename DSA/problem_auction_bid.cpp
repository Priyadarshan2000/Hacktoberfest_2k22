int main()
{
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,b,c;
	    cin>>a>>b>>c;
	    if(a>b && a>c){
	        cout<<"Alice\n";
	    }
	    else if(a<b && b>c){
	        cout<<"Bob\n";
	    }
	    else{
	        cout<<"Charlie\n";
	    }
	}
	return 0;
}
