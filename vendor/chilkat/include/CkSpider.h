// CkSpider.h: interface for the CkSpider class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#define _CkVersion 9.5.0.96

#ifndef _CkSpider_H
#define _CkSpider_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacks.h"

class CkTask;
class CkBaseProgress;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif


#undef Copy

// CLASS: CkSpider
class CK_VISIBLE_PUBLIC CkSpider  : public CkClassWithCallbacks
{
    private:

	// Don't allow assignment or copying these objects.
	CkSpider(const CkSpider &);
	CkSpider &operator=(const CkSpider &);

    public:
	CkSpider(void);
	virtual ~CkSpider(void);

	static CkSpider *createNew(void);
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	
		
	CkBaseProgress *get_EventCallbackObject(void) const;
	void put_EventCallbackObject(CkBaseProgress *progress);


	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// When set to true, causes the currently running method to abort. Methods that
	// always finish quickly (i.e.have no length file operations or network
	// communications) are not affected. If no method is running, then this property is
	// automatically reset to false when the next method is called. When the abort
	// occurs, this property is reset to false. Both synchronous and asynchronous
	// method calls can be aborted. (A synchronous method call could be aborted by
	// setting this property from a separate thread.)
	bool get_AbortCurrent(void);
	// When set to true, causes the currently running method to abort. Methods that
	// always finish quickly (i.e.have no length file operations or network
	// communications) are not affected. If no method is running, then this property is
	// automatically reset to false when the next method is called. When the abort
	// occurs, this property is reset to false. Both synchronous and asynchronous
	// method calls can be aborted. (A synchronous method call could be aborted by
	// setting this property from a separate thread.)
	void put_AbortCurrent(bool newVal);

	// If set the 1 (true) the spider will avoid all HTTPS URLs. The default is 0
	// (false).
	bool get_AvoidHttps(void);
	// If set the 1 (true) the spider will avoid all HTTPS URLs. The default is 0
	// (false).
	void put_AvoidHttps(bool newVal);

	// Specifies a cache directory to use for spidering. If either of the
	// FetchFromCache or UpdateCache properties are true, this is the location of the
	// cache to be used. Note: the Internet Explorer, Netscape, and FireFox caches are
	// completely separate from the Chilkat Spider cache directory. You should specify
	// a new and empty directory.
	void get_CacheDir(CkString &str);
	// Specifies a cache directory to use for spidering. If either of the
	// FetchFromCache or UpdateCache properties are true, this is the location of the
	// cache to be used. Note: the Internet Explorer, Netscape, and FireFox caches are
	// completely separate from the Chilkat Spider cache directory. You should specify
	// a new and empty directory.
	const char *cacheDir(void);
	// Specifies a cache directory to use for spidering. If either of the
	// FetchFromCache or UpdateCache properties are true, this is the location of the
	// cache to be used. Note: the Internet Explorer, Netscape, and FireFox caches are
	// completely separate from the Chilkat Spider cache directory. You should specify
	// a new and empty directory.
	void put_CacheDir(const char *newVal);

	// If equal to 1 (true), then the query portion of all URLs are automatically
	// removed when adding to the unspidered list. The default value is 0 (false).
	bool get_ChopAtQuery(void);
	// If equal to 1 (true), then the query portion of all URLs are automatically
	// removed when adding to the unspidered list. The default value is 0 (false).
	void put_ChopAtQuery(bool newVal);

	// The maximum number of seconds to wait while connecting to an HTTP server.
	int get_ConnectTimeout(void);
	// The maximum number of seconds to wait while connecting to an HTTP server.
	void put_ConnectTimeout(int newVal);

	// The domain name that is being spidered. This is the domain previously set in the
	// Initialize method.
	void get_Domain(CkString &str);
	// The domain name that is being spidered. This is the domain previously set in the
	// Initialize method.
	const char *domain(void);

	// If equal to 1 (true) then pages are fetched from cache when possible. If 0, the
	// cache is ignored. The default value is 1. Regardless, if no CacheDir is set then
	// the cache is not used.
	bool get_FetchFromCache(void);
	// If equal to 1 (true) then pages are fetched from cache when possible. If 0, the
	// cache is ignored. The default value is 1. Regardless, if no CacheDir is set then
	// the cache is not used.
	void put_FetchFromCache(bool newVal);

