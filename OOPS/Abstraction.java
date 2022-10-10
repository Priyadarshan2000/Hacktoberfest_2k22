abstract class Car{
	//abstract class constructor
	Car(){
  		System.out.println("Car is built. ");
 	}

	//abstract method
 	abstract void drive();

	void gearChange(){
  		System.out.println("Gearchanged!!");
 	}
} 

class Maruti extends Car{
  	//implementation of abstract method
	void drive(){
   		System.out.println("Drive Safely");
  	}
}

class AbstractionTest{
  	public static void main (String args[]){
		//parent class referene variable holds child class object
   		Car obj = new Maruti();
   		obj.drive();
   		obj. gearChange();
  	}
}
