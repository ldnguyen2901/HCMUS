package com.cnbhoang.inheritance;

public class Testcase {
	public static void main(String[] args) {
		SoftwareHouse sh = new SoftwareHouse();
		
		Programmer p1 = new Programmer("001", 3000, "Hoang", "C");
		Programmer p2 = new Programmer("002", 3500, "Bao", "Python");
		ProjectLeader pl = new ProjectLeader("003", 5500, "Duy", "C++");
		
		sh.addEmployee(p1);
		sh.addEmployee(pl);
		sh.addEmployee(p2);
		
		pl.addProgrammer(p1);
		pl.addProgrammer(p2);
		
		sh.displayStaff();
		
		Employee ad = new Administrator("004", 5000, "Hung");
		Employee p3 = new Programmer("005", 2500, "Anh", "Java");
		Employee pl2 = new ProjectLeader("006", 5200, "Thuan", "C#");
		
		sh.addEmployee(ad);
		sh.addEmployee(p3);
		sh.addEmployee(pl2);
		
		sh.displayStaff();
	}

}