	// If the last URL crawled was redirected (as indicated by the WasRedirected
	// property), this property will contain the final redirect URL.
	void get_FinalRedirectUrl(CkString &str);
	// If the last URL crawled was redirected (as indicated by the WasRedirected
	// property), this property will contain the final redirect URL.
	const char *finalRedirectUrl(void);

	// The number of milliseconds between each AbortCheck event callback. The
	// AbortCheck callback allows an application to abort any method call prior to
	// completion. If HeartbeatMs is 0 (the default), no AbortCheck event callbacks
	// will fire.
	int get_HeartbeatMs(void);
	// The number of milliseconds between each AbortCheck event callback. The
	// AbortCheck callback allows an application to abort any method call prior to
	// completion. If HeartbeatMs is 0 (the default), no AbortCheck event callbacks
	// will fire.
	void put_HeartbeatMs(int newVal);

	// Equal to 1 if the last page spidered was fetched from the cache. Otherwise equal
	// to 0.
	bool get_LastFromCache(void);

	// The HTML text of the last paged fetched by the spider.
	void get_LastHtml(CkString &str);
	// The HTML text of the last paged fetched by the spider.
	const char *lastHtml(void);

	// The HTML META description from the last page fetched by the spider.
	void get_LastHtmlDescription(CkString &str);
	// The HTML META description from the last page fetched by the spider.
	const char *lastHtmlDescription(void);

	// The HTML META keywords from the last page fetched by the spider.
	void get_LastHtmlKeywords(CkString &str);
	// The HTML META keywords from the last page fetched by the spider.
	const char *lastHtmlKeywords(void);

	// The HTML title from the last page fetched by the spider.
	void get_LastHtmlTitle(CkString &str);
	// The HTML title from the last page fetched by the spider.
	const char *lastHtmlTitle(void);

	// The last-modification date of the last URL spidered.
	void get_LastModDate(SYSTEMTIME &outSysTime);

	// The last modification date/time from the last page fetched by the spider.
	void get_LastModDateStr(CkString &str);
	// The last modification date/time from the last page fetched by the spider.
	const char *lastModDateStr(void);

	// The URL of the last page spidered.
	void get_LastUrl(CkString &str);
	// The URL of the last page spidered.
	const char *lastUrl(void);

	// The maximum HTTP response size allowed. The spider will automatically fail any
	// pages larger than this size. The default value is 250,000 bytes.
	int get_MaxResponseSize(void);
	// The maximum HTTP response size allowed. The spider will automatically fail any
	// pages larger than this size. The default value is 250,000 bytes.
	void put_MaxResponseSize(int newVal);

	// The maximum URL length allowed. URLs longer than this are not added to the
	// unspidered list. The default value is 200.
	int get_MaxUrlLen(void);
	// The maximum URL length allowed. URLs longer than this are not added to the
	// unspidered list. The default value is 200.
	void put_MaxUrlLen(int newVal);

	// The number of avoid patterns previously set by calling AddAvoidPattern.
	int get_NumAvoidPatterns(void);

	// The number of URLs in the object's failed URL list.
	int get_NumFailed(void);

	// The number of URLs in the object's outbound links URL list.
	int get_NumOutboundLinks(void);

	// The number of URLs in the object's already-spidered URL list.
	int get_NumSpidered(void);

	// The number of URLs in the object's unspidered URL list.
	int get_NumUnspidered(void);

	// If true, then use IPv6 over IPv4 when both are supported for a particular
	// domain. The default value of this property is false, which will choose IPv4
	// over IPv6.
	bool get_PreferIpv6(void);
	// If true, then use IPv6 over IPv4 when both are supported for a particular
	// domain. The default value of this property is false, which will choose IPv4
	// over IPv6.
	void put_PreferIpv6(bool newVal);

