// CkCharset.h: interface for the CkCharset class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#define _CkVersion 9.5.0.96

#ifndef _CkCharset_H
#define _CkCharset_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkMultiByteBase.h"

class CkByteData;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif


#undef Copy

// CLASS: CkCharset
class CK_VISIBLE_PUBLIC CkCharset  : public CkMultiByteBase
{
    private:

	// Don't allow assignment or copying these objects.
	CkCharset(const CkCharset &);
	CkCharset &operator=(const CkCharset &);

    public:
	CkCharset(void);
	virtual ~CkCharset(void);

	static CkCharset *createNew(void);
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	
		
	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// If the ErrorAction property is set to 6, then this property controls how errors
	// are handled. It specifies an alternate "To" charset. When a character in the
	// input data cannot be converted to the target charset, an attempt is made to
	// convert it to the AltToCharset. If that fails, the input character is dropped.
	void get_AltToCharset(CkString &str);
	// If the ErrorAction property is set to 6, then this property controls how errors
	// are handled. It specifies an alternate "To" charset. When a character in the
	// input data cannot be converted to the target charset, an attempt is made to
	// convert it to the AltToCharset. If that fails, the input character is dropped.
	const char *altToCharset(void);
	// If the ErrorAction property is set to 6, then this property controls how errors
	// are handled. It specifies an alternate "To" charset. When a character in the
	// input data cannot be converted to the target charset, an attempt is made to
	// convert it to the AltToCharset. If that fails, the input character is dropped.
	void put_AltToCharset(const char *newVal);

	// Controls how errors are handled. When a character in the input data cannot be
	// converted to the target charset, the action taken is controlled by this
	// property. The possible settings are: (0) drop the error characters, (1)
	// substitute the data set by the SetErrorBytes or SetErrorString method, (2)
	// convert to a hex-escaped string (
	int get_ErrorAction(void);
	// Controls how errors are handled. When a character in the input data cannot be
	// converted to the target charset, the action taken is controlled by this
	// property. The possible settings are: (0) drop the error characters, (1)
	// substitute the data set by the SetErrorBytes or SetErrorString method, (2)
	// convert to a hex-escaped string (
	void put_ErrorAction(int newVal);

