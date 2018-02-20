//
// Created by Moad, Karl on 2/19/18.
//

#ifndef DNALGORITHMS_FASTQRECORD_H
#define DNALGORITHMS_FASTQRECORD_H

#include <string>

namespace DNA {
    class FASTQRecord {
    private:
        std::string m_Header;
        std::string m_Read;
        std::string m_Info;
        std::string m_Quality;

    public:
        FASTQRecord();
        std::string getHeader() const;
        std::string getRead() const;
        std::string getInfo() const;
        std::string getQuality() const;

        class Builder{
        private:
            FASTQRecord *instance;
        public:
            Builder();
            Builder* setHeader(const std::string &header);
            Builder* setRead(const std::string &data);
            Builder* setInfo(const std::string &info);
            Builder* setQuality(const std::string &quality);
            FASTQRecord *build();
        };
    };
};


#endif //DNALGORITHMS_FASTQRECORD_H
