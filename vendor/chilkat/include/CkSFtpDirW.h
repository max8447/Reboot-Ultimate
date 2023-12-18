// CkSFtpDirW.h: interface for the CkSFtpDirW class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#ifndef _CkSFtpDirW_H
#define _CkSFtpDirW_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkWideCharBase.h"

class CkSFtpFileW;
class CkTaskW;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkSFtpDirW
class CK_VISIBLE_PUBLIC CkSFtpDirW  : public CkWideCharBase
{
	

	private:
	
	// Don't allow assignment or copying these objects.
	CkSFtpDirW(const CkSFtpDirW &);
	CkSFtpDirW &operator=(const CkSFtpDirW &);

    public:
	CkSFtpDirW(void);
	virtual ~CkSFtpDirW(void);

	

	static CkSFtpDirW *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The number of entries in this directory listing.
	int get_NumFilesAndDirs(void);

	// The original path used to fetch this directory listing. This is the string that
	// was originally passed to the OpenDir method when the directory was read.
	void get_OriginalPath(CkString &str);
	// The original path used to fetch this directory listing. This is the string that
	// was originally passed to the OpenDir method when the directory was read.
	const wchar_t *originalPath(void);



	// ----------------------
	// Methods
	// ----------------------
	// Returns the Nth filename in the directory (indexing begins at 0).
	bool GetFilename(int index, CkString &outStr);
	// Returns the Nth filename in the directory (indexing begins at 0).
	const wchar_t *getFilename(int index);
	// Returns the Nth filename in the directory (indexing begins at 0).
	const wchar_t *filename(int index);

	// Returns the Nth entry in the directory. Indexing begins at 0.
	// The caller is responsible for deleting the object returned by this method.
	CkSFtpFileW *GetFileObject(int index);

	// Loads the SFTP directory object from a completed asynchronous task.
	bool LoadTaskResult(CkTaskW &task);

	// Sorts the files and sub-directories in ascending or descending order based on
	// the field. Possible values for field are "filename", "filenameNoCase",
	// "lastModifiedTime", "lastAccessTime", "lastCreateTime", or "size". (For
	// case-insensitive filename sorting, use "filenameNoCase".)
	void Sort(const wchar_t *field, bool ascending);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
