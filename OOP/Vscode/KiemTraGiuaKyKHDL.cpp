#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(double a, double b) : x(a), y(b) {}
    void input()
    {
        cin >> x >> y;
    }
    double get_x()
    {
        return x;
    }
    double get_y()
    {
        return y;
    }
    double length(Point B)
    {
        return sqrt((B.x - x) * (B.x - x) + (B.y - y) * (B.y - y));
    }
    void move(double a = 1, double b = 1)
    {
        x += a;
        y += b;
    }
    void output() const
    {
        cout << "(" << x << ": " << y << ")\n";
    }
};

class Rectangle
{
private:
    Point upper_left;
    double length;
    double width;

public:
    Rectangle(Point A, double l, double w) : upper_left(A), length(l), width(w) {}
    void input()
    {
        upper_left.input();
        cin >> length >> width;
    }
    Point get_upper_left()
    {
        return upper_left;
    }
    Point get_upper_right()
    {
        return Point(upper_left.get_x() + length, upper_left.get_y());
    }
    Point get_lower_left()
    {
        return Point(upper_left.get_x(), upper_left.get_y() + width);
    }
    Point get_lower_right()
    {
        return Point(upper_left.get_x() + length, upper_left.get_y() + width);
    }
    bool is_inside(Point X)
    {
        Point A = upper_left;
        Point B = get_upper_right();
        Point C = get_lower_right();
        Point D = get_lower_left();
        double p1 = 0.5 * (A.length(X) + X.length(B) + B.length(A));
        double p2 = 0.5 * (B.length(X) + X.length(C) + C.length(B));
        double p3 = 0.5 * (C.length(X) + X.length(D) + D.length(C));
        double p4 = 0.5 * (D.length(X) + X.length(A) + A.length(D));
        double s1 = sqrt(p1 * (p1 - A.length(X)) * (p1 - X.length(B)) * (p1 - B.length(A)));
        double s2 = sqrt(p2 * (p2 - B.length(X)) * (p2 - X.length(C)) * (p1 - C.length(B)));
        double s3 = sqrt(p3 * (p3 - C.length(X)) * (p1 - X.length(D)) * (p1 - D.length(C)));
        double s4 = sqrt(p4 * (p4 - D.length(X)) * (p1 - X.length(A)) * (p1 - A.length(D)));
        double a = length * width;
        if (s1 + s2 + s3 + s4 - a < 1e-04)
        {
            return true;
        }
        return false;
    }
    void output()
    {
        upper_left.output();
        cout << length << " " << width << "\n";
    }
};

int main()
{
    Rectangle ABCD({4, 1}, 5, 4);
    Point X(5, 6);
    X.input();
    ABCD.input();
    bool check = ABCD.is_inside(X);
    cout << (check ? "Nam trong" : "Nam ngoai");
    X.output();
    ABCD.output();
    return 0;
}