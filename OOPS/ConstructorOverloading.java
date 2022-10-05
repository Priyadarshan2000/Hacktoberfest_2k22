// -------------------------------------------------------------------------
//  Here 'this()' is used to reffer current class constructor
// -------------------------------------------------------------------------
public class ConstructorOverloading {
    ConstructorOverloading(){
        // the first line inside a constructor should be this() or super() always
        this(10);
        System.out.println("This is a no-arg constructor");
    }
    ConstructorOverloading(int i){
        this(20,10.5);
        System.out.println("This is a one-arg constructor");
    }
    ConstructorOverloading(int i, double x){
        System.out.println("This is a multi-arg constructor");
    }
    public static void main(String[] args){
        System.out.println("This is an example of constructor overloading with this keyword");
        // creating an object of the class ConstructorOverloading and the reference variable is constructoroverloading
        new ConstructorOverloading();
    }
}
