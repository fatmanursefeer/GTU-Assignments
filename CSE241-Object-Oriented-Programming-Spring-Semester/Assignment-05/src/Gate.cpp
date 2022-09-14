#include <iostream>
#include <string>
#include "Gate.h"

using namespace std;

/* Base class Gate functions */
Gate::Gate()
{
    setGateName("NoName");  /* if the gate name is not entered sets the like NoName */
}

Gate::Gate(string name)
{
    setGateName(name);  /* sets the gate name with name value */
}

void Gate::setGateName(string newName)
{
    gateName = newName;   /* sets gate name value */
}

string Gate::getGateName() const
{
    return gateName;  /* returns gate name */
}

int Gate::getGateData() const
{
    return gateData;   /* returns gate data */
}

void Gate::setGateData(int newData)
{
    gateData = newData;  /* sets the gate data */
}

int Gate::getFlag() const
{
    return flag;   /* returns the flag value */
}

void Gate::setFlag(int newFlag)
{
    flag = newFlag;  /* sets the flag value */
}

/* Derived class InputGate functions */
InputGate::InputGate() : Gate()
{}

InputGate::InputGate(string name) : Gate(name)
{}

int InputGate::evaluate()
{
    return getGateData();   /* returns the gate data because it is input gate */
}

/* Derived class OutputGate functions */
OutputGate::OutputGate() : Gate()
{}

OutputGate::OutputGate(string name) : Gate(name)
{}

int OutputGate::evaluate()
{
    return getGateData();  /* returns the gate data because it is output gate */
}

/* Derived class AndGate functions */
AndGate::AndGate() : Gate()
{}

AndGate::AndGate(string name) : Gate(name)
{}

int AndGate::evaluate()
{
    if(getFlag() == 1)  /* uses that data if previously calculated and returns that value */
        return getGateData();
    int temp1, temp2;
    temp1 = in1->evaluate();  /* calculates the first input */
    temp2 = in2->evaluate();  /* calculates the second input */
    if((temp1 == 0) && (temp2 == 0)){  /* if first and second input = 0 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(0);  /* sets the gate data value by 0 */
        return 0;  /* returs the gate data value */
    }
    else if((temp1 == 0) && (temp2 == 1)){   /* if first input=0 and second input=1 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(0);  /* sets the gate data value by 0 */
        return 0;  /* returs the gate data value */
    }
    else if((temp1 == 1) && (temp2 == 0)){   /* if first input=1 and second input=0 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(0);  /* sets the gate data value by 0 */
        return 0;  /* returs the gate data value */
    }
    else if((temp1 == 1) && (temp2 == 1)){  /* if first and second input = 1 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(1);  /* sets the gate data value by 1 */
        return 1;  /* returs the gate data value */
    }
    return 0;
}

AndGate::~AndGate()
{
    delete in1;
    delete in2;
}

/* Derived class OrGate functions */
OrGate::OrGate() : Gate()
{}

OrGate::OrGate(string name) : Gate(name)
{}

int OrGate::evaluate()
{
    if(getFlag() == 1)  /* uses that data if previously calculated and returns that value */
        return getGateData();
    int temp1, temp2;
    temp1 = in1->evaluate();  /* calculates the first input */
    temp2 = in2->evaluate();  /* calculates the second input */
    if((temp1 == 0) && (temp2 == 0)){  /* if first and second input = 0 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(0);  /* sets the gate data value by 0 */
        return 0;  /* returs the gate data value */
    }
    else if((temp1 == 0) && (temp2 == 1)){   /* if first input=0 and second input=1 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(1);  /* sets the gate data value by 1 */
        return 1;  /* returs the gate data value */
    }
    else if((temp1 == 1) && (temp2 == 0)){   /* if first input=1 and second input=0 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(1);  /* sets the gate data value by 1 */
        return 1;  /* returs the gate data value */
    }
    else if((temp1 == 1) && (temp2 == 1)){  /* if first and second input = 1 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(1);  /* sets the gate data value by 1 */
        return 1;  /* returs the gate data value */
    }
    return 0;
}

