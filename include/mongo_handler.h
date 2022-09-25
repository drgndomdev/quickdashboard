#pragma once

#include <cstdint>
#include <string>

#include "bsoncxx/builder/stream/document.hpp"
#include "bsoncxx/json.hpp"
#include "bsoncxx/oid.hpp"
#include "character_size.h"
#include "mongocxx/client.hpp"
#include "mongocxx/database.hpp"
#include "mongocxx/uri.hpp"

namespace cppMongoDB {
    class MongoDbHandler {
        bool AddRecord(const std::string &record) {
            return true;
        }
        bool UpdateRecord(const std::string &record) {
            return true;
        }
        bool RemoveRecord(const std::string &record) {
            return true;
        }
    };
}