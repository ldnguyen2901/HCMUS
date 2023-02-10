package nguyen.db;

import java.sql.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Properties;

public class MainDB{
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		Class.forName("com.mysql.jdbc.Driver");
		System.out.println("1. Load the driver");
		String url = "jdbc:mysql://localhost:3306/world";
		
		Properties userInfo = new Properties();
		userInfo.put("user", "root");
		userInfo.put("password", "nguyenwolf");
		Connection conn = DriverManager.getConnection(url, userInfo);
		System.out.println("3. Establish the conn");
		Statement statement = conn.createStatement();
		ResultSet rs = statement.executeQuery("select code, name, indepyear from country");
		
		while(rs.next()) {
			String code = rs.getString("code");
			String name = rs.getString("name");
			String indepYear = rs.getString("Indepyear");
			System.out.println(code + "\t" + name + "\t" + indepYear);
		}
		conn.close();		
	}
}