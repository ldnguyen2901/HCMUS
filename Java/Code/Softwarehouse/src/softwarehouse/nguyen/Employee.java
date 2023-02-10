package softwarehouse.nguyen;

public class Employee {
	private String payrollNumber;
	private double monthlySalary;
	private String name;
	
	public void display() {
		System.out.println("Name: "+ this.getName());
		System.out.println("Payroll Number: "+ this.getPayrollNumber());
		System.out.println("Salary: "+ this.getMonthlySalary());
	}
	public Employee(String payrollnumber, double monthlySalary, String name) {
		this.setPayrollNumber(payrollnumber);
		this.setMonthlySalary(monthlySalary);
		this.setName(name);
	}
	
	public String getPayrollNumber() {
		return payrollNumber;
	}
	public void setPayrollNumber(String payrollNumber) {
		this.payrollNumber = payrollNumber;
	}
	
	public double getMonthlySalary() {
		return monthlySalary;
	}
	public void setMonthlySalary(double monthlySalary) {
		this.monthlySalary = monthlySalary;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
}