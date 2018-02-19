//
// Created by Moad, Karl on 2/19/18.
//

#ifndef DNALGORITHMS_FASTQFILE_H
#define DNALGORITHMS_FASTQFILE_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include "FASTQRecord.h"

namespace DNA {
    class FASTQFile {
    private:
        std::vector<std::shared_ptr<DNA::FASTQRecord>> records;

    public:
        FASTQFile();
        long size() const;
        const std::shared_ptr<DNA::FASTQRecord> &at(long i) const;

        static FASTQFile *readFile(std::string &path);
    };
};


#endif //DNALGORITHMS_FASTQFILE_H
