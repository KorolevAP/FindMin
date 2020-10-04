#pragma once
#include <vector>
#include <map>
#include <functional>
#include "GenerateData.hpp"
class Methods
{
public:
    virtual void findMin(double a, double b) = 0;

    std::map<double, double> points;
};

class FindMinAlg : public Methods
{
public:
    void findMin(double a, double b);
    void setFinderFunction(std::function<double(double)> f);
private:
    std::function<double(double)> findValue;
    std::vector<double> arrayX;
};

