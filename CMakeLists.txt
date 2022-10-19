cmake_minimum_required(VERSION 3.14)

project(QuickDashBoard VERSION 0.0.1 DESCRIPTION "A quick dashboard to assorted metrix" LANGUAGES CXX)

find_package(OpenSSL REQUIRED) # find module
find_package(Boost REQUIRED)
find_package(mongocxx REQUIRED)
find_package(Python REQUIRED Development)

include(GNUInstallDirs) # Required for ${CMAKE_INSTALL_LIBDIR}
set(CMAKE_SKIP_BUILD_RPATH FALSE) # use, i.e. don't skip the full RPATH for the build tree
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) # when building, don't use the install RPATH already  (but later on when installing)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE) # add the automatically determined parts of the RPATH which point to directories outside the build tree to the install RPATH (i.e. the location of libboost.so)

add_executable(QuickDashBoard)
target_sources(QuickDashBoard # 
    PRIVATE
        include/mongo_handler.h
        src/main.cpp
)

target_link_libraries(QuickDashBoard 
    PRIVATE
        Boost::headers
        mongo::mongocxx_shared
        mongo::bsoncxx_shared
        OpenSSL::Crypto
        OpenSSL::SSL
        Python::Python
)

set_target_properties(QuickDashBoard PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)