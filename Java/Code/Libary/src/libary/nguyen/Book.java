package libary.nguyen;

public class Book {
	private String title;
	private String author;
	private String number;
	
	private BorrowerRecord br = null;
		
	public Book(String title, String author, String number) {
		this.title = title;
		this.author = author;
		this.number = number;
		this.br = null;
	}
	
	public void display() {
		System.out.println("Title: " + this.title);
		System.out.println("Author: " + this.author);
		System.out.println("Number: " + this.number);
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public String getNumber() {
		return number;
	}

	public void setNumber(String number) {
		this.number = number;
	}

	public BorrowerRecord getBr() {
		return br;
	}

//	public void setBr(BorrowerRecord br) {
//		this.br = br;
//	}
	
	public boolean AvailableForLoan() {
		if(this.br == null)
			return true;
		return false;
	}
	
	public void attachBorrower(BorrowerRecord br) {
		this.br = br;
	}
	
	public void detachBorrower(BorrowerRecord br) {
		this.br = null;
	}
	
}
