/*
 * Copyright (C) 2006 RobotCub Consortium
 * Authors: Paul Fitzpatrick
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */


#ifndef YARP_DEV_DEVICEPIPE_H
#define YARP_DEV_DEVICEPIPE_H

#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/ServiceInterfaces.h>


namespace yarp{
    namespace dev {
        class DevicePipe;
    }
}

/**
 * @ingroup dev_impl_wrapper
 *
 * Tries to connect the output of one device to the input of another.
 *
 */
class YARP_dev_API yarp::dev::DevicePipe : public DeviceDriver,
                                           public IService {

public:
    virtual bool open(yarp::os::Searchable& config) override;

    virtual bool close() override;

    virtual bool startService() override {
        // please call updateService
        return false;
    }

    virtual bool stopService() override {
        return close();
    }

    virtual bool updateService() override;

protected:
    PolyDriver source, sink;

    bool open(const char *key, PolyDriver& poly,
              yarp::os::Searchable& config, const char *comment);
};


#endif // YARP_DEV_DEVICEPIPE_H
