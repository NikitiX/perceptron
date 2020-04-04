/*
TODO:
Add R-layer
Check if it is working
*/

#include "layers.h"

double random() {
    return ;// TODO
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

ALayer::ALayer() {};
void ALayer::connect() {};
void ALayer::update() {};
double ALayer::get_output() {};

bool Sensor::set_state (int n_state) {
    if ((n_state < 0) || (n_state > 2)) return false;
    state = n_state;
    return true;
};

int Sensor::get_state () {
    return state;
};

void SLayer::add_sensor(Sensor sensor) {
    sensors.push_back(sensor);
};

bool SLayer::set_outputs(vector<int> outputs) {
    if (outputs.size() != sensors.size()) return false;
    for (int i = 0; i < outputs.size(); i++) if ((outputs[i] < 0) || (outputs[i] > 1)) return false;
    for (int i = 0; i < outputs.size(); i++) sensors[i].set_output(outputs[i]);
};

int SLayer::get_output(int s_index) {
    if ((s_index < 0) || (s_index > sensors.size())) {return -2147483648;}
    return sensors[s_index].get_state();
}

ASLayer::ASLayer (SLayer prev) {prevLayer = prev};

bool ASLayer::check_correct(int index) {
    if ((index < 0) || (index > saconnections.size())) {
        return false;
    }
    return true;
};

int ASLayer::connect(int p_index,int s_index) {
    if (!check_correct(p_index)) {return false;}
    if (p_index == saconnections.size()) {
        vector<int> tmp;
        tmp.push_back(s_index);
        saconnections.push_back(tmp);
    }
    else {saconnections[i].push_back(s_index);}
    return true;
};

int ASLayer::connect(int p_index,vector<int> s_indexes) {
    if (!check_correct(p_index)) {return false;}
    if (p_index == saconnections.size()) {
        saconnections.push_back(s_indexes);
    }
    else {saconnections[i] = s_indexes;}
    return true;
};

void ASLayer::initialize() {
    for (int i = 0 ; i < saconnections.size(); i++) {
        perceptrons.push_back(Perceptron(saconnections[i].size()));
    }
    update();
}

void ASLayer::update() {
    for (int i = 0; i < perceptrons.size(); i++) {
        vector<int> tmp;
        for (auto& index : saconnections[i]) {
            tmp.push_back(prevLayer.get_output(index));
        }
        perceptrons[i].set_inputs(tmp);
        output[i] = perceptrons[i].get_output();
    }
};

double ASLayer::get_output(int index) {
    return output[index];
};

ASLayer::ASLayer (ALayer prev) {prevLayer = prev};

bool ASLayer::check_correct(int index) {
    if ((index < 0) || (index > saconnections.size())) {
        return false;
    }
    return true;
};

int ASLayer::connect(int p_index,int s_index) {
    if (!check_correct(p_index)) {return false;}
    if (p_index == saconnections.size()) {
        vector<int> tmp;
        tmp.push_back(s_index);
        saconnections.push_back(tmp);
    }
    else {saconnections[i].push_back(s_index);}
    return true;
};

int ASLayer::connect(int p_index,vector<int> s_indexes) {
    if (!check_correct(p_index)) {return false;}
    if (p_index == saconnections.size()) {
        saconnections.push_back(s_indexes);
    }
    else {saconnections[i] = s_indexes;}
    return true;
};

void ASLayer::initialize() {
    for (int i = 0 ; i < saconnections.size(); i++) {
        perceptrons.push_back(Perceptron(saconnections[i].size()));
    }
    update();
}

void ASLayer::update() {
    for (int i = 0; i < perceptrons.size(); i++) {
        vector<int> tmp;
        for (auto& index : saconnections[i]) {
            tmp.push_back(prevLayer.get_output(index));
        }
        perceptrons[i].set_inputs(tmp);
        output[i] = perceptrons[i].get_output();
    }
};

double ASLayer::get_output(int index) {
    return output[index];
};

int main() {

};