	// Tells the charset converter the charset of the input data for a conversion.
	// Possible values are:us-ascii
	// unicode  (also known as UTF16LE or simply UTF16)
	// unicodefffe  (also known as UTF16BE)
	// ebcdic
	// iso-8859-1
	// iso-8859-2
	// iso-8859-3
	// iso-8859-4
	// iso-8859-5
	// iso-8859-6
	// iso-8859-7
	// iso-8859-8
	// iso-8859-9
	// iso-8859-13
	// iso-8859-15
	// windows-874
	// windows-1250
	// windows-1251
	// windows-1252
	// windows-1253
	// windows-1254
	// windows-1255
	// windows-1256
	// windows-1257
	// windows-1258
	// utf-7
	// utf-8
	// utf-32
	// utf-32be
	// shift_jis
	// gb2312
	// ks_c_5601-1987
	// big5
	// iso-2022-jp
	// iso-2022-kr
	// euc-jp
	// euc-kr
	// macintosh
	// x-mac-japanese
	// x-mac-chinesetrad
	// x-mac-korean
	// x-mac-arabic
	// x-mac-hebrew
	// x-mac-greek
	// x-mac-cyrillic
	// x-mac-chinesesimp
	// x-mac-romanian
	// x-mac-ukrainian
	// x-mac-thai
	// x-mac-ce
	// x-mac-icelandic
	// x-mac-turkish
	// x-mac-croatian
	// asmo-708
	// dos-720
	// dos-862
	// ibm01140
	// ibm01141
	// ibm01142
	// ibm01143
	// ibm01144
	// ibm01145
	// ibm01146
	// ibm01147
	// ibm01148
	// ibm01149
	// ibm037
	// ibm437
	// ibm500
	// ibm737
	// ibm775
	// ibm850
	// ibm852
	// ibm855
	// ibm857
	// ibm00858
	// ibm860
	// ibm861
	// ibm863
	// ibm864
	// ibm865
	// cp866
	// ibm869
	// ibm870
	// cp875
	// koi8-r
	// koi8-u
	void get_FromCharset(CkString &str);
	// Tells the charset converter the charset of the input data for a conversion.
	// Possible values are:us-ascii
	// unicode  (also known as UTF16LE or simply UTF16)
	// unicodefffe  (also known as UTF16BE)
	// ebcdic
	// iso-8859-1
	// iso-8859-2
	// iso-8859-3
	// iso-8859-4
	// iso-8859-5
	// iso-8859-6
	// iso-8859-7
	// iso-8859-8
	// iso-8859-9
	// iso-8859-13
	// iso-8859-15
	// windows-874
	// windows-1250
	// windows-1251
	// windows-1252
	// windows-1253
	// windows-1254
	// windows-1255
	// windows-1256
	// windows-1257
	// windows-1258
	// utf-7
	// utf-8
	// utf-32
	// utf-32be
	// shift_jis
	// gb2312
	// ks_c_5601-1987
	// big5
	// iso-2022-jp
	// iso-2022-kr
	// euc-jp
	// euc-kr
	// macintosh
	// x-mac-japanese
	// x-mac-chinesetrad
	// x-mac-korean
	// x-mac-arabic
	// x-mac-hebrew
	// x-mac-greek
	// x-mac-cyrillic
	// x-mac-chinesesimp
	// x-mac-romanian
	// x-mac-ukrainian
	// x-mac-thai
	// x-mac-ce
	// x-mac-icelandic
	// x-mac-turkish
	// x-mac-croatian
	// asmo-708
	// dos-720
	// dos-862
	// ibm01140
	// ibm01141
	// ibm01142
	// ibm01143
	// ibm01144
	// ibm01145
	// ibm01146
	// ibm01147
	// ibm01148
	// ibm01149
	// ibm037
	// ibm437
	// ibm500
	// ibm737
	// ibm775
	// ibm850
	// ibm852
	// ibm855
	// ibm857
	// ibm00858
	// ibm860
	// ibm861
	// ibm863
	// ibm864
	// ibm865
	// cp866
	// ibm869
	// ibm870
	// cp875
	// koi8-r
	// koi8-u
	const char *fromCharset(void);
	// Tells the charset converter the charset of the input data for a conversion.
	// Possible values are:us-ascii
	// unicode  (also known as UTF16LE or simply UTF16)
	// unicodefffe  (also known as UTF16BE)
	// ebcdic
	// iso-8859-1
	// iso-8859-2
	// iso-8859-3
	// iso-8859-4
	// iso-8859-5
	// iso-8859-6
	// iso-8859-7
	// iso-8859-8
	// iso-8859-9
	// iso-8859-13
	// iso-8859-15
	// windows-874
	// windows-1250
	// windows-1251
	// windows-1252
	// windows-1253
	// windows-1254
	// windows-1255
	// windows-1256
	// windows-1257
	// windows-1258
	// utf-7
	// utf-8
	// utf-32
	// utf-32be
	// shift_jis
	// gb2312
	// ks_c_5601-1987
	// big5
	// iso-2022-jp
	// iso-2022-kr
	// euc-jp
	// euc-kr
	// macintosh
	// x-mac-japanese
	// x-mac-chinesetrad
	// x-mac-korean
	// x-mac-arabic
	// x-mac-hebrew
	// x-mac-greek
	// x-mac-cyrillic
	// x-mac-chinesesimp
	// x-mac-romanian
	// x-mac-ukrainian
	// x-mac-thai
	// x-mac-ce
	// x-mac-icelandic
	// x-mac-turkish
	// x-mac-croatian
	// asmo-708
	// dos-720
	// dos-862
	// ibm01140
	// ibm01141
	// ibm01142
	// ibm01143
	// ibm01144
	// ibm01145
	// ibm01146
	// ibm01147
	// ibm01148
	// ibm01149
	// ibm037
	// ibm437
	// ibm500
	// ibm737
	// ibm775
	// ibm850
	// ibm852
	// ibm855
	// ibm857
	// ibm00858
	// ibm860
	// ibm861
	// ibm863
	// ibm864
	// ibm865
	// cp866
	// ibm869
	// ibm870
	// cp875
	// koi8-r
	// koi8-u
	void put_FromCharset(const char *newVal);

