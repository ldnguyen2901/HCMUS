package nguyen.finalexam;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class MainFE{
	public static void main(String[] args) {
		Path s = Paths.get("D:\\HCMUS\\Computer_Science\\Java\\Code\\MainFE\\src\\data\\student.txt");
		Path c = Paths.get("D:\\HCMUS\\Computer_Science\\Java\\Code\\MainFE\\src\\data\\course.txt");
		List<Student> student = new ArrayList<Student>();
		try {
			List<String> lines = Files.readAllLines(s, Charset.defaultCharset());
			for (String line:lines) {
				String[] token = line.split("\t");
				student.add(new Student(token[0],token[1]));
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		Semester smt = new Semester("Fall 2022");
		
		List<Course> course = new ArrayList<Course>();
		try {
			List<String> lines = Files.readAllLines(c, Charset.defaultCharset());
			for (String line:lines) {
				String[] token = line.split("\t");
				course.add(new Course(token[0],token[1]));
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		for(Course cr: course) {
			smt.addcourse(cr);
		}

		smt.dangky("Mang may tinh", "20110001");
		smt.dangky("Mang may tinh", "20110002");
		smt.dangky("Co so du lieu", "20110002");
		smt.dangky("Co so du lieu", "20110003");
		smt.printsemester();
		
	}
	
}
