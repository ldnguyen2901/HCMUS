package libary.nguyen;

import java.util.ArrayList;

public class BorrowerRecord {
	private String name;
	private ArrayList<Book> books;
	
	public BorrowerRecord (String name) {
		this.setName(name);
		this.books = new ArrayList<Book>();
	}
	
	public void attachBook(Book books) {
		this.books.add(books);
	}
	
	public void detachBook(Book books) {
		this.books.remove(books);
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
}
