#include <iostream>
using namespace std;

class student{
    public:
    int rollno;
    string name;
    student(int i,string s){
         rollno = i;
         name = s;

    }

    void display(){
        cout << rollno << " " << name <<  endl;
    }
};

int main(){
    student s1= student(1,"Saksham");
    student s2= student(2,"Aman");
    student s3= student(3,"Soumya");
    student s4= student(4,"Love");
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    return 0;
}