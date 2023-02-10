package nguyen.finalexam;

import java.util.*;

public class Course {
	private String id;
	private String name;
	
	private Student st = null;
	
	public Course (String id, String name) {
		this.setId(id);
		this.setName(name);
		this.st = null;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	public void addstudent(Student student) {
		this.st = st;
	}
	public void printCourse() {
			System.out.println(id + "\t" + name);
	}
}
