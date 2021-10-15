#include "vidurkis.h"
#include <numeric>

double vidurkis(vector<double> namuDarbuPazymiai) {
    double average;
    average = accumulate(namuDarbuPazymiai.begin(), namuDarbuPazymiai.end(), 0) / namuDarbuPazymiai.size();
    return average;
}
