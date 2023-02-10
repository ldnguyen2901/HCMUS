package nguyen.train;

public class Vaccine {
	private String id;
	private String dose;
	private String product_name;
	private String date;
	
	public Vaccine(String id, String dose, String product_name, String date) {
		this.setId(id);
		this.setDose(dose);
		this.setProduct_name(product_name);
		this.setDate(date);
	}
	public String getId() {
		return id;
	}
	
	public String getDose() {
		return dose;
	}
	public String getProduct_name() {
		return product_name;
	}
	public String getDate() {
		return date;
	}
	public void setId(String id) {
		this.id = id;
	}
	public void setDose(String dose) {
		this.dose = dose;
	}
	public void setProduct_name(String product_name) {
		this.product_name = product_name;
	}
	public void setDate(String date) {
		this.date = date;
	}
	
	public void display() {
//		System.out.println("Id: " + this.getId());
		System.out.println("Dose: " + this.getDose());
		System.out.println("Product Name: " + this.getProduct_name());
		System.out.println("Date: " + this.getDate());
		System.out.println();
	}	
	
}
