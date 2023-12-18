// CkXml.h: interface for the CkXml class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#define _CkVersion 9.5.0.96

#ifndef _CkXml_H
#define _CkXml_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkMultiByteBase.h"

class CkByteData;
class CkStringBuilder;
class CkBinData;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif


#undef Copy

// CLASS: CkXml
class CK_VISIBLE_PUBLIC CkXml  : public CkMultiByteBase
{
    private:

	// Don't allow assignment or copying these objects.
	CkXml(const CkXml &);
	CkXml &operator=(const CkXml &);

    public:
	CkXml(void);
	virtual ~CkXml(void);

	static CkXml *createNew(void);
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	
		
	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// When True, causes an XML node's content to be encapsulated in a CDATA section.
	bool get_Cdata(void);
	// When True, causes an XML node's content to be encapsulated in a CDATA section.
	void put_Cdata(bool newVal);

	// The content of the XML node. It is the text between the open and close tags, not
	// including child nodes. For example:_LT_tag1_GT_This is the content_LT_/tag1_GT_
	// 
	// _LT_tag2_GT__LT_child1_GT_abc_LT_/child1_GT__LT_child2_GT_abc_LT_/child2_GT_This
	// is the content_LT_/tag2_GT_ Because the child nodes are not included, the
	// content of "tag1" and "tag2" are both equal to "This is the content".
	void get_Content(CkString &str);
	// The content of the XML node. It is the text between the open and close tags, not
	// including child nodes. For example:_LT_tag1_GT_This is the content_LT_/tag1_GT_
	// 
	// _LT_tag2_GT__LT_child1_GT_abc_LT_/child1_GT__LT_child2_GT_abc_LT_/child2_GT_This
	// is the content_LT_/tag2_GT_ Because the child nodes are not included, the
	// content of "tag1" and "tag2" are both equal to "This is the content".
	const char *content(void);
	// The content of the XML node. It is the text between the open and close tags, not
	// including child nodes. For example:_LT_tag1_GT_This is the content_LT_/tag1_GT_
	// 
	// _LT_tag2_GT__LT_child1_GT_abc_LT_/child1_GT__LT_child2_GT_abc_LT_/child2_GT_This
	// is the content_LT_/tag2_GT_ Because the child nodes are not included, the
	// content of "tag1" and "tag2" are both equal to "This is the content".
	void put_Content(const char *newVal);

	// Set/get the content as an integer.
	int get_ContentInt(void);
	// Set/get the content as an integer.
	void put_ContentInt(int newVal);

	// The DOCTYPE declaration (if any) for the XML document.
	void get_DocType(CkString &str);
	// The DOCTYPE declaration (if any) for the XML document.
	const char *docType(void);
	// The DOCTYPE declaration (if any) for the XML document.
	void put_DocType(const char *newVal);

	// If true, then emit the BOM (byte order mark, also known as a preamble) for
	// encodings such as utf-8, utf-16, etc. The defautl value is false. This only
	// applies when writing XML files. It does not apply when getting the XML as a
	// string via the GetXml method.
	bool get_EmitBom(void);
	// If true, then emit the BOM (byte order mark, also known as a preamble) for
	// encodings such as utf-8, utf-16, etc. The defautl value is false. This only
	// applies when writing XML files. It does not apply when getting the XML as a
	// string via the GetXml method.
	void put_EmitBom(bool newVal);

	// If true, then GetXml and GetXmlSb emit compact XML. The XML emitted has no
	// unnecessary whitespace, incuding no end-of-lines (CR's and/or LF's). The default
	// value is false, which maintains backward compatibility.
	bool get_EmitCompact(void);
	// If true, then GetXml and GetXmlSb emit compact XML. The XML emitted has no
	// unnecessary whitespace, incuding no end-of-lines (CR's and/or LF's). The default
	// value is false, which maintains backward compatibility.
	void put_EmitCompact(bool newVal);

	// If true, then the XML declaration is emitted for methods (such as GetXml or
	// SaveXml) where the XML is written to a file or string. The default value of this
	// property is true. If set to false, the XML declaration is not emitted. (The
	// XML declaration is the 1st line of an XML document starting with "_LT_?xml ...".
	bool get_EmitXmlDecl(void);
	// If true, then the XML declaration is emitted for methods (such as GetXml or
	// SaveXml) where the XML is written to a file or string. The default value of this
	// property is true. If set to false, the XML declaration is not emitted. (The
	// XML declaration is the 1st line of an XML document starting with "_LT_?xml ...".
	void put_EmitXmlDecl(bool newVal);

	// This is the encoding attribute in the XML declaration, such as "utf-8" or
	// "iso-8859-1". The default is "utf-8". This property can be set from any node in
	// the XML document and when set, causes the encoding property to be added to the
	// XML declaration. Setting this property does not cause the document to be
	// converted to a different encoding.
	// 
	// Calling any of the LoadXml* methods causes this property to be set to the
	// charset found within the XML, if any. If no charset is specified within the
	// loaded XML, then the LoadXml method resets this property to its default value of
	// "utf-8".
	// 
	void get_Encoding(CkString &str);
	// This is the encoding attribute in the XML declaration, such as "utf-8" or
	// "iso-8859-1". The default is "utf-8". This property can be set from any node in
	// the XML document and when set, causes the encoding property to be added to the
	// XML declaration. Setting this property does not cause the document to be
	// converted to a different encoding.
	// 
	// Calling any of the LoadXml* methods causes this property to be set to the
	// charset found within the XML, if any. If no charset is specified within the
	// loaded XML, then the LoadXml method resets this property to its default value of
	// "utf-8".
	// 
	const char *encoding(void);
	// This is the encoding attribute in the XML declaration, such as "utf-8" or
	// "iso-8859-1". The default is "utf-8". This property can be set from any node in
	// the XML document and when set, causes the encoding property to be added to the
	// XML declaration. Setting this property does not cause the document to be
	// converted to a different encoding.
	// 
	// Calling any of the LoadXml* methods causes this property to be set to the
	// charset found within the XML, if any. If no charset is specified within the
	// loaded XML, then the LoadXml method resets this property to its default value of
	// "utf-8".
	// 
	void put_Encoding(const char *newVal);

