package nguyen.fe;

import java.util.ArrayList;


public class Semester {
    private String name;
    private ArrayList<Course> monhocs;

    public Semester() {
        monhocs = new ArrayList<>();
    }

    public Semester(String name) {
        this.name = name;
        monhocs = new ArrayList<>();
    }

    public String getName() {
        return name;
    }
    
    void addCourse(Course item){
        for (Course x : monhocs) if (x.getId().compareTo(item.getId()) ==0) return;
        monhocs.add(item);
    }

    @Override
    public String toString() {
        return name;
    }
    
    
}
