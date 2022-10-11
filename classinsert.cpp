#include <iostream>
using namespace std;

class student{
    public:
      int rollno;
      string name;

      void insert(int i,string n){
        rollno = i;
        name = n;
      }

      void display(){
        cout << rollno << " " << name << endl;
      }
};

int main(){
    student s1;
   student s2;

   s1.insert(1,"Aman");
   s2.insert(2,"Saksham");

   s1.display();
   s2.display();

    return 0;
}