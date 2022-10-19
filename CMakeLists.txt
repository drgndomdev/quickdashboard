cmake_minimum_required(VERSION 3.14)

project(QuickDashBoard VERSION 0.0.1 DESCRIPTION "A quick dashboard to assorted metrix" LANGUAGES CXX)

find_package(OpenSSL REQUIRED) # find module
find_package(Boost REQUIRED)
find_package(mongocxx REQUIRED)
find_package(Python REQUIRED Development)

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