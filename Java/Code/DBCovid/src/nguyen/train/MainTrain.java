package nguyen.train;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class MainTrain {
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		Class.forName("com.mysql.jdbc.Driver");
		System.out.println("1. Load the driver");
		String url = "jdbc:mysql://localhost:3306/covid";
		
		Properties userInfo = new Properties();
		userInfo.put("user", "root");
		userInfo.put("password", "nguyenwolf");
		Connection conn = DriverManager.getConnection(url, userInfo);
		System.out.println("3. Establish the conn");
		Statement statement = conn.createStatement();
		
		List<Person> person = new ArrayList<Person>();
		ResultSet pp = statement.executeQuery("select id, namepeople, dates from people");
		while(pp.next()) {
			String id = pp.getString("id");
			String namepeople = pp.getString("namepeople");
			String dates = pp.getString("dates");
			person.add(new Person(id, namepeople, dates));
		}
		
			
		List<Vaccine> Vaccine = new ArrayList<Vaccine>();
		ResultSet vc = statement.executeQuery("select id, dose, typevaccine, dates from vaccine");
		while(vc.next()) {
			String id = vc.getString("id");
			String dose = vc.getString("dose");
			String namepeople = vc.getString("typevaccine");
			String dates = vc.getString("dates");
			Vaccine.add(new Vaccine(id, dose, namepeople, dates));
		}
			
			for (Person j :person) {
//				System.out.println("Id: " + j.getId());
				j.display();
				for (Vaccine i : Vaccine) {
					if (i.getId().equals(j.getId())){
						i.display();
//						System.out.println("Dose: " + i.getDose());
//						System.out.println("Product Name: " + i.getProduct_name());
//						System.out.println("Date: " + i.getDate());
					}
				}
				System.out.println("------------------------------");
			}
			conn.close();		
	}
}
