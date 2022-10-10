//Abstract class program

import java.util.Random;
abstract class Instrument{
	abstract void play();
}
class Piano extends Instrument{
	void play(){
		System.out.println("Piano is playing tan tan tan tan");
	}
}
class Flute extends Instrument{
	void play(){
		System.out.println("Flute is playing toot toot toot toot");
	}
}
class Guitar extends Instrument{
	void play(){
		System.out.println("Guitar is playing tin tin tin tin");
	}
}

class TestInstrument{
	public static void main(String[] args){
		Instrument[] instruments = new Instrument[10];
		//System.out.println(instruments.getClass().getName());
		
		Random rand=new Random();//Random is predefined class in java.util package
		
		for(int i=0;i<=10;i++){
			/*I need random number between 1 to 3*/
			int randNum = rand.nextInt(3)+1;

			if(randNum==1)
				instruments[i] = new Piano();
			else if(randNum==2)
				instruments[i] = new Flute();
			else if(randNum==3)
				instruments[i] = new Guitar();

			instruments[i].play();
		}
			
		System.out.println();

		for(int i=0;i<10;i++){
			if(instruments[i] instanceof Piano)
				System.out.println("Piano is stored at index "+i);
			else if(instruments[i] instanceof Flute)
				System.out.println("Flute is stored at index "+i);
			else if(instruments[i] instanceof Guitar)
				System.out.println("Guitar is stored at index "+i);
		}
	}
}
