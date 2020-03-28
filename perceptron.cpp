#include "perceptron.h"

using namespace std;

Perceptron::Perceptron(int n) {
    num_of_inputs = n;
    for (int i = 0; i < n; i++) {
        coefficients.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) - 0.5);
    }
};

bool Perceptron::set_inputs(vector<double> a_inputs) {
    if (a_inputs.size() != num_of_inputs - 1) {
        return false;
    }
    inputs = a_inputs;
    return true;
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
    srand (static_cast <unsigned> (time(0)));
    vector<double> inputs = {0.5,1};
    Perceptron p(3);
    if (!p.set_inputs(inputs)) {
        cout << "Failed to load inputs into the perceptron.";
    } else {
        cout << "The result is " << p.get_output();
    };
}
