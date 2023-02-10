package nguyen.finalexam;

import java.util.*;

public class Student extends Person {
	private String id;
	private List<Course> courses;
	public Student (String id ,String name) {
		super (name);
		this.setId(id);
		this.courses = new ArrayList<Course>();
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}
	public void addcourse(Course course) {
		this.courses.add(course);
	}
}