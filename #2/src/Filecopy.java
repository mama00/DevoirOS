/* Executable name: Filecopy.java
 * Description : A Java program that copies the contents of one file to the destination file
 *               The user provides the source and the destination file and the contents are copied
 * Author : Ruban Anderson
 * Date : 19/09/2020
 */
import java.io.BufferedReader; // Reads text from a character-input stream, buffering characters so as to provide for the efficient reading of characters, arrays, and lines
import java.io.File; // An abstract representation of file 
import java.io.FileReader; // Convenience class for reading character files
import java.io.FileWriter; // Convenience class for writing character files
import java.io.IOException; // Signals that an I/O exception of some sort has occurred
import java.util.Scanner; // Use the scanner class to permit the user to enter the name of the source and the destination file

public class Filecopy {

	public static void main(String[] args) 
	{
		// First we ask the user the source file path and the destination file path
		Scanner in = new Scanner(System.in); // create a Scanner object to use later to make the entry
		System.out.println("Entrez le nom du fichier source"); // Asks the user to enter the name of the source file
		String source = in.next(); // Put the source file path in a string variable
		System.out.println("Entrez le nom de la destination de votre texte"); // Asks the user to enter the name of the destination file
		String destination = in.next(); // Put the destination file path in a string variable
		
		// We verify if the source file exists
		File sourcefile = new File(source);
		boolean exists = sourcefile.exists();
		
		// If the file exists, we execute the copy. Else we print a error message
		if (exists)
		{
			//we put our code in a "try" statement to get track of the possible errors that could cause failure
			try
			{
				FileReader fr = new FileReader(source); // create a new object of the file reader class to read through our file
				BufferedReader br = new BufferedReader(fr); // create a new bufferedReader object to read from our file, buffer them so we can read them line by line
				FileWriter fw = new FileWriter(destination,true); // constructs a filewriter object with our destination file name and a boolean indication wheter or not to append the data written
				String s; // create a string variable to contain the lines to write in our destination file
				
				while ((s=br.readLine())!= null) // we read the file line by line with the buffer and we put them in our string to process it
				{
					fw.write(s); // write in the file using the string variable
					fw.flush(); // to force the writing of the lines if it's not already done
				}
				br.close(); // close the buffer
				fw.close(); // close the destination file
				System.out.println("Le fichier a ete copie");
			}
			catch(IOException e)
			{
				e.printStackTrace(); // the error to print if failed
			}
		}
		else
		{
			System.out.println("Desole mais votre fichier n'existe pas");
		}
		
	}

}
