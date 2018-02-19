//
// Created by Moad, Karl on 2/19/18.
//

#include "FASTQRecord.h"

DNA::FASTQRecord::FASTQRecord() {}

std::string DNA::FASTQRecord::getHeader() const {
    return this->m_Header;
}

std::string DNA::FASTQRecord::getData() const {
    return this->m_Data;
}

std::string DNA::FASTQRecord::getInfo() const {
    return this->m_Info;
}

std::string DNA::FASTQRecord::getQuality() const {
    return this->m_Quality;
}

DNA::FASTQRecord::Builder::Builder() {
    this->instance = new DNA::FASTQRecord();
}

DNA::FASTQRecord::Builder *DNA::FASTQRecord::Builder::setHeader(const std::string &header) {
    this->instance->m_Header = header;
    return this;
}

DNA::FASTQRecord::Builder *DNA::FASTQRecord::Builder::setData(const std::string &data) {
    this->instance->m_Data = data;
    return this;
}

DNA::FASTQRecord::Builder *DNA::FASTQRecord::Builder::setInfo(const std::string &info) {
    this->instance->m_Info = info;
    return this;
}

DNA::FASTQRecord::Builder *DNA::FASTQRecord::Builder::setQuality(const std::string &quality) {
    this->instance->m_Quality = quality;
    return this;
}

DNA::FASTQRecord *DNA::FASTQRecord::Builder::build() {
    return this->instance;
}
