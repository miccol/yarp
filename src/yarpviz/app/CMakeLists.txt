# Copyright (C) 2014 Istituto Italiano di Tecnologia (IIT)
# Author: Ali Paikan <ali.paikan@iit.it>
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.8)
set(PROJECTNAME yarpviz-plugins)

file(GLOB plugins ${CMAKE_CURRENT_SOURCE_DIR}/plugins/*.lua)
yarp_install(FILES ${plugins} DESTINATION ${YARP_CONTEXTS_INSTALL_DIR}/yarpviz)