OrGate::~OrGate()
{
    delete in1;
    delete in2;
}

/* Derived class NotGate functions */
NotGate::NotGate() : Gate()
{}

NotGate::NotGate(string name) : Gate(name)
{}

int NotGate::evaluate()
{
    if(getFlag() == 1)  /* uses that data if previously calculated and returns that value */
        return getGateData();
    int temp = in1->evaluate();  /* calculates the input */
    if(temp == 0){   /* if input=0 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(1);  /* sets the gate data value by 1 */
        return 1;  /* returs the gate data value */
    }
    else if(temp == 1){   /* if input=1 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(0);  /* sets the gate data value by 0 */
        return 0;  /* returs the gate data value */
    }
    return 0;
}

NotGate::~NotGate()
{
    delete in1;
}

/* Derived class FlipFlopGate functions */
FlipFlopGate::FlipFlopGate() : Gate()
{}

FlipFlopGate::FlipFlopGate(string name) : Gate(name)
{}

int FlipFlopGate::evaluate()
{
    if(getFlag() == 1)  /* uses that data if previously calculated and returns that value */
        return getGateData();
    int temp = in1->evaluate();  /* calculates the input */
    if((temp == 0) && (former_out == 0)){  /* if input and former_out=0 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(0);  /* sets the gate data value by 0 */
        return 0;  /* returs the gate data value */
    }
    else if((temp == 0) && (former_out == 1)){   /* if input=0 and former_out=1 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(1);  /* sets the gate data value by 1 */
        return 1;  /* returs the gate data value */
    }
    else if((temp == 1) && (former_out == 0)){   /* if input=1 and former_out=0 this block works */
        former_out = 1;  /* sets the former_out=1 because the value is changing */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(1);  /* sets the gate data value by 1 */
        return 1;  /* returs the gate data value */
    }
    else if((temp == 1) && (former_out == 1)){  /* if input and former_out=1 this block works */
        former_out = 0;  /* sets the former_out=0 because the value is changing */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(0);  /* sets the gate data value by 0 */
        return 0;  /* returs the gate data value */
    }
    return 0;
}

FlipFlopGate::~FlipFlopGate()
{
    delete in1;
}

/* Derived class DecoderGate functions */
DecoderGate::DecoderGate() : Gate()
{}

DecoderGate::DecoderGate(string name) : Gate(name)
{}

int DecoderGate::evaluate()
{
    if(getFlag() == 1)  /* uses that data if previously calculated and returns that value */
        return getGateData();
    int temp1, temp2;
    temp1 = in1->evaluate();  /* calculates the first input */
    temp2 = in2->evaluate();  /* calculates the second input */
    if((temp1 == 0) && (temp2 == 0)){  /* if first and second input = 0 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(1);  /* sets the gate data value by 0001 (it is reverse of actual value because it is more comfortable when editing outputs)*/
        return 1;  /* returs the gate data value */
    }
    else if((temp1 == 0) && (temp2 == 1)){   /* if first input=0 and second input=1 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(10);  /* sets the gate data value by 0010 */
        return 10;  /* returs the gate data value */
    }
    else if((temp1 == 1) && (temp2 == 0)){   /* if first input=1 and second input=0 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(100);  /* sets the gate data value by 0100 */
        return 100;  /* returs the gate data value */
    }
    else if((temp1 == 1) && (temp2 == 1)){  /* if first and second input = 1 this block works */
        setFlag(1);  /* sets the flag by 1 so it does not have to do these calculations again */
        setGateData(1000);  /* sets the gate data value by 1000 */
        return 1000;  /* returs the gate data value */
    }
    return 0;
}

DecoderGate::~DecoderGate()
{
    delete in1;
    delete in2;
}
