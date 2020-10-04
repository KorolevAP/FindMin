#include "Methods.h"

void FindMinAlg::findMin(double a, double b)
{   
    arrayX.clear();
    arrayX.push_back(a);
    arrayX.push_back(b);

    points[a] = findValue(a);
    points[b] = findValue(b);






    std::cout << points[a] << "..." << points[b];
}

void FindMinAlg::setFinderFunction(std::function<double(double)> f)
{
    findValue = f;
}
