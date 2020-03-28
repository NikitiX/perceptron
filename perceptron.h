#include <iostream>
#include <vector>

using namespace std;

enum return_code {SUCCESS, ERROR};

class Perceptron {
public:
    Perceptron(vector<double> f_coefficients);
    return_code set_inputs(vector<double> a_inputs);
    double get_output();
private:
    vector<double> inputs;
    vector<double> coefficients;
    int num_of_inputs;
};
