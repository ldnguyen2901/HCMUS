package softwarehouse.nguyen;

public class Maintest {
	public static void main(String[] args) {
		SoftwareHouse sh = new SoftwareHouse();
		
		Programmer p1 = new Programmer("001", 1000, "Huyen", "C");
		Programmer p2 = new Programmer("002", 1500, "Duy", "Go");
		ProjectLeader p3 = new ProjectLeader("003", 1300, "Nguyen", "C++");
		
		sh.addEmployee(p1);
		sh.addEmployee(p2);
		sh.addEmployee(p3);
		
		p3.addProgrammer(p1);
		p3.addProgrammer(p2);
		
		sh.displayStaff();
		
		System.out.println("----------------------------");
		
		Employee p4 = new Administrator("004", 5000, "Hung");
		Employee p5 = new Programmer("005", 2500, "Anh", "Java");
		Employee p6 = new ProjectLeader("006", 5200, "Thuan", "C#");
		
		sh.addEmployee(p4);
		sh.addEmployee(p5);
		sh.addEmployee(p6);
		
		System.out.println("----------------------------");
		
		sh.displayStaff();
		
	}
}
