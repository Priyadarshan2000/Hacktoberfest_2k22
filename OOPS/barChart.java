class Bar{
	static void chart()
	{
		int run[]={16,4,6,10,1,2,18,11,14,27,36,21,19,7,12};
		int r[][]=new int[run.length][];
		for(int i=0;i<run.length;i++)
		{
			r[i]=new int[run[i]];
		}
		for(int i=0;i<r.length;i++)
		{
			for(int j=0;j<r[i].length;j++)
			{
				System.out.print(r[i][j]);
			}
			System.out.println("");
		}
	}
	public static void main(String args[]){
		chart();
	}
}
