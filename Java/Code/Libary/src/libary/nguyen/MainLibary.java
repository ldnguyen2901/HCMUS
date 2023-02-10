package libary.nguyen;

public class MainLibary {
	public static void main(String[] args) {
		Libary lib = new Libary("Fahasa");
		
		//test case 1: Register One Borrower
		lib.registerOneBorrower("Nguyen");
		System.out.println("Test case 1\nRegister One Borrower success");
		
		//test case 2: Add one book
		Book DTC = new Book("Conan","Aoyama Gosho", "1078");
		lib.addOneBook(DTC);
		Book DRM = new Book("Doreamon","Fujiko F. Fujio","2023");
		lib.addOneBook(DRM);
		System.out.println("\nTest case 2\nAdd one book success");
		
		//test case 3: Display book available
		System.out.println("\nTest case 3");
		lib.displayBooksAvailableForLoan();
		
		//test case 4: Display books out on loan
		System.out.println("\nTest case 4");
		lib.displayBooksOnLoan();
		
		//test case 5: Lend one book
		System.out.println("\nTest case 5");
		lib.lendonebook("1078", "Nguyen");
		lib.displayBooksOnLoan();
		lib.displayBooksAvailableForLoan();
		
		//test case 6: return one book
		System.out.println("\nTest case 6");
		lib.returnonebook("2023", "Nguyen");
		lib.displayBooksOnLoan();
		lib.displayBooksAvailableForLoan();
	}
}
