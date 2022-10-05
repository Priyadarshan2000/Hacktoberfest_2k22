//Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Intuition: For this types of String Palindrome problems, its always better to start thinking using two pointer approach. The following approach is based on that concept.

Approach:

Firstly check three basic corner cases of string length=0, string length=1 and string length=2. Return accordingly.
Use an extra O(n) space to store the array, reverse it and directly check if its pallindrome or not.
These two approaches will save a lot of time.
Using the concept of two pointers, start traversing the string character by character from front and from the
back. If all the the characters comes up to be same, your string must be pallindrome.
If two characters comes up as not the same, try checking neglecting both the character one at a time, and check
if the rest of available string is pallindrome or not (clue: use another function for this checking part).
If it comes true even after neglecting any one of the unmatched character. Your string must be pallindrome. Else
it cannot be a pallindrome.

Code:
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        if(s.length()==0 || s.length()==1)
            return false;
        if(s.length()==2)
            return true;
        string temp;
        temp=s;
        reverse(temp.begin(),temp.end());
        if(s==temp)
            return true;

        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
                return isPalindrome(s,i+1,j)||isPalindrome(s,i,j-1);

        }
        return true; 
    }
int main()
{
	string s;
	cin>>s;
	cout<<validPalindrom(s);
	return 0;
}