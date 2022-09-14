#ifndef GATE_H
#define GATE_H

#include <iostream>
#include <string>

using namespace std;

/* Base class : Gate */
class Gate
{
public:
    Gate();   /* no parameter constructor */
    Gate(string name);  /* constructor which takes string parameter */
    virtual int evaluate() = 0;  /* pure virtual evoluation function evaluate the circuit */
    void setGateName(string newName);  /* sets the gate name */
    string getGateName() const;  /* returns the gate name */
    int getGateData() const;  /* returns the gate data */
    void setGateData(int newData);   /* sets the gate data */
    int getFlag() const;  /* returns the flag value */
    void setFlag(int newFlag);  /* sets the flag value */
private:
    string gateName;  /* values */
    int gateData, flag = 0;
};

/* Derived class : InputGate */
class InputGate : public Gate
{
public:
    InputGate();   /* no parameter constructor */
    InputGate(string name);  /* constructor which takes the string value */
    virtual int evaluate();   /* evaluates the gate value */
};

/* Derived class : OutputGate */
class OutputGate : public Gate
{
public:
    OutputGate();  /* no parameter constructor */
    OutputGate(string name);  /* constructor which takes string value */
    virtual int evaluate();  /* evaluates the gate value */
};

/* Derived class : AndGate */
class AndGate : public Gate
{
public:
    AndGate();  /* no parameter constructor */
    AndGate(string name);  /* constructor which takes string value */
    virtual int evaluate();  /* evaluates the gate value */
    ~AndGate(); /* destructor */
    Gate* in1;  /* for first input */
    Gate* in2;  /* for second input */
};

/* Derived class : OrGate */
class OrGate : public Gate
{
public:
    OrGate();  /* no parameter constructor */
    OrGate(string name);  /* constructor which take string value */
    virtual int evaluate();  /* evaluates the gate value */
    ~OrGate(); /* destructor */
    Gate* in1;  /* for first input */
    Gate* in2;  /* for second input */
};

/* Derived class : NotGate */
class NotGate : public Gate
{
public:
    NotGate();  /* no parameter constructor */
    NotGate(string name);    /* constructor which takes the string value */
    virtual int evaluate();    /* evaluates the gate value */
    ~NotGate(); /* destructor */
    Gate* in1;    /* for the input */
};

/* Derived class : FlipFlopGate */
class FlipFlopGate : public Gate
{
public:
    FlipFlopGate();  /* no parameter constructor */
    FlipFlopGate(string name);    /* constructor which takes the string value */
    virtual int evaluate();    /* evaluates the gate value */
    ~FlipFlopGate(); /* destructor */
    Gate* in1;  /* for the input */
private:
    int former_out = 0;  /* for the former out */
};

/* Derived class : DecoderGate */
class DecoderGate : public Gate
{
public:
    DecoderGate();  /* no parameter constructor */
    DecoderGate(string name);   /* constructor which takes the string value */
    virtual int evaluate();    /* evaluates the gate value */
    ~DecoderGate(); /* destructor */
    Gate* in1;  /* for first input */
    Gate* in2;  /* for second input */
};

#endif