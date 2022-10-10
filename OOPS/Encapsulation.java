// Java program to demonstrate encapsulation
class Student {
    // private variables declared
    // these can only be accessed by
    // public methods of class
    private String sName;
    private int sRoll;
    private int sAge;
 
    // getter method for age to access
    // private variable sAge
    public int getAge() { 
	return sAge; 
    }
 
    // getter method for name to access
    // private variable sName
    public String getName() { 
	return sName; 
    }
 
    // getter method for roll to access
    // private variable sRoll
    public int getRoll() { 
	return sRoll; 
    }
 
    // setter method for age to access
    // private variable sage
    public void setAge(int newAge) { 
	sAge = newAge; 
    }
 
    // setter method for name to access
    // private variable sName
    public void setName(String newName) {
        sName = newName;
    }
 
    // setter method for roll to access
    // private variable sRoll
    public void setRoll(int newRoll) { 
	sRoll = newRoll; 
    }
}
 
class TestEncapsulation {
    public static void main(String[] args)
    {
        Student obj = new Student();
 
        // setting values of the variables
        obj.setName("Sourav");
        obj.setAge(21);
        obj.setRoll(58);
 
        // Displaying values of the variables
        System.out.println("Student's name: " + obj.getName());
        System.out.println("Student's age: " + obj.getAge());
        System.out.println("Student's roll: " + obj.getRoll());
 
        // Direct access of sRoll is not possible
        // due to encapsulation
        // System.out.println("Student's name: " + obj.geekName);
    }
}
