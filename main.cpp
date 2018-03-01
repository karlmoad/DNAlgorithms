#include <iostream>
#include "DNAUtility.h"
#include "FASTQFile.h"
#include "FASTQRecord.h"
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <memory>

int main(int argc, char* argv[]){

    std::string s1("ACCATGGTTA");
    std::string s2("ACCAGTGTAAA");
    std::string s3("ACCTTGG");
    std::string s4 = s3;


    std::cout << "Longest Common Prefix  S1 & S2:" << DNA::DNAUtility::LongestCommonPrefix(s1,s2) << std::endl;

    std::cout << "Match S1 & S2: " << (DNA::DNAUtility::Match(s1,s2) ? "True" : "False") << std::endl;

    std::cout << "Match S3 & S4: " << (DNA::DNAUtility::Match(s3,s4) ? "True" : "False") << std::endl;


    std::cout << "Complement : " << s3 << " : " << DNA::DNAUtility::Complement(s3) << std::endl;
    std::cout << "RComplement: " << s3 << " : " << DNA::DNAUtility::ReverseComplement(s3) << std::endl;


    std::string fileBuffer;
    std::string f1("../data/lambda_virus.fa");
    std::string f2("../data/SRR835775_1.first1000.fastq");

    std::ifstream file(f1); // pass file name as argment
    std::string linebuffer;

    while (file && getline(file, linebuffer)){
        if (linebuffer.length() == 0)continue;
        if(linebuffer.at(0) == '>') continue;  //skip the meta header

        fileBuffer += linebuffer;
    }

    file.close();

    std::cout <<  "Lambda virus DNA: " << fileBuffer << std::endl;
    std::cout << "Genome size: " << fileBuffer.size() << std::endl;

    std::map<char, long> base_freq = {{'A', 0L}, {'T', 0L}, {'C',0L}, {'G',0L}};

    for(long i = 0; i < fileBuffer.size(); i++){
        base_freq[fileBuffer.at(i)]++;
    }

    std::cout << "Base Frequencies:" << std::endl;
    std::cout << "A : " << base_freq['A'] << std::endl;
    std::cout << "T : " << base_freq['T'] << std::endl;
    std::cout << "C : " << base_freq['C'] << std::endl;
    std::cout << "G : " << base_freq['G'] << std::endl;

    std::cout << "Frequency check :" << ((base_freq['A'] + base_freq['T'] + base_freq['C'] + base_freq['G']) == fileBuffer.size() ? "Positive" : "Negative") << std::endl;

    std::shared_ptr<DNA::FASTQFile> FQFile(DNA::FASTQFile::readFile(f2));

    std::cout << "FASTQ File Number OF Records :" << FQFile->size() << std::endl;


    for(int i = 0; i < 10; i++){
        std::cout << "Sample : \n"
                  << "Header: " <<  FQFile->at(i)->getHeader() << "\n"
                  << "Data: " << FQFile->at(i)->getRead() << "\n"
                  << "Info:" << FQFile->at(i)->getInfo() << "\n"
                  << "Quality: " << FQFile->at(i)->getQuality() << std::endl;
    }
}



