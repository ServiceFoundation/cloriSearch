//
// indexer main class definition
// version: 1.0 
// Copyright (C) 2018 James Wei (weijianlhp@163.com). All rights reserved
//

#ifndef CLORIS_CONJUNCTION_SCORER_H_
#define CLORIS_CONJUNCTION_SCORER_H_

#include <unistd.h>
#include <vector>
#include <list>
#include "posting_list.h"

namespace cloris {

// refer to lucene implementation
// Conjunction Algorithm refered from << indexing boolean expression >>
// 每个倒排链起名叫posting list
class ConjunctionScorer {
public:
    ConjunctionScorer() {}
    ~ConjunctionScorer(); 
    std::vector<int> GetMatchedDocid(size_t k);
    void AddPostingList(std::list<DocidNode>* doc_list, const ReclaimHandler& handler);
private:
    std::vector<PostingList> plists_;
};

} // namespace cloris

#endif // CLORIS_CONJUNCTION_SCORER_H_
