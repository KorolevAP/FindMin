#pragma once
#include <vector>
#include <iostream>

// enum functionType {
//     polinome,
//     sin,
//     arctg
// };


class Data
{
protected:
    std::vector<double> yArray = {};
    std::vector<double> xArray = {};
    double leftPoint = 0;
    double rightPoint = 10;
    size_t numOfPoints = 10;
    void setArrayX();
public:
    Data() = default;
    void setLeftPoint(double leftPoint);
    void setRightPoint(double rightPoint);
    void setNumOfPoints(size_t numOfPoints);
    virtual void generate() = 0;
    std::vector<double> getArrayY();
    std::vector<double> getArrayX();
};

class Polinome : virtual public Data
{
private:
    std::vector<double> coefficients = {};
    size_t polinomeLevel = 2;
    void findPoints();
public:
    Polinome() = default;
    void setPolinomeLevel(size_t level);
    void generate();
};

class Sin : virtual public Data
{
public:
    void generate();
};