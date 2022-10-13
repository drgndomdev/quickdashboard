#include <iostream>

#include "mongocxx/instance.hpp"

#include "mongo_handler.h"

int main() {
    std::cout << "Hello World!" << std::endl;
    mongocxx::instance mongoInstance;
    cppMongod::MongoDbHandler mongoHandler;
    mongoHandler.AddRecord("Test1", 2);

    return 0;
}