#include "GenerateData.hpp"
#include "Methods.h"

int main() {
  
    auto doubleFunc = [](double s) { return s * s; };
    FindMinAlg alg;
    alg.setFinderFunction(doubleFunc);
    alg.findMin(1,4);
    return 0;
}