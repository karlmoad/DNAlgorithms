//
// Created by Moad, Karl on 2/19/18.
//

#include "FASTQFile.h"

long DNA::FASTQFile::size() const {
    return this->records.size();
}

const std::shared_ptr<DNA::FASTQRecord> &DNA::FASTQFile::at(long i) const {
    return this->records.at(i);
}

DNA::FASTQFile *DNA::FASTQFile::readFile(std::string &path) {

    FASTQFile *out = new FASTQFile();

    std::ifstream file(path); // pass file name as argment
    std::string linebuffer;

    int offset = 0;
    DNA::FASTQRecord::Builder *builder = nullptr;
    while (file && getline(file, linebuffer)){
        switch(offset % 4){
            case 1:
                builder->setData(linebuffer);
                break;
            case 2:
                builder->setInfo(linebuffer);
                break;
            case 3:
                builder->setQuality(linebuffer);
                break;
            default:
                if(builder != nullptr){
                    out->records.push_back(std::shared_ptr<DNA::FASTQRecord>(builder->build()));
                    delete builder;
                }
                builder = new DNA::FASTQRecord::Builder();
                builder->setHeader(linebuffer);
                break;
        }
        offset++;
    }

    delete builder;
    file.close();

    return out;
}

DNA::FASTQFile::FASTQFile()=default;
