#ifndef SERIALISER_HPP
#define SERIALISER_HPP

#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h> 

using namespace std;

template <typename T> class serialiser{
    T data;
    public:
        void Serialise(T data, string& outName, bool update);
        T unSerialise(const char *inName);
};

template <typename T> void serialiser<T>::Serialise(T data, string& outName, bool update = true){
    struct stat stFileInfo; 
    outName.append(".state");

    int intStat = stat(outName.c_str(), &stFileInfo);
    if(intStat == 0 && update == true){
        if(remove(outName.c_str()) != 0){
            printf("[serialiser.hpp] deletion of %s failed", outName.c_str());
        }
        ofstream ofs(outName.c_str(), ios::binary);
        ofs.write((char *)&data, sizeof(data));
    } else if(intStat != 0){
        ofstream ofs(outName.c_str(), ios::binary);
        ofs.write((char *)&data, sizeof(data));
    }
}
template <typename T>T serialiser<T>::unSerialise(const char *inName){
    T out;
    ifstream ifs(inName, ios::binary);
    ifs.read((char *)&out, sizeof(out));
    return out;
}

#endif

