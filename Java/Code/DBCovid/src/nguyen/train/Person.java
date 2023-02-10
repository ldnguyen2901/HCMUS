package nguyen.train;

import java.util.*;

public class Person {
	private String id;
	private String name;
	private String date_of_birth;
	
	private List<Vaccine> Vaccines;

	public Person(String id, String name, String date_of_birth) {
		this.setId(id);
		this.setName(name);
		this.setDate_of_birth(date_of_birth);
		this.Vaccines = new ArrayList<>();
	}
	
	public void vaccinated(Vaccine Vaccine) {
		this.Vaccines.add(Vaccine);
	}
	
	public String getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public String getDate_of_birth() {
		return date_of_birth;
	}

	public void setId(String id) {
		this.id = id;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setDate_of_birth(String date_of_birth) {
		this.date_of_birth = date_of_birth;
	}
	
	public void display() {
		System.out.println("Id: " + this.getId());
		System.out.println("Name: " + this.getName());
		System.out.println("Date of birth: " + this.getDate_of_birth());
		System.out.println();
	}
}
