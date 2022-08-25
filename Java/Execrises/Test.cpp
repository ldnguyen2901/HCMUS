#include<iostream>
using namespace std;

class Person
{
private:
    float weight;
    float height;
    float BMI;
public:
    void calcBMI()
    {
       BMI = weight / (height * height);
    }
};

