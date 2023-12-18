// CkZipProgress.h: interface for the CkZipProgress class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CKZIPPROGRESS_H
#define _CKZIPPROGRESS_H

#include "CkBaseProgress.h"

/*

  To receive progress events (callbacks), create a C++ class that 
  inherits this one and provides one or more overriding implementations 
  for the events you wish to receive.

  */

 
// When creating an application class that inherits the CkZipProgress base class, use the CK_ZIPPROGRESS_API 
// definition to declare the overrides in the class header.  This has the effect that if for
// some unforeseen and unlikely reason the Chilkat event callback API changes, or if new
// callback methods are added in a future version, then you'll discover them at compile time
// after updating to the new Chilkat version.  
// For example:
/*
    class MyProgress : public CkZipProgress
    {
	public:
	    CK_ZIPPROGRESS_API

	...
    };
*/
#define CK_ZIPPROGRESS_API \
	void ToBeAdded(const char *filePath, __int64 fileSize, bool *skip);\
	void DirToBeAdded(const char *filePath, bool *skip);\
	void FileAdded(const char *filePath, __int64 fileSize, bool *abort);\
	void ToBeZipped(const char *filePath, __int64 fileSize, bool *skip);\
	void FileZipped(const char *filePath, __int64 fileSize, __int64 compressedSize, bool *abort);\
	void ToBeUnzipped(const char *filePath, __int64 compressedSize,__int64 fileSize, bool isDirectory,bool *skip);\
	void FileUnzipped(const char *filePath, __int64 compressedSize,__int64 fileSize, bool isDirectory,bool *abort);\
	void SkippedForUnzip(const char *filePath, __int64 compressedSize,__int64 fileSize,bool isDirectory);\
	void AddFilesBegin(void);\
	void AddFilesEnd(void);\
	void WriteZipBegin(void);\
	void WriteZipEnd(void);\
	void UnzipBegin(void);\
	void UnzipEnd(void);


#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif

class CK_VISIBLE_PUBLIC CkZipProgress : public CkBaseProgress 
{
    public:
	CkZipProgress() { }
	virtual ~CkZipProgress() { }

	virtual void ToBeAdded(const char *filePath, 
	    __int64 fileSize, 
	    bool *skip) 
	    { 
	    bool b = ToBeAdded(filePath,fileSize);
	    if (skip) *skip = b;
	    }
	virtual bool ToBeAdded(const char * /*filePath*/, 
	    __int64 /*fileSize*/) { return false; }

	virtual void DirToBeAdded(const char *filePath, 
	    bool *skip) 
	    { 
	    bool b = DirToBeAdded(filePath);
	    if (skip) *skip = b;
	    }
	virtual bool DirToBeAdded(const char * /*filePath*/) { return false; }

	virtual void FileAdded(const char *filePath, 
	    __int64 fileSize, 
	    bool *abort) 
	    { 
	    bool b = FileAdded(filePath,fileSize);
	    if (abort) *abort = b;
	    }
	virtual bool FileAdded(const char * /*filePath*/, 
	    __int64 /*fileSize*/) { return false; }

	virtual void ToBeZipped(const char *filePath, 
	    __int64 fileSize, 
	    bool *skip) 
	    { 
	    bool b = ToBeZipped(filePath,fileSize);
	    if (skip) *skip = b;
	    }
	virtual bool ToBeZipped(const char * /*filePath*/, 
	    __int64 /*fileSize*/) { return false; }

	virtual void FileZipped(const char *filePath, 
	    __int64 fileSize, 
	    __int64 compressedSize, 
	    bool *abort) 
	    { 
	    bool b = FileZipped(filePath,fileSize,compressedSize);
	    if (abort) *abort = b;
	    }
	virtual bool FileZipped(const char * /*filePath*/, 
	    __int64 /*fileSize*/, 
	    __int64 /*compressedSize*/) { return false; }

	virtual void ToBeUnzipped(const char *filePath, 
	    __int64 compressedSize,
	    __int64 fileSize, 
	    bool isDirectory,
	    bool *skip) 
	    { 
	    bool b = ToBeUnzipped(filePath,compressedSize,fileSize,isDirectory);
	    if (skip) *skip = b;
	    }
	virtual bool ToBeUnzipped(const char * /*filePath*/, 
	    __int64 /*compressedSize*/,
	    __int64 /*fileSize*/, 
	    bool /*isDirectory*/) { return false; }

	virtual void FileUnzipped(const char *filePath, 
	    __int64 compressedSize,
	    __int64 fileSize, 
	    bool isDirectory,
	    bool *abort) 
	    { 
	    bool b = FileUnzipped(filePath,compressedSize,fileSize,isDirectory);
	    if (abort) *abort = b;
	    }
	virtual bool FileUnzipped(const char * /*filePath*/, 
	    __int64 /*compressedSize*/,
	    __int64 /*fileSize*/, 
	    bool /*isDirectory*/) { return false; }

	virtual void SkippedForUnzip(const char * /*filePath*/, 
	    __int64 /*compressedSize*/,
	    __int64 /*fileSize*/,
	    bool /*isDirectory*/) { }

	virtual void AddFilesBegin(void) { }
	virtual void AddFilesEnd(void) { }
	virtual void WriteZipBegin(void) { }
	virtual void WriteZipEnd(void) { }
	virtual void UnzipBegin(void) { }
	virtual void UnzipEnd(void) { }
};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


#endif
