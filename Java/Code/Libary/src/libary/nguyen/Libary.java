package libary.nguyen;

import java.util.ArrayList;

public class Libary{
	private String name;
	private ArrayList<Book> listBooks;
	private ArrayList<BorrowerRecord> listBorrower;
	
	public Libary (String name) {
		this.name = name;
		this.listBooks = new ArrayList<Book>();
		this.listBorrower = new ArrayList<BorrowerRecord>();
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void registerOneBorrower(String aBorrowerName) {
		BorrowerRecord aBorrower = new BorrowerRecord(aBorrowerName);
		this.listBorrower.add(aBorrower);
		
	}
	
	public void addOneBook(Book book) {
		this.listBooks.add(book);
	}
	
	public void displayBooksAvailableForLoan() {
		Book bk = null;
		int flash = 0;
		System.out.println("Books available on loan: ");
		for(int i = 0; i < this.listBooks.size(); i++) {
			bk = this.listBooks.get(i);
			if(bk.AvailableForLoan()) {
				bk.display();
				System.out.println();
				flash = 1;
			}
		}
		if(flash == 0)
			System.out.println("Null");
	}
	
	public void displayBooksOnLoan() {
		Book bk = null;
		int flash = 0;
		System.out.println("Books on Loan: ");
		for(int i = 0; i < this.listBooks.size(); i++) {
			bk = this.listBooks.get(i);
			if(!bk.AvailableForLoan()) {
				bk.display();
				System.out.println("Borrower Name: " + bk.getBr().getName());
				System.out.println();
				flash = 1;
			}
		}
		if(flash == 0)
			System.out.println("Null");
	}
	
	public void lendonebook(String number, String name) {
		Book bk = null;
		for(int i = 0; i < this.listBooks.size(); i++) {
			if(this.listBooks.get(i).getNumber().equals(number)) {
				bk = this.listBooks.get(i);
				break;
			}
		}
		
		BorrowerRecord br = null;
		for(int i = 0; i < this.listBorrower.size(); i++) {
			if(this.listBorrower.get(i).getName().equals(name)) {
				br = this.listBorrower.get(i);
				break;
			}
		}
		
		br.attachBook(bk);
		bk.attachBorrower(br);
	}
	
	public void returnonebook(String number, String name) {
		Book bk = null;
		for(int i = 0; i < this.listBooks.size(); i++) {
			if(this.listBooks.get(i).getNumber().equals(number)) {
				bk = this.listBooks.get(i);
				break;
			}
		}
		
		BorrowerRecord br = null;
		for(int i = 0; i < this.listBorrower.size(); i++) {
			if(this.listBorrower.get(i).getName().equals(name)) {
				br = this.listBorrower.get(i);
				break;
			}
		}
		
		br.detachBook(bk);
		bk.detachBorrower(br);
	}
	
	public int listbookinlibary() {
		return this.listBooks.size();
	}
}