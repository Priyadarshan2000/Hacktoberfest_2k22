//package userinput;

public class ArrayOfObject {
	public static void main(String[] args) {
		Doga[] myDogs = new Doga[3];
		myDogs[0] = new Doga();
		myDogs[1] = new Doga();
		myDogs[2] = new Doga();
		myDogs[0].name = "fred";
		myDogs[1].name = "merge";
		myDogs[2].name = "bart";
		
		int x = 0;
		while(x<3) {
			myDogs[x].bark();
			x = x + 1;
		}

	}

}
class Doga{
	String name;
	void bark() {
		System.out.println(	name + " says Ruff");
	}
}