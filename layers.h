#include "perceptron.h"

class Sensor {
public:
    bool set_state(int n_state);
    int get_state();
private:
    int state;
};

class SLayer {
public:
    void add_sensor(Sensor sensor);
    bool set_outputs(vector<int> outputs);
    int get_output(int s_index);
private:
    vector<Sensor> sensors;
};

class ALayer {
public:
    ALayer();
    virtual void connect();
    virtual void update();
    virtual double get_output();
};

class ASLayer : public ALayer {
public:
    ASLayer(SLayer prev);
    bool connect(int p_index,int s_index);
    bool connect(int p_index,vector<int> s_indexes);
    void initialize();
    void update();
    double get_output(int index);
private:
    SLayer prevLayer;
    bool check_correct(int index);
    vector<int> perceptrons;
    vector<vector<int>> saconnections;
    vector<double> output;
};

class SSLayer : public ALayer {
public:
    SSLayer(ALayer prev);
    bool connect(int p_index,int s_index);
    bool connect(int p_index,vector<int> s_indexes);
    void initialize();
    void update();
    double get_output(int index);
private:
    ALayer prevLayer;
    bool check_correct(int index);
    vector<int> perceptrons;
    vector<vector<int>> saconnections;
    vector<double> output;
};
