package com.cnbhoang.inheritance;

import java.util.*;

public class ProjectLeader extends Programmer {
	private List<Programmer> team;
	
	public ProjectLeader(String payrollNumber, double monthlySalary, String name, String language) {
		super(payrollNumber, monthlySalary, name, language);
		this.team = new ArrayList<>();
	}
	
	public void addProgrammer(Programmer p) {
		this.team.add(p);
	}
	
	public void display() {
		System.out.println("---Project Leader---");
		super.display();
	}
}