	// If SaveLast is set to true, then the input and output of a conversion is saved
	// to allow the exact bytes that are sent to the converter to be seen (for
	// debugging purposes). This property shows the last input data in a
	// hexidecimalized string.
	void get_LastInputAsHex(CkString &str);
	// If SaveLast is set to true, then the input and output of a conversion is saved
	// to allow the exact bytes that are sent to the converter to be seen (for
	// debugging purposes). This property shows the last input data in a
	// hexidecimalized string.
	const char *lastInputAsHex(void);

	// If SaveLast is set to true, then the input and output of a conversion is saved
	// to allow the exact bytes that are sent to the converter to be seen (for
	// debugging purposes). This property shows the last input data in a
	// quoted-printable string.
	void get_LastInputAsQP(CkString &str);
	// If SaveLast is set to true, then the input and output of a conversion is saved
	// to allow the exact bytes that are sent to the converter to be seen (for
	// debugging purposes). This property shows the last input data in a
	// quoted-printable string.
	const char *lastInputAsQP(void);

	// If SaveLast is set to true, then the input and output of a conversion is saved
	// to allow the exact bytes that are sent to the converter to be seen (for
	// debugging purposes). This property shows the last output data in a
	// hexidecimalized string.
	void get_LastOutputAsHex(CkString &str);
	// If SaveLast is set to true, then the input and output of a conversion is saved
	// to allow the exact bytes that are sent to the converter to be seen (for
	// debugging purposes). This property shows the last output data in a
	// hexidecimalized string.
	const char *lastOutputAsHex(void);

	// If SaveLast is set to true, then the input and output of a conversion is saved
	// to allow the exact bytes that are sent to the converter to be seen (for
	// debugging purposes). This property shows the last output data in a
	// quoted-printable string.
	void get_LastOutputAsQP(CkString &str);
	// If SaveLast is set to true, then the input and output of a conversion is saved
	// to allow the exact bytes that are sent to the converter to be seen (for
	// debugging purposes). This property shows the last output data in a
	// quoted-printable string.
	const char *lastOutputAsQP(void);

	// Tells the component to keep the input/output byte data in memory after a
	// conversion is complete so the data can be examined via the LastInputAsHex/QP and
	// LastOutputAsHex/QP properties. (for debugging purposes)
	bool get_SaveLast(void);
	// Tells the component to keep the input/output byte data in memory after a
	// conversion is complete so the data can be examined via the LastInputAsHex/QP and
	// LastOutputAsHex/QP properties. (for debugging purposes)
	void put_SaveLast(bool newVal);

