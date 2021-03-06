/* 
 * File:   EDFHeader.h
 *
 * Created on November 4, 2010, 3:53 PM
 */

#ifndef _EDFHEADER_H
#define	_EDFHEADER_H

#include <string>
#include "EDFPatient.h"
#include "EDFTime.h"
#include "EDFDate.h"

using std::string;

class EDFHeader {
public:
    enum FILE_TYPE { EDF, EDFPLUS };
    enum CONTINUITY { CONTINUOUS, DISCONTINUOUS };

    EDFHeader();
    EDFHeader(const EDFHeader&);
    virtual ~EDFHeader();
    EDFHeader& operator=(const EDFHeader&);

    void setFiletype(FILE_TYPE);
    void setContinuity(CONTINUITY);
    void setSignalCount(int);
    void setFileDuration(int);
    void setDate(EDFDate);
    void setStartTime(EDFTime);
    void setPatient(EDFPatient);
    void setRecording(string);
    void setRecordingAdditional(string);
    void setAdminCode(string);
    void setTechnician(string);
    void setEquipment(string);
    void setDataRecordDuration(double);
    void setDataRecordCount(int);
    void setDataRecordSize(int);
    void setAnnotationIndex(int);

    void setLabel(int, string);
    void setPhysicalMax(int, double);
    void setPhysicalMin(int, double);
    void setDigitalMax(int, int);
    void setDigitalMin(int, int);
    void setSignalSampleCount(int, int);
    void setPhysicalDimension(int, string);
    void setPrefilter(int, string);
    void setTransducer(int, string);
    void setReserved(int, string);
    void setBufferOffset(int, int);

    FILE_TYPE  getFiletype();
    CONTINUITY getContinuity();
    int        getSignalCount();
    int        getFileDuration();
    EDFDate    getDate();
    EDFTime    getStartTime();
    EDFPatient getPatient();
    string     getRecording();
    string     getRecordingAdditional();
    string     getAdminCode();
    string     getTechnician();
    string     getEquipment();
    double     getDataRecordDuration();
    int        getDataRecordCount();
    int        getDataRecordSize();
    int        getAnnotationIndex();

    string getLabel(int);
    double getPhysicalMax(int);
    double getPhysicalMin(int);
    int    getDigitalMax(int);
    int    getDigitalMin(int);
    int    getSignalSampleCount(int);
    string getPhysicalDimension(int);
    string getPrefilter(int);
    string getTransducer(int);
    string getReserved(int);
    int    getBufferOffset(int);

    bool   hasAnnotations();
    double getTotalRecordingTime();

private:
    FILE_TYPE  filetype;
    CONTINUITY continuity;
    int        signalCount;
    int        fileDuration;
    EDFDate    date;
    EDFTime    startTime;
    EDFPatient patient;
    string     recording, recordingAdditional, adminCode, technician;
    string     equipment;
    double     dataRecordDuration;
    int        dataRecordCount;
    int        dataRecordSize;
    int        annotationIndex;
    string*    label;
    double*    physicalMax;
    double*    physicalMin;
    int*       digitalMax;
    int*       digitalMin;
    int*       signalSampleCount;
    string*    physicalDimension;
    string*    prefilter;
    string*    transducer;
    string*    reserved;
    int*       bufferOffset;

    bool       validSignal(int);
};

#endif	/* _EDFHeader_H */

