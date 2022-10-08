#include<bits/stdc++.h>                      
using namespace std;

class triange{
    private:
        float height;
        float base;
    public:
        void get_data(float height , float base){
            this->height=height;
            this->base=base;
        }

        float getAreaTri(){
            return 0.5*base*height;
        }
};

class rectange{
    private:
        float height;
        float base;
    public:
        void get_data(float height , float base){
            this->height=height;
            this->base=base;
        }

        float getAreaRec(){
            return base*height;
        }
};

class square{
    private:
        float side;
    public:
        void get_data(float side){
            this->side=side;
        }

        float getAreaSqu(){
            return side*side;
        }
};


int main()
{
    float a,b,c,d,e;
    float Tri_area, Rec_area, Squ_area;

    cout<<"Enter the height of a triangle : "<<endl;
    cin>>a;
    cout<<"Enter the of base of a triangle : "<<endl;
    cin>>b;
    triange t1;
    t1.get_data(a,b);
    Tri_area=t1.getAreaTri();
    cout<<"Area of Triangle is : "<<Tri_area<<endl;
    cout<<endl;

    cout<<"Enter the height of a rectange : "<<endl;
    cin>>c;
    cout<<"Enter the base of a rectange : "<<endl;
    cin>>d;
    rectange r1;
    r1.get_data(c,d);
    Rec_area=r1.getAreaRec();
    cout<<"Area of Triangle is : "<<Rec_area<<endl;
    cout<<endl;


    cout<<"Enter the side of a square : "<<endl;
    cin>>e;
    square s1;
    s1.get_data(e);
    Squ_area=s1.getAreaSqu();
    cout<<"Area of Triangle is : "<<Squ_area<<endl;

    return 0;
}