	// Tells the charset converter the target charset for a conversion. Possible values
	// are:us-ascii
	// unicode  (also known as UTF16LE or simply UTF16)
	// unicodefffe  (also known as UTF16BE)
	// ebcdic
	// iso-8859-1
	// iso-8859-2
	// iso-8859-3
	// iso-8859-4
	// iso-8859-5
	// iso-8859-6
	// iso-8859-7
	// iso-8859-8
	// iso-8859-9
	// iso-8859-13
	// iso-8859-15
	// windows-874
	// windows-1250
	// windows-1251
	// windows-1252
	// windows-1253
	// windows-1254
	// windows-1255
	// windows-1256
	// windows-1257
	// windows-1258
	// utf-7
	// utf-8
	// utf-32
	// utf-32be
	// shift_jis
	// gb2312
	// ks_c_5601-1987
	// big5
	// iso-2022-jp
	// iso-2022-kr
	// euc-jp
	// euc-kr
	// macintosh
	// x-mac-japanese
	// x-mac-chinesetrad
	// x-mac-korean
	// x-mac-arabic
	// x-mac-hebrew
	// x-mac-greek
	// x-mac-cyrillic
	// x-mac-chinesesimp
	// x-mac-romanian
	// x-mac-ukrainian
	// x-mac-thai
	// x-mac-ce
	// x-mac-icelandic
	// x-mac-turkish
	// x-mac-croatian
	// asmo-708
	// dos-720
	// dos-862
	// ibm01140
	// ibm01141
	// ibm01142
	// ibm01143
	// ibm01144
	// ibm01145
	// ibm01146
	// ibm01147
	// ibm01148
	// ibm01149
	// ibm037
	// ibm437
	// ibm500
	// ibm737
	// ibm775
	// ibm850
	// ibm852
	// ibm855
	// ibm857
	// ibm00858
	// ibm860
	// ibm861
	// ibm863
	// ibm864
	// ibm865
	// cp866
	// ibm869
	// ibm870
	// cp875
	// koi8-r
	// koi8-u
	void get_ToCharset(CkString &str);
	// Tells the charset converter the target charset for a conversion. Possible values
	// are:us-ascii
	// unicode  (also known as UTF16LE or simply UTF16)
	// unicodefffe  (also known as UTF16BE)
	// ebcdic
	// iso-8859-1
	// iso-8859-2
	// iso-8859-3
	// iso-8859-4
	// iso-8859-5
	// iso-8859-6
	// iso-8859-7
	// iso-8859-8
	// iso-8859-9
	// iso-8859-13
	// iso-8859-15
	// windows-874
	// windows-1250
	// windows-1251
	// windows-1252
	// windows-1253
	// windows-1254
	// windows-1255
	// windows-1256
	// windows-1257
	// windows-1258
	// utf-7
	// utf-8
	// utf-32
	// utf-32be
	// shift_jis
	// gb2312
	// ks_c_5601-1987
	// big5
	// iso-2022-jp
	// iso-2022-kr
	// euc-jp
	// euc-kr
	// macintosh
	// x-mac-japanese
	// x-mac-chinesetrad
	// x-mac-korean
	// x-mac-arabic
	// x-mac-hebrew
	// x-mac-greek
	// x-mac-cyrillic
	// x-mac-chinesesimp
	// x-mac-romanian
	// x-mac-ukrainian
	// x-mac-thai
	// x-mac-ce
	// x-mac-icelandic
	// x-mac-turkish
	// x-mac-croatian
	// asmo-708
	// dos-720
	// dos-862
	// ibm01140
	// ibm01141
	// ibm01142
	// ibm01143
	// ibm01144
	// ibm01145
	// ibm01146
	// ibm01147
	// ibm01148
	// ibm01149
	// ibm037
	// ibm437
	// ibm500
	// ibm737
	// ibm775
	// ibm850
	// ibm852
	// ibm855
	// ibm857
	// ibm00858
	// ibm860
	// ibm861
	// ibm863
	// ibm864
	// ibm865
	// cp866
	// ibm869
	// ibm870
	// cp875
	// koi8-r
	// koi8-u
	const char *toCharset(void);
	// Tells the charset converter the target charset for a conversion. Possible values
	// are:us-ascii
	// unicode  (also known as UTF16LE or simply UTF16)
	// unicodefffe  (also known as UTF16BE)
	// ebcdic
	// iso-8859-1
	// iso-8859-2
	// iso-8859-3
	// iso-8859-4
	// iso-8859-5
	// iso-8859-6
	// iso-8859-7
	// iso-8859-8
	// iso-8859-9
	// iso-8859-13
	// iso-8859-15
	// windows-874
	// windows-1250
	// windows-1251
	// windows-1252
	// windows-1253
	// windows-1254
	// windows-1255
	// windows-1256
	// windows-1257
	// windows-1258
	// utf-7
	// utf-8
	// utf-32
	// utf-32be
	// shift_jis
	// gb2312
	// ks_c_5601-1987
	// big5
	// iso-2022-jp
	// iso-2022-kr
	// euc-jp
	// euc-kr
	// macintosh
	// x-mac-japanese
	// x-mac-chinesetrad
	// x-mac-korean
	// x-mac-arabic
	// x-mac-hebrew
	// x-mac-greek
	// x-mac-cyrillic
	// x-mac-chinesesimp
	// x-mac-romanian
	// x-mac-ukrainian
	// x-mac-thai
	// x-mac-ce
	// x-mac-icelandic
	// x-mac-turkish
	// x-mac-croatian
	// asmo-708
	// dos-720
	// dos-862
	// ibm01140
	// ibm01141
	// ibm01142
	// ibm01143
	// ibm01144
	// ibm01145
	// ibm01146
	// ibm01147
	// ibm01148
	// ibm01149
	// ibm037
	// ibm437
	// ibm500
	// ibm737
	// ibm775
	// ibm850
	// ibm852
	// ibm855
	// ibm857
	// ibm00858
	// ibm860
	// ibm861
	// ibm863
	// ibm864
	// ibm865
	// cp866
	// ibm869
	// ibm870
	// cp875
	// koi8-r
	// koi8-u
	void put_ToCharset(const char *newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Converts a charset name to a code page number. For example, "iso-8859-1"
	// converts to code page 28591.
	int CharsetToCodePage(const char *charsetName);


	// Converts a code page number to a charset name. For example, 65001 converts to
	// "utf-8".
	bool CodePageToCharset(int codePage, CkString &outCharset);

	// Converts a code page number to a charset name. For example, 65001 converts to
	// "utf-8".
	const char *codePageToCharset(int codePage);

	// Converts character data from one charset to another. Before calling ConvertData,
	// the FromCharset and ToCharset properties must be set to the source and
	// destination charset names, such as "iso-8859-1" or "Shift_JIS".
	bool ConvertData(CkByteData &inData, CkByteData &outData);


	// Converts a file from one character encoding to another. The FromCharset and
	// ToCharset properties specify the source and destination character encodings. If
	// the ToCharset is utf-16 or utf-8, then the preamble (also known as BOM) is
	// included in the output. (Call ConvertFileNoPreamble to suppress the output of
	// the BOM.)
	bool ConvertFile(const char *inPath, const char *destPath);


	// Converts a file from one character encoding to another. The FromCharset and
	// ToCharset properties specify the source and destination character encodings. No
	// preamble (also known as BOM) is included in the output.
	bool ConvertFileNoPreamble(const char *inPath, const char *destPath);


	// Converts Unicode (utf-16) text to the charset specified by the ToCharset
	// property.
	bool ConvertFromUnicode(const char *inData, CkByteData &outBytes);


	// Converts utf-16 text to the charset specified by the ToCharset property.
	bool ConvertFromUtf16(CkByteData &uniData, CkByteData &outMbData);


	// Converts HTML text from one character encoding to another. The FromCharset and
	// ToCharset properties must be set prior to calling this method. This method
	// automatically edits the META tag within the HTML that indicates the charset.
	bool ConvertHtml(CkByteData &inData, CkByteData &outHtml);


	// Converts an HTML file from one character encoding to another. The ToCharset
	// properties must be set prior to calling this method. If the FromCharset is not
	// set, it is obtained from the HTML META tag that indicates the charset. This
	// method automatically edits the META tag within the HTML that indicates the
	// charset.
	bool ConvertHtmlFile(const char *inPath, const char *destPath);


	// Converts multibyte character data to a Unicode string. The FromCharset property
	// should be set before calling this method.
	bool ConvertToUnicode(CkByteData &inData, CkString &outStr);

	// Converts multibyte character data to a Unicode string. The FromCharset property
	// should be set before calling this method.
	const char *convertToUnicode(CkByteData &inData);

	// Converts the mbData to utf-16 bytes.
	bool ConvertToUtf16(CkByteData &mbData, CkByteData &outUniData);


	// Converts non-US-ASCII characters to Unicode decimal entities (_AMP_#xxxxx;)
	bool EntityEncodeDec(const char *str, CkString &outStr);

	// Converts non-US-ASCII characters to Unicode decimal entities (_AMP_#xxxxx;)
	const char *entityEncodeDec(const char *str);

	// Converts non-US-ASCII characters to Unicode hex entities (_AMP_#xXXXX;)
	bool EntityEncodeHex(const char *str, CkString &outStr);

	// Converts non-US-ASCII characters to Unicode hex entities (_AMP_#xXXXX;)
	const char *entityEncodeHex(const char *str);

	// Examines HTML text and extracts the charset name specified by the META tag, if
	// present.
	bool GetHtmlCharset(CkByteData &inData, CkString &outCharset);

	// Examines HTML text and extracts the charset name specified by the META tag, if
	// present.
	const char *getHtmlCharset(CkByteData &inData);
	// Examines HTML text and extracts the charset name specified by the META tag, if
	// present.
	const char *htmlCharset(CkByteData &inData);


	// Examines an HTML file and extracts the charset name specified by the META tag,
	// if present.
	bool GetHtmlFileCharset(const char *htmlFilePath, CkString &outCharset);

	// Examines an HTML file and extracts the charset name specified by the META tag,
	// if present.
	const char *getHtmlFileCharset(const char *htmlFilePath);
	// Examines an HTML file and extracts the charset name specified by the META tag,
	// if present.
	const char *htmlFileCharset(const char *htmlFilePath);


	// Converts HTML entities to Unicode characters.
	bool HtmlDecodeToStr(const char *inStr, CkString &outStr);

	// Converts HTML entities to Unicode characters.
	const char *htmlDecodeToStr(const char *inStr);

	// Decodes HTML entities. See http://www.w3.org/TR/REC-html40/sgml/entities.html
	// for information on HTML entities. Examples of HTML entities are _AMP_lt; ,
	// _AMP_#229; , _AMP_#xE5; , _AMP_#x6C34; , _AMP_Iacute; , etc.
	bool HtmlEntityDecode(CkByteData &inHtml, CkByteData &outData);


	// Decodes HTML entities in a file and creates a new HTML file with the entities
	// decoded. See http://www.w3.org/TR/REC-html40/sgml/entities.html for information
	// on HTML entities. Examples of HTML entities are _AMP_lt; , _AMP_#229; ,
	// _AMP_#xE5; , _AMP_#x6C34; , _AMP_Iacute; , etc.
	bool HtmlEntityDecodeFile(const char *inPath, const char *destPath);


	// Converts a string to lowercase.
	bool LowerCase(const char *inStr, CkString &outStr);

	// Converts a string to lowercase.
	const char *lowerCase(const char *inStr);

	// Convenience method for reading the entire contents of a file into a byte array.
	bool ReadFile(const char *path, CkByteData &outData);


	// Reads a text file and returns the text converted to a Unicode string. The
	// filename is specified by the first method argument, and the charset of the text
	// data is specified by the 2nd method argument.
	bool ReadFileToString(const char *path, const char *charset, CkString &outStr);

	// Reads a text file and returns the text converted to a Unicode string. The
	// filename is specified by the first method argument, and the charset of the text
	// data is specified by the 2nd method argument.
	const char *readFileToString(const char *path, const char *charset);

	// If the ErrorAction property is set to 1, the bytes passed to this method are
	// used as the result for any characters that cannot be converted during a
	// conversion.
	void SetErrorBytes(CkByteData &data);


	// If the ErrorAction property is set to 1, the string passed to this method is
	// used as the result for any characters that cannot be converted during a
	// conversion.
	void SetErrorString(const char *str, const char *charset);


	// Unlocks the component. This method must be called once at the beginning of the
	// program. Properties can be get/set without unlocking, but methods will not work
	// unless the component has been unlocked.
	bool UnlockComponent(const char *unlockCode);


	// Converts a string to uppercase.
	bool UpperCase(const char *inStr, CkString &outStr);

	// Converts a string to uppercase.
	const char *upperCase(const char *inStr);

	// URL decodes a string.
	// 
	// This method assumes the ANSI byte representation was used for encoding. For
	// example, the letter É, where the ANSI charset is Latin-1, would appear as "%C9"
	// when URL encoded. (As opposed to the utf-8 encoding where É is represented by 2
	// bytes 0xC3, 0x89 and would appear as "%C3%89" when URl encoded. This method
	// assumes ANSI encoding.
	// 
	// You can use encoding/decoding methods in Chilkat's StringBuilder class to
	// specify the charset from which to decode or encode.
	// 
	bool UrlDecodeStr(const char *inStr, CkString &outStr);

	// URL decodes a string.
	// 
	// This method assumes the ANSI byte representation was used for encoding. For
	// example, the letter É, where the ANSI charset is Latin-1, would appear as "%C9"
	// when URL encoded. (As opposed to the utf-8 encoding where É is represented by 2
	// bytes 0xC3, 0x89 and would appear as "%C3%89" when URl encoded. This method
	// assumes ANSI encoding.
	// 
	// You can use encoding/decoding methods in Chilkat's StringBuilder class to
	// specify the charset from which to decode or encode.
	// 
	const char *urlDecodeStr(const char *inStr);

	// Returns true if the byte data conforms to the charset passed in the first
	// argument.
	bool VerifyData(const char *charset, CkByteData &inData);


	// Returns true if the file contains character data that conforms to the charset
	// passed in the 1st argument.
	bool VerifyFile(const char *charset, const char *path);


	// Convenience method for saving an entire byte array to a file.
	bool WriteFile(const char *path, CkByteData &byteData);


	// Converts a Unicode string to a multibyte charset and writes the multibyte text
	// data to a file. The destination charset is specified in the 2nd method argument.
	bool WriteStringToFile(const char *textData, const char *path, const char *charset);






	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
