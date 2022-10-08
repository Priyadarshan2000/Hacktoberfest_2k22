#include<iostream>
using namespace std;
#define MAX 20
int M[MAX];
struct Interval
{
	int start_time, finish_time, weight;
};
class WIS
{
	Interval I[MAX];
public:
	int n;
	WIS()
	{
		for (int i = 0; i <= MAX; i++)
			M[i] = 0;
	}
	int input();
	void interval_sort();
	int z(int); //getting finished and non-overlapping intervals
	int m_compute_opt(int);
};
int WIS::z(int j)
{
	for (int i = j - 1; i > 0; i--)
	{
		if (I[i].finish_time <= I[j].start_time)
		{
			return i;
		}
	}
	return 0;
}
int WIS::input()
{
	cout << "\nEnter number of intervals: ";
	cin >> n;
	cout << "\nEnter the starting time, finishing time and weight value of intervals: ";
	cout << "\n\nSi "<<" Fi "<<" Vi\n";
	for (int i = 1; i <= n; i++)
	{
		cin >> I[i].start_time;
		cin >> I[i].finish_time;
		cin >> I[i].weight;
	}
}
void WIS::interval_sort()
{
	int i, flag = 1;
	Interval temp;
	for (i = 1; (i <= n) && flag; i++)
	{
		flag = 0;
		for (int j = 1; j < n; j++)
		{
			if (I[j+1].finish_time < I[j].finish_time)
			{
				temp = I[j];
				I[j] = I[j + 1];
				I[j + 1] = temp;
				flag = 1;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (I[i].finish_time == I[j].finish_time && I[i].start_time > I[j].start_time)
			{
				temp = I[i];
				I[i] = I[j];
				I[j] = temp;
			}
		}
	}
	cout << "I<i>\t\tS<i>\t\tF<i>\t\tV<i>\n";
	for (int i = 1; i <= n; i++)
	{
		cout << i << "\t\t" << I[i].start_time << "\t\t" << I[i].finish_time << "\t\t" << I[i].weight << "\n";
	}
}
int WIS::m_compute_opt(int j)
{
	if (j == 0)
	{
		return 0;
	}
	else if (M[j])
	{
		return M[j];
	}
	else
	{
		M[j] = max((I[j].weight + m_compute_opt(z(j))),m_compute_opt(j - 1));
	}
	return M[j];
}
int main()
{
	WIS job;
	job.input();
	cout << "\nSorted Input Intervals: \n";
	job.interval_sort();
	cout << endl;
	for (int i = 1; i <= job.n; i++)
		cout << "OPT[" << i << "]\t";
	cout << endl;
	for (int i = 1; i <= job.n; i++)
		cout << job.m_compute_opt(i) << "\t";
	return 0;
}