	// Used in tagPaths (and ChilkatPath). The value of this property is substituted
	// for "i" in "[i]". See the example below..
	int get_I(void);
	// Used in tagPaths (and ChilkatPath). The value of this property is substituted
	// for "i" in "[i]". See the example below..
	void put_I(int newVal);

	// Returns true if the content contains only those characters allowed in the
	// base64 encoding. A base64 string is composed of characters 'A'..'Z', 'a'..'z',
	// '0'..'9', '+', '/' and it is often padded at the end with up to two '=', to make
	// the length a multiple of 4. Whitespace is ignored.
	bool get_IsBase64(void);

	// Used in tagPaths (and ChilkatPath). The value of this property is substituted
	// for "j" in "[j]". See the example below..
	int get_J(void);
	// Used in tagPaths (and ChilkatPath). The value of this property is substituted
	// for "j" in "[j]". See the example below..
	void put_J(int newVal);

	// Used in tagPaths (and ChilkatPath). The value of this property is substituted
	// for "k" in "[k]". See the example below..
	int get_K(void);
	// Used in tagPaths (and ChilkatPath). The value of this property is substituted
	// for "k" in "[k]". See the example below..
	void put_K(int newVal);

	// The number of attributes. For example, the following node has 2 attributes:_LT_tag attr1="value1" attr2="value2"> This is the content_LT_/tag>
	int get_NumAttributes(void);

	// The number of direct child nodes contained under this XML node.
	int get_NumChildren(void);

	// If true (or 1 for ActiveX), then all Sort* methods use case insensitive sorting.
	bool get_SortCaseInsensitive(void);
	// If true (or 1 for ActiveX), then all Sort* methods use case insensitive sorting.
	void put_SortCaseInsensitive(bool newVal);

	// This is the standalone attribute in the XML declaration. This property can be
	// set from any node in the XML document. A value of true adds a standalone="yes"
	// to the XML declaration:_LT_?xml ... standalone="yes">
	bool get_Standalone(void);
	// This is the standalone attribute in the XML declaration. This property can be
	// set from any node in the XML document. A value of true adds a standalone="yes"
	// to the XML declaration:_LT_?xml ... standalone="yes">
	void put_Standalone(bool newVal);

	// The XML node's tag, including the namespace prefix.
	void get_Tag(CkString &str);
	// The XML node's tag, including the namespace prefix.
	const char *tag(void);
	// The XML node's tag, including the namespace prefix.
	void put_Tag(const char *newVal);

	// The node's namespace prefix, if present. For example, if the tag is
	// "soapenv:Envelope", then this property will return "soapenv".
	void get_TagNsPrefix(CkString &str);
	// The node's namespace prefix, if present. For example, if the tag is
	// "soapenv:Envelope", then this property will return "soapenv".
	const char *tagNsPrefix(void);
	// The node's namespace prefix, if present. For example, if the tag is
	// "soapenv:Envelope", then this property will return "soapenv".
	void put_TagNsPrefix(const char *newVal);

	// Returns the path to reach this element from the XML document root. If the caller
	// is the document root, then the empty string is returned.
	void get_TagPath(CkString &str);
	// Returns the path to reach this element from the XML document root. If the caller
	// is the document root, then the empty string is returned.
	const char *tagPath(void);

	// The node's tag without the namespace prefix. For example, if the tag is
	// "soapenv:Envelope", then this property will return "Envelope".
	void get_TagUnprefixed(CkString &str);
	// The node's tag without the namespace prefix. For example, if the tag is
	// "soapenv:Envelope", then this property will return "Envelope".
	const char *tagUnprefixed(void);
	// The node's tag without the namespace prefix. For example, if the tag is
	// "soapenv:Envelope", then this property will return "Envelope".
	void put_TagUnprefixed(const char *newVal);

