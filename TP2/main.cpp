#include <iostream>
#include "headers/gau.h"
#include "headers/sin.h"
#include "headers/stp.h"
#include "headers/tsdata.h"

int main(){
    GaussianGenerator g;
    SinWaveGenerator s;
    StepGenerator st;

    cout << "Gaussian Generator: " << endl;
    TimeSeriesGenerator::printTimeSeries(g.generateTimeSeries(10));

    cout << "Sinus Generator " << endl;
    TimeSeriesGenerator::printTimeSeries(s.generateTimeSeries(10));

    cout << "Step Generator " << endl;
    TimeSeriesGenerator::printTimeSeries(st.generateTimeSeries(10));

    return 0;
}
