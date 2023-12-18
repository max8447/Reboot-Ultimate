// CkDnsW.h: interface for the CkDnsW class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#ifndef _CkDnsW_H
#define _CkDnsW_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacksW.h"

class CkJsonObjectW;
class CkTaskW;
class CkBaseProgressW;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkDnsW
class CK_VISIBLE_PUBLIC CkDnsW  : public CkClassWithCallbacksW
{
	private:
	bool m_cbOwned;

	private:
	
	// Don't allow assignment or copying these objects.
	CkDnsW(const CkDnsW &);
	CkDnsW &operator=(const CkDnsW &);

    public:
	CkDnsW(void);
	virtual ~CkDnsW(void);

	

	static CkDnsW *createNew(void);
	

	CkDnsW(bool bCallbackOwned);
	static CkDnsW *createNew(bool bCallbackOwned);

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	CkBaseProgressW *get_EventCallbackObject(void) const;
	void put_EventCallbackObject(CkBaseProgressW *progress);


	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The number of milliseconds between each AbortCheck event callback. The
	// AbortCheck callback allows an application to abort any DNS operation prior to
	// completion. If HeartbeatMs is 0 (the default), no AbortCheck event callbacks
	// will fire.
	int get_HeartbeatMs(void);
	// The number of milliseconds between each AbortCheck event callback. The
	// AbortCheck callback allows an application to abort any DNS operation prior to
	// completion. If HeartbeatMs is 0 (the default), no AbortCheck event callbacks
	// will fire.
	void put_HeartbeatMs(int newVal);

	// The maxiumum number of milliseconds to wait for the answer to a DNS query. A
	// value of 0 is to wait indefinitely (no timeout). It's not a good idea to specify
	// 0 (infinite timeout) or a value less than 1000 (1 second). The default value is
	// 10000 milliseconds.
	int get_MaxWaitMs(void);
	// The maxiumum number of milliseconds to wait for the answer to a DNS query. A
	// value of 0 is to wait indefinitely (no timeout). It's not a good idea to specify
	// 0 (infinite timeout) or a value less than 1000 (1 second). The default value is
	// 10000 milliseconds.
	void put_MaxWaitMs(int newVal);

	// The number of nameservers currently being used by Chilkat for DNS queries in all
	// objects/classes, such as for HTTP, Email, FTP, SSH, etc.
	int get_NumNameservers(void);

	// Specifies the TLS preference. Possible values are:
	//     0 = No TLS
	//     1 = Prefer TLS if possible.
	//     2 = Require TLS
	// 
	// The default value is 0. If TLS is preferred then DNS nameservers with TLS
	// capability will be tried first. If none succeed, then UDP/TCP will be tried. If
	// TLS is required, then only TLS capable nameservers will be tried and all DNS
	// queries will use TLS.
	// 
	// Note: To use TLS, your application needs to first specify nameservers by calling
	// AddNameserver once per nameserver with the supportsTls argument set to true.
	// 
	int get_TlsPref(void);
	// Specifies the TLS preference. Possible values are:
	//     0 = No TLS
	//     1 = Prefer TLS if possible.
	//     2 = Require TLS
	// 
	// The default value is 0. If TLS is preferred then DNS nameservers with TLS
	// capability will be tried first. If none succeed, then UDP/TCP will be tried. If
	// TLS is required, then only TLS capable nameservers will be tried and all DNS
	// queries will use TLS.
	// 
	// Note: To use TLS, your application needs to first specify nameservers by calling
	// AddNameserver once per nameserver with the supportsTls argument set to true.
	// 
	void put_TlsPref(int newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Adds the default (auto-assigned) nameservers to the collection of nameservers
	// used by Chilkat for DNS queries and domain to IP address lookups.
	void AddDefaultNameservers(void);

	// Adds a new nameserver to the collection of nameservers used by Chilkat for DNS
	// queries and domain to IP address lookups. The ipAddr specifies the IPv4 address of
	// the nameserver. The supportsTls indicates if the namserver supports DoT (DNS over TLS.
	// DoT uses port 853 for encrypted DNS communication.) If the TlsPreference
	// property is set to 1 or 2, then Chilkat will use TLS nameservers.
	void AddNameserver(const wchar_t *ipAddr, bool supportsTls);

	// Returns the IP address of the Nth nameserver currently used by Chilkat for DNS
	// queries and domain to IP address lookups. The index specifies the index of the
	// nameserver. The 1st nameserver is at index 0.
	bool GetNameserver(int index, CkString &outStr);
	// Returns the IP address of the Nth nameserver currently used by Chilkat for DNS
	// queries and domain to IP address lookups. The index specifies the index of the
	// nameserver. The 1st nameserver is at index 0.
	const wchar_t *getNameserver(int index);
	// Returns the IP address of the Nth nameserver currently used by Chilkat for DNS
	// queries and domain to IP address lookups. The index specifies the index of the
	// nameserver. The 1st nameserver is at index 0.
	const wchar_t *nameserver(int index);

	// Performs an DNS query for domain and returns the answer in answer. The type of DNS
	// query is specified in recordType and can be A, AAAA, ALIAS, CAA, MX, NS, SOA, TXT.
	// Additional record types can be added as needed.
	bool Query(const wchar_t *recordType, const wchar_t *domain, CkJsonObjectW &answer);

	// Creates an asynchronous task to call the Query method with the arguments
	// provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskW *QueryAsync(const wchar_t *recordType, const wchar_t *domain, CkJsonObjectW &answer);

	// Removes all nameservers from the collection of nameservers used by Chilkat. An
	// application can call this method to reset to 0 nameservers before adding new
	// nameservers. If a DNS domain to IP address resolution is needed by Chilkat, then
	// the auto-assigned nameserver IP addresses will be automaticaly restored.
	void RemoveAllNameservers(void);

	// Removes a nameserver from the collection of nameservers used by Chilkat. The
	// ipAddr is the IPv4 address of the nameserver to be removed.
	void RemoveNameserver(const wchar_t *ipAddr);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