	// Each tree (or XML document) has a unique TreeId. This is the ID of the tree, and
	// can be used to determine if two Xml objects belong to the same tree.
	int get_TreeId(void);

	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string and should typically remain empty.
	void get_UncommonOptions(CkString &str);
	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string and should typically remain empty.
	const char *uncommonOptions(void);
	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string and should typically remain empty.
	void put_UncommonOptions(const char *newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Accumulates the content of all nodes having a specific tag into a single result
	// string. SkipTags specifies a set of subtrees to be avoided. The skipTags are
	// formatted as a string of tags delimited by vertical bar characters. All nodes in
	// sub-trees rooted with a tag appearing in skipTags are not included in the
	// result.
	bool AccumulateTagContent(const char *tag, const char *skipTags, CkString &outStr);

	// Accumulates the content of all nodes having a specific tag into a single result
	// string. SkipTags specifies a set of subtrees to be avoided. The skipTags are
	// formatted as a string of tags delimited by vertical bar characters. All nodes in
	// sub-trees rooted with a tag appearing in skipTags are not included in the
	// result.
	const char *accumulateTagContent(const char *tag, const char *skipTags);

	// Adds an attribute to the calling node in the XML document. Returns True for
	// success, and False for failure.
	bool AddAttribute(const char *name, const char *value);


	// Adds an integer attribute to a node.
	bool AddAttributeInt(const char *name, int value);


	// Adds an entire subtree as a child. If the child was a subtree within another Xml
	// document then the subtree is effectively transferred from one XML document to
	// another.
	bool AddChildTree(CkXml &tree);


	// Adds an attribute to an XML node. If an attribute having the specified name
	// already exists, the value is updated.
	void AddOrUpdateAttribute(const char *name, const char *value);


	// Adds an integer attribute to an XML node. If an attribute having the specified
	// name already exists, the value is updated.
	void AddOrUpdateAttributeI(const char *name, int value);


	// Adds a style sheet declaration to the XML document. The styleSheet should be a string
	// such as:_LT_?xml-stylesheet href="mystyle.css" title="Compact" type="text/css"?>
	void AddStyleSheet(const char *styleSheet);


	// Adds an integer amount to an integer attribute's value. If the attribute does
	// not yet exist, this method behaves the same as AddOrUpdateAttributeI.
	void AddToAttribute(const char *name, int amount);


	// Adds an integer value to the content of a child node.
	void AddToChildContent(const char *tag, int amount);


	// Adds an integer amount to the node's content.
	void AddToContent(int amount);


	// Appends text to the content of an XML node
	bool AppendToContent(const char *str);


	// Sets the node's content with 8bit data that is in a specified multibyte
	// character encoding such as utf-8, shift-jis, big5, etc. The data is first
	// B-encoded and the content is set to be the B-encoded string. For example, if
	// called with "Big5"for the charset, you would get a string that looks something
	// like this: "=?Big5?B?pHCtsw==?=". The data is Base64-encoded and stored between
	// the last pair of "?" delimiters. Use the DecodeContent method to retrieve the
	// byte data from a B encoded string.
	bool BEncodeContent(const char *charset, CkByteData &inData);


	// Return true if a child at the specified tagPath contains content that matches a
	// wildcarded pattern. Otherwise returns false.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	bool ChildContentMatches(const char *tagPath, const char *pattern, bool caseSensitive);


	// Follows a series of commands to navigate through an XML document to return a
	// piece of data or update the caller's reference to a new XML document node.
	// 
	// Note: This method not related to the XPath (XML Path) standard in any way.
	// 
	// The pathCmd is formatted as a series of commands separated by vertical bar
	// characters, and terminated with a
	// return-command:command|command|command|...|returnCommand 
	// 
	// A command can be any of the following:
	//     TagName -- Navigate to the 1st direct child with the given tag.
	//     TagName[n] -- Navigate to the Nth direct child with the given tag.
	//     ".." -- Navigate up to the parent.
	//     "++" -- Navigate to the next sibling. (next/previous sibling feature added
	//     in v9.5.0.76)
	//     "--" -- Navigate to the previous sibling.
	//     TagName{Content} -- Navigate to the 1st direct child with the given tag
	//     having the exact content.
	//     /T/TagName -- Traverse the XML DOM tree (rooted at the caller) and navigate
	//     to the 1st node having the given tag.
	//     /C/TagName,ContentPattern -- Traverse the XML DOM tree (rooted at the
	//     caller) and navigate to the 1st node having the given tag with content that
	//     matches the ContentPattern. ContentPattern may use one or more asterisk ('*")
	//     characters to represent 0 or more of any character.
	//     /C/ContentPattern -- Traverse the XML DOM tree (rooted at the caller) and
	//     navigate to the 1st node having any tag with content that matches the
	//     ContentPattern. ContentPattern may use one or more asterisk ('*") characters to
	//     represent 0 or more of any character.
	//     /A/TagName,AttrName,AttrValuePattern -- Traverse the XML DOM tree (rooted at
	//     the caller) and navigate to the 1st node having the given tag, and attribute,
	//     with the attribute value that matches the AttrValuePattern. AttrValuePattern may
	//     use one or more asterisk ('*") characters to represent 0 or more of any
	//     character.
	// The returnCommand can be any of the following:
	//     * -- Return the Content of the node.
	//     (AttrName) -- Return the value of the given attribute.
	//     $ -- Update the caller's internal reference to be the node (arrived at by
	//     following the series of commands). Returns an empty string.
	// 
	bool ChilkatPath(const char *pathCmd, CkString &outStr);

	// Follows a series of commands to navigate through an XML document to return a
	// piece of data or update the caller's reference to a new XML document node.
	// 
	// Note: This method not related to the XPath (XML Path) standard in any way.
	// 
	// The pathCmd is formatted as a series of commands separated by vertical bar
	// characters, and terminated with a
	// return-command:command|command|command|...|returnCommand 
	// 
	// A command can be any of the following:
	//     TagName -- Navigate to the 1st direct child with the given tag.
	//     TagName[n] -- Navigate to the Nth direct child with the given tag.
	//     ".." -- Navigate up to the parent.
	//     "++" -- Navigate to the next sibling. (next/previous sibling feature added
	//     in v9.5.0.76)
	//     "--" -- Navigate to the previous sibling.
	//     TagName{Content} -- Navigate to the 1st direct child with the given tag
	//     having the exact content.
	//     /T/TagName -- Traverse the XML DOM tree (rooted at the caller) and navigate
	//     to the 1st node having the given tag.
	//     /C/TagName,ContentPattern -- Traverse the XML DOM tree (rooted at the
	//     caller) and navigate to the 1st node having the given tag with content that
	//     matches the ContentPattern. ContentPattern may use one or more asterisk ('*")
	//     characters to represent 0 or more of any character.
	//     /C/ContentPattern -- Traverse the XML DOM tree (rooted at the caller) and
	//     navigate to the 1st node having any tag with content that matches the
	//     ContentPattern. ContentPattern may use one or more asterisk ('*") characters to
	//     represent 0 or more of any character.
	//     /A/TagName,AttrName,AttrValuePattern -- Traverse the XML DOM tree (rooted at
	//     the caller) and navigate to the 1st node having the given tag, and attribute,
	//     with the attribute value that matches the AttrValuePattern. AttrValuePattern may
	//     use one or more asterisk ('*") characters to represent 0 or more of any
	//     character.
	// The returnCommand can be any of the following:
	//     * -- Return the Content of the node.
	//     (AttrName) -- Return the value of the given attribute.
	//     $ -- Update the caller's internal reference to be the node (arrived at by
	//     following the series of commands). Returns an empty string.
	// 
	const char *chilkatPath(const char *pathCmd);

	// Removes all children, attributes, and content from the XML node. Resets the tag
	// name to "unnamed".
	void Clear(void);


	// Return true if the node's content matches a wildcarded pattern.
	bool ContentMatches(const char *pattern, bool caseSensitive);


	// Copies the tag, content, and attributes to the calling node.
	void Copy(CkXml &node);


	// Discards the caller's current internal reference and copies the internal
	// reference from copyFromNode. Effectively updates the caller node to point to the same
	// node in the XML document as copyFromNode.
	void CopyRef(CkXml &copyFromNode);


	// Decodes a node's Q or B-encoded content string and returns the byte data.
	bool DecodeContent(CkByteData &outData);


	// Utility method to decode HTML entities. It accepts a string containing
	// (potentially) HTML entities and returns a string with the entities decoded.
	bool DecodeEntities(const char *str, CkString &outStr);

	// Utility method to decode HTML entities. It accepts a string containing
	// (potentially) HTML entities and returns a string with the entities decoded.
	const char *decodeEntities(const char *str);

	// Decrypts the content of an XML node that was previously 128-bit AES encrypted
	// with the EncryptContent method.
	bool DecryptContent(const char *password);


	// Encrypts the content of the calling XML node using 128-bit CBC AES encryption.
	// The base64-encoded encrypted content replaces the original content.
	bool EncryptContent(const char *password);


	// Removes and returns the Nth child of an XML node. The first child is at index 0.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *ExtractChildByIndex(int index);


	// Removes and returns the first child node at the specified tag or tag path. The
	// attrName and attrValue may be empty, in which case the first child matching the tag is
	// removed and returned. If attrName is specified, then the first child having a tag
	// equal to tagPath, and an attribute with attrName is returned. If attrValue is also
	// specified, then only a child having a tag equal to tagPath, and an attribute named
	// attrName, with a value equal to attrValue is returned.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *ExtractChildByName(const char *tagPath, const char *attrName, const char *attrValue);


	// Returns the child with the given tag or at the specified tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *FindChild(const char *tagPath);


	// Updates the Xml object's internal reference to point to a child at the specified
	// tag or tagPath.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	bool FindChild2(const char *tagPath);


	// Returns the next record node where the child with a specific tag matches a
	// wildcarded pattern. This method makes it easy to iterate over high-level
	// records.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *FindNextRecord(const char *tagPath, const char *contentPattern);


	// First checks for a child at tagPath, and if found, returns it. Otherwise creates a
	// new child with empty content.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *FindOrAddNewChild(const char *tagPath);


	// Returns the first child. A program can step through the children by calling
	// FirstChild, and then NextSibling repeatedly.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *FirstChild(void);


	// Updates the internal reference of the caller to point to its first child.
	bool FirstChild2(void);


	// Returns the name of the Nth attribute of an XML node. The first attribute is at
	// index 0.
	bool GetAttributeName(int index, CkString &outStr);

	// Returns the name of the Nth attribute of an XML node. The first attribute is at
	// index 0.
	const char *getAttributeName(int index);
	// Returns the name of the Nth attribute of an XML node. The first attribute is at
	// index 0.
	const char *attributeName(int index);


	// Returns the value of the Nth attribute of an XML node. The first attribute is at
	// index 0.
	bool GetAttributeValue(int index, CkString &outStr);

	// Returns the value of the Nth attribute of an XML node. The first attribute is at
	// index 0.
	const char *getAttributeValue(int index);
	// Returns the value of the Nth attribute of an XML node. The first attribute is at
	// index 0.
	const char *attributeValue(int index);


	// Returns an attribute as an integer. Returns 0 if the attribute does not exist.
	int GetAttributeValueInt(int index);


	// Find and return the value of an attribute having a specified name.
	bool GetAttrValue(const char *name, CkString &outStr);

	// Find and return the value of an attribute having a specified name.
	const char *getAttrValue(const char *name);
	// Find and return the value of an attribute having a specified name.
	const char *attrValue(const char *name);


	// Returns an attribute as an integer. Returns 0 if the attribute does not exist.
	int GetAttrValueInt(const char *name);


	// Returns binary content of an XML node as a byte array. The content may have been
	// Zip compressed, AES encrypted, or both. Unzip compression and AES decryption
	// flags should be set appropriately.
	bool GetBinaryContent(bool unzipFlag, bool decryptFlag, const char *password, CkByteData &outData);


	// Returns the Nth child of an XML node
	// The caller is responsible for deleting the object returned by this method.
	CkXml *GetChild(int index);


	// Updates the calling object's internal reference to the Nth child node.
	bool GetChild2(int index);


	// Returns the content of a descendant child having a specified attribute. The tagPath
	// can be a tag or a tag path.
	bool GetChildAttrValue(const char *tagPath, const char *attrName, CkString &outStr);

	// Returns the content of a descendant child having a specified attribute. The tagPath
	// can be a tag or a tag path.
	const char *getChildAttrValue(const char *tagPath, const char *attrName);
	// Returns the content of a descendant child having a specified attribute. The tagPath
	// can be a tag or a tag path.
	const char *childAttrValue(const char *tagPath, const char *attrName);


	// Returns false if the node's content is "0", otherwise returns true if the
	// node contains a non-zero integer. The tagPath can be a tag or a tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "colors|primary|red".
	// 
	bool GetChildBoolValue(const char *tagPath);


	// Returns the content of a child having a specified tag. The tagPath can be a tag or
	// a tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "colors|primary|red".
	// 
	bool GetChildContent(const char *tagPath, CkString &outStr);

	// Returns the content of a child having a specified tag. The tagPath can be a tag or
	// a tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "colors|primary|red".
	// 
	const char *getChildContent(const char *tagPath);
	// Returns the content of a child having a specified tag. The tagPath can be a tag or
	// a tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "colors|primary|red".
	// 
	const char *childContent(const char *tagPath);


	// Returns the content of the Nth child node.
	bool GetChildContentByIndex(int index, CkString &outStr);

	// Returns the content of the Nth child node.
	const char *getChildContentByIndex(int index);
	// Returns the content of the Nth child node.
	const char *childContentByIndex(int index);


	// Returns the content of the XML element at the tagPath. The XML element's content is
	// appended to the sb.
	bool GetChildContentSb(const char *tagPath, CkStringBuilder &sb);


	// Returns the child having the exact tag and content.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *GetChildExact(const char *tag, const char *content);


	// Returns the child integer content for a given tag. The tagPath can be a tag or a
	// tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "colors|primary|red".
	// 
	int GetChildIntValue(const char *tagPath);


	// Returns the tag name of the Nth child node.
	bool GetChildTag(int index, CkString &outStr);

	// Returns the tag name of the Nth child node.
	const char *getChildTag(int index);
	// Returns the tag name of the Nth child node.
	const char *childTag(int index);


	// Returns the tag name of the Nth child node.
	bool GetChildTagByIndex(int index, CkString &outStr);

	// Returns the tag name of the Nth child node.
	const char *getChildTagByIndex(int index);
	// Returns the tag name of the Nth child node.
	const char *childTagByIndex(int index);


	// Finds and returns the XML child node having both a given tag and an attribute
	// with a given name and value.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *GetChildWithAttr(const char *tagPath, const char *attrName, const char *attrValue);


	// Returns the first child found having the exact content specified.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *GetChildWithContent(const char *content);


	// Returns the child at the specified tag or tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *GetChildWithTag(const char *tagPath);


	// Returns the Nth child having a tag that matches exactly with the tagName. Use
	// the NumChildrenHavingTag method to determine how many children have a particular
	// tag.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *GetNthChildWithTag(const char *tag, int n);


	// Updates the calling object's internal reference to the Nth child node having a
	// specific tag.
	bool GetNthChildWithTag2(const char *tag, int n);


	// Returns the parent of this XML node, or NULL if the node is the root of the
	// tree.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *GetParent(void);


	// Updates the internal reference of the caller to its parent.
	bool GetParent2(void);


	// Returns the root node of the XML document
	// The caller is responsible for deleting the object returned by this method.
	CkXml *GetRoot(void);


	// Updates the internal reference of the caller to the document root.
	void GetRoot2(void);


	// Returns a new XML object instance that references the same XML node.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *GetSelf(void);


	// Generate the XML text document for the XML tree rooted at this node. If called
	// from the root node of the XML document, then the XML declarator ("_LT_?xml
	// version="1.0" encoding="utf-8" ?>") is included at the beginning of the XML.
	// Otherwise, it is not included.
	bool GetXml(CkString &outStr);

	// Generate the XML text document for the XML tree rooted at this node. If called
	// from the root node of the XML document, then the XML declarator ("_LT_?xml
	// version="1.0" encoding="utf-8" ?>") is included at the beginning of the XML.
	// Otherwise, it is not included.
	const char *getXml(void);
	// Generate the XML text document for the XML tree rooted at this node. If called
	// from the root node of the XML document, then the XML declarator ("_LT_?xml
	// version="1.0" encoding="utf-8" ?>") is included at the beginning of the XML.
	// Otherwise, it is not included.
	const char *xml(void);


	// Emits (appends) the XML to the contents of bd.
	bool GetXmlBd(CkBinData &bd);


	// Emits the XML to a StringBuilder object. (Appends to the existing contents of
	// sb.)
	bool GetXmlSb(CkStringBuilder &sb);


	// Returns true if the node contains an attribute with the specified name.
	bool HasAttribute(const char *name);


	// Returns true if the node contains attribute with the name and value.
	bool HasAttrWithValue(const char *name, const char *value);


	// Returns true if the node has a direct child node containing the exact content
	// string specified.
	bool HasChildWithContent(const char *content);


	// Returns true if the node has a child with the given tag (or tag path).
	// Otherwise returns false.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	bool HasChildWithTag(const char *tagPath);


	// Returns true if the node contains child with the given tag (or tag path) and
	// content specified.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	bool HasChildWithTagAndContent(const char *tagPath, const char *content);


	// Adds an entire subtree as a child. If the child was a subtree within another Xml
	// document then the subtree is effectively transferred from one XML document to
	// another. The child tree is inserted in a position after the Nth child (of the
	// calling node).
	void InsertChildTreeAfter(int index, CkXml &tree);


	// Adds an entire subtree as a child. If the child was a subtree within another Xml
	// document then the subtree is effectively transferred from one XML document to
	// another. The child tree is inserted in a position before the Nth child (of the
	// calling node).
	void InsertChildTreeBefore(int index, CkXml &tree);


	// Returns the last Xml child node. A node's children can be enumerated by calling
	// LastChild and then repeatedly calling PreviousSibling, until a NULL is returned.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *LastChild(void);


	// Updates the internal reference of the caller to its last child.
	bool LastChild2(void);


	// Loads XML from the contents of bd. If autoTrim is true, then each element's text
	// content is trimmed of leading and trailing whitespace.
	bool LoadBd(CkBinData &bd, bool autoTrim);


	// Loads XML from the contents of a StringBuilder object.
	bool LoadSb(CkStringBuilder &sb, bool autoTrim);


	// Loads an XML document from a memory buffer and returns true if successful. The
	// contents of the calling node are replaced with the root node of the XML document
	// loaded.
	bool LoadXml(const char *xmlData);


	// Same as LoadXml, but an additional argument controls whether or not
	// leading/trailing whitespace is auto-trimmed from each leaf node's content.
	bool LoadXml2(const char *xmlData, bool autoTrim);


	// Loads an XML document from a file and returns true if successful. The contents
	// of the calling node are replaced with the root node of the XML document loaded.
	bool LoadXmlFile(const char *fileName);


	// Same as LoadXmlFile, but an additional argument controls whether or not
	// leading/trailing whitespace is auto-trimmed from each leaf node's content.
	bool LoadXmlFile2(const char *fileName, bool autoTrim);


	// Creates a new child having tag and content. The new child is created even if a
	// child with a tag equal to tagPath already exists. (Use FindOrAddNewChild to prevent
	// creating children having the same tags.)
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "colors|primary|red". See the example below for details.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *NewChild(const char *tagPath, const char *content);


	// Creates a new child node, but does not return the node that is created. The tagPath
	// can be a tag or a tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "colors|primary|red". See the example below for details.
	// 
	void NewChild2(const char *tagPath, const char *content);


	// Inserts a new child in a position after the Nth child node.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *NewChildAfter(int index, const char *tag, const char *content);


	// Inserts a new child in a position before the Nth child node.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *NewChildBefore(int index, const char *tag, const char *content);


	// Inserts a new child having an integer for content. The tagPath can be a tag or a
	// tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "colors|primary|red". See the example below for details.
	// 
	void NewChildInt2(const char *tagPath, int value);


	// Updates to Xml object's internal reference to the next node in a depth-first
	// traversal. (This method name, NextInTraversal2, ends with "2" to signify that
	// the internal reference is updated. There is no "NextInTraversal" method.)
	// 
	// The sbState contains the current state of the traversal. sbState should be empty when
	// beginning a traversal.
	// 
	bool NextInTraversal2(CkStringBuilder &sbState);


	// Returns the nodes next sibling, or NULL if there are no more.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *NextSibling(void);


	// Updates the internal reference of the caller to its next sibling.
	bool NextSibling2(void);


	// Returns the number of children for the node indicated by tagPath. Returns -1 if the
	// node at tagPath does not exist.
	int NumChildrenAt(const char *tagPath);


	// Returns the number of children having a specific tag name.
	int NumChildrenHavingTag(const char *tag);


	// Returns the Xml object that is the node's previous sibling, or NULL if there are
	// no more.
	// The caller is responsible for deleting the object returned by this method.
	CkXml *PreviousSibling(void);


	// Updates the internal reference of the caller to its previous sibling.
	bool PreviousSibling2(void);


	// Recursively descends the XML from this node and removes all occurrences of the
	// specified attribute. Returns the number of attribute occurrences removed.
	int PruneAttribute(const char *attrName);


	// Recursively descends the XML from this node and removes all occurrences of the
	// specified tag, including all descendents of each removed node. Returns the
	// number of tag occurrences removed.
	int PruneTag(const char *tag);


	// Sets the node's content with 8bit data that is in a specified multibyte
	// character encoding such as utf-8, shift-jis, big5, etc. The data is first
	// Q-encoded and the content is set to be the Q-encoded string. For example, if
	// called with "gb2312"for the charset, you would get a string that looks something
	// like this: "=?gb2312?Q?=C5=B5=BB=F9?=". Character that are not 7bit are
	// represented as "=XX" where XX is the hexidecimal value of the byte. Use the
	// DecodeContent method to retrieve the byte data from a Q encoded string.
	bool QEncodeContent(const char *charset, CkByteData &inData);


	// Removes all attributes from an XML node. Should always return True.
	bool RemoveAllAttributes(void);


	// Removes all children from the calling node.
	void RemoveAllChildren(void);


	// Removes an attribute by name from and XML node.
	bool RemoveAttribute(const char *name);


	// Removes all children with a given tag or tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	void RemoveChild(const char *tagPath);


	// Removes the Nth child from the calling node.
	void RemoveChildByIndex(int index);


	// Removes all children having the exact content specified.
	void RemoveChildWithContent(const char *content);


	// Removes the calling object and its sub-tree from the XML document making it the
	// root of its own tree.
	void RemoveFromTree(void);


	// Removes all XML stylesheets having an attribute with attrName equal to attrValue. Returns
	// the number of stylesheets removed, or -1 if there was an error.
	int RemoveStyleSheet(const char *attrName, const char *attrValue);


	// Saves a node's binary content to a file.
	bool SaveBinaryContent(const char *filename, bool unzipFlag, bool decryptFlag, const char *password);


	// Generates XML representing the tree or subtree rooted at this node and writes it
	// to a file.
	bool SaveXml(const char *fileName);


	// Recursively traverses the XML rooted at the caller and scrubs according to the
	// instructions in the comma separated directives. The currently defined directives are:
	//     "AttrTrimEnds" - Leading and trailing whitespace removed from attribute
	//     values.
	//     "AttrTrimInside" - Replace all tabs, CR's, and LF's with SPACE chars, and
	//     removes extra SPACE chars so that no more than one SPACE char in a row exists.
	//     "ContentTrimEnds" - Same as AttrTrimEnds but for content.
	//     "ContentTrimInside" - Same as AttrTrimInside but for content.
	//     "LowercaseAttrs" - Convert all attribute names to lowercase.
	//     "LowercaseTags" - Convert all tags to lowercase.
	//     "RemoveCtrl" - Remove non-printable us-ascii control chars (us-ascii values
	// 
	// If you have other ideas for useful XML scrubbing directives, send email to
	// support@chilkatsoft.com. It must be general enough such that many developers
	// will find it useful.
	// 
	void Scrub(const char *directives);


	// Returns the first node having content matching the contentPattern. The contentPattern is a
	// case-sensitive string that may contain any number of '*'s, each representing 0
	// or more occurrences of any character. The search is breadth-first over the
	// sub-tree rooted at the caller. A match is returned only after the search has
	// traversed past the node indicated by afterPtr. To find the 1st occurrence, set afterPtr
	// equal to _NULL_. (For the ActiveX implementation, the afterPtr should never be
	// _NULL_. A reference to the caller's node should be passed instead.)
	// 
	// To iterate over matching nodes, the returned node can be passed in afterPtr for the
	// next call to SearchAllForContent, until the method returns _NULL_.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *SearchAllForContent(CkXml *afterPtr, const char *contentPattern);


	// Same as SearchAllForContent except the internal reference of the caller is
	// updated to point to the search result (instead of returning a new object).
	bool SearchAllForContent2(CkXml *afterPtr, const char *contentPattern);


	// Returns the first node having a tag equal to tag, an attribute named attr,
	// whose value matches valuePattern. The valuePattern is a case-sensitive string that may contain
	// any number of '*'s, each representing 0 or more occurrences of any character.
	// The search is breadth-first over the sub-tree rooted at the caller. A match is
	// returned only after the search has traversed past the node indicated by afterPtr. To
	// find the 1st occurrence, set afterPtr equal to _NULL_. (For the ActiveX
	// implementation, the afterPtr should never be _NULL_. A reference to the caller's
	// node should be passed instead.)
	// 
	// To iterate over matching nodes, the returned node can be passed in afterPtr for the
	// next call to SearchForAttribute, until the method returns _NULL_.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *SearchForAttribute(CkXml *afterPtr, const char *tag, const char *attr, const char *valuePattern);


	// Same as SearchForAttribute except the internal reference of the caller is
	// updated to point to the search result (instead of returning a new object).
	bool SearchForAttribute2(CkXml *afterPtr, const char *tag, const char *attr, const char *valuePattern);


	// Returns the first node having a tag equal to tag, whose content matches contentPattern.
	// The contentPattern is a case-sensitive string that may contain any number of '*'s, each
	// representing 0 or more occurrences of any character. The search is breadth-first
	// over the sub-tree rooted at the caller. A match is returned only after the
	// search has traversed past the node indicated by afterPtr. To find the 1st
	// occurrence, set afterPtr equal to _NULL_. (For the ActiveX implementation, the afterPtr
	// should never be _NULL_. A reference to the caller's node should be passed
	// instead.)
	// 
	// To iterate over matching nodes, the returned node can be passed in afterPtr for the
	// next call to SearchForContent, until the method returns _NULL_.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *SearchForContent(CkXml *afterPtr, const char *tag, const char *contentPattern);


	// Same as SearchForContent except the internal reference of the caller is updated
	// to point to the search result (instead of returning a new object).
	bool SearchForContent2(CkXml *afterPtr, const char *tag, const char *contentPattern);


	// Returns the first node having a tag equal to tag. The search is breadth-first
	// over the sub-tree rooted at the caller. A match is returned only after the
	// search has traversed past the node indicated by afterPtr. To find the 1st
	// occurrence, set afterPtr equal to _NULL_. (For the ActiveX implementation, the afterPtr
	// should never be _NULL_. A reference to the caller's node should be passed
	// instead.)
	// 
	// To iterate over matching nodes, the returned node can be passed in afterPtr for the
	// next call to SearchForTag, until the method returns _NULL_.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkXml *SearchForTag(CkXml *afterPtr, const char *tag);


	// Same as SearchForTag except the internal reference of the caller is updated to
	// point to the search result (instead of returning a new object).
	bool SearchForTag2(CkXml *afterPtr, const char *tag);


	// Sets the node's content to a block of binary data with optional Zip compression
	// and/or AES encryption. The binary data is automatically converted to base64
	// format whenever XML text is generated. If the zipFlag is True, the data is first
	// compressed. If the encryptFlag is True, the data is AES encrypted using the
	// Rijndael 128-bit symmetric-encryption algorithm.
	bool SetBinaryContent(CkByteData &inData, bool zipFlag, bool encryptFlag, const char *password);


#if !defined(CHILKAT_MONO)
	// The same as SetBinaryContent but the data is provided via a pointer and byte
	// count.
	bool SetBinaryContent2(const void *pByteData, unsigned long szByteData, bool zipFlag, bool encryptFlag, const char *password);

#endif

	// Sets the node's content with binary (or text) data from a file. The file
	// contents can be Zip compressed and/or encrypted, and the result is base-64
	// encoded.
	bool SetBinaryContentFromFile(const char *filename, bool zipFlag, bool encryptFlag, const char *password);


	// Sorts the direct child nodes by the value of a specified attribute.
	void SortByAttribute(const char *attrName, bool ascending);


	// Sorts the direct child nodes by the value of a specified attribute interpreted
	// as an integer (not lexicographically as strings).
	void SortByAttributeInt(const char *attrName, bool ascending);


	// Sorts the direct child nodes by content.
	void SortByContent(bool ascending);


	// Sorts the direct child nodes by tag.
	void SortByTag(bool ascending);


	// Sorts the direct child nodes by the content of an attribute in the grandchild
	// nodes.
	void SortRecordsByAttribute(const char *sortTag, const char *attrName, bool ascending);


	// Sorts the direct child nodes by the content of the grandchild nodes.
	void SortRecordsByContent(const char *sortTag, bool ascending);


	// Sorts the direct child nodes by the content of the grandchild nodes. For sorting
	// purposes, the content is interpreted as an integer (not lexicographically as for
	// strings).
	void SortRecordsByContentInt(const char *sortTag, bool ascending);


	// Swaps another node's tag, content, and attributes with this one.
	bool SwapNode(CkXml &node);


	// Swaps another node's tag, content, attributes, and children with this one.
	bool SwapTree(CkXml &tree);


	// Returns the content of the 1st node found in the sub-tree rooted at the caller
	// that has a given tag. (Note: The search for the node having tag ARG is not
	// limited to the direct children of the caller.)
	bool TagContent(const char *tagName, CkString &outStr);

	// Returns the content of the 1st node found in the sub-tree rooted at the caller
	// that has a given tag. (Note: The search for the node having tag ARG is not
	// limited to the direct children of the caller.)
	const char *tagContent(const char *tagName);

	// Returns true if the node's tag equals the specified string.
	bool TagEquals(const char *tag);


	// Returns the index of the XML node with the given tag. Returns -1 if no node
	// having the specified tag is found at the tagPath.
	int TagIndex(const char *tagPath);


	// Returns true if the node's tag namespace prefix equals the specified ns.
	bool TagNsEquals(const char *ns);


	// Returns true if the node's unprefixed tag equals the specified string. For
	// example, if the tag is "soapenv:Body", the unprefixed tag is "Body".
	bool TagUnpEquals(const char *unprefixedTag);


	// Unzip the content of the XML node replacing it's content with the decompressed
	// data.
	bool UnzipContent(void);


	// Unzips and recreates the XML node and the entire subtree, restoring it to the
	// state before it was zip compressed.
	bool UnzipTree(void);


	// Updates the content for the node indicated by tagPath. If autoCreate is true, then
	// nodes along tagPath are auto-created as needed.
	bool UpdateAt(const char *tagPath, bool autoCreate, const char *value);


	// Updates or adds the attribute value for the node indicated by tagPath. If autoCreate is
	// true, then nodes along tagPath are auto-created as needed.
	bool UpdateAttrAt(const char *tagPath, bool autoCreate, const char *attrName, const char *attrValue);


	// Adds an attribute to the node if it doesn't already exist. Otherwise it updates
	// the existing attribute with the new value.
	bool UpdateAttribute(const char *attrName, const char *attrValue);


	// Updates an attribute value. (Call UpdateAttribute if the attribute value is a
	// string.)
	bool UpdateAttributeInt(const char *attrName, int value);


	// Replaces the content of a child node. The tagPath can be a tag or tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC". The nodes in the tagPath are automatically created as needed.
	// 
	void UpdateChildContent(const char *tagPath, const char *value);


	// Replaces the content of a child node where the content is an integer. The tagPath
	// can be a tag or tag path.
	// 
	// Beginning in version 9.5.0.64, the tagPath can be a tag path. A tag path is a
	// series of tags separated by vertical bar characters. For example:
	// "tagA|tagB|tagC".
	// 
	void UpdateChildContentInt(const char *tagPath, int value);


	// Applies Zip compression to the content of an XML node and replaces the content
	// with base64-encoded compressed data.
	bool ZipContent(void);


	// Zip compresses the content and entire subtree rooted at the calling XML node and
	// replaces the current content with base64-encoded Zip compressed data. The node
	// and subtree can be restored by calling UnzipTree. Note that the node name and
	// attributes are unaffected.
	bool ZipTree(void);






	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
