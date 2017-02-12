import java.util.ArrayList;

public class MyStringBuffer {
	
	private ArrayList<String> arrayOfStrings;
	
	public MyStringBuffer(){
		arrayOfStrings = new ArrayList<String>();
	}
	
	public MyStringBuffer(String[] words){
		arrayOfStrings = new ArrayList<String>();
		for (String word: words){
			append(word);
		}
	}
	
	public void append(String word){
		arrayOfStrings.add(word);
	}
	
	public String toString(){
		String returnString = "";
		for (String word: arrayOfStrings){
			returnString += word;
		}
		return returnString;
	}	
}
