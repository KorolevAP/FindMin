#include "GenerateData.hpp"

void Data::setArrayX()
{
    xArray.push_back(leftPoint);
    auto diff = (rightPoint - leftPoint) / numOfPoints;
    for (auto i = 1; i <= numOfPoints; ++i) {
        xArray.push_back(diff * i);
    }
}

void Data::setLeftPoint(double leftPoint)
{
    this->leftPoint = leftPoint;
}

void Data::setRightPoint(double rightPoint)
{
    this->rightPoint = rightPoint;
}

void Data::setNumOfPoints(size_t numOfPoints)
{
    this->numOfPoints = numOfPoints;
}

std::vector<double> Data::getArrayY()
{
    return this->yArray;
}

std::vector<double> Data::getArrayX()
{
    return xArray;
}

void Polinome:: findPoints()
{
    if (coefficients.empty())
    {
        return;
    }

    setArrayX();
    yArray.clear();
    for (auto i = 0; i < numOfPoints; ++i) {
        auto tmp = polinomeLevel;
        auto y_i = 0.0;
        for (auto elem : coefficients) {
            y_i += elem * pow(xArray[i], tmp--);
        }
        yArray.push_back(y_i);
    }

}

void Polinome::setPolinomeLevel(size_t level)
{
    polinomeLevel = level;
}

void Polinome::generate()
{
    setPolinomeLevel(3);
    setNumOfPoints(10);
    coefficients.clear();
    std::srand(1);
    std::cout << "polinomlvl = " << polinomeLevel << std::endl;
    for (size_t i = 0; i < polinomeLevel; ++i) {
        coefficients.push_back(5 - ((double)rand() / RAND_MAX) * 10);
    }
    findPoints();

    std::cout << "\ncoeffs:";
    for (auto s : coefficients)
        std::cout << s << " ";
    std::cout << "\nx_array\n";
    for (auto s : xArray)
        std::cout << s << " ";
    std::cout << "\ny_i :\n";
    for (int i = 0; i < yArray.size(); ++i) {
        std::cout << yArray[i] << "\t";
        if (i + 1 % 5 == 0)
            std::cout << "\n";
    }
}

void Polinome::addNewPoint(double point)
{
    
}

void Sin::generate()
{
    yArray.clear();
    setArrayX();
    for (int i = 0; i < xArray.size(); ++i) {
        yArray.push_back(sin(xArray[i]));
    }
}