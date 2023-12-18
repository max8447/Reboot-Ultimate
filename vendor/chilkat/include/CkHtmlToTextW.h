// CkHtmlToTextW.h: interface for the CkHtmlToTextW class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#ifndef _CkHtmlToTextW_H
#define _CkHtmlToTextW_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkWideCharBase.h"




#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkHtmlToTextW
class CK_VISIBLE_PUBLIC CkHtmlToTextW  : public CkWideCharBase
{
	

	private:
	
	// Don't allow assignment or copying these objects.
	CkHtmlToTextW(const CkHtmlToTextW &);
	CkHtmlToTextW &operator=(const CkHtmlToTextW &);

    public:
	CkHtmlToTextW(void);
	virtual ~CkHtmlToTextW(void);

	

	static CkHtmlToTextW *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// If true, then HTML entities are automatically decoded. For example _AMP_amp;
	// is automatically decoded to _AMP_. If this property is set to false, then HTML
	// entities are not decoded. The default value is true.
	bool get_DecodeHtmlEntities(void);
	// If true, then HTML entities are automatically decoded. For example _AMP_amp;
	// is automatically decoded to _AMP_. If this property is set to false, then HTML
	// entities are not decoded. The default value is true.
	void put_DecodeHtmlEntities(bool newVal);

	// Used to control wrapping of text. The default value is 80. When the text gets
	// close to this margin, the converter will try to break the line at a SPACE
	// character. Set this property to 0 for no right margin.
	int get_RightMargin(void);
	// Used to control wrapping of text. The default value is 80. When the text gets
	// close to this margin, the converter will try to break the line at a SPACE
	// character. Set this property to 0 for no right margin.
	void put_RightMargin(int newVal);

	// If false, then link URL's are preserved inline. For example, the following
	// HTML fragment:
	// 
	// _LT_p>Test _LT_a href="https://www.chilkatsoft.com/">chilkat_LT_/a>_LT_/p>
	// 
	// converts to:Test chilkat _LT_https://www.chilkatsoft.com/> If this property is
	// true, the above HTML would convert to:Test chilkat The default value of this
	// property is true.
	// 
	bool get_SuppressLinks(void);
	// If false, then link URL's are preserved inline. For example, the following
	// HTML fragment:
	// 
	// _LT_p>Test _LT_a href="https://www.chilkatsoft.com/">chilkat_LT_/a>_LT_/p>
	// 
	// converts to:Test chilkat _LT_https://www.chilkatsoft.com/> If this property is
	// true, the above HTML would convert to:Test chilkat The default value of this
	// property is true.
	// 
	void put_SuppressLinks(bool newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Convenience method for reading a text file into a string. The character encoding
	// of the text file is specified by srcCharset. Valid values, such as "iso-8895-1" or
	// "utf-8" are listed at: List of Charsets
	// <https://www.chilkatsoft.com/p/p_463.asp>.
	bool ReadFileToString(const wchar_t *filename, const wchar_t *srcCharset, CkString &outStr);
	// Convenience method for reading a text file into a string. The character encoding
	// of the text file is specified by srcCharset. Valid values, such as "iso-8895-1" or
	// "utf-8" are listed at: List of Charsets
	// <https://www.chilkatsoft.com/p/p_463.asp>.
	const wchar_t *readFileToString(const wchar_t *filename, const wchar_t *srcCharset);

	// Converts HTML to plain-text.
	bool ToText(const wchar_t *html, CkString &outStr);
	// Converts HTML to plain-text.
	const wchar_t *toText(const wchar_t *html);

	// Unlocks the component. An arbitrary unlock code may be passed to automatically
	// begin a 30-day trial.
	// 
	// This class is included with the Chilkat HTML-to-XML conversion component
	// license.
	// 
	bool UnlockComponent(const wchar_t *code);

	// Convenience method for saving a string to a file. The character encoding of the
	// output text file is specified by charset (the string is converted to this charset
	// when writing). Valid values, such as "iso-8895-1" or "utf-8" are listed at: List
	// of Charsets
	// <https://www.chilkatsoft.com/p/p_463.asp>.
	bool WriteStringToFile(const wchar_t *stringToWrite, const wchar_t *filename, const wchar_t *charset);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
