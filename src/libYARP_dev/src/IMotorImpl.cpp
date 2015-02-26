// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2015 iCub Facility, Istituto Italiano di Tecnologia
 * Authors: Marco Randazzo <marco.randazzo@iit.it>
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#include "yarp/dev/ControlBoardInterfacesImpl.h"
#include <yarp/dev/ControlBoardHelper.h>

#include <stdio.h>
using namespace yarp::dev;

////////////////////////
// Encoder Interface Timed Implementation
ImplementMotor::ImplementMotor(IMotorRaw *y)
{
    imotor=y;
    helper = 0;
    temp=0;
    temp2=0;
}

ImplementMotor::~ImplementMotor()
{
    uninitialize();
}

bool ImplementMotor:: initialize (int size, const int *amap)
{
    if (helper!=0)
        return false;
    
    helper=(void *)(new ControlBoardHelper(size, amap, 0, 0, 0));
    yAssert (helper != 0);
    temp=new double [size];
    yAssert (temp != 0);
    temp2=new double [size];
    yAssert (temp2 != 0);
    return true;
}

/**
* Clean up internal data and memory.
* @return true if uninitialization is executed, false otherwise.
*/
bool ImplementMotor::uninitialize ()
{
    if (helper!=0)
    {
        delete castToMapper(helper);
        helper=0;
    }
    
    checkAndDestroy(temp);
    checkAndDestroy(temp2);

    return true;
}

bool ImplementMotor::getNumberOfMotors(int *num)
{
    (*num)=castToMapper(helper)->axes();
    return true;
}

bool ImplementMotor::getTemperature(int m, double* temp)
{
    bool ret;
    int k=castToMapper(helper)->toHw(m);

    ret=imotor->getTemperatureRaw(k, temp);

    return ret;
}
