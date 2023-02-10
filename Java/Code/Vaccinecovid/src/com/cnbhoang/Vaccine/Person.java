package com.cnbhoang.Vaccine;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Person {
	String id;
	String name;
	Date dob;
	List<Vaccine> vaccines;
	
	public Person(String id, String name, Date dob) {
		this.setId(id);
		this.setName(name);
		this.setDOB(dob);
		vaccines = new ArrayList<>();
	}
	
	public void addVaccine(Vaccine vac) {
		vaccines.add(vac);
	}

	public void printVaccineInfo() {
		System.out.println("CMND/CCCD       : " + id);
		System.out.println("Name            : " + name);
		System.out.println("Date of birth   : " + dob.toString());
		System.out.println("List of vaccine (" + this.vaccines.size() + " doses) : ");
		for (Vaccine vac : vaccines) {
			vac.printInfo();
		}
		System.out.println("-------------------------------------------");
	}
	
	public String getId() {
		return this.id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return this.name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Date getDOB() {
		return this.dob;
	}
	public void setDOB(Date dob) {
		this.dob = dob;
	}
}