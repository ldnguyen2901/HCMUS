package nguyen.fe;

import java.util.ArrayList;


public class Student extends Person{
    private String id;
    private ArrayList<DangKy> dangkys;

    public Student() {
        dangkys = new ArrayList<>();
    }

    public Student(String name, String id) {
        super(name);
        this.id = id;
        dangkys = new ArrayList<>();
    }

    public String getId() {
        return id;
    }

    public ArrayList<DangKy> getDangkys() {
        return dangkys;
    }

    @Override
    public String getName() {
        return super.getName(); 
    }
    
    void addDangKy(DangKy item){
        dangkys.add(item);
    }

    @Override
    public String toString() {
        return String.format("%s\t%s", id, getName());
    }
    
    
}
