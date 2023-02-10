package com.cnbhoang.inheritance;

public class Programmer extends Employee {
	private String language;
	
	public Programmer(String payrollNumber, double monthlySalary, String name,
			          String language) {
		super(payrollNumber, monthlySalary, name);
		this.setLanguage(language);
	}
	public void display() {
		super.display();
		System.out.println("Language: "+ this.getLanguage());
	}
	
	public String getLanguage() {
		return language;
	}
	public void setLanguage(String language) {
		this.language = language;
	}

}
