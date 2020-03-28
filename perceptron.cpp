#include "perceptron.h"

using namespace std;

double random() {
    return static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
};

Perceptron::Perceptron(unsigned int n,double l=0.3,double e=0.001) {
    num_of_inputs = n;
    for (int i = 0; i < n; i++) {
        coefficients.push_back(random() - 0.5);
    }
    learn_rate = l;
    epsilon = e;
};

bool Perceptron::set_inputs(vector<double> a_inputs) {
    if (a_inputs.size() != num_of_inputs - 1) {
        return false;
    }
    inputs = a_inputs;
    process();
    return true;
};

double Perceptron::process() {
    current_result = coefficients[0];
    for (int i = 0; i < num_of_inputs; i++) {
        current_result += inputs[i] * coefficients[i+1];
    }
};

double Perceptron::get_output() {
    return current_result;
};

double Perceptron::activationFunction(double arg) {
    return 1. / (1. + exp(-arg));
};

double Perceptron::dActivationFunction(double arg) {
    return activationFunction(arg) * (1. - activationFunction(arg));
};

bool Perceptron::learn(double real_answer) {
    double error = real_answer - current_result;
    //cout << endl << error << endl;
    if ((error<0?-error:error) < epsilon) {
        return true;
    }
	double teta = error * activationFunction(current_result);
	for (int i = 1; i < num_of_inputs; i++) {
		coefficients[i] += learn_rate * teta * inputs[i-1];
	};
	coefficients[0] += learn_rate * teta;
	return false;
};

void Perceptron::print() {
    for (int i = 0; i < num_of_inputs; i++) {
        cout << coefficients[i] << ' ';
    }
    cout << endl;
};

int main()
{
    srand(static_cast <unsigned> (time(0)));
    Perceptron p(3);
    int right_answers = 0;
    while (true) {
        double a = random();
        double b = random();
        vector<double> inputs = {a,b};
        //cout << "Learning a - (b/2): ";
        //p.print();
        p.set_inputs(inputs);
        double real_answer = a - (b / 2.);
        //cout << "Inputs: " << a << ' ' << b << ", the real answer is " << real_answer << ", the perceptron answer is " << p.get_output() << endl;
        if (p.learn(real_answer)) {
            if (++right_answers == 10) {
                break;
            }
        } else {
            right_answers = 0;
        }
    }
}
