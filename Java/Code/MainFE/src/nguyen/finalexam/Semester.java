package nguyen.finalexam;

import java.util.*;

public class Semester {
	private String name;
	
	public List<Course> courses;
	public List<Student> students;
	
	public Semester(String name) {
		this.setName(name);
		this.courses = new ArrayList<>();
//		this.students = new ArrayList<>();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	public void addcourse(Course course) {
		this.courses.add(course);
	}
	
	public void dangky(String tenhp, String mssv) {
		Course cr = null;
		for(int i = 0; i < this.courses.size(); i++){
			if(this.courses.get(i).getName().equals(tenhp)) {
				cr = this.courses.get(i);
			}
		}
		
		Student st = null;
		for(int i = 0; i < this.students.size(); i++){
			if(this.students.get(i).getName().equals(mssv)) {
				st = this.students.get(i);
			}
		}
		st.addcourse(cr);
		cr.addstudent(st);
	}
	
	public void printsemester() {
		for(Course cr: courses) {
			cr.printCourse();
		}
	}
	
}
