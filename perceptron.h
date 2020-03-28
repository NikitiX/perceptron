#include <iostream>
#include <vector>

using namespace std;

class Perceptron {
public:
    Perceptron(vector<double> f_coefficients);
    int set_inputs(vector<double> a_inputs);
    int set_input(int index, double value);
    int set_coefficients(vector<double> a_coefficients);
    int set_coefficient(int index, double value);
    double get_output();
private:
    vector<double> inputs;
    vector<double> coefficients;
    int num_of_inputs;
};
