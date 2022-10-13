#pragma once

#include <cstdint>
#include <string>
#include <ctime>


#include "bsoncxx/json.hpp"
#include <bsoncxx/builder/stream/helpers.hpp>
#include <mongocxx/collection.hpp>
#include "bsoncxx/oid.hpp"
#include "bsoncxx/builder/stream/document.hpp"
#include "mongocxx/client.hpp"
#include "mongocxx/database.hpp"
#include "mongocxx/uri.hpp"


namespace cppMongod {
    constexpr char kMongodUri[] = "mongodb://127.0.0.1:27017";
    constexpr char kDatabase[] = "quickdashboard";
    constexpr char kCollection[] = "StockPrices";
    class MongoDbHandler {
        public:
        MongoDbHandler()
            : uri(mongocxx::uri(kMongodUri)),
            client(mongocxx::client(uri)),
            db(client[kDatabase]) {}

            // MongoDbHandler() {
            //     uri(mongocxx::uri(kMongodUri));
            //     client(mongocxx::client(uri));
            //     db(client[kDatabase]);
            // }

            bool AddStock(const std::string &name, const std::string &fullName, // early idea, need to supply entire timeline at once, JSON format
                        const double &openPrice, const double &closePrice,
                        const double &lowPrice, const double &highPrice,
                        const long &datetime) {
                            return true;
                        }

            bool RemoveStock(const std::string &name) { // Find by name and remove
            return true;
            }

            bool UpdateStock(const std::string &name) { // idea #1, remove existing record and add a new one
                return true;                            // idea #2. find timeline to be changed and replace
            }

            bool UpdateOneTimeline(const std::string &name,
                                const double &openPrice, const double &closePrice,
                                const double &lowPrice, const double &highPrice,
                                const long &timeline
                                ) {
                                    return true;
                                }

            bool UpdateMultipleTimelines(const std::string &name,
                                const double &openPrice, const double &closePrice,
                                const double &lowPrice, const double &highPrice,
                                const long &timeline) {
                                    return true;
                                }

            bool AddRecord(const std::string &record, const int &number) {
                mongocxx::collection collection = db[kCollection];
                auto builder = bsoncxx::builder::stream::document{};

                bsoncxx::document::value add_document = 
                    builder << "Record" << record
                            << "NumberValue" << number << bsoncxx::builder::stream::finalize;

                collection.insert_one(add_document.view());
                return true;
            }

            bool UpdateRecord(const std::string &id) {
                mongocxx::collection collection = db[kCollection];
                auto builder = bsoncxx::builder::stream::document{};

                bsoncxx::oid doc_id(id);

                bsoncxx::document::value update_query = 
                    builder << "_id" << doc_id << bsoncxx::builder::stream::finalize;

                // TODO: update found query

                // TODO: Commit changes
                // collection.update_one(update_query.view()); 

                return true;
            }

            bool RemoveRecord(const std::string &record) {
                return true;
            }
        private:
            mongocxx::uri uri;
            mongocxx::client client;
            mongocxx::database db;
    };
}