	// The domain name of a proxy host if an HTTP proxy is used.
	void get_ProxyDomain(CkString &str);
	// The domain name of a proxy host if an HTTP proxy is used.
	const char *proxyDomain(void);
	// The domain name of a proxy host if an HTTP proxy is used.
	void put_ProxyDomain(const char *newVal);

	// If an HTTP proxy is used and it requires authentication, this property specifies
	// the HTTP proxy login.
	void get_ProxyLogin(CkString &str);
	// If an HTTP proxy is used and it requires authentication, this property specifies
	// the HTTP proxy login.
	const char *proxyLogin(void);
	// If an HTTP proxy is used and it requires authentication, this property specifies
	// the HTTP proxy login.
	void put_ProxyLogin(const char *newVal);

	// If an HTTP proxy is used and it requires authentication, this property specifies
	// the HTTP proxy password.
	void get_ProxyPassword(CkString &str);
	// If an HTTP proxy is used and it requires authentication, this property specifies
	// the HTTP proxy password.
	const char *proxyPassword(void);
	// If an HTTP proxy is used and it requires authentication, this property specifies
	// the HTTP proxy password.
	void put_ProxyPassword(const char *newVal);

	// The port number of a proxy server if an HTTP proxy is used.
	int get_ProxyPort(void);
	// The port number of a proxy server if an HTTP proxy is used.
	void put_ProxyPort(int newVal);

	// The maximum number of seconds to wait when reading from an HTTP server.
	int get_ReadTimeout(void);
	// The maximum number of seconds to wait when reading from an HTTP server.
	void put_ReadTimeout(int newVal);

	// If equal to 1 (true) then pages saved to the cache. If 0, the cache is ignored.
	// The default value is 1. Regardless, if no CacheDir is set then the cache is not
	// used.
	bool get_UpdateCache(void);
	// If equal to 1 (true) then pages saved to the cache. If 0, the cache is ignored.
	// The default value is 1. Regardless, if no CacheDir is set then the cache is not
	// used.
	void put_UpdateCache(bool newVal);

	// The value of the HTTP user-agent header field to be sent with HTTP requests.
	// This can be set to any desired value, but be aware that some websites may reject
	// requests from unknown user agents.
	void get_UserAgent(CkString &str);
	// The value of the HTTP user-agent header field to be sent with HTTP requests.
	// This can be set to any desired value, but be aware that some websites may reject
	// requests from unknown user agents.
	const char *userAgent(void);
	// The value of the HTTP user-agent header field to be sent with HTTP requests.
	// This can be set to any desired value, but be aware that some websites may reject
	// requests from unknown user agents.
	void put_UserAgent(const char *newVal);

	// Indicates whether the last URL crawled was redirected. (true = yes, false =
	// no)
	bool get_WasRedirected(void);

