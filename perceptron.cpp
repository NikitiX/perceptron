#include "perceptron.h"

using namespace std;

Perceptron::Perceptron(vector<double> f_coefficients) {
    num_of_inputs = f_coefficients.size();
    coefficients = f_coefficients;
};

int Perceptron::set_inputs(vector<double> a_inputs) {
    if (a_inputs.size() != num_of_inputs - 1) {
        return 0;
    }
    inputs = a_inputs;
    return 1;
};

int Perceptron::set_input(int index, double value) {
    if ((index < 0) || (index >= num_of_inputs)) {
        return 0;
    }
    inputs[index] = value;
    return 1;
};

int Perceptron::set_coefficients(vector<double> a_coefficients) {
    if (a_coefficients.size() != num_of_inputs) {
        return 0;
    }
    coefficients = a_coefficients;
    return 1;
};

int Perceptron::set_coefficient(int index, double value) {
    if ((index < 0) || (index > num_of_inputs)) {
        return 0;
    }
    coefficients[index] = value;
    return 1;
};

double Perceptron::get_output() {
    double result = coefficients[0];
    for (int i = 0; i < num_of_inputs; i++) {
        result += inputs[i] * coefficients[i+1];
    }
    return result;
};

int main()
{
    vector<double> c = {0.5,1.5,1};
    vector<double> inputs = {0,0.5};
    Perceptron p(c);
    if (!p.set_inputs(inputs)) {
        cout << "Failed to load inputs into the perceptron.";
    } else {
        cout << "The result is " << p.get_output();
    };
}
