package com.cnbhoang.Vaccine;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class MainApp {

	static List<Person> people;
	
	public static void main(String[] args) {
		System.out.println(new File("./").getAbsolutePath());
		people = new ArrayList<>();
		// add people
		List<String> peopleSt = readFile("people.txt");
		for (String st : peopleSt) {
			String s[] = st.split(" ");
			String id = String.valueOf(s[0]);
			String name = String.valueOf(s[1]);
			int year = Integer.valueOf(s[2].substring(0, 4));
			int month = Integer.valueOf(s[2].substring(4, 6));
			int day = Integer.valueOf(s[2].substring(6, 8));
			Date dob = new Date(day, month, year);
			people.add(new Person(id, name, dob));
		}
		
		
		List<String> vaccineSt = readFile("vaccine.txt");
		for (String st : vaccineSt) {
			String s[] = st.split(" ");
			String id = String.valueOf(s[0]);
			int dose = Integer.valueOf(s[1]);
			String name = String.valueOf(s[2]);
			int year = Integer.valueOf(s[3].substring(0, 4));
			int month = Integer.valueOf(s[3].substring(4, 6));
			int day = Integer.valueOf(s[3].substring(6, 8));
			Date vaccinedDate = new Date(day, month, year);
			Vaccine vac = new Vaccine(dose, name, vaccinedDate);
			for (Person person : people) {
				if (person.getId().equals(id)) {
					person.addVaccine(vac);
				}
			}
		}
		
		
		for (Person person : people) {
			person.printVaccineInfo();
		}
	}
	
	private static ArrayList<String> readFile(String fileName) {
		ArrayList<String> lines = new ArrayList<>();
	    try {  
		  File url = new File("./");
		  int len = url.getAbsolutePath().length();
		  String path = url.getAbsolutePath().substring(0, len - 1) + "/src/data/" + fileName;
	      File myObj = new File(path);
	      Scanner myReader = new Scanner(myObj);
	      while (myReader.hasNextLine()) {
	        String line = myReader.nextLine();
	        lines.add(line);	        
	      }
	      myReader.close();
	    } catch (FileNotFoundException e) {
	      System.out.println("An error occurred.");
	      e.printStackTrace();
	    }
	    return lines;
	}
}