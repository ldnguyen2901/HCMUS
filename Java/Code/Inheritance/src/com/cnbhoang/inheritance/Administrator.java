package com.cnbhoang.inheritance;

public class Administrator extends Employee {
	public Administrator(String payrollNumber, double monthlySalary, String name) {
		super(payrollNumber, monthlySalary, name);
	}
	
	public void display() {
		System.out.println("---Administrator---");
		super.display();
	}
}
