//
// indexer factory class definition
// version: 1.0 
// Copyright (C) 2018 James Wei (weijianlhp@163.com). All rights reserved
//

#include "internal/singleton.h"
#include "simple_indexer.h"
#include "interval_indexer.h"
#include "geo_indexer.h"
#include "indexer_factory.h"

#define INDEX_TYPE_SIMPLE       "simple"
#define INDEX_TYPE_INTERVAL     "interval"
#define INDEX_TYPE_GEO          "geo"

#define KEY_TYPE_INT32          "int32"
#define KEY_TYPE_DOUBLE         "double"
#define KEY_TYPE_STRING         "string"

namespace cloris {

IndexerFactory* IndexerFactory::instance() noexcept {
    return Singleton<IndexerFactory>::instance();
}

Indexer* IndexerFactory::CreateIndexer(const std::string& name, const std::string& key_type, const std::string& index_type) {
    if (index_type == INDEX_TYPE_SIMPLE) {
        if (key_type == KEY_TYPE_INT32) {
            return new SimpleIndexer(name, ValueType::INT32);
        } else if (key_type == KEY_TYPE_STRING) {
            return new SimpleIndexer(name, ValueType::STRING);
        } else {
            return NULL;
        }
    } else if (index_type == INDEX_TYPE_INTERVAL) {
        if (key_type == KEY_TYPE_INT32) {
            return new IntervalIndexer<int32_t>(name);
        } else if (key_type == KEY_TYPE_DOUBLE) {
            return new IntervalIndexer<double>(name);
        } else if (key_type == KEY_TYPE_STRING) {
            return new IntervalIndexer<std::string>(name);
        } else {
            return NULL;
        }
    } else if (index_type == INDEX_TYPE_GEO) {
        return new GeoIndexer(name);
    } else {
        return NULL;
    }
}

} // namespace cloris
