package nguyenwolf;

public class Account{
	private String number;
	private int balance;
	
	public Account(String num, int balance) {
		this.number = num;
		this.balance = balance;
	}
	
	public String getNumber() {
		return this.number;
	}
	
	public int getBalance() {
		return this.balance;
	}
}