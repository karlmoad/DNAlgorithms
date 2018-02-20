//
// Created by Moad, Karl on 2/19/18.
//

#ifndef DNALGORITHMS_DNAUTILITY_H
#define DNALGORITHMS_DNAUTILITY_H

#include <string>
#include <algorithm>

namespace DNA {

    class DNAUtility {
    private:

        //Provides the complement to the base provided
        static char BaseComplement(char base){
            switch(base){
                case 'A': return 'T';
                case 'T': return 'A';
                case 'C': return 'G';
                case 'G': return 'C';
                default:  return 'N';
            }
        }

    public:

        //Finds the longest common starting substring to which both inputs share
        static std::string LongestCommonPrefix(std::string &s1, std::string &s2) {
            long i = 0L;

            while (i < s1.size() && i < s2.size() && s1.at(i) == s2.at(i)) {
                i++;
            }

            if (i > 0) {
                return s1.substr(0, i);
            } else {
                return std::string("");
            }
        }

        //Informs if the supplied input match or not
        static bool Match(std::string &s1, std::string &s2) {
            return s1.compare(s2) == 0;
        }

        //returns a string complement of the input string
        static std::string Complement(std::string &s1){
            std::string out;

            for(long i = 0; i < s1.size(); i++){
                out += BaseComplement(s1.at(i));
            }

            return out;
        }

        //returns a reversed string complement of the input string
        static std::string ReverseComplement(std::string &s1){
            std::string complement = Complement(s1);
            std::reverse(complement.begin(), complement.end());

            return complement;
        }

        //return the Phred33 ASCII encoded value for the corresponding Q value
        static char QualityToPhred33(int Q){
            return (char)(Q + 33);
        }

        //Return the quality value of the provided Phred33 value
        static int Phred33toQuality(char P){
            return (int)P - 33;
        }
    };
};


#endif //DNALGORITHMS_DNAUTILITY_H
