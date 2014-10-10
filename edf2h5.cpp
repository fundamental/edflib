/** 
 @file edf2h5.cpp
 @brief Demo program for extracting info from existing
 edf files and placing it in the more common HDF5 Format

 @author Mark McCurry
 @date 10/10/2014
*/
#include <iostream>
#include <vector>
#include <H5Cpp.h>
#include "EDFFile.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

struct sigData
{
    string name;
    vector<int16_t> data;
};


void usage(void)
{
    cout << "usage: edf2hdf5 INPUT.edf OUTPUT.hdf5" << endl;
    cout << "This tool dumps all signal channels to the hdf5 file" << endl;
}

int main(int argc, char **argv)
{
    //Check Args
    if(argc != 3)
    {
        usage();
        return 1;
    }

    string edfFile = argv[1];
    string h5File  = argv[2];
    
    //Gather All
    EDFFile file(edfFile.c_str());

    EDFHeader* header = file.getHeader();
    
    int Annotation = header->getAnnotationIndex();
    int N = header->getSignalCount();

    std::vector<sigData> data;

    for(int sig = 0; sig < N && sig != Annotation; sig++) {
        sigData d;
        d.name = header->getLabel(sig);
        size_t samples =  header->getSignalSampleCount(sig);
        EDFSignalData *sigData = file.getSignalData(sig, 0, samples);
        d.data = sigData->getData();
        data.push_back(d);
    }

    //Dump Into A HDF5 File
    try
    {
        H5::H5File hFile(argv[2], H5F_ACC_TRUNC);
        for(unsigned i=0; i<data.size(); ++i) {
            hsize_t dims[1];
            dims[0] = data[i].data.size();
            H5::DataSpace dataspace(1,dims);
            H5::IntType datatype(H5::PredType::NATIVE_INT16);
            H5::DataSet dataset = 
                hFile.createDataSet(data[i].name, datatype, dataspace);
            dataset.write(data[i].data.data(), H5::PredType::NATIVE_INT16);
        }
    } catch(H5::Exception e)
    {
        return 1;
    }
    return 0;
}
