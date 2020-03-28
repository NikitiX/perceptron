#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

class Perceptron {
public:
    Perceptron(unsigned int num_of_inputs,double learning_rate,double epsilon);
    bool set_inputs(vector<double> a_inputs);
    bool learn(double real_answer);
    double get_output();
    void print();
private:
    double process();
    double activationFunction(double arg);
    double dActivationFunction(double arg);
    vector<double> inputs;
    vector<double> coefficients;
    unsigned int num_of_inputs;
    double epsilon;
    double learn_rate;
    double current_result;
};
