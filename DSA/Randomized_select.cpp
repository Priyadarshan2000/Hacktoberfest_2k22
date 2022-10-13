#include<iostream>
#include<stdlib.h>
using namespace std;
template<class t>
class random
{
public:
	t a[500];
	int count, n;
	void input();
	void display();
	int qsort(t a[], int p, int r);
	int partition(t a[], int p, int r);
	int randomSelect(t a[], int p, int r, int i);
};
template<class t>
void random<t>::input()
{
	int i;
	cout << "Enter the no of elements" << endl;
	cin >> n;
	for (i = 1;i <= n; i++)
		a[i] = rand() % 100;
}
template<class t>
void random<t>::display()
{
	for (int i = 1; i <= n;i++)
		cout << a[i] << " ";
}
template<class t>
int random<t>::partition(t a[], int p, int r)
{
	int x, i, j, temp;
	x = a[r];
	i = p - 1;
	for (j = p; j <= r - 1; j++)
	{
		if (a[j] <= x)
		{
			i = i + 1;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
		count++;
	}
	temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	return i + 1;
}
template<class t>
int random<t>::randomSelect(t a[], int p, int r, int i)
{
	int k, q;
	if (p == r)
		return a[p];
	q = partition(a, p, r);
	k = q - p + 1;
	if (i == k)
		return a[q];
	else if (i < k)
		return randomSelect(a, p, r, i);
	else
		return randomSelect(a, q + 1, r, k);
}
template<class t>
int random<t>::qsort(t a[], int p, int r)
{
	int q, i;
	if (p < r)
	{
		q = partition(a, p, r);
		qsort(a, p, q - 1);
		qsort(a, q + 1, r);
	}
	return count;
}
int main()
{
	int c;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		random<int> o;
		o.input();
		cout << "\n The elements of the array are: ";
		o.display();
		o.count = 0;
		c = o.qsort(o.a, 1, o.n);
		cout << "count: " << c;
		cout << "\n After Sorting =]: " << endl;
		o.display();
		cout << "\n Do you want to continue?(y/n)";
		cin >> ch;
	}
	return 0;
}
