package nguyenwolf;

import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) {
		List<Account> accounts = new ArrayList<>();
		
		accounts.add(new Account("001",1000));
		accounts.add(new Account("002",2000));
		
		for(int i = 0; i < accounts.size(); i++)
			System.out.println(accounts.get(i).getBalance());
		System.out.println();
		for(Account account: accounts)
			System.out.println(account.getBalance());
	}
}