	// The "wind-down" phase begins when this number of URLs has been spidered. When in
	// the wind-down phase, no new URLs are added to the unspidered list. The default
	// value is 0 which means that there is NO wind-down phase.
	int get_WindDownCount(void);
	// The "wind-down" phase begins when this number of URLs has been spidered. When in
	// the wind-down phase, no new URLs are added to the unspidered list. The default
	// value is 0 which means that there is NO wind-down phase.
	void put_WindDownCount(int newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Adds a wildcarded pattern to prevent collecting matching outbound link URLs. For
	// example, if "*google*" is added, then any outbound links containing the word
	// "google" will be ignored. The "*" character matches zero or more of any
	// character.
	void AddAvoidOutboundLinkPattern(const char *pattern);


	// Adds a wildcarded pattern to prevent spidering matching URLs. For example, if
	// "*register*" is added, then any url containing the word "register" is not
	// spidered. The "*" character matches zero or more of any character.
	void AddAvoidPattern(const char *pattern);


	// Adds a wildcarded pattern to limit spidering to only URLs that match the
	// pattern. For example, if "*/products/*" is added, then only URLs containing
	// "/products/" are spidered. This is helpful for only spidering a portion of a
	// website. The "*" character matches zero or more of any character.
	void AddMustMatchPattern(const char *pattern);


	// To begin spidering you must call this method one or more times to provide
	// starting points. It adds a single URL to the object's internal queue of URLs to
	// be spidered.
	void AddUnspidered(const char *url);


	// Canonicalizes a URL by doing the following:
	//     Drops username/password if present.
	//     Drops fragment if present.
	//     Converts domain to lowercase.
	//     Removes port 80 or 443
	//     Remove default.asp, index.html, index.htm, default.html, index.htm,
	//     default.htm, index.php, index.asp, default.php, .cfm, .aspx, ,php3, .pl, .cgi,
	//     .txt, .shtml, .phtml
	//     Remove www. from the domain if present.
	bool CanonicalizeUrl(const char *url, CkString &outStr);

	// Canonicalizes a URL by doing the following:
	//     Drops username/password if present.
	//     Drops fragment if present.
	//     Converts domain to lowercase.
	//     Removes port 80 or 443
	//     Remove default.asp, index.html, index.htm, default.html, index.htm,
	//     default.htm, index.php, index.asp, default.php, .cfm, .aspx, ,php3, .pl, .cgi,
	//     .txt, .shtml, .phtml
	//     Remove www. from the domain if present.
	const char *canonicalizeUrl(const char *url);

	// Clears the object's internal list of URLs that could not be downloaded.
	void ClearFailedUrls(void);


	// Clears the object's internal list of outbound URLs that will automatically
	// accumulate while spidering.
	void ClearOutboundLinks(void);


	// Clears the object's internal list of already-spidered URLs that will
	// automatically accumulate while spidering.
	void ClearSpideredUrls(void);


	// Crawls the next URL in the internal list of unspidered URLs. The URL is moved
	// from the unspidered list to the spidered list. Any new links within the same
	// domain and not yet spidered are added to the unspidered list. (providing that
	// they do not match "avoid" patterns, etc.) Any new outbound links are added to
	// the outbound URL list. If successful, the HTML of the downloaded page is
	// available in the LastHtml property. If there are no more URLs left unspidered,
	// the method returns false. Information about the URL crawled is available in
	// the properties LastUrl, LastFromCache, and LastModDate.
	bool CrawlNext(void);

	// Crawls the next URL in the internal list of unspidered URLs. The URL is moved
	// from the unspidered list to the spidered list. Any new links within the same
	// domain and not yet spidered are added to the unspidered list. (providing that
	// they do not match "avoid" patterns, etc.) Any new outbound links are added to
	// the outbound URL list. If successful, the HTML of the downloaded page is
	// available in the LastHtml property. If there are no more URLs left unspidered,
	// the method returns false. Information about the URL crawled is available in
	// the properties LastUrl, LastFromCache, and LastModDate.
	CkTask *CrawlNextAsync(void);


	// Returns the contents of the robots.txt file from the domain being crawled. This
	// spider object will not crawl URLs excluded by robots.txt. If you believe the
	// spider is not behaving correctly, please notify us at support@chilkatsoft.com
	// and provide information detailing a case that allows us to reproduce the
	// problem.
	bool FetchRobotsText(CkString &outStr);

	// Returns the contents of the robots.txt file from the domain being crawled. This
	// spider object will not crawl URLs excluded by robots.txt. If you believe the
	// spider is not behaving correctly, please notify us at support@chilkatsoft.com
	// and provide information detailing a case that allows us to reproduce the
	// problem.
	const char *fetchRobotsText(void);
	// Returns the contents of the robots.txt file from the domain being crawled. This
	// spider object will not crawl URLs excluded by robots.txt. If you believe the
	// spider is not behaving correctly, please notify us at support@chilkatsoft.com
	// and provide information detailing a case that allows us to reproduce the
	// problem.
	CkTask *FetchRobotsTextAsync(void);


	// Returns the Nth avoid pattern previously added by calling AddAvoidPattern.
	// Indexing begins at 0.
	bool GetAvoidPattern(int index, CkString &outStr);

	// Returns the Nth avoid pattern previously added by calling AddAvoidPattern.
	// Indexing begins at 0.
	const char *getAvoidPattern(int index);
	// Returns the Nth avoid pattern previously added by calling AddAvoidPattern.
	// Indexing begins at 0.
	const char *avoidPattern(int index);


	// Returns the second-level + top-level domain of the domain. For example, if domain is
	// "xyz.example.com", this returns "example.com". For some domains, such as
	// "xyz.example.co.uk", the top 3 levels are returned, such as "example.co.uk".
	bool GetBaseDomain(const char *domain, CkString &outStr);

	// Returns the second-level + top-level domain of the domain. For example, if domain is
	// "xyz.example.com", this returns "example.com". For some domains, such as
	// "xyz.example.co.uk", the top 3 levels are returned, such as "example.co.uk".
	const char *getBaseDomain(const char *domain);
	// Returns the second-level + top-level domain of the domain. For example, if domain is
	// "xyz.example.com", this returns "example.com". For some domains, such as
	// "xyz.example.co.uk", the top 3 levels are returned, such as "example.co.uk".
	const char *baseDomain(const char *domain);


	// Returns the Nth URL in the failed URL list. Indexing begins at 0.
	bool GetFailedUrl(int index, CkString &outStr);

	// Returns the Nth URL in the failed URL list. Indexing begins at 0.
	const char *getFailedUrl(int index);
	// Returns the Nth URL in the failed URL list. Indexing begins at 0.
	const char *failedUrl(int index);


	// Returns the Nth URL in the outbound link URL list. Indexing begins at 0.
	bool GetOutboundLink(int index, CkString &outStr);

	// Returns the Nth URL in the outbound link URL list. Indexing begins at 0.
	const char *getOutboundLink(int index);
	// Returns the Nth URL in the outbound link URL list. Indexing begins at 0.
	const char *outboundLink(int index);


	// Returns the Nth URL in the already-spidered URL list. Indexing begins at 0.
	bool GetSpideredUrl(int index, CkString &outStr);

	// Returns the Nth URL in the already-spidered URL list. Indexing begins at 0.
	const char *getSpideredUrl(int index);
	// Returns the Nth URL in the already-spidered URL list. Indexing begins at 0.
	const char *spideredUrl(int index);


	// Returns the Nth URL in the unspidered URL list. Indexing begins at 0.
	bool GetUnspideredUrl(int index, CkString &outStr);

	// Returns the Nth URL in the unspidered URL list. Indexing begins at 0.
	const char *getUnspideredUrl(int index);
	// Returns the Nth URL in the unspidered URL list. Indexing begins at 0.
	const char *unspideredUrl(int index);


	// Returns the domain name part of a URL. For example, if the URL is
	// "https://www.chilkatsoft.com/test.asp", then "www.chilkatsoft.com" is returned.
	bool GetUrlDomain(const char *url, CkString &outStr);

	// Returns the domain name part of a URL. For example, if the URL is
	// "https://www.chilkatsoft.com/test.asp", then "www.chilkatsoft.com" is returned.
	const char *getUrlDomain(const char *url);
	// Returns the domain name part of a URL. For example, if the URL is
	// "https://www.chilkatsoft.com/test.asp", then "www.chilkatsoft.com" is returned.
	const char *urlDomain(const char *url);


	// Initializes the object to begin spidering a domain. Calling Initialize clears
	// any patterns added via the AddAvoidOutboundLinkPattern, AddAvoidPattern, and
	// AddMustMatchPattern methods. The domain name passed to this method is what is
	// returned by the Domain property. The spider only crawls URLs within the same
	// domain.
	void Initialize(const char *domain);


	// Loads the caller of the task's async method.
	bool LoadTaskCaller(CkTask &task);


	// Re-crawls the last URL spidered. This helpful when cookies set in a previous
	// page load cause the page to be loaded differently the next time.
	bool RecrawlLast(void);

	// Re-crawls the last URL spidered. This helpful when cookies set in a previous
	// page load cause the page to be loaded differently the next time.
	CkTask *RecrawlLastAsync(void);


	// Moves a URL from the unspidered list to the spidered list. This allows an
	// application to skip a specific URL.
	void SkipUnspidered(int index);


	// Suspends the execution of the current thread until the time-out interval
	// elapses.
	void SleepMs(int numMilliseconds);






	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
