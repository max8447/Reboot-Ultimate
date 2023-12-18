// CkMessageSetW.h: interface for the CkMessageSetW class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#ifndef _CkMessageSetW_H
#define _CkMessageSetW_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkWideCharBase.h"

class CkTaskW;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkMessageSetW
class CK_VISIBLE_PUBLIC CkMessageSetW  : public CkWideCharBase
{
	

	private:
	
	// Don't allow assignment or copying these objects.
	CkMessageSetW(const CkMessageSetW &);
	CkMessageSetW &operator=(const CkMessageSetW &);

    public:
	CkMessageSetW(void);
	virtual ~CkMessageSetW(void);

	

	static CkMessageSetW *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The number of message UIDs (or sequence numbers) in this message set.
	int get_Count(void);

	// If true then the message set contains UIDs, otherwise it contains sequence
	// numbers.
	bool get_HasUids(void);
	// If true then the message set contains UIDs, otherwise it contains sequence
	// numbers.
	void put_HasUids(bool newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Returns true if the msgId is contained in the message set.
	bool ContainsId(unsigned long msgId);

	// Loads the message set from a compact-string representation. Here are some
	// examples:
	// 
	// Non-Compact String
	// 
	// Compact String
	// 
	// 1,2,3,4,5
	// 
	// 1:5
	// 
	// 1,2,3,4,5,8,9,10
	// 
	// 1:5,8:10
	// 
	// 1,3,4,5,8,9,10
	// 
	// 1,3:5,8:10
	// 
	bool FromCompactString(const wchar_t *str);

	// Returns the message ID of the Nth message in the set. (indexing begins at 0).
	// Returns 0xFFFFFFFF if the index is out of range.
	unsigned long GetId(int index);

	// Inserts a message ID into the set. If the ID already exists, a duplicate is not
	// inserted.
	void InsertId(unsigned long id);

	// Loads the message set from a completed asynchronous task.
	bool LoadTaskResult(CkTaskW &task);

	// Removes a message ID from the set.
	void RemoveId(unsigned long id);

	// Returns a string of comma-separated message IDs. (This is the non-compact string
	// format.)
	bool ToCommaSeparatedStr(CkString &outStr);
	// Returns a string of comma-separated message IDs. (This is the non-compact string
	// format.)
	const wchar_t *toCommaSeparatedStr(void);

	// Returns the set of message IDs represented as a compact string. Here are some
	// examples:
	// 
	// Non-Compact String
	// 
	// Compact String
	// 
	// 1,2,3,4,5
	// 
	// 1:5
	// 
	// 1,2,3,4,5,8,9,10
	// 
	// 1:5,8:10
	// 
	// 1,3,4,5,8,9,10
	// 
	// 1,3:5,8:10
	// 
	bool ToCompactString(CkString &outStr);
	// Returns the set of message IDs represented as a compact string. Here are some
	// examples:
	// 
	// Non-Compact String
	// 
	// Compact String
	// 
	// 1,2,3,4,5
	// 
	// 1:5
	// 
	// 1,2,3,4,5,8,9,10
	// 
	// 1:5,8:10
	// 
	// 1,3,4,5,8,9,10
	// 
	// 1,3:5,8:10
	// 
	const wchar_t *toCompactString(void);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
