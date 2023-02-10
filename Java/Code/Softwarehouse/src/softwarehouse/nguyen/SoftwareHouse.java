package softwarehouse.nguyen;

import java.util.*;

public class SoftwareHouse {
	private List<Employee> staff;
	
	public void displayStaff() {
		for(Employee e: this.staff) { 
			e.display();
			System.out.println(" ");
		}
	}
	
	public SoftwareHouse() {
		this.staff = new ArrayList<>();
		
	}
	
	public void addEmployee(Employee e) {
		this.staff.add(e);
	}
}
