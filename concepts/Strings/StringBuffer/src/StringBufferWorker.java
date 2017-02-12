//Author: Taimoor Alam
//Book: Cracking the Coding Interview Lakhman
//Page: 72
//Topic: String Buffer

public class StringBufferWorker {
	
		//main function
		public static void main (String[] args){
				System.out.println(joinWords(new String[]{"one","two","three"}));
		}
		
		//join words
		public static String joinWords(String []words){
				MyStringBuffer sentence = new MyStringBuffer();
				for (String word : words){
						sentence.append(word);
				}
				return sentence.toString();
		}
}