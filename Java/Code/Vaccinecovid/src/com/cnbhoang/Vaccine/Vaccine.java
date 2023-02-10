package com.cnbhoang.Vaccine;

import java.util.Date;

public class Vaccine {
	int dose;
	String productName;
	Date vaccinedDate;
	public Vaccine(int dose, String productName, Date vaccinedDate) {
		this.dose = dose;
		this.productName = productName;
		this.vaccinedDate = vaccinedDate;
	}
	
	public void printInfo() {
		System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~");
		System.out.println("Dose : " + dose);
		System.out.println("Type : " + productName);
		System.out.println("Date : " + vaccinedDate.toString());
	}
}