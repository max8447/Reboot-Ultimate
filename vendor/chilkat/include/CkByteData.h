// CkByteData.h: interface for the CkByteData class.
//
//////////////////////////////////////////////////////////////////////

// This header is NOT generated.

#ifndef _CKBYTEDATA_H
#define _CKBYTEDATA_H

#include "chilkatDefs.h"
#include "CkObject.h"
#include "CkString.h"


// The CkByteData class is a convenient class for holding a block of
// binary data, or non-null terminated text data.

#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkByteData
class CK_VISIBLE_PUBLIC CkByteData : public CkObject
{
    public:
	CkByteData();
	~CkByteData();

	static CkByteData *createNew(void);

	CkByteData(const CkByteData &);
	CkByteData &operator=(const CkByteData &);

	// BEGIN PUBLIC INTERFACE
	bool get_Utf8(void) const;
	void put_Utf8(bool b);

	// If set to true, then whenever the internal data is deallocated, the memory is first overwritten with 0 bytes.
	bool get_SecureClear(void) const;
	void put_SecureClear(bool b);

	// Take the data from the passed-in object (does not copy, but simply takes the internal data pointer)
	// After the method call, the srcData will be empty, and this CkByteData will contain
	// exactly what srcData contained.  
	void takeByteData(CkByteData &srcData);

	// Clears the object of data.  This also deallocates the internal memory.  If the SecureClear property (above) is set to true, the memory is zeroed out before deallocating.
	void clear(void);

	// Sets the size of the data to 0, but keeps the allocated internal buffer (if it exists).
	void dropData(void);

	// Get the size in bytes.
        unsigned long getSize(void) const;

	bool equals2(const void *pByteData, unsigned long szByteData) const;
	bool equals(const CkByteData &db) const;

	// Get a pointer to the data.
        const unsigned char *getData(void) const;
        const unsigned char *getBytes(void) const;
        const unsigned char *getDataAt(unsigned long byteIndex) const;
        const unsigned char *getRange(unsigned long byteIndex, unsigned long numBytes);
        const char *getRangeStr(unsigned long byteIndex, unsigned long numAnsiChars);
	
	unsigned char getByte(unsigned long byteIndex) const;
	char getChar(unsigned long byteIndex) const;
	unsigned int getUInt(unsigned long byteIndex) const;
	int getInt(unsigned long byteIndex) const;
	unsigned short getUShort(unsigned long byteIndex) const;
	short getShort(unsigned long byteIndex) const;

	void appendRandom(int numBytes);

	void appendInt(int v, bool littleEndian);
	void appendShort(short v, bool littleEndian);
	const char *getEncodedRange(const char *encoding, unsigned long index, unsigned long numBytes);
	void appendRange(const CkByteData &byteData, unsigned long index, unsigned long numBytes);
	bool ensureBuffer(unsigned long numBytes);
	// Return -1 if not found, otherwise returns the index.
	int findBytes2(const void *pByteData, unsigned long szByteData);
	int findBytes(const CkByteData &byteData);

	bool beginsWith2(const void *pByteData, unsigned long szByteData);
	bool beginsWith(const CkByteData &byteData);

	void removeChunk(unsigned long index, unsigned long numBytes);
	void byteSwap4321(void);
	void pad(int blockSize, int paddingScheme);
	void unpad(int blockSize, int paddingScheme);
	bool is7bit(void) const;
	const char *computeHash(const char *hashAlg, const char *encoding);

	// Encoding can be "base64", "quoted-printable", "hex", or "url"
	const char *getEncoded(const char *encoding);
	const wchar_t *getEncodedW(const wchar_t *encoding);

	void replaceChar(unsigned char c, unsigned char replacement);

	// Append more data
        //void append(const unsigned char *data, unsigned long numBytes);
	//void append(const char *byteData, unsigned long numBytes);
	void append2(const void *pByteData, unsigned long szByteData);
	void append(const CkByteData &db);

	// Appends null-terminated sequence of bytes, which may be characters in any multibyte charset. 
	void appendStr(const char *str);    

	// Appends a string, but the charset must be explictly specified because
	// the Unicode string is first converted to this charset (such as utf-8) prior
	// to appending.
	void appendStrW(const wchar_t *str, const wchar_t *charset);

	void appendChar(char ch);
	void appendCharN(char ch, int numTimes);

	// Encoding can be "base64", "quoted-printable", "hex", or "url"
	void appendEncoded(const char *str, const char *encoding);
	void appendEncodedW(const wchar_t *str, const wchar_t *encoding);

	void encode(const char *encoding, CkString &str);
	void encodeW(const wchar_t *encoding, CkString &str);

	// Load a complete file into this object.  The contents of this object
	// are automatically cleared before the file is loaded, so the result
	// is a mirror image (in memory) of the bytes in the file.
        bool loadFile(const char *path);
	bool saveFile(const char *path);

        bool loadFileW(const wchar_t *path);
	bool saveFileW(const wchar_t *path);

	// Create a new file, or append to an existing file.
	bool appendFile(const char *path);
	bool appendFileW(const wchar_t *path);

	// Discards the last numBytes of data.
        void shorten(unsigned long numBytes);

	// The CkByteData will use *your* memory buffer, and will not delete
	// it when the object is destructed.  
	void borrowData(const void *pByteData, unsigned long szByteData);

	// Removes the data from the CkByteData object.  The caller will receive
	// a pointer to the memory buffer, and is responsible for deleting it.
	// (Example: 
	//	unsigned char *data = byteData.removeData();
	//	... do something with the data....
	//	delete [] data;
	unsigned char *removeData(void);

	bool preAllocate(unsigned long expectedNumBytes);

	const wchar_t *to_ws(const char *charset);
        const char *to_s(void);

	const char *getXmlCharset(void);


	// BYTES_INSERT_POINT

	// END PUBLIC INTERFACE


    private:
	// Internal implementation.
	void *m_impl;
	bool m_utf8;	// If true, all input "const char *" parameters are utf-8, otherwise they are ANSI strings.
	bool m_secureClear;
	void *m_pResultData;    // For to_s(), getRange(), getRangeStr()

    public:
	// Used internally by Chilkat.
	void *getImpl(void) const;
	const void *getImplC(void) const;
	void setImpl(void *impl);

};


// Undocumented class for random-access of data in large files.
class CK_VISIBLE_PUBLIC CkBigFileAccess : public CkObject
{
    public:
	CkBigFileAccess();
	~CkBigFileAccess();

	//static CkBigFileAccess *createNew(void);

	CkBigFileAccess(const CkBigFileAccess &);
	CkBigFileAccess &operator=(const CkBigFileAccess &);

	bool openFile(const char *path);
	// Appends bytes to result.  If the full amount is not available, false is returned and nothing is appended.
	bool readBytes(__int64 offset, int numBytes, CkByteData &result);
	// Get the file size after opening.
	__int64 fileSize(void);
	bool closeFile(void);

    private:
	// Internal implementation.
	void *m_impl;

    };

#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


#endif
