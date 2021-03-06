/**
 * @file TcpAcceptor.h
 * @brief
 *
 * This file is created at Almende B.V. It is open-source software and part of the Common
 * Hybrid Agent Platform (CHAP). A toolbox with a lot of open-source tools, ranging from
 * thread pools and TCP/IP components to control architectures and learning algorithms.
 * This software is published under the GNU Lesser General Public license (LGPL).
 *
 * It is not possible to add usage restrictions to an open-source license. Nevertheless,
 * we personally strongly object against this software used by the military, in the
 * bio-industry, for animal experimentation, or anything that violates the Universal
 * Declaration of Human Rights.
 *
 * Copyright © 2010 Anne van Rossum <anne@almende.com>
 *
 * @author  Anne C. van Rossum
 * @date    Feb 15, 2011
 * @project Replicator FP7
 * @company Almende B.V.
 * @case
 */


#ifndef YARP_OS_IMPL_TCPACCEPTOR_H
#define YARP_OS_IMPL_TCPACCEPTOR_H


#include <yarp/os/TwoWayStream.h>
#include <yarp/os/impl/Logger.h>

#include <yarp/os/impl/TcpStream.h>

//#include <sys/time.h>
//#include <iostream>
//
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>
//#include <unistd.h>

// General files

namespace yarp {
    namespace os {
        namespace impl {
            class TcpAcceptor;
        }
    }
}

/* **************************************************************************************
 * Interface of TcpAcceptor
 * **************************************************************************************/

class YARP_OS_impl_API yarp::os::impl::TcpAcceptor
{
public:

    TcpAcceptor();

    virtual ~TcpAcceptor() {};

    int open(const yarp::os::Contact& address);

    int connect(const yarp::os::Contact& address);

    int close();

    int accept(TcpStream &new_stream);

    int get_port_number() {
      return port_number;
    }

//    const Address& getLocalAddress();

//    const Address& getRemoteAddress();
protected:
    int shared_open(const yarp::os::Contact& address);

    int get_handle() { return ad; }

    void set_handle(int h) { ad = h; }
private:
    // acceptor descriptor
    int ad;
    int port_number;
};

#endif // YARP_OS_IMPL_TCPACCEPTOR_H
