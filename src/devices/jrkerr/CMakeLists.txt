# Copyright: (C) 2009 RobotCub Consortium
# Author: Paul Fitzpatrick
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

yarp_prepare_plugin(jrkerr
                    CATEGORY device
                    TYPE yarp::dev::JrkerrMotionControl
                    INCLUDE JrkerrMotionControl.h
                    EXTRA_CONFIG WRAPPER=controlboard
                    DEPENDS "CREATE_DEVICE_LIBRARY_MODULES;WIN32")

if(NOT SKIP_jrkerr)
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
  yarp_add_plugin(yarp_jrkerr JrkerrMotionControl.cpp
                              nmccom.cpp
                              picservo.cpp
                              sio_util.cpp
                              JrkerrMotionControl.h
                              nmccom.h
                              picservo.h
                              sio_util.h)
  target_link_libraries(yarp_jrkerr YARP::YARP_OS
                                    YARP::YARP_dev)
  yarp_install(TARGETS yarp_jrkerr
               EXPORT YARP
               COMPONENT runtime
               LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
               ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR})
  yarp_install(FILES jrkerr.ini
               COMPONENT runtime
               DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})

  set_property(TARGET yarp_jrkerr PROPERTY FOLDER "Unsupported")
endif()
