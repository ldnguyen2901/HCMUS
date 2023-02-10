package nguyen.fe;

public class Course {
    private String id, name;

    public Course() {
    }

    public Course(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return String.format("%s\t%s", id, name);
    }
    
    
    
}
