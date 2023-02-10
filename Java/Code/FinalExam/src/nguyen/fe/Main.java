package nguyen.fe;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Semester hocky = new Semester("Hoc ky I 2023");
        ArrayList<Student> students = new ArrayList<>();
        File file = new File("danhsach.txt");
        try {
            Scanner sc = new Scanner(file);

            while (sc.hasNextLine()) {
                String[] line = sc.nextLine().split("\t");
                Course c = new Course(line[0], line[1]);
                Student st = new Student(line[3], line[2]);
                hocky.addCourse(c);
                int exist_student = 0;
                for (Student s : students) {
                    if (s.getId().compareTo(st.getId()) == 0) {
                        s.addDangKy(new DangKy(c, hocky.getName()));
                        exist_student = 1;
                    }
                }
                if (exist_student == 0) {
                    st.addDangKy(new DangKy(c, hocky.getName()));
                    students.add(st);
                }
            }
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(hocky);
        for (Student s : students){
            for (DangKy dk : s.getDangkys()){
                System.out.print(dk.getMonhoc() + "\t");
                System.out.println(s);
            }                
        }
    }
}
