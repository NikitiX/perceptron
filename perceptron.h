#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Perceptron {
public:
    Perceptron(int num_of_inputs);
    bool set_inputs(vector<double> a_inputs);
    double get_output();
private:
    vector<double> inputs;
    vector<double> coefficients;
    int num_of_inputs;
};
