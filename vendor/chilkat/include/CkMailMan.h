// CkMailMan.h: interface for the CkMailMan class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#define _CkVersion 9.5.0.96

#ifndef _CkMailMan_H
#define _CkMailMan_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacks.h"

class CkByteData;
class CkTask;
class CkEmailBundle;
class CkEmail;
class CkStringArray;
class CkBinData;
class CkCert;
class CkJsonObject;
class CkStringBuilder;
class CkPrivateKey;
class CkSecureString;
class CkSshKey;
class CkXmlCertVault;
class CkSsh;
class CkSocket;
class CkMailManProgress;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif


#undef Copy

// CLASS: CkMailMan
class CK_VISIBLE_PUBLIC CkMailMan  : public CkClassWithCallbacks
{
    private:

	// Don't allow assignment or copying these objects.
	CkMailMan(const CkMailMan &);
	CkMailMan &operator=(const CkMailMan &);

    public:
	CkMailMan(void);
	virtual ~CkMailMan(void);

	static CkMailMan *createNew(void);
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	
		
	CkMailManProgress *get_EventCallbackObject(void) const;
	void put_EventCallbackObject(CkMailManProgress *progress);


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

	// Prevents sending any email if any of the addresses in the recipient list are
	// rejected by the SMTP server. The default value is false, which indicates that
	// the mail sending should continue even if some email addresses are invalid.
	// (Note: Not all SMTP servers check the validity of email addresses, and even for
	// those that do, it is not 100% accurate.)
	// 
	// Note: An SMTP server only knows the validity of email addresses within the
	// domain it controls.
	// 
	// Important: The AllOrNone property only works if SMTP pipelining is turned off.
	// By default, the SmtpPipelining property is turned on and has the value of
	// true. If all-or-none behavior is desired, make sure to set SmtpPipelining
	// equal to false.
	// 
	bool get_AllOrNone(void);
	// Prevents sending any email if any of the addresses in the recipient list are
	// rejected by the SMTP server. The default value is false, which indicates that
	// the mail sending should continue even if some email addresses are invalid.
	// (Note: Not all SMTP servers check the validity of email addresses, and even for
	// those that do, it is not 100% accurate.)
	// 
	// Note: An SMTP server only knows the validity of email addresses within the
	// domain it controls.
	// 
	// Important: The AllOrNone property only works if SMTP pipelining is turned off.
	// By default, the SmtpPipelining property is turned on and has the value of
	// true. If all-or-none behavior is desired, make sure to set SmtpPipelining
	// equal to false.
	// 
	void put_AllOrNone(bool newVal);

	// If true, then the following will occur when a connection is made to an SMTP or
	// POP3 server:
	// 
	// 1) If the SmtpPort property = 465, then sets StartTLS = false and SmtpSsl =
	// true
	// 2) If the SmtpPort property = 25, sets SmtpSsl = false
	// 3) If the MailPort property = 995, sets PopSsl = true
	// 4) If the MailPort property = 110, sets PopSsl = false
	// 
	// The default value of this property is true.
	// 
	bool get_AutoFix(void);
	// If true, then the following will occur when a connection is made to an SMTP or
	// POP3 server:
	// 
	// 1) If the SmtpPort property = 465, then sets StartTLS = false and SmtpSsl =
	// true
	// 2) If the SmtpPort property = 25, sets SmtpSsl = false
	// 3) If the MailPort property = 995, sets PopSsl = true
	// 4) If the MailPort property = 110, sets PopSsl = false
	// 
	// The default value of this property is true.
	// 
	void put_AutoFix(bool newVal);

	// Controls whether a unique Message-ID header is auto-generated for each email
	// sent.
	// 
	// The Message-ID header field should contain a unique message ID for each email
	// that is sent. The default behavior is to auto-generate this header field at the
	// time the message is sent. This makes it easier for the same email object to be
	// re-used. If the message ID is not unique, the SMTP server may consider the
	// message to be a duplicate of one that has already been sent, and may discard it
	// without sending. This property controls whether message IDs are automatically
	// generated. If auto-generation is turned on (true), the value returned by
	// GetHeaderField("Message-ID") will not reflect the actual message ID that gets
	// sent with the email.
	// 
	// To turn off automatic Message-ID generation, set this property to false.
	// 
	bool get_AutoGenMessageId(void);
	// Controls whether a unique Message-ID header is auto-generated for each email
	// sent.
	// 
	// The Message-ID header field should contain a unique message ID for each email
	// that is sent. The default behavior is to auto-generate this header field at the
	// time the message is sent. This makes it easier for the same email object to be
	// re-used. If the message ID is not unique, the SMTP server may consider the
	// message to be a duplicate of one that has already been sent, and may discard it
	// without sending. This property controls whether message IDs are automatically
	// generated. If auto-generation is turned on (true), the value returned by
	// GetHeaderField("Message-ID") will not reflect the actual message ID that gets
	// sent with the email.
	// 
	// To turn off automatic Message-ID generation, set this property to false.
	// 
	void put_AutoGenMessageId(bool newVal);

	// If true, then the SMTP "RSET" command is automatically sent to ensure that the
	// SMTP connection is in a valid state when a new email is about to be sent on an
	// already established connection. The default value is false.
	// 
	// Important: This property only applies when an email is sent on an already-open
	// SMTP connection.
	// 
	bool get_AutoSmtpRset(void);
	// If true, then the SMTP "RSET" command is automatically sent to ensure that the
	// SMTP connection is in a valid state when a new email is about to be sent on an
	// already established connection. The default value is false.
	// 
	// Important: This property only applies when an email is sent on an already-open
	// SMTP connection.
	// 
	void put_AutoSmtpRset(bool newVal);

	// If true, then digitally signed and/or encrypted email when downloaded from a
	// mail server is automatically "unwrapped" and the results of the signature
	// validation and decryption are available in various email object properties and
	// methods. The default value of this property is true. Set this property to
	// false to prevent unwrapping.
	// 
	// Note: A digitally signed or encrypted email can ONLY be verified and/or
	// decrypted when initially loading the original MIME into the email object (i.e.
	// when downloading from the server, or when loading from MIME). Once the MIME is
	// parsed and stored in the internal email object format, the exactnes of the MIME
	// has been lost and the signature can no longer be verified. This is why the
	// signature is verified upon the intial loading of the MIME, and the results are
	// made available through the various properties and methods. This property
	// provides a means for downloading email where the .p7m (or .p7s) attachments are
	// are to be treated as simple attachments and the desire is to access or save the
	// original .p7m/.p7s files.
	// 
	bool get_AutoUnwrapSecurity(void);
	// If true, then digitally signed and/or encrypted email when downloaded from a
	// mail server is automatically "unwrapped" and the results of the signature
	// validation and decryption are available in various email object properties and
	// methods. The default value of this property is true. Set this property to
	// false to prevent unwrapping.
	// 
	// Note: A digitally signed or encrypted email can ONLY be verified and/or
	// decrypted when initially loading the original MIME into the email object (i.e.
	// when downloading from the server, or when loading from MIME). Once the MIME is
	// parsed and stored in the internal email object format, the exactnes of the MIME
	// has been lost and the signature can no longer be verified. This is why the
	// signature is verified upon the intial loading of the MIME, and the results are
	// made available through the various properties and methods. This property
	// provides a means for downloading email where the .p7m (or .p7s) attachments are
	// are to be treated as simple attachments and the desire is to access or save the
	// original .p7m/.p7s files.
	// 
	void put_AutoUnwrapSecurity(bool newVal);

	// The IP address to use for computers with multiple network interfaces or IP
	// addresses. For computers with a single network interface (i.e. most computers),
	// this property should not be set. For multihoming computers, the default IP
	// address is automatically used if this property is not set.
	// 
	// The IP address is a string such as in dotted notation using numbers, not domain
	// names, such as "165.164.55.124".
	// 
	void get_ClientIpAddress(CkString &str);
	// The IP address to use for computers with multiple network interfaces or IP
	// addresses. For computers with a single network interface (i.e. most computers),
	// this property should not be set. For multihoming computers, the default IP
	// address is automatically used if this property is not set.
	// 
	// The IP address is a string such as in dotted notation using numbers, not domain
	// names, such as "165.164.55.124".
	// 
	const char *clientIpAddress(void);
	// The IP address to use for computers with multiple network interfaces or IP
	// addresses. For computers with a single network interface (i.e. most computers),
	// this property should not be set. For multihoming computers, the default IP
	// address is automatically used if this property is not set.
	// 
	// The IP address is a string such as in dotted notation using numbers, not domain
	// names, such as "165.164.55.124".
	// 
	void put_ClientIpAddress(const char *newVal);

	// This property will be set to the status of the last connection made (or failed
	// to be made) by any method.
	// 
	// Possible values are:0 = success
	// 
	// Normal (non-TLS) sockets:
	// 1 = empty hostname
	// 2 = DNS lookup failed
	// 3 = DNS timeout
	// 4 = Aborted by application.
	// 5 = Internal failure.
	// 6 = Connect Timed Out
	// 7 = Connect Rejected (or failed for some other reason)
	// 
	// SSL/TLS:
	// 100 = TLS internal error.
	// 101 = Failed to send client hello.
	// 102 = Unexpected handshake message.
	// 103 = Failed to read server hello.
	// 104 = No server certificate.
	// 105 = Unexpected TLS protocol version.
	// 106 = Server certificate verify failed (the server certificate is expired or the cert's signature verification failed).
	// 107 = Unacceptable TLS protocol version.
	// 109 = Failed to read handshake messages.
	// 110 = Failed to send client certificate handshake message.
	// 111 = Failed to send client key exchange handshake message.
	// 112 = Client certificate's private key not accessible.
	// 113 = Failed to send client cert verify handshake message.
	// 114 = Failed to send change cipher spec handshake message.
	// 115 = Failed to send finished handshake message.
	// 116 = Server's Finished message is invalid.
	// 
	int get_ConnectFailReason(void);

	// The time (in seconds) to wait before while trying to connect to a mail server
	// (POP3 or SMTP). The default value is 30.
	int get_ConnectTimeout(void);
	// The time (in seconds) to wait before while trying to connect to a mail server
	// (POP3 or SMTP). The default value is 30.
	void put_ConnectTimeout(int newVal);

	// (An SMTP DSN service extension feature) An arbitrary string that will be used as
	// the ENVID property when sending email. See RFC 3461 for more details.
	void get_DsnEnvid(CkString &str);
	// (An SMTP DSN service extension feature) An arbitrary string that will be used as
	// the ENVID property when sending email. See RFC 3461 for more details.
	const char *dsnEnvid(void);
	// (An SMTP DSN service extension feature) An arbitrary string that will be used as
	// the ENVID property when sending email. See RFC 3461 for more details.
	void put_DsnEnvid(const char *newVal);

	// (An SMTP DSN service extension feature) A string that will be used as the NOTIFY
	// parameter when sending email. (See RFC 3461 for more details. ) This string can
	// be left blank, or can be set to "NEVER", or any combination of a comma-separated
	// list of "SUCCESS", "FAILURE", or "NOTIFY".
	void get_DsnNotify(CkString &str);
	// (An SMTP DSN service extension feature) A string that will be used as the NOTIFY
	// parameter when sending email. (See RFC 3461 for more details. ) This string can
	// be left blank, or can be set to "NEVER", or any combination of a comma-separated
	// list of "SUCCESS", "FAILURE", or "NOTIFY".
	const char *dsnNotify(void);
	// (An SMTP DSN service extension feature) A string that will be used as the NOTIFY
	// parameter when sending email. (See RFC 3461 for more details. ) This string can
	// be left blank, or can be set to "NEVER", or any combination of a comma-separated
	// list of "SUCCESS", "FAILURE", or "NOTIFY".
	void put_DsnNotify(const char *newVal);

	// (An SMTP DSN service extension feature) A string that will be used as the RET
	// parameter when sending email. (See RFC 3461 for more details. ) This string can
	// be left blank, or can be set to "FULL" to receive entire-message DSN
	// notifications, or "HDRS" to receive header-only DSN notifications.
	void get_DsnRet(CkString &str);
	// (An SMTP DSN service extension feature) A string that will be used as the RET
	// parameter when sending email. (See RFC 3461 for more details. ) This string can
	// be left blank, or can be set to "FULL" to receive entire-message DSN
	// notifications, or "HDRS" to receive header-only DSN notifications.
	const char *dsnRet(void);
	// (An SMTP DSN service extension feature) A string that will be used as the RET
	// parameter when sending email. (See RFC 3461 for more details. ) This string can
	// be left blank, or can be set to "FULL" to receive entire-message DSN
	// notifications, or "HDRS" to receive header-only DSN notifications.
	void put_DsnRet(const char *newVal);

	// If true, causes the digital certificate chain to be embedded in signed emails.
	// The certificates in the chain of authentication are embedded up to but not
	// including the root certificate. If the IncludeRootCert property is also true,
	// then the root CA certificate is also included in the S/MIME signature.
	bool get_EmbedCertChain(void);
	// If true, causes the digital certificate chain to be embedded in signed emails.
	// The certificates in the chain of authentication are embedded up to but not
	// including the root certificate. If the IncludeRootCert property is also true,
	// then the root CA certificate is also included in the S/MIME signature.
	void put_EmbedCertChain(bool newVal);

	// An expression that is applied to any of the following method calls when present:
	// LoadXmlFile, LoadXmlString, LoadMbx, CopyMail, and TransferMail. For these
	// methods, only the emails that match the filter's expression are returned in the
	// email bundle. In the case of TransferMail, only the matching emails are removed
	// from the mail server. The filter allows any header field, or the body, to be
	// checked.Here are some examples of expressions:
	// 
	// Body like "mortgage rates*". 
	// Subject contains "update" and From contains "chilkat" 
	// To = "info@chilkatsoft.com" 
	// 
	// Here are the general rules for forming filter expressions:
	// 
	// Any MIME header field name can be used, case is insensitive. 
	// Literal strings are double-quoted, and case is insensitive. 
	// The "*" wildcard matches 0 or more occurrences of any character. 
	// Parentheses can be used to control precedence. 
	// The logical operators are: AND, OR, NOT (case insensitive) 
	// Comparison operators are: =,,=,String comparison operators are: CONTAINS, LIKE (case insensitive)
	// 
	// Note: This property only works on text strings, not dates or numbers.
	void get_Filter(CkString &str);
	// An expression that is applied to any of the following method calls when present:
	// LoadXmlFile, LoadXmlString, LoadMbx, CopyMail, and TransferMail. For these
	// methods, only the emails that match the filter's expression are returned in the
	// email bundle. In the case of TransferMail, only the matching emails are removed
	// from the mail server. The filter allows any header field, or the body, to be
	// checked.Here are some examples of expressions:
	// 
	// Body like "mortgage rates*". 
	// Subject contains "update" and From contains "chilkat" 
	// To = "info@chilkatsoft.com" 
	// 
	// Here are the general rules for forming filter expressions:
	// 
	// Any MIME header field name can be used, case is insensitive. 
	// Literal strings are double-quoted, and case is insensitive. 
	// The "*" wildcard matches 0 or more occurrences of any character. 
	// Parentheses can be used to control precedence. 
	// The logical operators are: AND, OR, NOT (case insensitive) 
	// Comparison operators are: =,,=,String comparison operators are: CONTAINS, LIKE (case insensitive)
	// 
	// Note: This property only works on text strings, not dates or numbers.
	const char *filter(void);
	// An expression that is applied to any of the following method calls when present:
	// LoadXmlFile, LoadXmlString, LoadMbx, CopyMail, and TransferMail. For these
	// methods, only the emails that match the filter's expression are returned in the
	// email bundle. In the case of TransferMail, only the matching emails are removed
	// from the mail server. The filter allows any header field, or the body, to be
	// checked.Here are some examples of expressions:
	// 
	// Body like "mortgage rates*". 
	// Subject contains "update" and From contains "chilkat" 
	// To = "info@chilkatsoft.com" 
	// 
	// Here are the general rules for forming filter expressions:
	// 
	// Any MIME header field name can be used, case is insensitive. 
	// Literal strings are double-quoted, and case is insensitive. 
	// The "*" wildcard matches 0 or more occurrences of any character. 
	// Parentheses can be used to control precedence. 
	// The logical operators are: AND, OR, NOT (case insensitive) 
	// Comparison operators are: =,,=,String comparison operators are: CONTAINS, LIKE (case insensitive)
	// 
	// Note: This property only works on text strings, not dates or numbers.
	void put_Filter(const char *newVal);

	// The time interval, in milliseconds, between AbortCheck event callbacks. The
	// heartbeat provides a means for an application to monitor a mail-sending and/or
	// mail-reading method call, and to abort it while in progress.
	int get_HeartbeatMs(void);
	// The time interval, in milliseconds, between AbortCheck event callbacks. The
	// heartbeat provides a means for an application to monitor a mail-sending and/or
	// mail-reading method call, and to abort it while in progress.
	void put_HeartbeatMs(int newVal);

	// Specifies the hostname to be used for the EHLO/HELO command sent to an SMTP
	// server. By default, this property is an empty string which causes the local
	// hostname to be used.
	void get_HeloHostname(CkString &str);
	// Specifies the hostname to be used for the EHLO/HELO command sent to an SMTP
	// server. By default, this property is an empty string which causes the local
	// hostname to be used.
	const char *heloHostname(void);
	// Specifies the hostname to be used for the EHLO/HELO command sent to an SMTP
	// server. By default, this property is an empty string which causes the local
	// hostname to be used.
	void put_HeloHostname(const char *newVal);

	// If an HTTP proxy requiring authentication is to be used, set this property to
	// the HTTP proxy authentication method name. Valid choices are "Basic" or "NTLM".
	void get_HttpProxyAuthMethod(CkString &str);
	// If an HTTP proxy requiring authentication is to be used, set this property to
	// the HTTP proxy authentication method name. Valid choices are "Basic" or "NTLM".
	const char *httpProxyAuthMethod(void);
	// If an HTTP proxy requiring authentication is to be used, set this property to
	// the HTTP proxy authentication method name. Valid choices are "Basic" or "NTLM".
	void put_HttpProxyAuthMethod(const char *newVal);

	// The NTLM authentication domain (optional) if NTLM authentication is used.
	void get_HttpProxyDomain(CkString &str);
	// The NTLM authentication domain (optional) if NTLM authentication is used.
	const char *httpProxyDomain(void);
	// The NTLM authentication domain (optional) if NTLM authentication is used.
	void put_HttpProxyDomain(const char *newVal);

	// If an HTTP proxy is to be used, set this property to the HTTP proxy hostname or
	// IPv4 address (in dotted decimal notation).
	void get_HttpProxyHostname(CkString &str);
	// If an HTTP proxy is to be used, set this property to the HTTP proxy hostname or
	// IPv4 address (in dotted decimal notation).
	const char *httpProxyHostname(void);
	// If an HTTP proxy is to be used, set this property to the HTTP proxy hostname or
	// IPv4 address (in dotted decimal notation).
	void put_HttpProxyHostname(const char *newVal);

	// If an HTTP proxy requiring authentication is to be used, set this property to
	// the HTTP proxy password.
	void get_HttpProxyPassword(CkString &str);
	// If an HTTP proxy requiring authentication is to be used, set this property to
	// the HTTP proxy password.
	const char *httpProxyPassword(void);
	// If an HTTP proxy requiring authentication is to be used, set this property to
	// the HTTP proxy password.
	void put_HttpProxyPassword(const char *newVal);

	// If an HTTP proxy is to be used, set this property to the HTTP proxy port number.
	// (Two commonly used HTTP proxy ports are 8080 and 3128.)
	int get_HttpProxyPort(void);
	// If an HTTP proxy is to be used, set this property to the HTTP proxy port number.
	// (Two commonly used HTTP proxy ports are 8080 and 3128.)
	void put_HttpProxyPort(int newVal);

	// If an HTTP proxy requiring authentication is to be used, set this property to
	// the HTTP proxy login name.
	void get_HttpProxyUsername(CkString &str);
	// If an HTTP proxy requiring authentication is to be used, set this property to
	// the HTTP proxy login name.
	const char *httpProxyUsername(void);
	// If an HTTP proxy requiring authentication is to be used, set this property to
	// the HTTP proxy login name.
	void put_HttpProxyUsername(const char *newVal);

	// If true (the default) then any method that deletes an email from the POP3
	// server will also issue a QUIT command to close the session to ensure the message
	// is deleted immediately.
	// 
	// The POP3 protocol is such that the DELE command marks a message for deletion. It
	// is not actually deleted until the QUIT command is sent and the session is
	// closed. If ImmediateDelete is true, then any Chilkat MailMan method that marks
	// a message (or messages) for deletion will also followup with a QUIT command and
	// close the session. If your program sets ImmediateDelete to false, it must make
	// sure to call Pop3EndSession to ensure that messages marked for deletion are
	// actually deleted.
	// 
	bool get_ImmediateDelete(void);
	// If true (the default) then any method that deletes an email from the POP3
	// server will also issue a QUIT command to close the session to ensure the message
	// is deleted immediately.
	// 
	// The POP3 protocol is such that the DELE command marks a message for deletion. It
	// is not actually deleted until the QUIT command is sent and the session is
	// closed. If ImmediateDelete is true, then any Chilkat MailMan method that marks
	// a message (or messages) for deletion will also followup with a QUIT command and
	// close the session. If your program sets ImmediateDelete to false, it must make
	// sure to call Pop3EndSession to ensure that messages marked for deletion are
	// actually deleted.
	// 
	void put_ImmediateDelete(bool newVal);

	// Controls whether the root certificate in the chain of authentication (i.e. the
	// CA root certificate) is included within the S/MIME signature of a signed email.
	// Note: This property only applies if the EmbedCertChain property is also true.
	bool get_IncludeRootCert(void);
	// Controls whether the root certificate in the chain of authentication (i.e. the
	// CA root certificate) is included within the S/MIME signature of a signed email.
	// Note: This property only applies if the EmbedCertChain property is also true.
	void put_IncludeRootCert(bool newVal);

	// Returns true if still connected to the POP3 server. Otherwise returns false.
	// 
	// Note: Accessing this property does not trigger any communication with the POP3
	// server. A connection to the POP3 server is established by explicitly calling
	// Pop3BeginSession, or it is implicitly established as needed by any method that
	// requires communication. A lost connection might only be detected when attempting
	// to communicate with the server. To truly determine if a connection to the POP3
	// server is open and valid, it may be necessary to call the Pop3Noop method
	// instead. This property might return true if the server has disconnected, but
	// the client has not attempted to communicate with the server since the
	// disconnect.
	// 
	bool get_IsPop3Connected(void);

	// Returns true if still connected to the SMTP server. Otherwise returns false
	// (if there was never a connection in the first place, or if the connection was
	// lost).
	// 
	// Note: Accessing this property does not trigger any communication with the SMTP
	// server. A connection to the SMTP server is established by explicitly calling
	// OpenSmtpConnection, or it is implicitly established as needed by any method that
	// requires communication. A lost connection might only be detected when attempting
	// to communicate with the server. To truly determine if a connection to the SMTP
	// server is open and valid, it may be necessary to call the SmtpNoop method
	// instead. This property might return true if the server has disconnected, but
	// the client has not attempted to communicate with the server since the
	// disconnect.
	// 
	bool get_IsSmtpConnected(void);

	// The name of the file created in the SMTPQ's queue directory for the last email
	// sent via SendQ, SendQ2, or SendMimeQ.
	void get_LastSendQFilename(CkString &str);
	// The name of the file created in the SMTPQ's queue directory for the last email
	// sent via SendQ, SendQ2, or SendMimeQ.
	const char *lastSendQFilename(void);

	// Returns the last SMTP diagnostic status code. This can be checked after sending
	// an email. SMTP reply codes are defined by RFC 821 - Simple Mail Transfer
	// Protocol.
	int get_LastSmtpStatus(void);

	// Returns the last SMTP status message associated with the last SMTP status code
	// received. This can be checked after sending an email.
	void get_LastSmtpStatusMsg(CkString &str);
	// Returns the last SMTP status message associated with the last SMTP status code
	// received. This can be checked after sending an email.
	const char *lastSmtpStatusMsg(void);

	// A log filename where the MailMan will log each message in the exact form it was
	// received from a POP3 server. This property is provided for help in debugging.
	void get_LogMailReceivedFilename(CkString &str);
	// A log filename where the MailMan will log each message in the exact form it was
	// received from a POP3 server. This property is provided for help in debugging.
	const char *logMailReceivedFilename(void);
	// A log filename where the MailMan will log each message in the exact form it was
	// received from a POP3 server. This property is provided for help in debugging.
	void put_LogMailReceivedFilename(const char *newVal);

	// A log filename where the MailMan will log the exact message sent to the SMTP
	// server. This property is helpful in debugging.
	void get_LogMailSentFilename(CkString &str);
	// A log filename where the MailMan will log the exact message sent to the SMTP
	// server. This property is helpful in debugging.
	const char *logMailSentFilename(void);
	// A log filename where the MailMan will log the exact message sent to the SMTP
	// server. This property is helpful in debugging.
	void put_LogMailSentFilename(const char *newVal);

	// The domain name of the POP3 server. Do not include "http://" in the domain name.
	// This property may also be set to an IP address string, such as "168.144.70.227".
	// Both IPv4 and IPv6 address formats are supported.
	void get_MailHost(CkString &str);
	// The domain name of the POP3 server. Do not include "http://" in the domain name.
	// This property may also be set to an IP address string, such as "168.144.70.227".
	// Both IPv4 and IPv6 address formats are supported.
	const char *mailHost(void);
	// The domain name of the POP3 server. Do not include "http://" in the domain name.
	// This property may also be set to an IP address string, such as "168.144.70.227".
	// Both IPv4 and IPv6 address formats are supported.
	void put_MailHost(const char *newVal);

	// The port number of the POP3 server. Only needs to be set if the POP3 server is
	// running on a non-standard port. The default value is 110. (If SSL/TLS is used by
	// setting the PopSsl property = true, then this property should probably be set
	// to 995, which is the standard SSL/TLS port for POP3.)
	int get_MailPort(void);
	// The port number of the POP3 server. Only needs to be set if the POP3 server is
	// running on a non-standard port. The default value is 110. (If SSL/TLS is used by
	// setting the PopSsl property = true, then this property should probably be set
	// to 995, which is the standard SSL/TLS port for POP3.)
	void put_MailPort(int newVal);

	// Limits the number of messages the MailMan will try to retrieve from the POP3
	// server in a single method call. If you are trying to read a large mailbox, you
	// might set this to a value such as 100 to download 100 emails at a time.
	int get_MaxCount(void);
	// Limits the number of messages the MailMan will try to retrieve from the POP3
	// server in a single method call. If you are trying to read a large mailbox, you
	// might set this to a value such as 100 to download 100 emails at a time.
	void put_MaxCount(int newVal);

	// The OAUTH2 access token if OAUTH2 authentication is to be used for the
	// authentication. For GMail, the Chilkat HTTP class/object's G_SvcOauthAccessToken
	// method can be called to obtain an OAUTH2 access token for a GMail service
	// account.
	// 
	// Starting in v9.5.0.83, this property can be set to also do XOAUTH2
	// authentication for POP3 sessions (pop.gmail.com).
	// 
	void get_OAuth2AccessToken(CkString &str);
	// The OAUTH2 access token if OAUTH2 authentication is to be used for the
	// authentication. For GMail, the Chilkat HTTP class/object's G_SvcOauthAccessToken
	// method can be called to obtain an OAUTH2 access token for a GMail service
	// account.
	// 
	// Starting in v9.5.0.83, this property can be set to also do XOAUTH2
	// authentication for POP3 sessions (pop.gmail.com).
	// 
	const char *oAuth2AccessToken(void);
	// The OAUTH2 access token if OAUTH2 authentication is to be used for the
	// authentication. For GMail, the Chilkat HTTP class/object's G_SvcOauthAccessToken
	// method can be called to obtain an OAUTH2 access token for a GMail service
	// account.
	// 
	// Starting in v9.5.0.83, this property can be set to also do XOAUTH2
	// authentication for POP3 sessions (pop.gmail.com).
	// 
	void put_OAuth2AccessToken(const char *newVal);

	// When false, a signed email is generated as multipart/signed. For example:Content-Type: multipart/signed; charset=utf-8; boundary="------------010909020906040709090605";
	//  protocol="application/pkcs7-signature";
	// micalg=sha256
	// 
	// When true, a signed email is generated as signed-data. For example:
	// 
	// Content-Type: application/pkcs7-mime; name="smime.p7m"; micalg=sha256;
	// smime-type="signed-data"
	// 
	// A multipart/signed email is such that the signature is contained in a separate
	// MIME body part and the original content of the email is not encapsulated within
	// the signature. A signed-data email is such that it's non-multipart MIME (content
	// type is "application/pkcs7-signature") and the original email is encapsulated
	// within the signature. This is historically known as an opaque signature.
	// 
	// The default value is true.
	// 
	bool get_OpaqueSigning(void);
	// When false, a signed email is generated as multipart/signed. For example:Content-Type: multipart/signed; charset=utf-8; boundary="------------010909020906040709090605";
	//  protocol="application/pkcs7-signature";
	// micalg=sha256
	// 
	// When true, a signed email is generated as signed-data. For example:
	// 
	// Content-Type: application/pkcs7-mime; name="smime.p7m"; micalg=sha256;
	// smime-type="signed-data"
	// 
	// A multipart/signed email is such that the signature is contained in a separate
	// MIME body part and the original content of the email is not encapsulated within
	// the signature. A signed-data email is such that it's non-multipart MIME (content
	// type is "application/pkcs7-signature") and the original email is encapsulated
	// within the signature. This is historically known as an opaque signature.
	// 
	// The default value is true.
	// 
	void put_OpaqueSigning(bool newVal);

	// The filename attribute to be used in the Content-Disposition header field when
	// sending a PCKS7 encrypted email. The default value is "smime.p7m".
	void get_P7mEncryptAttachFilename(CkString &str);
	// The filename attribute to be used in the Content-Disposition header field when
	// sending a PCKS7 encrypted email. The default value is "smime.p7m".
	const char *p7mEncryptAttachFilename(void);
	// The filename attribute to be used in the Content-Disposition header field when
	// sending a PCKS7 encrypted email. The default value is "smime.p7m".
	void put_P7mEncryptAttachFilename(const char *newVal);

	// The filename attribute to be used in the Content-Disposition header field when
	// sending a PCKS7 opaque signed email. The default value is "smime.p7m".
	void get_P7mSigAttachFilename(CkString &str);
	// The filename attribute to be used in the Content-Disposition header field when
	// sending a PCKS7 opaque signed email. The default value is "smime.p7m".
	const char *p7mSigAttachFilename(void);
	// The filename attribute to be used in the Content-Disposition header field when
	// sending a PCKS7 opaque signed email. The default value is "smime.p7m".
	void put_P7mSigAttachFilename(const char *newVal);

	// The filename attribute to be used in the Content-Disposition header field when
	// sending a signed email with a detached PKCS7 signature. The default value is
	// "smime.p7s".
	void get_P7sSigAttachFilename(CkString &str);
	// The filename attribute to be used in the Content-Disposition header field when
	// sending a signed email with a detached PKCS7 signature. The default value is
	// "smime.p7s".
	const char *p7sSigAttachFilename(void);
	// The filename attribute to be used in the Content-Disposition header field when
	// sending a signed email with a detached PKCS7 signature. The default value is
	// "smime.p7s".
	void put_P7sSigAttachFilename(const char *newVal);

	// This property is only valid in programming environment and languages that allow
	// for event callbacks.
	// 
	// Sets the value to be defined as 100% complete for the purpose of PercentDone
	// event callbacks. The defaut value of 100 means that at most 100 event
	// PercentDone callbacks will occur in a method that (1) is event enabled and (2)
	// is such that it is possible to measure progress as a percentage completed. This
	// property may be set to larger numbers to get more fine-grained PercentDone
	// callbacks. For example, setting this property equal to 1000 will provide
	// callbacks with .1 percent granularity. For example, a value of 453 would
	// indicate 45.3% competed. This property is clamped to a minimum value of 10, and
	// a maximum value of 100000.
	// 
	int get_PercentDoneScale(void);
	// This property is only valid in programming environment and languages that allow
	// for event callbacks.
	// 
	// Sets the value to be defined as 100% complete for the purpose of PercentDone
	// event callbacks. The defaut value of 100 means that at most 100 event
	// PercentDone callbacks will occur in a method that (1) is event enabled and (2)
	// is such that it is possible to measure progress as a percentage completed. This
	// property may be set to larger numbers to get more fine-grained PercentDone
	// callbacks. For example, setting this property equal to 1000 will provide
	// callbacks with .1 percent granularity. For example, a value of 453 would
	// indicate 45.3% competed. This property is clamped to a minimum value of 10, and
	// a maximum value of 100000.
	// 
	void put_PercentDoneScale(int newVal);

	// 0 if no POP3 session is active. Otherwise a positive integer that is incremented
	// with each new POP3 session. It may be used to determine if a new POP3 session
	// has been established.
	int get_Pop3SessionId(void);

	// This string property accumulates the raw commands sent to the POP3 server, and
	// the raw responses received from the POP3 server. This property is read-only, but
	// it may be cleared by calling ClearPop3SessionLog.
	void get_Pop3SessionLog(CkString &str);
	// This string property accumulates the raw commands sent to the POP3 server, and
	// the raw responses received from the POP3 server. This property is read-only, but
	// it may be cleared by calling ClearPop3SessionLog.
	const char *pop3SessionLog(void);

	// Controls whether SPA authentication for POP3 is used or not. To use SPA
	// authentication, set this property = true. No other programming changes are
	// required. The default value is false.
	// 
	// Note: If SPA (i.e. NTLM) authentication does not succeed, set the
	// Global.DefaultNtlmVersion property equal to 1 and then retry.
	// 
	bool get_Pop3SPA(void);
	// Controls whether SPA authentication for POP3 is used or not. To use SPA
	// authentication, set this property = true. No other programming changes are
	// required. The default value is false.
	// 
	// Note: If SPA (i.e. NTLM) authentication does not succeed, set the
	// Global.DefaultNtlmVersion property equal to 1 and then retry.
	// 
	void put_Pop3SPA(bool newVal);

	// When connecting via SSL, this property is true if the POP3 server's SSL
	// certificate was verified. Otherwise it is set to false.
	bool get_Pop3SslServerCertVerified(void);

	// If true, then an unencrypted connection (typically on port 110) is
	// automatically converted to a secure TLS connection via the STLS command (see RFC
	// 2595) when connecting. This should only be used with POP3 servers that are known
	// to support the STLS capability. If this property is set to true, then the
	// PopSsl property should be set to false. (The PopSsl property controls whether
	// the connection is SSL/TLS from the beginning. Setting the Pop3Stls property =
	// true indicates that the POP3 client will initially connect unencrypted and
	// then convert to TLS.)
	// 
	// The default value of this property is false.
	// 
	bool get_Pop3Stls(void);
	// If true, then an unencrypted connection (typically on port 110) is
	// automatically converted to a secure TLS connection via the STLS command (see RFC
	// 2595) when connecting. This should only be used with POP3 servers that are known
	// to support the STLS capability. If this property is set to true, then the
	// PopSsl property should be set to false. (The PopSsl property controls whether
	// the connection is SSL/TLS from the beginning. Setting the Pop3Stls property =
	// true indicates that the POP3 client will initially connect unencrypted and
	// then convert to TLS.)
	// 
	// The default value of this property is false.
	// 
	void put_Pop3Stls(bool newVal);

	// If true, then an unencrypted connection (typically on port 110) is
	// automatically converted to a secure TLS connection via the STLS command if the
	// mail server supports the STLS command. If the mail server does not support STLS,
	// then the connection will remain unencrypted.
	// 
	// The default value of this property is false.
	// 
	bool get_Pop3StlsIfPossible(void);
	// If true, then an unencrypted connection (typically on port 110) is
	// automatically converted to a secure TLS connection via the STLS command if the
	// mail server supports the STLS command. If the mail server does not support STLS,
	// then the connection will remain unencrypted.
	// 
	// The default value of this property is false.
	// 
	void put_Pop3StlsIfPossible(bool newVal);

	// The POP3 password.
	// 
	// If the Pop3SPA property is set, the PopUsername and PopPassword properties may
	// be set to the string "default" to cause the component to use the current
	// logged-on credentials (of the calling process) for authentication.
	// 
	void get_PopPassword(CkString &str);
	// The POP3 password.
	// 
	// If the Pop3SPA property is set, the PopUsername and PopPassword properties may
	// be set to the string "default" to cause the component to use the current
	// logged-on credentials (of the calling process) for authentication.
	// 
	const char *popPassword(void);
	// The POP3 password.
	// 
	// If the Pop3SPA property is set, the PopUsername and PopPassword properties may
	// be set to the string "default" to cause the component to use the current
	// logged-on credentials (of the calling process) for authentication.
	// 
	void put_PopPassword(const char *newVal);

	// Provides a way to specify the POP3 password from a Base64-encoded string.
	void get_PopPasswordBase64(CkString &str);
	// Provides a way to specify the POP3 password from a Base64-encoded string.
	const char *popPasswordBase64(void);
	// Provides a way to specify the POP3 password from a Base64-encoded string.
	void put_PopPasswordBase64(const char *newVal);

	// Controls whether TLS/SSL is used when reading email from a POP3 server. Note:
	// Check first to determine if your POP3 server can accept TLS/SSL connections.
	// Also, be sure to set the MailPort property to the TLS/SSL POP3 port number,
	// which is typically 995.
	// 
	// The default value of this property is false.
	// 
	bool get_PopSsl(void);
	// Controls whether TLS/SSL is used when reading email from a POP3 server. Note:
	// Check first to determine if your POP3 server can accept TLS/SSL connections.
	// Also, be sure to set the MailPort property to the TLS/SSL POP3 port number,
	// which is typically 995.
	// 
	// The default value of this property is false.
	// 
	void put_PopSsl(bool newVal);

	// The POP3 login name.
	// 
	// If the Pop3SPA property is set, the PopUsername and PopPassword properties may
	// be set to the string "default" to cause the component to use the current
	// logged-on credentials (of the calling process) for authentication.
	// 
	void get_PopUsername(CkString &str);
	// The POP3 login name.
	// 
	// If the Pop3SPA property is set, the PopUsername and PopPassword properties may
	// be set to the string "default" to cause the component to use the current
	// logged-on credentials (of the calling process) for authentication.
	// 
	const char *popUsername(void);
	// The POP3 login name.
	// 
	// If the Pop3SPA property is set, the PopUsername and PopPassword properties may
	// be set to the string "default" to cause the component to use the current
	// logged-on credentials (of the calling process) for authentication.
	// 
	void put_PopUsername(const char *newVal);

	// If true, then use IPv6 over IPv4 when both are supported for a particular
	// domain. The default value of this property is false, which will choose IPv4
	// over IPv6.
	bool get_PreferIpv6(void);
	// If true, then use IPv6 over IPv4 when both are supported for a particular
	// domain. The default value of this property is false, which will choose IPv4
	// over IPv6.
	void put_PreferIpv6(bool newVal);

	// The maximum time to wait, in seconds, if the POP3 or SMTP server stops
	// responding. The default value is 30 seconds.
	int get_ReadTimeout(void);
	// The maximum time to wait, in seconds, if the POP3 or SMTP server stops
	// responding. The default value is 30 seconds.
	void put_ReadTimeout(int newVal);

	// If true, then the mailman will verify the SMTP or POP3 server's SSL
	// certificate when connecting. The certificate is expired, or if the cert's
	// signature is invalid, the connection is not allowed. The default value of this
	// property is false. (Obviously, this only applies to SSL/TLS connections.)
	bool get_RequireSslCertVerify(void);
	// If true, then the mailman will verify the SMTP or POP3 server's SSL
	// certificate when connecting. The certificate is expired, or if the cert's
	// signature is invalid, the connection is not allowed. The default value of this
	// property is false. (Obviously, this only applies to SSL/TLS connections.)
	void put_RequireSslCertVerify(bool newVal);

	// Controls whether the Date header field is reset to the current date/time when an
	// email is loaded from LoadMbx, LoadEml, LoadMime, LoadXml, or LoadXmlString. The
	// default is false (to not reset the date). To automatically reset the date, set
	// this property equal to true.
	bool get_ResetDateOnLoad(void);
	// Controls whether the Date header field is reset to the current date/time when an
	// email is loaded from LoadMbx, LoadEml, LoadMime, LoadXml, or LoadXmlString. The
	// default is false (to not reset the date). To automatically reset the date, set
	// this property equal to true.
	void put_ResetDateOnLoad(bool newVal);

	// The buffer size to be used with the underlying TCP/IP socket for sending. The
	// default value is 32767.
	int get_SendBufferSize(void);
	// The buffer size to be used with the underlying TCP/IP socket for sending. The
	// default value is 32767.
	void put_SendBufferSize(int newVal);

	// Determines how emails are sent to distribution lists. If true, emails are sent
	// to each recipient in the list one at a time, with the "To"header field
	// containing the email address of the recipient. If false, emails will contain
	// in the "To"header field, and are sent to 100 BCC recipients at a time. As an
	// example, if your distribution list contained 350 email addresses, 4 emails would
	// be sent, the first 3 having 100 BCC recipients, and the last email with 50 BCC
	// recipients.The default value of this property is true.
	bool get_SendIndividual(void);
	// Determines how emails are sent to distribution lists. If true, emails are sent
	// to each recipient in the list one at a time, with the "To"header field
	// containing the email address of the recipient. If false, emails will contain
	// in the "To"header field, and are sent to 100 BCC recipients at a time. As an
	// example, if your distribution list contained 350 email addresses, 4 emails would
	// be sent, the first 3 having 100 BCC recipients, and the last email with 50 BCC
	// recipients.The default value of this property is true.
	void put_SendIndividual(bool newVal);

	// The MailMan will not try to retrieve mail messages from a POP3 server that are
	// greater than this size limit. The default value is 0 indicating no size limit.
	// The SizeLimit is specified in number of bytes.
	int get_SizeLimit(void);
	// The MailMan will not try to retrieve mail messages from a POP3 server that are
	// greater than this size limit. The default value is 0 indicating no size limit.
	// The SizeLimit is specified in number of bytes.
	void put_SizeLimit(int newVal);

	// This property should usually be left empty. The MailMan will by default choose
	// the most secure login method available to prevent unencrypted username and
	// passwords from being transmitted if possible. However, some SMTP servers may not
	// advertise the acceptable authorization methods, and therefore it is not possible
	// to automatically determine the best authorization method. To force a particular
	// auth method, or to prevent any authorization from being used, set this property
	// to one of the following values: "NONE", "LOGIN", "PLAIN", "CRAM-MD5", or "NTLM".
	// 
	// Note: If NTLM authentication does not succeed, set the Global.DefaultNtlmVersion
	// property equal to 1 and then retry.
	// 
	void get_SmtpAuthMethod(CkString &str);
	// This property should usually be left empty. The MailMan will by default choose
	// the most secure login method available to prevent unencrypted username and
	// passwords from being transmitted if possible. However, some SMTP servers may not
	// advertise the acceptable authorization methods, and therefore it is not possible
	// to automatically determine the best authorization method. To force a particular
	// auth method, or to prevent any authorization from being used, set this property
	// to one of the following values: "NONE", "LOGIN", "PLAIN", "CRAM-MD5", or "NTLM".
	// 
	// Note: If NTLM authentication does not succeed, set the Global.DefaultNtlmVersion
	// property equal to 1 and then retry.
	// 
	const char *smtpAuthMethod(void);
	// This property should usually be left empty. The MailMan will by default choose
	// the most secure login method available to prevent unencrypted username and
	// passwords from being transmitted if possible. However, some SMTP servers may not
	// advertise the acceptable authorization methods, and therefore it is not possible
	// to automatically determine the best authorization method. To force a particular
	// auth method, or to prevent any authorization from being used, set this property
	// to one of the following values: "NONE", "LOGIN", "PLAIN", "CRAM-MD5", or "NTLM".
	// 
	// Note: If NTLM authentication does not succeed, set the Global.DefaultNtlmVersion
	// property equal to 1 and then retry.
	// 
	void put_SmtpAuthMethod(const char *newVal);

	// A keyword that indicates the cause of failure (or success) for the last SMTP
	// related method called. Possible values are:
	//     Success The method call was successful.
	//     Failed A general failure not covered by any of the other possible keywords.
	//     NoValidRecipients The SMTP server rejected all receipients.
	//     NoRecipients The app failed to provide any recipients (TO, CC, or BCC).
	//     SomeBadRecipients The AllOrNone property is true, and some recipients were
	//     rejected by the SMTP server.
	//     Aborted The application aborted the method.
	//     NoFrom The failed to provide a FROM address.
	//     FromFailure The SMTP replied with an error in response to the "MAIL FROM"
	//     command.
	//     NoCredentials The application did not provide the required credentials, such
	//     as username or password.
	//     AuthFailure The login (authentication) failed.
	//     DataFailure The SMTP replied with an error in response to the "DATA"
	//     command.
	//     NoSmtpHostname The application failed to provide an SMTP hostname or IP
	//     address.
	//     StartTlsFailed Failed to convert the TCP connection to TLS via STARTTLS.
	//     ConnectFailed Unable to establish a TCP or TLS connection to the SMTP
	//     server.
	//     GreetingError The SMTP server immediately responded with an error status in
	//     the intial greeting.
	//     ConnectionLost The connection to the SMTP server was lost at some point
	//     during the method call.
	//     Timeout A timeout occurred when reading or writing the socket connection.
	//     RenderFailed A failure occurred when rendering the email. (Rendering the
	//     email for sending includes tasks such as signing or encrypting.)
	//     NotUnlocked The UnlockComponent method was not previously called on at least
	//     one instance of the mailman object.
	//     InternalFailure An internal failure that should be reported to Chilkat
	//     support.
	void get_SmtpFailReason(CkString &str);
	// A keyword that indicates the cause of failure (or success) for the last SMTP
	// related method called. Possible values are:
	//     Success The method call was successful.
	//     Failed A general failure not covered by any of the other possible keywords.
	//     NoValidRecipients The SMTP server rejected all receipients.
	//     NoRecipients The app failed to provide any recipients (TO, CC, or BCC).
	//     SomeBadRecipients The AllOrNone property is true, and some recipients were
	//     rejected by the SMTP server.
	//     Aborted The application aborted the method.
	//     NoFrom The failed to provide a FROM address.
	//     FromFailure The SMTP replied with an error in response to the "MAIL FROM"
	//     command.
	//     NoCredentials The application did not provide the required credentials, such
	//     as username or password.
	//     AuthFailure The login (authentication) failed.
	//     DataFailure The SMTP replied with an error in response to the "DATA"
	//     command.
	//     NoSmtpHostname The application failed to provide an SMTP hostname or IP
	//     address.
	//     StartTlsFailed Failed to convert the TCP connection to TLS via STARTTLS.
	//     ConnectFailed Unable to establish a TCP or TLS connection to the SMTP
	//     server.
	//     GreetingError The SMTP server immediately responded with an error status in
	//     the intial greeting.
	//     ConnectionLost The connection to the SMTP server was lost at some point
	//     during the method call.
	//     Timeout A timeout occurred when reading or writing the socket connection.
	//     RenderFailed A failure occurred when rendering the email. (Rendering the
	//     email for sending includes tasks such as signing or encrypting.)
	//     NotUnlocked The UnlockComponent method was not previously called on at least
	//     one instance of the mailman object.
	//     InternalFailure An internal failure that should be reported to Chilkat
	//     support.
	const char *smtpFailReason(void);

	// The domain name of the SMTP server. Do not include "http://" in the domain name.
	// This property may also be set to an IP address string, such as "168.144.70.227".
	// Both IPv4 and IPv6 address formats are supported.
	void get_SmtpHost(CkString &str);
	// The domain name of the SMTP server. Do not include "http://" in the domain name.
	// This property may also be set to an IP address string, such as "168.144.70.227".
	// Both IPv4 and IPv6 address formats are supported.
	const char *smtpHost(void);
	// The domain name of the SMTP server. Do not include "http://" in the domain name.
	// This property may also be set to an IP address string, such as "168.144.70.227".
	// Both IPv4 and IPv6 address formats are supported.
	void put_SmtpHost(const char *newVal);

	// The Windows domain for logging into the SMTP server. Use this only if your SMTP
	// server requires NTLM authentication, which means your SMTP server uses
	// Integrated Windows Authentication. If there is no domain, this can be left
	// empty.
	void get_SmtpLoginDomain(CkString &str);
	// The Windows domain for logging into the SMTP server. Use this only if your SMTP
	// server requires NTLM authentication, which means your SMTP server uses
	// Integrated Windows Authentication. If there is no domain, this can be left
	// empty.
	const char *smtpLoginDomain(void);
	// The Windows domain for logging into the SMTP server. Use this only if your SMTP
	// server requires NTLM authentication, which means your SMTP server uses
	// Integrated Windows Authentication. If there is no domain, this can be left
	// empty.
	void put_SmtpLoginDomain(const char *newVal);

	// The password for logging into the SMTP server. Use this only if your SMTP server
	// requires authentication. Chilkat Email.NET supports the LOGIN, PLAIN, CRAM-MD5,
	// and NTLM login methods, and it will automatically choose the most secure method
	// available. Additional login methods will be available in the future.
	// 
	// If NTLM (Windows-Integrated) authentication is used, the SmtpUsername and
	// SmtpPassword properties may be set to the string "default" to cause the
	// component to use the current logged-on credentials (of the calling process) for
	// authentication.
	// 
	void get_SmtpPassword(CkString &str);
	// The password for logging into the SMTP server. Use this only if your SMTP server
	// requires authentication. Chilkat Email.NET supports the LOGIN, PLAIN, CRAM-MD5,
	// and NTLM login methods, and it will automatically choose the most secure method
	// available. Additional login methods will be available in the future.
	// 
	// If NTLM (Windows-Integrated) authentication is used, the SmtpUsername and
	// SmtpPassword properties may be set to the string "default" to cause the
	// component to use the current logged-on credentials (of the calling process) for
	// authentication.
	// 
	const char *smtpPassword(void);
	// The password for logging into the SMTP server. Use this only if your SMTP server
	// requires authentication. Chilkat Email.NET supports the LOGIN, PLAIN, CRAM-MD5,
	// and NTLM login methods, and it will automatically choose the most secure method
	// available. Additional login methods will be available in the future.
	// 
	// If NTLM (Windows-Integrated) authentication is used, the SmtpUsername and
	// SmtpPassword properties may be set to the string "default" to cause the
	// component to use the current logged-on credentials (of the calling process) for
	// authentication.
	// 
	void put_SmtpPassword(const char *newVal);

	// Controls whether SMTP pipelining is automatically used when the SMTP server
	// indicates support for it. The default is true. Setting this property equal to
	// false will prevent the SMTP pipelining feature from being used.
	bool get_SmtpPipelining(void);
	// Controls whether SMTP pipelining is automatically used when the SMTP server
	// indicates support for it. The default is true. Setting this property equal to
	// false will prevent the SMTP pipelining feature from being used.
	void put_SmtpPipelining(bool newVal);

	// The port number of the SMTP server used to send email. Only needs to be set if
	// the SMTP server is running on a non-standard port. The default value is 25. If
	// SmtpSsl is set to true, this property should be set to 465. (TCP port 465 is
	// reserved by common industry practice for secure SMTP communication using the SSL
	// protocol.)
	int get_SmtpPort(void);
	// The port number of the SMTP server used to send email. Only needs to be set if
	// the SMTP server is running on a non-standard port. The default value is 25. If
	// SmtpSsl is set to true, this property should be set to 465. (TCP port 465 is
	// reserved by common industry practice for secure SMTP communication using the SSL
	// protocol.)
	void put_SmtpPort(int newVal);

	// This string property accumulates the raw commands sent to the SMTP server, and
	// the raw responses received from the SMTP server. This property is read-only, but
	// it may be cleared by calling ClearSmtpSessionLog.
	void get_SmtpSessionLog(CkString &str);
	// This string property accumulates the raw commands sent to the SMTP server, and
	// the raw responses received from the SMTP server. This property is read-only, but
	// it may be cleared by calling ClearSmtpSessionLog.
	const char *smtpSessionLog(void);

	// When set to true, causes the mailman to connect to the SMTP server with
	// implicit SSL/TLS.
	bool get_SmtpSsl(void);
	// When set to true, causes the mailman to connect to the SMTP server with
	// implicit SSL/TLS.
	void put_SmtpSsl(bool newVal);

	// If using SSL, this property will be set to true if the SMTP server's SSL
	// certificate was verified when establishing the connection. Otherwise it is set
	// to false.
	bool get_SmtpSslServerCertVerified(void);

	// The login for logging into the SMTP server. Use this only if your SMTP server
	// requires authentication.
	// 
	// Note: In many cases, an SMTP server will not require authentication when sending
	// to an email address local to it's domain. However, when sending email to an
	// external domain, authentication is required (i.e. the SMTP server is being used
	// as a relay).
	// 
	// If the SmtpAuthMethod property is set to "NTLM", the SmtpUsername and
	// SmtpPassword properties may be set to the string "default" to use the current
	// Windows logged-on user credentials.
	// 
	// smtp.office365.com: If SMTP authentication fails for your smtp.office365.com
	// account, it may be that your account is configured to require MFA (multi-factor
	// authentication). You may need to change settings to allow for legacy
	// authentication (single-factor auth). See
	// https://docs.microsoft.com/en-us/azure/active-directory/conditional-access/block-
	// legacy-authentication Also, an app password may be required. See
	// https://docs.microsoft.com/en-us/azure/active-directory/user-help/multi-factor-au
	// thentication-end-user-app-passwords
	// 
	void get_SmtpUsername(CkString &str);
	// The login for logging into the SMTP server. Use this only if your SMTP server
	// requires authentication.
	// 
	// Note: In many cases, an SMTP server will not require authentication when sending
	// to an email address local to it's domain. However, when sending email to an
	// external domain, authentication is required (i.e. the SMTP server is being used
	// as a relay).
	// 
	// If the SmtpAuthMethod property is set to "NTLM", the SmtpUsername and
	// SmtpPassword properties may be set to the string "default" to use the current
	// Windows logged-on user credentials.
	// 
	// smtp.office365.com: If SMTP authentication fails for your smtp.office365.com
	// account, it may be that your account is configured to require MFA (multi-factor
	// authentication). You may need to change settings to allow for legacy
	// authentication (single-factor auth). See
	// https://docs.microsoft.com/en-us/azure/active-directory/conditional-access/block-
	// legacy-authentication Also, an app password may be required. See
	// https://docs.microsoft.com/en-us/azure/active-directory/user-help/multi-factor-au
	// thentication-end-user-app-passwords
	// 
	const char *smtpUsername(void);
	// The login for logging into the SMTP server. Use this only if your SMTP server
	// requires authentication.
	// 
	// Note: In many cases, an SMTP server will not require authentication when sending
	// to an email address local to it's domain. However, when sending email to an
	// external domain, authentication is required (i.e. the SMTP server is being used
	// as a relay).
	// 
	// If the SmtpAuthMethod property is set to "NTLM", the SmtpUsername and
	// SmtpPassword properties may be set to the string "default" to use the current
	// Windows logged-on user credentials.
	// 
	// smtp.office365.com: If SMTP authentication fails for your smtp.office365.com
	// account, it may be that your account is configured to require MFA (multi-factor
	// authentication). You may need to change settings to allow for legacy
	// authentication (single-factor auth). See
	// https://docs.microsoft.com/en-us/azure/active-directory/conditional-access/block-
	// legacy-authentication Also, an app password may be required. See
	// https://docs.microsoft.com/en-us/azure/active-directory/user-help/multi-factor-au
	// thentication-end-user-app-passwords
	// 
	void put_SmtpUsername(const char *newVal);

	// The SOCKS4/SOCKS5 hostname or IPv4 address (in dotted decimal notation). This
	// property is only used if the SocksVersion property is set to 4 or 5).
	void get_SocksHostname(CkString &str);
	// The SOCKS4/SOCKS5 hostname or IPv4 address (in dotted decimal notation). This
	// property is only used if the SocksVersion property is set to 4 or 5).
	const char *socksHostname(void);
	// The SOCKS4/SOCKS5 hostname or IPv4 address (in dotted decimal notation). This
	// property is only used if the SocksVersion property is set to 4 or 5).
	void put_SocksHostname(const char *newVal);

	// The SOCKS5 password (if required). The SOCKS4 protocol does not include the use
	// of a password, so this does not apply to SOCKS4.
	void get_SocksPassword(CkString &str);
	// The SOCKS5 password (if required). The SOCKS4 protocol does not include the use
	// of a password, so this does not apply to SOCKS4.
	const char *socksPassword(void);
	// The SOCKS5 password (if required). The SOCKS4 protocol does not include the use
	// of a password, so this does not apply to SOCKS4.
	void put_SocksPassword(const char *newVal);

	// The SOCKS4/SOCKS5 proxy port. The default value is 1080. This property only
	// applies if a SOCKS proxy is used (if the SocksVersion property is set to 4 or
	// 5).
	int get_SocksPort(void);
	// The SOCKS4/SOCKS5 proxy port. The default value is 1080. This property only
	// applies if a SOCKS proxy is used (if the SocksVersion property is set to 4 or
	// 5).
	void put_SocksPort(int newVal);

	// The SOCKS4/SOCKS5 proxy username. This property is only used if the SocksVersion
	// property is set to 4 or 5).
	void get_SocksUsername(CkString &str);
	// The SOCKS4/SOCKS5 proxy username. This property is only used if the SocksVersion
	// property is set to 4 or 5).
	const char *socksUsername(void);
	// The SOCKS4/SOCKS5 proxy username. This property is only used if the SocksVersion
	// property is set to 4 or 5).
	void put_SocksUsername(const char *newVal);

	// May be set to one of the following integer values:
	// 
	// 0 - No SOCKS proxy is used. This is the default.
	// 4 - Connect via a SOCKS4 proxy.
	// 5 - Connect via a SOCKS5 proxy.
	// 
	int get_SocksVersion(void);
	// May be set to one of the following integer values:
	// 
	// 0 - No SOCKS proxy is used. This is the default.
	// 4 - Connect via a SOCKS4 proxy.
	// 5 - Connect via a SOCKS5 proxy.
	// 
	void put_SocksVersion(int newVal);

	// Sets the receive buffer size socket option. Normally, this property should be
	// left unchanged. The default value is 4194304.
	// 
	// This property can be increased if download performance seems slow. It is
	// recommended to be a multiple of 4096.
	// 
	int get_SoRcvBuf(void);
	// Sets the receive buffer size socket option. Normally, this property should be
	// left unchanged. The default value is 4194304.
	// 
	// This property can be increased if download performance seems slow. It is
	// recommended to be a multiple of 4096.
	// 
	void put_SoRcvBuf(int newVal);

	// Sets the send buffer size socket option. Normally, this property should be left
	// unchanged. The default value is 262144.
	// 
	// This property can be increased if upload performance seems slow. It is
	// recommended to be a multiple of 4096. Testing with sizes such as 512K and 1MB is
	// reasonable.
	// 
	int get_SoSndBuf(void);
	// Sets the send buffer size socket option. Normally, this property should be left
	// unchanged. The default value is 262144.
	// 
	// This property can be increased if upload performance seems slow. It is
	// recommended to be a multiple of 4096. Testing with sizes such as 512K and 1MB is
	// reasonable.
	// 
	void put_SoSndBuf(int newVal);

	// Provides a means for setting a list of ciphers that are allowed for SSL/TLS
	// connections. The default (empty string) indicates that all implemented ciphers
	// are possible. The TLS ciphers supported in Chilkat v9.5.0.55 and later are:TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256
	// TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256
	// TLS_DHE_RSA_WITH_CHACHA20_POLY1305_SHA256
	// TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
	// TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
	// TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA
	// TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384
	// TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384
	// TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
	// TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA
	// TLS_DHE_RSA_WITH_AES_256_CBC_SHA256
	// TLS_DHE_RSA_WITH_AES_256_GCM_SHA384
	// TLS_DHE_RSA_WITH_AES_256_CBC_SHA
	// TLS_RSA_WITH_AES_256_CBC_SHA256
	// TLS_RSA_WITH_AES_256_GCM_SHA384
	// TLS_RSA_WITH_AES_256_CBC_SHA
	// TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256
	// TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
	// TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA
	// TLS_DHE_RSA_WITH_AES_128_CBC_SHA256
	// TLS_DHE_RSA_WITH_AES_128_GCM_SHA256
	// TLS_DHE_RSA_WITH_AES_128_CBC_SHA
	// TLS_RSA_WITH_AES_128_CBC_SHA256
	// TLS_RSA_WITH_AES_128_GCM_SHA256
	// TLS_RSA_WITH_AES_128_CBC_SHA
	// TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA
	// TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA
	// TLS_RSA_WITH_3DES_EDE_CBC_SHA
	// TLS_ECDHE_RSA_WITH_RC4_128_SHA
	// TLS_RSA_WITH_RC4_128_SHA
	// TLS_RSA_WITH_RC4_128_MD5
	// TLS_DHE_RSA_WITH_DES_CBC_SHA
	// TLS_RSA_WITH_DES_CBC_SHA To restrict SSL/TLS connections to one or more specific
	// ciphers, set this property to a comma-separated list of ciphers such as
	// "TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384, TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384".
	// The order should be in terms of preference, with the preferred algorithms listed
	// first. (Note that the client cannot specifically choose the algorithm is picked
	// because it is the server that chooses. The client simply provides the server
	// with a list from which to choose.)
	// 
	// The property can also disallow connections with servers having certificates with
	// RSA keys less than a certain size. By default, server certificates having RSA
	// keys of 512 bits or greater are allowed. Add the keyword "rsa1024" to disallow
	// connections with servers having keys smaller than 1024 bits. Add the keyword
	// "rsa2048" to disallow connections with servers having keys smaller than 2048
	// bits.
	// 
	// Note: Prior to Chilkat v9.5.0.55, it was not possible to explicitly list allowed
	// cipher suites. The deprecated means for indicating allowed ciphers was both
	// incomplete and unprecise. For example, the following keywords could be listed to
	// allow matching ciphers: "aes256-cbc", "aes128-cbc", "3des-cbc", and "rc4". These
	// keywords will still be recognized, but programs should be updated to explicitly
	// list the allowed ciphers.
	// 
	// secure-renegotiation: Starting in Chilkat v9.5.0.55, the keyword
	// "secure-renegotiation" may be added to require that all renegotions be done
	// securely (as per RFC 5746).
	// 
	// best-practices: Starting in Chilkat v9.5.0.55, this property may be set to the
	// single keyword "best-practices". This will allow ciphers based on the current
	// best practices. As new versions of Chilkat are released, the best practices may
	// change. Changes will be noted here. The current best practices are:
	// 
	//     If the server uses an RSA key, it must be 1024 bits or greater.
	//     All renegotations must be secure renegotiations.
	//     All ciphers using RC4, DES, or 3DES are disallowed.
	// 
	// Example: The following string would restrict to 2 specific cipher suites,
	// require RSA keys to be 1024 bits or greater, and require secure renegotiations:
	// "TLS_DHE_RSA_WITH_AES_256_CBC_SHA256, TLS_RSA_WITH_AES_256_CBC_SHA, rsa1024,
	// secure-renegotiation"
	// 
	void get_SslAllowedCiphers(CkString &str);
	// Provides a means for setting a list of ciphers that are allowed for SSL/TLS
	// connections. The default (empty string) indicates that all implemented ciphers
	// are possible. The TLS ciphers supported in Chilkat v9.5.0.55 and later are:TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256
	// TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256
	// TLS_DHE_RSA_WITH_CHACHA20_POLY1305_SHA256
	// TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
	// TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
	// TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA
	// TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384
	// TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384
	// TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
	// TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA
	// TLS_DHE_RSA_WITH_AES_256_CBC_SHA256
	// TLS_DHE_RSA_WITH_AES_256_GCM_SHA384
	// TLS_DHE_RSA_WITH_AES_256_CBC_SHA
	// TLS_RSA_WITH_AES_256_CBC_SHA256
	// TLS_RSA_WITH_AES_256_GCM_SHA384
	// TLS_RSA_WITH_AES_256_CBC_SHA
	// TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256
	// TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
	// TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA
	// TLS_DHE_RSA_WITH_AES_128_CBC_SHA256
	// TLS_DHE_RSA_WITH_AES_128_GCM_SHA256
	// TLS_DHE_RSA_WITH_AES_128_CBC_SHA
	// TLS_RSA_WITH_AES_128_CBC_SHA256
	// TLS_RSA_WITH_AES_128_GCM_SHA256
	// TLS_RSA_WITH_AES_128_CBC_SHA
	// TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA
	// TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA
	// TLS_RSA_WITH_3DES_EDE_CBC_SHA
	// TLS_ECDHE_RSA_WITH_RC4_128_SHA
	// TLS_RSA_WITH_RC4_128_SHA
	// TLS_RSA_WITH_RC4_128_MD5
	// TLS_DHE_RSA_WITH_DES_CBC_SHA
	// TLS_RSA_WITH_DES_CBC_SHA To restrict SSL/TLS connections to one or more specific
	// ciphers, set this property to a comma-separated list of ciphers such as
	// "TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384, TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384".
	// The order should be in terms of preference, with the preferred algorithms listed
	// first. (Note that the client cannot specifically choose the algorithm is picked
	// because it is the server that chooses. The client simply provides the server
	// with a list from which to choose.)
	// 
	// The property can also disallow connections with servers having certificates with
	// RSA keys less than a certain size. By default, server certificates having RSA
	// keys of 512 bits or greater are allowed. Add the keyword "rsa1024" to disallow
	// connections with servers having keys smaller than 1024 bits. Add the keyword
	// "rsa2048" to disallow connections with servers having keys smaller than 2048
	// bits.
	// 
	// Note: Prior to Chilkat v9.5.0.55, it was not possible to explicitly list allowed
	// cipher suites. The deprecated means for indicating allowed ciphers was both
	// incomplete and unprecise. For example, the following keywords could be listed to
	// allow matching ciphers: "aes256-cbc", "aes128-cbc", "3des-cbc", and "rc4". These
	// keywords will still be recognized, but programs should be updated to explicitly
	// list the allowed ciphers.
	// 
	// secure-renegotiation: Starting in Chilkat v9.5.0.55, the keyword
	// "secure-renegotiation" may be added to require that all renegotions be done
	// securely (as per RFC 5746).
	// 
	// best-practices: Starting in Chilkat v9.5.0.55, this property may be set to the
	// single keyword "best-practices". This will allow ciphers based on the current
	// best practices. As new versions of Chilkat are released, the best practices may
	// change. Changes will be noted here. The current best practices are:
	// 
	//     If the server uses an RSA key, it must be 1024 bits or greater.
	//     All renegotations must be secure renegotiations.
	//     All ciphers using RC4, DES, or 3DES are disallowed.
	// 
	// Example: The following string would restrict to 2 specific cipher suites,
	// require RSA keys to be 1024 bits or greater, and require secure renegotiations:
	// "TLS_DHE_RSA_WITH_AES_256_CBC_SHA256, TLS_RSA_WITH_AES_256_CBC_SHA, rsa1024,
	// secure-renegotiation"
	// 
	const char *sslAllowedCiphers(void);
	// Provides a means for setting a list of ciphers that are allowed for SSL/TLS
	// connections. The default (empty string) indicates that all implemented ciphers
	// are possible. The TLS ciphers supported in Chilkat v9.5.0.55 and later are:TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256
	// TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256
	// TLS_DHE_RSA_WITH_CHACHA20_POLY1305_SHA256
	// TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
	// TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
	// TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA
	// TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384
	// TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384
	// TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
	// TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA
	// TLS_DHE_RSA_WITH_AES_256_CBC_SHA256
	// TLS_DHE_RSA_WITH_AES_256_GCM_SHA384
	// TLS_DHE_RSA_WITH_AES_256_CBC_SHA
	// TLS_RSA_WITH_AES_256_CBC_SHA256
	// TLS_RSA_WITH_AES_256_GCM_SHA384
	// TLS_RSA_WITH_AES_256_CBC_SHA
	// TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256
	// TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
	// TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA
	// TLS_DHE_RSA_WITH_AES_128_CBC_SHA256
	// TLS_DHE_RSA_WITH_AES_128_GCM_SHA256
	// TLS_DHE_RSA_WITH_AES_128_CBC_SHA
	// TLS_RSA_WITH_AES_128_CBC_SHA256
	// TLS_RSA_WITH_AES_128_GCM_SHA256
	// TLS_RSA_WITH_AES_128_CBC_SHA
	// TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA
	// TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA
	// TLS_RSA_WITH_3DES_EDE_CBC_SHA
	// TLS_ECDHE_RSA_WITH_RC4_128_SHA
	// TLS_RSA_WITH_RC4_128_SHA
	// TLS_RSA_WITH_RC4_128_MD5
	// TLS_DHE_RSA_WITH_DES_CBC_SHA
	// TLS_RSA_WITH_DES_CBC_SHA To restrict SSL/TLS connections to one or more specific
	// ciphers, set this property to a comma-separated list of ciphers such as
	// "TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384, TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384".
	// The order should be in terms of preference, with the preferred algorithms listed
	// first. (Note that the client cannot specifically choose the algorithm is picked
	// because it is the server that chooses. The client simply provides the server
	// with a list from which to choose.)
	// 
	// The property can also disallow connections with servers having certificates with
	// RSA keys less than a certain size. By default, server certificates having RSA
	// keys of 512 bits or greater are allowed. Add the keyword "rsa1024" to disallow
	// connections with servers having keys smaller than 1024 bits. Add the keyword
	// "rsa2048" to disallow connections with servers having keys smaller than 2048
	// bits.
	// 
	// Note: Prior to Chilkat v9.5.0.55, it was not possible to explicitly list allowed
	// cipher suites. The deprecated means for indicating allowed ciphers was both
	// incomplete and unprecise. For example, the following keywords could be listed to
	// allow matching ciphers: "aes256-cbc", "aes128-cbc", "3des-cbc", and "rc4". These
	// keywords will still be recognized, but programs should be updated to explicitly
	// list the allowed ciphers.
	// 
	// secure-renegotiation: Starting in Chilkat v9.5.0.55, the keyword
	// "secure-renegotiation" may be added to require that all renegotions be done
	// securely (as per RFC 5746).
	// 
	// best-practices: Starting in Chilkat v9.5.0.55, this property may be set to the
	// single keyword "best-practices". This will allow ciphers based on the current
	// best practices. As new versions of Chilkat are released, the best practices may
	// change. Changes will be noted here. The current best practices are:
	// 
	//     If the server uses an RSA key, it must be 1024 bits or greater.
	//     All renegotations must be secure renegotiations.
	//     All ciphers using RC4, DES, or 3DES are disallowed.
	// 
	// Example: The following string would restrict to 2 specific cipher suites,
	// require RSA keys to be 1024 bits or greater, and require secure renegotiations:
	// "TLS_DHE_RSA_WITH_AES_256_CBC_SHA256, TLS_RSA_WITH_AES_256_CBC_SHA, rsa1024,
	// secure-renegotiation"
	// 
	void put_SslAllowedCiphers(const char *newVal);

	// Selects the secure protocol to be used for secure (SSL/TLS) connections (for
	// both SMTP and POP3). Possible values are:
	// 
	//     default
	//     TLS 1.3
	//     TLS 1.2
	//     TLS 1.1
	//     TLS 1.0
	//     SSL 3.0
	//     TLS 1.3 or higher
	//     TLS 1.2 or higher
	//     TLS 1.1 or higher
	//     TLS 1.0 or higher
	//      
	// 
	// The default value is "default" which will choose the, which allows for the
	// protocol to be selected dynamically at runtime based on the requirements of the
	// server. Choosing an exact protocol will cause the connection to fail unless that
	// exact protocol is negotiated. It is better to choose "X or higher" than an exact
	// protocol. The "default" is effectively "SSL 3.0 or higher".
	void get_SslProtocol(CkString &str);
	// Selects the secure protocol to be used for secure (SSL/TLS) connections (for
	// both SMTP and POP3). Possible values are:
	// 
	//     default
	//     TLS 1.3
	//     TLS 1.2
	//     TLS 1.1
	//     TLS 1.0
	//     SSL 3.0
	//     TLS 1.3 or higher
	//     TLS 1.2 or higher
	//     TLS 1.1 or higher
	//     TLS 1.0 or higher
	//      
	// 
	// The default value is "default" which will choose the, which allows for the
	// protocol to be selected dynamically at runtime based on the requirements of the
	// server. Choosing an exact protocol will cause the connection to fail unless that
	// exact protocol is negotiated. It is better to choose "X or higher" than an exact
	// protocol. The "default" is effectively "SSL 3.0 or higher".
	const char *sslProtocol(void);
	// Selects the secure protocol to be used for secure (SSL/TLS) connections (for
	// both SMTP and POP3). Possible values are:
	// 
	//     default
	//     TLS 1.3
	//     TLS 1.2
	//     TLS 1.1
	//     TLS 1.0
	//     SSL 3.0
	//     TLS 1.3 or higher
	//     TLS 1.2 or higher
	//     TLS 1.1 or higher
	//     TLS 1.0 or higher
	//      
	// 
	// The default value is "default" which will choose the, which allows for the
	// protocol to be selected dynamically at runtime based on the requirements of the
	// server. Choosing an exact protocol will cause the connection to fail unless that
	// exact protocol is negotiated. It is better to choose "X or higher" than an exact
	// protocol. The "default" is effectively "SSL 3.0 or higher".
	void put_SslProtocol(const char *newVal);

	// When set to true, causes the mailman to issue a STARTTLS command to switch
	// over to a secure SSL/TLS connection prior to authenticating and sending email.
	// The default value is false.
	// 
	// Note: This property applies to SMTP, not to POP3.
	// 
	bool get_StartTLS(void);
	// When set to true, causes the mailman to issue a STARTTLS command to switch
	// over to a secure SSL/TLS connection prior to authenticating and sending email.
	// The default value is false.
	// 
	// Note: This property applies to SMTP, not to POP3.
	// 
	void put_StartTLS(bool newVal);

	// When set to true, causes the mailman to do STARTTLS (if possible and supported
	// by the server) to convert to a secure SMTP SSL/TLS connection prior to
	// authenticating and sending email. The default value is true.
	// 
	// Note: Setting the StartTLS property = true causes STARTTLS to always be used,
	// even if the SMTP server does not support it. This property allows for a
	// non-encrypted connection, whereas the StartTLS property disallows non-encrypted
	// connections.
	// 
	// Note: This property applies to SMTP, not to POP3.
	// 
	bool get_StartTLSifPossible(void);
	// When set to true, causes the mailman to do STARTTLS (if possible and supported
	// by the server) to convert to a secure SMTP SSL/TLS connection prior to
	// authenticating and sending email. The default value is true.
	// 
	// Note: Setting the StartTLS property = true causes STARTTLS to always be used,
	// even if the SMTP server does not support it. This property allows for a
	// non-encrypted connection, whereas the StartTLS property disallows non-encrypted
	// connections.
	// 
	// Note: This property applies to SMTP, not to POP3.
	// 
	void put_StartTLSifPossible(bool newVal);

	// Contains the current or last negotiated TLS cipher suite. If no TLS connection
	// has yet to be established, or if a connection as attempted and failed, then this
	// will be empty. A sample cipher suite string looks like this:
	// TLS_DHE_RSA_WITH_AES_256_CBC_SHA256.
	void get_TlsCipherSuite(CkString &str);
	// Contains the current or last negotiated TLS cipher suite. If no TLS connection
	// has yet to be established, or if a connection as attempted and failed, then this
	// will be empty. A sample cipher suite string looks like this:
	// TLS_DHE_RSA_WITH_AES_256_CBC_SHA256.
	const char *tlsCipherSuite(void);

	// Specifies a set of pins for Public Key Pinning for TLS connections. This
	// property lists the expected SPKI fingerprints for the server certificates. If
	// the server's certificate (sent during the TLS handshake) does not match any of
	// the SPKI fingerprints, then the TLS handshake is aborted and the connection
	// fails. The format of this string property is as follows:hash_algorithm,
	// encoding, SPKI_fingerprint_1, SPKI_fingerprint_2, ... For example, the following
	// string specifies a single sha256 base64-encoded SPKI fingerprint:"sha256,
	// base64, lKg1SIqyhPSK19tlPbjl8s02yChsVTDklQpkMCHvsTE=" This example specifies two
	// SPKI fingerprints:"sha256, base64, 4t37LpnGmrMEAG8HEz9yIrnvJV2euVRwCLb9EH5WZyI=,
	// 68b0G5iqMvWVWvUCjMuhLEyekM5729PadtnU5tdXZKs=" Any of the following hash
	// algorithms are allowed:.sha1, sha256, sha384, sha512, md2, md5, haval,
	// ripemd128, ripemd160,ripemd256, or ripemd320.
	// 
	// The following encodings are allowed: base64, hex, and any of the encodings
	// indicated in the link below.
	// 
	void get_TlsPinSet(CkString &str);
	// Specifies a set of pins for Public Key Pinning for TLS connections. This
	// property lists the expected SPKI fingerprints for the server certificates. If
	// the server's certificate (sent during the TLS handshake) does not match any of
	// the SPKI fingerprints, then the TLS handshake is aborted and the connection
	// fails. The format of this string property is as follows:hash_algorithm,
	// encoding, SPKI_fingerprint_1, SPKI_fingerprint_2, ... For example, the following
	// string specifies a single sha256 base64-encoded SPKI fingerprint:"sha256,
	// base64, lKg1SIqyhPSK19tlPbjl8s02yChsVTDklQpkMCHvsTE=" This example specifies two
	// SPKI fingerprints:"sha256, base64, 4t37LpnGmrMEAG8HEz9yIrnvJV2euVRwCLb9EH5WZyI=,
	// 68b0G5iqMvWVWvUCjMuhLEyekM5729PadtnU5tdXZKs=" Any of the following hash
	// algorithms are allowed:.sha1, sha256, sha384, sha512, md2, md5, haval,
	// ripemd128, ripemd160,ripemd256, or ripemd320.
	// 
	// The following encodings are allowed: base64, hex, and any of the encodings
	// indicated in the link below.
	// 
	const char *tlsPinSet(void);
	// Specifies a set of pins for Public Key Pinning for TLS connections. This
	// property lists the expected SPKI fingerprints for the server certificates. If
	// the server's certificate (sent during the TLS handshake) does not match any of
	// the SPKI fingerprints, then the TLS handshake is aborted and the connection
	// fails. The format of this string property is as follows:hash_algorithm,
	// encoding, SPKI_fingerprint_1, SPKI_fingerprint_2, ... For example, the following
	// string specifies a single sha256 base64-encoded SPKI fingerprint:"sha256,
	// base64, lKg1SIqyhPSK19tlPbjl8s02yChsVTDklQpkMCHvsTE=" This example specifies two
	// SPKI fingerprints:"sha256, base64, 4t37LpnGmrMEAG8HEz9yIrnvJV2euVRwCLb9EH5WZyI=,
	// 68b0G5iqMvWVWvUCjMuhLEyekM5729PadtnU5tdXZKs=" Any of the following hash
	// algorithms are allowed:.sha1, sha256, sha384, sha512, md2, md5, haval,
	// ripemd128, ripemd160,ripemd256, or ripemd320.
	// 
	// The following encodings are allowed: base64, hex, and any of the encodings
	// indicated in the link below.
	// 
	void put_TlsPinSet(const char *newVal);

	// Contains the current or last negotiated TLS protocol version. If no TLS
	// connection has yet to be established, or if a connection as attempted and
	// failed, then this will be empty. Possible values are "SSL 3.0", "TLS 1.0", "TLS
	// 1.1", "TLS 1.2", and "TLS 1.3".
	void get_TlsVersion(CkString &str);
	// Contains the current or last negotiated TLS protocol version. If no TLS
	// connection has yet to be established, or if a connection as attempted and
	// failed, then this will be empty. Possible values are "SSL 3.0", "TLS 1.0", "TLS
	// 1.1", "TLS 1.2", and "TLS 1.3".
	const char *tlsVersion(void);

	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string and should typically remain empty. Can be set to a
	// list of the following comma separated keywords:
	//     "ProtectFromVpn" - Introduced in v9.5.0.80. On Android systems, will bypass
	//     any VPN that may be installed or active.
	void get_UncommonOptions(CkString &str);
	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string and should typically remain empty. Can be set to a
	// list of the following comma separated keywords:
	//     "ProtectFromVpn" - Introduced in v9.5.0.80. On Android systems, will bypass
	//     any VPN that may be installed or active.
	const char *uncommonOptions(void);
	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string and should typically remain empty. Can be set to a
	// list of the following comma separated keywords:
	//     "ProtectFromVpn" - Introduced in v9.5.0.80. On Android systems, will bypass
	//     any VPN that may be installed or active.
	void put_UncommonOptions(const char *newVal);

	// If true, will automatically use APOP authentication if the POP3 server
	// supports it. The default value of this property is false.
	bool get_UseApop(void);
	// If true, will automatically use APOP authentication if the POP3 server
	// supports it. The default value of this property is false.
	void put_UseApop(bool newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Adds a PFX to the object's internal list of sources to be searched for
	// certificates and private keys when decrypting or when creating signed email for
	// sending. Multiple PFX sources can be added by calling this method once for each.
	// (On the Windows operating system, the registry-based certificate stores are also
	// automatically searched, so it is commonly not required to explicitly add PFX
	// sources.)
	// 
	// The pfxData contains the bytes of a PFX file (also known as PKCS12 or .p12).
	// 
	bool AddPfxSourceData(CkByteData &pfxData, const char *password);


	// Adds a PFX file to the object's internal list of sources to be searched for
	// certificates and private keys when decrypting or when sending signed email.
	// Multiple PFX files can be added by calling this method once for each. (On the
	// Windows operating system, the registry-based certificate stores are also
	// automatically searched, so it is commonly not required to explicitly add PFX
	// sources.)
	// 
	// The pfxFilePath contains the bytes of a PFX file (also known as PKCS12 or .p12).
	// 
	bool AddPfxSourceFile(const char *pfxFilePath, const char *password);


	// Returns the number of emails available on the POP3 server. Returns -1 on error.
	// 
	// The VerifyPopConnection method can be called to verify basic TCP/IP connectivity
	// with the POP3 server. The VerifyPopLogin method can be called to verify the POP3
	// login. The Verify* methods are intended to be called as a way of diagnosing the
	// failure when a POP3 method returns an error status.
	// 
	int CheckMail(void);

	// Returns the number of emails available on the POP3 server. Returns -1 on error.
	// 
	// The VerifyPopConnection method can be called to verify basic TCP/IP connectivity
	// with the POP3 server. The VerifyPopLogin method can be called to verify the POP3
	// login. The Verify* methods are intended to be called as a way of diagnosing the
	// failure when a POP3 method returns an error status.
	// 
	CkTask *CheckMailAsync(void);


	// Clears the list of bad email addresses stored within the Mailman object. When an
	// email-sending method is called, any email addresses rejected by the SMTP server
	// will be cached within the Mailman object. These can be accessed by calling the
	// GetBadEmailAddresses method. This method clears the Mailman's in-memory cache of
	// bad addresses.
	void ClearBadEmailAddresses(void);


	// Clears the contents of the Pop3SessionLog property.
	void ClearPop3SessionLog(void);


	// Clears the contents of the SmtpSessionLog property.
	void ClearSmtpSessionLog(void);


	// The mailman object automatically opens an SMTP connection (if necessary)
	// whenever an email-sending method is called. The connection is kept open until
	// explicitly closed by this method. Calling this method is entirely optional. The
	// SMTP connection is also automatically closed when the mailman object is
	// destructed. Thus, if an application calls SendEmail 10 times to send 10 emails,
	// the 1st call will open the SMTP connection, while the subsequent 9 will send
	// over the existing connection (unless a property such as username, login,
	// hostname, etc. is changed, which would force the connection to become closed and
	// re-established with the next mail-sending method call).
	// 
	// Note: This method sends a QUIT command to the SMTP server prior to closing the
	// connection.
	// 
	bool CloseSmtpConnection(void);

	// The mailman object automatically opens an SMTP connection (if necessary)
	// whenever an email-sending method is called. The connection is kept open until
	// explicitly closed by this method. Calling this method is entirely optional. The
	// SMTP connection is also automatically closed when the mailman object is
	// destructed. Thus, if an application calls SendEmail 10 times to send 10 emails,
	// the 1st call will open the SMTP connection, while the subsequent 9 will send
	// over the existing connection (unless a property such as username, login,
	// hostname, etc. is changed, which would force the connection to become closed and
	// re-established with the next mail-sending method call).
	// 
	// Note: This method sends a QUIT command to the SMTP server prior to closing the
	// connection.
	// 
	CkTask *CloseSmtpConnectionAsync(void);


	// Copy the email from a POP3 server into a EmailBundle. This does not remove the
	// email from the POP3 server.
	// The caller is responsible for deleting the object returned by this method.
	CkEmailBundle *CopyMail(void);

	// Copy the email from a POP3 server into a EmailBundle. This does not remove the
	// email from the POP3 server.
	CkTask *CopyMailAsync(void);


	// Marks multiple emails on the POP3 server for deletion. (Each email in emailBundle that
	// is also present on the server is marked for deletion.) To complete the deletion
	// of the emails, a "QUIT" message must be sent and the POP3 session ended. This
	// will happen automatically when the ImmediateDelete property equals true, which
	// is the default. If ImmediateDelete equals false, then the Pop3EndSession
	// method can be called to send the "QUIT" and end the session (i.e. disconnect.)
	// 
	// Note: When making multiple calls to a Delete* method, it's best to turn off
	// ImmediateDelete, and then manually call Pop3EndSession to finalize the
	// deletions.
	// 
	// Also, any method call requiring communication with the POP3 server will
	// automatically re-establish a session based on the current property settings.
	// 
	bool DeleteBundle(CkEmailBundle &emailBundle);

	// Marks multiple emails on the POP3 server for deletion. (Each email in emailBundle that
	// is also present on the server is marked for deletion.) To complete the deletion
	// of the emails, a "QUIT" message must be sent and the POP3 session ended. This
	// will happen automatically when the ImmediateDelete property equals true, which
	// is the default. If ImmediateDelete equals false, then the Pop3EndSession
	// method can be called to send the "QUIT" and end the session (i.e. disconnect.)
	// 
	// Note: When making multiple calls to a Delete* method, it's best to turn off
	// ImmediateDelete, and then manually call Pop3EndSession to finalize the
	// deletions.
	// 
	// Also, any method call requiring communication with the POP3 server will
	// automatically re-establish a session based on the current property settings.
	// 
	CkTask *DeleteBundleAsync(CkEmailBundle &emailBundle);


	// Marks an email for deletion by message number. WARNING: Be very careful if
	// calling this method. Message numbers are specific to a POP3 session. If a
	// maildrop has (for example) 10 messages, the message numbers will be 1, 2, 3, ...
	// 10. If message number 1 is deleted and a new POP3 session is established, there
	// will be 9 messages numbered 1, 2, 3, ... 9.
	// 
	// IMPORTANT: A POP3 must first be established by either calling Pop3BeginSession
	// explicitly, or implicitly by calling some other method that automatically
	// establishes the session. This method will not automatically establish a new POP3
	// session (because if it did, the message numbers would potentially be different
	// than what the application expects).
	// 
	// This method only marks an email for deletion. It is not actually removed from
	// the maildrop until the POP3 session is explicitly ended by calling
	// Pop3EndSession.
	// 
	bool DeleteByMsgnum(int msgnum);

	// Marks an email for deletion by message number. WARNING: Be very careful if
	// calling this method. Message numbers are specific to a POP3 session. If a
	// maildrop has (for example) 10 messages, the message numbers will be 1, 2, 3, ...
	// 10. If message number 1 is deleted and a new POP3 session is established, there
	// will be 9 messages numbered 1, 2, 3, ... 9.
	// 
	// IMPORTANT: A POP3 must first be established by either calling Pop3BeginSession
	// explicitly, or implicitly by calling some other method that automatically
	// establishes the session. This method will not automatically establish a new POP3
	// session (because if it did, the message numbers would potentially be different
	// than what the application expects).
	// 
	// This method only marks an email for deletion. It is not actually removed from
	// the maildrop until the POP3 session is explicitly ended by calling
	// Pop3EndSession.
	// 
	CkTask *DeleteByMsgnumAsync(int msgnum);


	// Marks an email on the POP3 server for deletion. To complete the deletion of an
	// email, a "QUIT" message must be sent and the POP3 session ended. This will
	// happen automatically when the ImmediateDelete property equals true, which is
	// the default. If ImmediateDelete equals false, then the Pop3EndSession method
	// can be called to send the "QUIT" and end the session (i.e. disconnect.)
	// 
	// Note: When making multiple calls to a Delete* method, it's best to turn off
	// ImmediateDelete, and then manually call Pop3EndSession to finalize the
	// deletions.
	// 
	// Also, any method call requiring communication with the POP3 server will
	// automatically re-establish a session based on the current property settings.
	// 
	bool DeleteByUidl(const char *uidl);

	// Marks an email on the POP3 server for deletion. To complete the deletion of an
	// email, a "QUIT" message must be sent and the POP3 session ended. This will
	// happen automatically when the ImmediateDelete property equals true, which is
	// the default. If ImmediateDelete equals false, then the Pop3EndSession method
	// can be called to send the "QUIT" and end the session (i.e. disconnect.)
	// 
	// Note: When making multiple calls to a Delete* method, it's best to turn off
	// ImmediateDelete, and then manually call Pop3EndSession to finalize the
	// deletions.
	// 
	// Also, any method call requiring communication with the POP3 server will
	// automatically re-establish a session based on the current property settings.
	// 
	CkTask *DeleteByUidlAsync(const char *uidl);


	// Marks an email on the POP3 server for deletion. To complete the deletion of an
	// email, a "QUIT" message must be sent and the POP3 session ended. This will
	// happen automatically when the ImmediateDelete property equals true, which is
	// the default. If ImmediateDelete equals false, then the Pop3EndSession method
	// can be called to send the "QUIT" and end the session (i.e. disconnect.)
	// 
	// Note: When making multiple calls to a Delete* method, it's best to turn off
	// ImmediateDelete, and then manually call Pop3EndSession to finalize the
	// deletions.
	// 
	// Also, any method call requiring communication with the POP3 server will
	// automatically re-establish a session based on the current property settings.
	// 
	bool DeleteEmail(CkEmail &email);

	// Marks an email on the POP3 server for deletion. To complete the deletion of an
	// email, a "QUIT" message must be sent and the POP3 session ended. This will
	// happen automatically when the ImmediateDelete property equals true, which is
	// the default. If ImmediateDelete equals false, then the Pop3EndSession method
	// can be called to send the "QUIT" and end the session (i.e. disconnect.)
	// 
	// Note: When making multiple calls to a Delete* method, it's best to turn off
	// ImmediateDelete, and then manually call Pop3EndSession to finalize the
	// deletions.
	// 
	// Also, any method call requiring communication with the POP3 server will
	// automatically re-establish a session based on the current property settings.
	// 
	CkTask *DeleteEmailAsync(CkEmail &email);


	// Marks multiple emails on the POP3 server for deletion. (Any email on the server
	// having a UIDL equal to a UIDL found in uidlArray is marked for deletion.) To complete
	// the deletion of the emails, a "QUIT" message must be sent and the POP3 session
	// ended. This will happen automatically when the ImmediateDelete property equals
	// true, which is the default. If ImmediateDelete equals false, then the
	// Pop3EndSession method can be called to send the "QUIT" and end the session (i.e.
	// disconnect.)
	// 
	// Note: When making multiple calls to a Delete* method, it's best to turn off
	// ImmediateDelete, and then manually call Pop3EndSession to finalize the
	// deletions.
	// 
	// Also, any method call requiring communication with the POP3 server will
	// automatically re-establish a session based on the current property settings.
	// 
	bool DeleteMultiple(CkStringArray &uidlArray);

	// Marks multiple emails on the POP3 server for deletion. (Any email on the server
	// having a UIDL equal to a UIDL found in uidlArray is marked for deletion.) To complete
	// the deletion of the emails, a "QUIT" message must be sent and the POP3 session
	// ended. This will happen automatically when the ImmediateDelete property equals
	// true, which is the default. If ImmediateDelete equals false, then the
	// Pop3EndSession method can be called to send the "QUIT" and end the session (i.e.
	// disconnect.)
	// 
	// Note: When making multiple calls to a Delete* method, it's best to turn off
	// ImmediateDelete, and then manually call Pop3EndSession to finalize the
	// deletions.
	// 
	// Also, any method call requiring communication with the POP3 server will
	// automatically re-establish a session based on the current property settings.
	// 
	CkTask *DeleteMultipleAsync(CkStringArray &uidlArray);


	// Fetches an email by message number. WARNING: Be very careful if calling this
	// method. Message numbers are specific to a POP3 session. If a maildrop has (for
	// example) 10 messages, the message numbers will be 1, 2, 3, ... 10. If message
	// number 1 is deleted and a new POP3 session is established, there will be 9
	// messages numbered 1, 2, 3, ... 9.
	// 
	// IMPORTANT: A POP3 connection must first be established by either calling
	// Pop3BeginSession explicitly, or implicitly by calling some other method that
	// automatically establishes the session. This method will not automatically
	// establish a new POP3 session (because if it did, the message numbers would
	// potentially be different than what the application expects).
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *FetchByMsgnum(int msgnum);

	// Fetches an email by message number. WARNING: Be very careful if calling this
	// method. Message numbers are specific to a POP3 session. If a maildrop has (for
	// example) 10 messages, the message numbers will be 1, 2, 3, ... 10. If message
	// number 1 is deleted and a new POP3 session is established, there will be 9
	// messages numbered 1, 2, 3, ... 9.
	// 
	// IMPORTANT: A POP3 connection must first be established by either calling
	// Pop3BeginSession explicitly, or implicitly by calling some other method that
	// automatically establishes the session. This method will not automatically
	// establish a new POP3 session (because if it did, the message numbers would
	// potentially be different than what the application expects).
	// 
	CkTask *FetchByMsgnumAsync(int msgnum);


	// Fetches an email from the POP3 mail server given its UIDL. Calling this method
	// does not remove the email from the server. A typical program might get the email
	// headers from the POP3 server by calling GetAllHeaders or GetHeaders, and then
	// fetch individual emails by UIDL.
	// 
	// Returns a null reference on failure.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *FetchEmail(const char *uidl);

	// Fetches an email from the POP3 mail server given its UIDL. Calling this method
	// does not remove the email from the server. A typical program might get the email
	// headers from the POP3 server by calling GetAllHeaders or GetHeaders, and then
	// fetch individual emails by UIDL.
	// 
	// Returns a null reference on failure.
	// 
	CkTask *FetchEmailAsync(const char *uidl);


	// Fetches an email by UIDL and returns the MIME source of the email in a byte
	// array.
	bool FetchMime(const char *uidl, CkByteData &outData);

	// Fetches an email by UIDL and returns the MIME source of the email in a byte
	// array.
	CkTask *FetchMimeAsync(const char *uidl);


	// Fetches an email by UIDL and returns the MIME source of the email in uidl.
	bool FetchMimeBd(const char *uidl, CkBinData &mimeData);

	// Fetches an email by UIDL and returns the MIME source of the email in uidl.
	CkTask *FetchMimeBdAsync(const char *uidl, CkBinData &mimeData);


	// Fetches an email by message number and returns the MIME source of the email in a
	// byte array. WARNING: Message sequend numbers are specific to a POP3 session. If
	// a maildrop has (for example) 10 messages, the message numbers will be 1, 2, 3,
	// ... 10. If message number 1 is deleted and a new POP3 session is established,
	// there will be 9 messages numbered 1, 2, 3, ... 9.
	// 
	// IMPORTANT: A POP3 connection must first be established by either calling
	// Pop3BeginSession explicitly, or implicitly by calling some other method that
	// automatically establishes the session. This method will not automatically
	// establish a new POP3 session (because if it did, the message numbers would
	// potentially be different than what the application expects).
	// 
	bool FetchMimeByMsgnum(int msgnum, CkByteData &outBytes);

	// Fetches an email by message number and returns the MIME source of the email in a
	// byte array. WARNING: Message sequend numbers are specific to a POP3 session. If
	// a maildrop has (for example) 10 messages, the message numbers will be 1, 2, 3,
	// ... 10. If message number 1 is deleted and a new POP3 session is established,
	// there will be 9 messages numbered 1, 2, 3, ... 9.
	// 
	// IMPORTANT: A POP3 connection must first be established by either calling
	// Pop3BeginSession explicitly, or implicitly by calling some other method that
	// automatically establishes the session. This method will not automatically
	// establish a new POP3 session (because if it did, the message numbers would
	// potentially be different than what the application expects).
	// 
	CkTask *FetchMimeByMsgnumAsync(int msgnum);


	// Given an array of UIDL strings, fetchs all the emails from the POP3 server whose
	// UIDL is present in the array, and returns the emails in a bundle.
	// The caller is responsible for deleting the object returned by this method.
	CkEmailBundle *FetchMultiple(CkStringArray &uidlArray);

	// Given an array of UIDL strings, fetchs all the emails from the POP3 server whose
	// UIDL is present in the array, and returns the emails in a bundle.
	CkTask *FetchMultipleAsync(CkStringArray &uidlArray);


	// Given an array of UIDL strings, fetchs all the email headers from the POP3
	// server whose UIDL is present in the array.
	// 
	// Note: The email objects returned in the bundle contain only headers. The
	// attachments will be missing, and the bodies will be mostly missing (only the 1st
	// numBodyLines lines of either the plain-text or HTML body will be present).
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkEmailBundle *FetchMultipleHeaders(CkStringArray &uidlArray, int numBodyLines);

	// Given an array of UIDL strings, fetchs all the email headers from the POP3
	// server whose UIDL is present in the array.
	// 
	// Note: The email objects returned in the bundle contain only headers. The
	// attachments will be missing, and the bodies will be mostly missing (only the 1st
	// numBodyLines lines of either the plain-text or HTML body will be present).
	// 
	CkTask *FetchMultipleHeadersAsync(CkStringArray &uidlArray, int numBodyLines);


	// Given an array of UIDL strings, fetchs all the emails from the POP3 server whose
	// UIDL is present in the array, and returns the MIME source of each email in an
	// "stringarray" -- an object containing a collection of strings. Returns a null
	// reference on failure.
	// The caller is responsible for deleting the object returned by this method.
	CkStringArray *FetchMultipleMime(CkStringArray &uidlArray);

	// Given an array of UIDL strings, fetchs all the emails from the POP3 server whose
	// UIDL is present in the array, and returns the MIME source of each email in an
	// "stringarray" -- an object containing a collection of strings. Returns a null
	// reference on failure.
	CkTask *FetchMultipleMimeAsync(CkStringArray &uidlArray);


	// Fetches a single header by message number. Returns an email object on success,
	// or a null reference on failure.
	// 
	// Note: The email objects returned in the bundle contain only headers. The
	// attachments will be missing, and the bodies will be mostly missing (only the 1st
	// messageNumber lines of either the plain-text or HTML body will be present).
	// 
	// Also Important:Message numbers are specific to a POP3 session (whereas UIDLs are
	// valid across sessions). Be very careful when using this method.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *FetchSingleHeader(int numBodyLines, int messageNumber);

	// Fetches a single header by message number. Returns an email object on success,
	// or a null reference on failure.
	// 
	// Note: The email objects returned in the bundle contain only headers. The
	// attachments will be missing, and the bodies will be mostly missing (only the 1st
	// messageNumber lines of either the plain-text or HTML body will be present).
	// 
	// Also Important:Message numbers are specific to a POP3 session (whereas UIDLs are
	// valid across sessions). Be very careful when using this method.
	// 
	CkTask *FetchSingleHeaderAsync(int numBodyLines, int messageNumber);


	// Fetches a single header by UIDL. Returns an email object on success, or a null
	// reference on failure.
	// 
	// Note: The email objects returned in the bundle contain only headers. The
	// attachments will be missing, and the bodies will be mostly missing (only the 1st
	// uidl lines of either the plain-text or HTML body will be present).
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *FetchSingleHeaderByUidl(int numBodyLines, const char *uidl);

	// Fetches a single header by UIDL. Returns an email object on success, or a null
	// reference on failure.
	// 
	// Note: The email objects returned in the bundle contain only headers. The
	// attachments will be missing, and the bodies will be mostly missing (only the 1st
	// uidl lines of either the plain-text or HTML body will be present).
	// 
	CkTask *FetchSingleHeaderByUidlAsync(int numBodyLines, const char *uidl);


	// Returns all the emails from the POP3 server, but only the first numBodyLines lines of
	// the body. Attachments are not returned. The emails returned in the bundle are
	// valid email objects, the only difference is that the body is truncated to
	// include only the top numBodyLines lines, and the attachments will be missing.
	// The caller is responsible for deleting the object returned by this method.
	CkEmailBundle *GetAllHeaders(int numBodyLines);

	// Returns all the emails from the POP3 server, but only the first numBodyLines lines of
	// the body. Attachments are not returned. The emails returned in the bundle are
	// valid email objects, the only difference is that the body is truncated to
	// include only the top numBodyLines lines, and the attachments will be missing.
	CkTask *GetAllHeadersAsync(int numBodyLines);


	// Returns a string array object containing a list of failed and invalid email
	// addresses that have accumulated during SMTP sends. The list will not contain
	// duplicates. Also, this only works with some SMTP servers -- not all SMTP servers
	// check the validity of each email address.
	// 
	// Note: An SMTP server can only validate the email addresses within it's own
	// domain. External email address are not verifiable at the time of sending.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkStringArray *GetBadEmailAddrs(void);


	// If a partial email was obtained using GetHeaders or GetAllHeaders, this method
	// will take the partial email as an argument, and download the full email from the
	// server. A new email object (separate from the partial email) is returned. A null
	// reference is returned on failure.
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *GetFullEmail(CkEmail &email);

	// If a partial email was obtained using GetHeaders or GetAllHeaders, this method
	// will take the partial email as an argument, and download the full email from the
	// server. A new email object (separate from the partial email) is returned. A null
	// reference is returned on failure.
	CkTask *GetFullEmailAsync(CkEmail &email);


	// The same as the GetAllHeaders method, except only the emails from fromIndex to toIndex
	// on the POP3 server are returned. The first email on the server is at index 0.
	// The caller is responsible for deleting the object returned by this method.
	CkEmailBundle *GetHeaders(int numBodyLines, int fromIndex, int toIndex);

	// The same as the GetAllHeaders method, except only the emails from fromIndex to toIndex
	// on the POP3 server are returned. The first email on the server is at index 0.
	CkTask *GetHeadersAsync(int numBodyLines, int fromIndex, int toIndex);


	// Returns the number of emails on the POP3 server, or -1 for failure.
	// 
	// This method is identical to CheckEmail. It was added for clarity.
	// 
	int GetMailboxCount(void);

	// Returns the number of emails on the POP3 server, or -1 for failure.
	// 
	// This method is identical to CheckEmail. It was added for clarity.
	// 
	CkTask *GetMailboxCountAsync(void);


	// Returns an XML document with information about the emails in a POP3 mailbox. The
	// XML contains the UIDL and size (in bytes) of each email in the mailbox.
	bool GetMailboxInfoXml(CkString &outXml);

	// Returns an XML document with information about the emails in a POP3 mailbox. The
	// XML contains the UIDL and size (in bytes) of each email in the mailbox.
	const char *getMailboxInfoXml(void);
	// Returns an XML document with information about the emails in a POP3 mailbox. The
	// XML contains the UIDL and size (in bytes) of each email in the mailbox.
	const char *mailboxInfoXml(void);

	// Returns an XML document with information about the emails in a POP3 mailbox. The
	// XML contains the UIDL and size (in bytes) of each email in the mailbox.
	CkTask *GetMailboxInfoXmlAsync(void);


	// Returns the total combined size in bytes of all the emails in the POP3 mailbox.
	// This is also known as the "mail drop" size. Returns -1 on failure.
	unsigned long GetMailboxSize(void);

	// Returns the total combined size in bytes of all the emails in the POP3 mailbox.
	// This is also known as the "mail drop" size. Returns -1 on failure.
	CkTask *GetMailboxSizeAsync(void);


	// Returns the POP3 server's SSL certificate. This is available after connecting
	// via SSL to a POP3 server. (To use POP3 SSL, set the PopSsl property = true.)
	// 
	// Returns a null reference if no POP3 SSL certificate is available.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkCert *GetPop3SslServerCert(void);


	// Returns the list of successful email addresses in the last call to a mail
	// sending method, such as SendEmail.
	// 
	// When an email is sent, the email addresses that were flagged invalid by the SMTP
	// server are saved in a "bad email addresses" list within the mailman object, and
	// the acceptable email addresses are saved in a "good email addresses" list
	// (within the mailman object). These internal lists are automatically reset at the
	// start of the next mail-sending method call. This allows for a program to know
	// which email addresses were accepted and which were not.
	// 
	// Note: The AllOrNone property controls whether the mail-sending method, such as
	// SendEmail, returns false (to indicate failure) if any single email address is
	// rejected.
	// 
	// Note: An SMTP server can only be aware of invalid email addresses that are of
	// the same domain. For example, the comcast.net mail servers would only be aware
	// of what comcast.net email addresses are valid. All external email addresses are
	// implicitly accepted because the server is simply forwarding the email towards
	// the mail server controlling that domain.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkStringArray *GetSentToEmailAddrs(void);


	// Returns the size of an email (including attachments) given the UIDL of the email
	// on the POP3 server. Returns -1 for failure.
	int GetSizeByUidl(const char *uidl);

	// Returns the size of an email (including attachments) given the UIDL of the email
	// on the POP3 server. Returns -1 for failure.
	CkTask *GetSizeByUidlAsync(const char *uidl);


	// If using SSL/TLS, this method returns the SMTP server's digital certificate used
	// with the secure connection.
	// The caller is responsible for deleting the object returned by this method.
	CkCert *GetSmtpSslServerCert(void);


	// Returns the UIDLs of the emails currently stored on the POP3 server.
	// The caller is responsible for deleting the object returned by this method.
	CkStringArray *GetUidls(void);

	// Returns the UIDLs of the emails currently stored on the POP3 server.
	CkTask *GetUidlsAsync(void);


	// Contacts the SMTP server and determines if it supports the DSN (Delivery Status
	// Notification) features specified by RFC 3461 and supported by the DsnEnvid,
	// DsnNotify, and DsnRet properties. Returns true if the SMTP server supports
	// DSN, otherwise returns false.
	bool IsSmtpDsnCapable(void);

	// Contacts the SMTP server and determines if it supports the DSN (Delivery Status
	// Notification) features specified by RFC 3461 and supported by the DsnEnvid,
	// DsnNotify, and DsnRet properties. Returns true if the SMTP server supports
	// DSN, otherwise returns false.
	CkTask *IsSmtpDsnCapableAsync(void);


	// Returns true if the mailman is already unlocked, otherwise returns false.
	bool IsUnlocked(void);


	// Provides information about what transpired in the last method called on this
	// object instance. For many methods, there is no information. However, for some
	// methods, details about what occurred can be obtained by getting the LastJsonData
	// right after the method call returns.
	// The caller is responsible for deleting the object returned by this method.
	CkJsonObject *LastJsonData(void);


	// Loads an email from a .eml file. (EML files contain the MIME source of an
	// email.) Returns a null reference on failure.
	// 
	// Note: MHT files can be loaded into an email object by calling this method.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *LoadEml(const char *emlFilename);


	// Loads a .mbx file containing emails and returns an email bundle. If a Filter is
	// present, only emails matching the filter are returned.
	// The caller is responsible for deleting the object returned by this method.
	CkEmailBundle *LoadMbx(const char *mbxFileName);


	// Creates and loads an email from a MIME string. Returns a null reference on
	// failure.
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *LoadMime(const char *mimeText);


	// Loads an email previously written to a Chilkat SMTPQ file via the SendQ/SendQ2
	// methods. When SendQ or SendQ2 writes an email to a queue directory, the .eml
	// created contains special MIME header fields used by the SMTPQ process. These
	// include fields to specify the SMTP server, login/password, whether the email
	// should be sent signed and/or encrypted, etc. The SMTPQ process reads these
	// fields and removes them before sending. This method will read the .eml and set
	// the mailman properties to reflect the settings at the time when SendQ/SendQ2 was
	// originally called. This makes it possible for you to write your own "SMTPQ"
	// process that processes files from a queue directory and sends according to the
	// SMTP hostname/login parameters specified by the program that queued the email.
	// 
	// Returns a null reference upon failure.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *LoadQueuedEmail(const char *path);


	// Loads the caller of the task's async method.
	bool LoadTaskCaller(CkTask &task);


	// Loads an XML file containing a single email and returns an email object. Returns
	// a null reference on failure.
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *LoadXmlEmail(const char *filename);


	// Loads an XML string containing a single email and returns an email object.
	// Returns a null reference on failure.
	// The caller is responsible for deleting the object returned by this method.
	CkEmail *LoadXmlEmailString(const char *xmlString);


	// Loads an XML file containing one or more emails and returns an email bundle. If
	// a Filter is present, only emails matching the filter are returned. Returns a
	// null reference on failure.
	// The caller is responsible for deleting the object returned by this method.
	CkEmailBundle *LoadXmlFile(const char *filename);


	// Loads from an XML string containing emails and returns an email bundle. If a
	// Filter is present, only emails matching the filter are returned.
	// The caller is responsible for deleting the object returned by this method.
	CkEmailBundle *LoadXmlString(const char *xmlString);


	// Performs a DNS MX lookup to return the mail server hostname based on an email
	// address.
	bool MxLookup(const char *emailAddress, CkString &outStrHostname);

	// Performs a DNS MX lookup to return the mail server hostname based on an email
	// address.
	const char *mxLookup(const char *emailAddress);

	// Performs a DNS MX lookup to return the list of mail server hostnames based on an
	// email address. The primary server is at index 0. In most cases, there is only
	// one mail server for a given email address.
	// The caller is responsible for deleting the object returned by this method.
	CkStringArray *MxLookupAll(const char *emailAddress);


	// Explicitly opens a connection to the SMTP server and authenticates (if a
	// username/password was specified). Calling this method is optional because the
	// SendEmail method and other mail-sending methods will automatically open the
	// connection to the SMTP server if one is not already established.
	// 
	// Note: This method is the equivalent of calling SmtpConnect followed by
	// SmtpAuthenticate.
	// 
	bool OpenSmtpConnection(void);

	// Explicitly opens a connection to the SMTP server and authenticates (if a
	// username/password was specified). Calling this method is optional because the
	// SendEmail method and other mail-sending methods will automatically open the
	// connection to the SMTP server if one is not already established.
	// 
	// Note: This method is the equivalent of calling SmtpConnect followed by
	// SmtpAuthenticate.
	// 
	CkTask *OpenSmtpConnectionAsync(void);


	// Authenticates with the POP3 server using the property settings such as
	// PopUsername, PopPassword, etc. This method should only be called after a
	// successful call to Pop3Connect.
	// 
	// Note 1: The Pop3BeginSession method both connects and authenticates. It is the
	// equivalent of calling Pop3Connect followed by Pop3Authenticate.
	// 
	// Note 2: All methods that communicate with the POP3 server, such as FetchEmail,
	// will automatically connect and authenticate if not already connected and
	// authenticated.
	// 
	bool Pop3Authenticate(void);

	// Authenticates with the POP3 server using the property settings such as
	// PopUsername, PopPassword, etc. This method should only be called after a
	// successful call to Pop3Connect.
	// 
	// Note 1: The Pop3BeginSession method both connects and authenticates. It is the
	// equivalent of calling Pop3Connect followed by Pop3Authenticate.
	// 
	// Note 2: All methods that communicate with the POP3 server, such as FetchEmail,
	// will automatically connect and authenticate if not already connected and
	// authenticated.
	// 
	CkTask *Pop3AuthenticateAsync(void);


	// Call to explicitly begin a POP3 session. It is not necessary to call this method
	// because any method requiring an established POP3 session will automatically
	// connect and login if a session is not already open.
	// 
	// Important: All TCP-based Internet communications, regardless of the protocol
	// (such as HTTP, FTP, SSH, IMAP, POP3, SMTP, etc.), and regardless of SSL/TLS,
	// begin with establishing a TCP connection to a remote host:port. External
	// security-related infrastructure such as software firewalls (Windows Firewall),
	// hardware firewalls, anti-virus, at either source or destination (or both) can
	// block the connection. If the connection fails, make sure to check all potential
	// external causes of blockage.
	// 
	bool Pop3BeginSession(void);

	// Call to explicitly begin a POP3 session. It is not necessary to call this method
	// because any method requiring an established POP3 session will automatically
	// connect and login if a session is not already open.
	// 
	// Important: All TCP-based Internet communications, regardless of the protocol
	// (such as HTTP, FTP, SSH, IMAP, POP3, SMTP, etc.), and regardless of SSL/TLS,
	// begin with establishing a TCP connection to a remote host:port. External
	// security-related infrastructure such as software firewalls (Windows Firewall),
	// hardware firewalls, anti-virus, at either source or destination (or both) can
	// block the connection. If the connection fails, make sure to check all potential
	// external causes of blockage.
	// 
	CkTask *Pop3BeginSessionAsync(void);


	// Explicitly establishes a connection to the POP3 server, which includes
	// establishing a secure TLS channel if required, and receives the initial
	// greeting. This method stops short of authenticating. The Pop3Authenticate method
	// should be called after a successful call to this method.
	// 
	// When finished transacting with a POP3 mail server you can disconnect by calling
	// Pop3EndSession or Pop3EndSessionNoQuit.
	// 
	// Note 1: The Pop3BeginSession method both connects and authenticates. It is the
	// equivalent of calling Pop3Connect followed by Pop3Authenticate.
	// 
	// Note 2: All methods that communicate with the POP3 server, such as FetchEmail,
	// will automatically connect and authenticate if not already connected and
	// authenticated.
	// 
	// Important: All TCP-based Internet communications, regardless of the protocol
	// (such as HTTP, FTP, SSH, IMAP, POP3, SMTP, etc.), and regardless of SSL/TLS,
	// begin with establishing a TCP connection to a remote host:port. External
	// security-related infrastructure such as software firewalls (Windows Firewall),
	// hardware firewalls, anti-virus, at either source or destination (or both) can
	// block the connection. If the connection fails, make sure to check all potential
	// external causes of blockage.
	// 
	bool Pop3Connect(void);

	// Explicitly establishes a connection to the POP3 server, which includes
	// establishing a secure TLS channel if required, and receives the initial
	// greeting. This method stops short of authenticating. The Pop3Authenticate method
	// should be called after a successful call to this method.
	// 
	// When finished transacting with a POP3 mail server you can disconnect by calling
	// Pop3EndSession or Pop3EndSessionNoQuit.
	// 
	// Note 1: The Pop3BeginSession method both connects and authenticates. It is the
	// equivalent of calling Pop3Connect followed by Pop3Authenticate.
	// 
	// Note 2: All methods that communicate with the POP3 server, such as FetchEmail,
	// will automatically connect and authenticate if not already connected and
	// authenticated.
	// 
	// Important: All TCP-based Internet communications, regardless of the protocol
	// (such as HTTP, FTP, SSH, IMAP, POP3, SMTP, etc.), and regardless of SSL/TLS,
	// begin with establishing a TCP connection to a remote host:port. External
	// security-related infrastructure such as software firewalls (Windows Firewall),
	// hardware firewalls, anti-virus, at either source or destination (or both) can
	// block the connection. If the connection fails, make sure to check all potential
	// external causes of blockage.
	// 
	CkTask *Pop3ConnectAsync(void);


	// Call to explicitly end a POP3 session (sends the QUIT command and then closes
	// the connection with the POP3 server). If the ImmediateDelete property is set to
	// false, and emails marked for deletion will be deleted at this time.
	bool Pop3EndSession(void);

	// Call to explicitly end a POP3 session (sends the QUIT command and then closes
	// the connection with the POP3 server). If the ImmediateDelete property is set to
	// false, and emails marked for deletion will be deleted at this time.
	CkTask *Pop3EndSessionAsync(void);


	// This method is identical to Pop3EndSession, but no "QUIT" command is sent. The
	// client simply disconnects from the POP3 server.
	// 
	// This method should always return true.
	// 
	bool Pop3EndSessionNoQuit(void);

	// This method is identical to Pop3EndSession, but no "QUIT" command is sent. The
	// client simply disconnects from the POP3 server.
	// 
	// This method should always return true.
	// 
	CkTask *Pop3EndSessionNoQuitAsync(void);


	// Sends a NOOP command to the POP3 server. This may be a useful method to call
	// periodically to keep a connection open, or to verify that the POP3 connection
	// (session) is open and functioning.
	bool Pop3Noop(void);

	// Sends a NOOP command to the POP3 server. This may be a useful method to call
	// periodically to keep a connection open, or to verify that the POP3 connection
	// (session) is open and functioning.
	CkTask *Pop3NoopAsync(void);


	// Sends a RSET command to the POP3 server. If any messages have been marked as
	// deleted by the POP3 server, they are unmarked. Calling Pop3Reset resets the POP3
	// session to a valid, known starting point.
	bool Pop3Reset(void);

	// Sends a RSET command to the POP3 server. If any messages have been marked as
	// deleted by the POP3 server, they are unmarked. Calling Pop3Reset resets the POP3
	// session to a valid, known starting point.
	CkTask *Pop3ResetAsync(void);


	// Sends a raw command to the POP3 server and returns the POP3 server's response.
	// If non-us-ascii characters are included in command, then charset indicates the charset
	// to be used in sending the command (such as "utf-8", "ansi", "iso-8859-1",
	// "Shift_JIS", etc.)
	bool Pop3SendRawCommand(const char *command, const char *charset, CkString &outStr);

	// Sends a raw command to the POP3 server and returns the POP3 server's response.
	// If non-us-ascii characters are included in command, then charset indicates the charset
	// to be used in sending the command (such as "utf-8", "ansi", "iso-8859-1",
	// "Shift_JIS", etc.)
	const char *pop3SendRawCommand(const char *command, const char *charset);
	// Sends a raw command to the POP3 server and returns the POP3 server's response.
	// If non-us-ascii characters are included in command, then charset indicates the charset
	// to be used in sending the command (such as "utf-8", "ansi", "iso-8859-1",
	// "Shift_JIS", etc.)
	CkTask *Pop3SendRawCommandAsync(const char *command, const char *charset);


	// A quick way to send an email to a single recipient without having to explicitly
	// create an email object.
	bool QuickSend(const char *fromAddr, const char *toAddr, const char *subject, const char *body, const char *smtpServer);

	// A quick way to send an email to a single recipient without having to explicitly
	// create an email object.
	CkTask *QuickSendAsync(const char *fromAddr, const char *toAddr, const char *subject, const char *body, const char *smtpServer);


	// When an email is sent by calling SendEmail, it is first "rendered" according to
	// the values of the email properties and contents. It may be digitally signed,
	// encrypted, values substituted for replacement patterns, and header fields "Q"or
	// "B" encoded as needed based on the email. The RenderToMime method performs the
	// rendering, but without the actual sending. The MIME text produced is exactly
	// what would be sent to the SMTP server had SendEmail been called. (The SendEmail
	// method is effectively the same as calling RenderToMime followed by a call to
	// SendMime.)
	// 
	// The rendered MIME string is returned on success.
	// 
	bool RenderToMime(CkEmail &email, CkString &outStr);

	// When an email is sent by calling SendEmail, it is first "rendered" according to
	// the values of the email properties and contents. It may be digitally signed,
	// encrypted, values substituted for replacement patterns, and header fields "Q"or
	// "B" encoded as needed based on the email. The RenderToMime method performs the
	// rendering, but without the actual sending. The MIME text produced is exactly
	// what would be sent to the SMTP server had SendEmail been called. (The SendEmail
	// method is effectively the same as calling RenderToMime followed by a call to
	// SendMime.)
	// 
	// The rendered MIME string is returned on success.
	// 
	const char *renderToMime(CkEmail &email);

	// The same as RenderToMimeBytes, except the MIME is rendered into renderedMime. The
	// rendered MIME is appended to renderedMime.
	bool RenderToMimeBd(CkEmail &email, CkBinData &renderedMime);


	// This method is the same as RenderToMime, but the MIME is returned in a byte
	// array. If an email uses an 8bit or binary MIME encoding, then calling
	// RenderToMime may introduce errors because it is not possible to return non-text
	// binary data as a string. Therefore, calling RenderToMimeBytes is recommended
	// over RenderToMime, unless it is assured that the email (MIME) does not use a
	// binary encoding for non-text data.
	bool RenderToMimeBytes(CkEmail &email, CkByteData &outBytes);


	// The same as RenderToMime, except the MIME is rendered into renderedMime. The rendered
	// MIME is appended to renderedMime.
	bool RenderToMimeSb(CkEmail &email, CkStringBuilder &renderedMime);


	// Sends a bundle of emails. This is identical to calling SendEmail for each email
	// in the bundle.
	// 
	// If an error occurs when sending one of the emails in the bundle, it will
	// continue with each subsequent email until each email in the bundle has been
	// attempted (unless a fatal error occurs, in which case the send is aborted).
	// 
	// Because it is difficult or impossible to programmatically identify which emails
	// in the bundle failed and which succeeded, it is best to write a loop that sends
	// each email separately (via the SendEmail method).
	// 
	bool SendBundle(CkEmailBundle &bundle);

	// Sends a bundle of emails. This is identical to calling SendEmail for each email
	// in the bundle.
	// 
	// If an error occurs when sending one of the emails in the bundle, it will
	// continue with each subsequent email until each email in the bundle has been
	// attempted (unless a fatal error occurs, in which case the send is aborted).
	// 
	// Because it is difficult or impossible to programmatically identify which emails
	// in the bundle failed and which succeeded, it is best to write a loop that sends
	// each email separately (via the SendEmail method).
	// 
	CkTask *SendBundleAsync(CkEmailBundle &bundle);


	// Sends a single email. The connection to the SMTP server will remain open so that
	// a subsequent call to SendEmail (or other email-sending methods) can re-use the
	// same connection. If any properties relating to the SMTP server are changed, such
	// as SmtpHost, SmtpUsername, etc., then the next call to an email-sending method
	// will automatically close the connection and re-establish a connection using the
	// updated property settings.
	// 
	// Important: Some SMTP servers do not actually send the email until the connection
	// is closed. In these cases, it is necessary to call CloseSmtpConnection for the
	// mail to be sent. Most SMTP servers send the email immediately, and it is not
	// required to close the connection.
	// 
	// GMail: If sending via smtp.gmail.com, then send with OAuth2 authentication if
	// possible. Otherwise you will need to change your GMail account settings to allow
	// for sending by less secure apps. See the links below.
	// 
	// Note: After sending email, information about what transpired is available via
	// the LastJsonData method.
	// 
	bool SendEmail(CkEmail &email);

	// Sends a single email. The connection to the SMTP server will remain open so that
	// a subsequent call to SendEmail (or other email-sending methods) can re-use the
	// same connection. If any properties relating to the SMTP server are changed, such
	// as SmtpHost, SmtpUsername, etc., then the next call to an email-sending method
	// will automatically close the connection and re-establish a connection using the
	// updated property settings.
	// 
	// Important: Some SMTP servers do not actually send the email until the connection
	// is closed. In these cases, it is necessary to call CloseSmtpConnection for the
	// mail to be sent. Most SMTP servers send the email immediately, and it is not
	// required to close the connection.
	// 
	// GMail: If sending via smtp.gmail.com, then send with OAuth2 authentication if
	// possible. Otherwise you will need to change your GMail account settings to allow
	// for sending by less secure apps. See the links below.
	// 
	// Note: After sending email, information about what transpired is available via
	// the LastJsonData method.
	// 
	CkTask *SendEmailAsync(CkEmail &email);


	// Provides complete control over the email that is sent. The MIME text passed in
	// mimeSource (the MIME source of an email) is passed exactly as-is to the SMTP server.
	// The recipients is a comma separated list of recipient email addresses. The fromAddr is the
	// reverse-path email address. This is where bounced email (non-delivery reports)
	// will be delivered. It may be different than the "From" header field in the mimeSource.
	// 
	// To understand how the fromAddr and recipients relate to the email addresses found in the
	// MIME headers (FROM, TO, CC), see the link below entitled "SMTP Protocol in a
	// Nutshell". The fromAddr is what is passed to the SMTP server in the "MAIL FROM"
	// command. The recipients are the email addresses passed in "RCPT TO" commands. These
	// are usually the same email addresses found in the MIME headers, but need not be
	// (unless the SMTP server enforces policies that require them to be the same).
	// 
	bool SendMime(const char *fromAddr, const char *recipients, const char *mimeSource);

	// Provides complete control over the email that is sent. The MIME text passed in
	// mimeSource (the MIME source of an email) is passed exactly as-is to the SMTP server.
	// The recipients is a comma separated list of recipient email addresses. The fromAddr is the
	// reverse-path email address. This is where bounced email (non-delivery reports)
	// will be delivered. It may be different than the "From" header field in the mimeSource.
	// 
	// To understand how the fromAddr and recipients relate to the email addresses found in the
	// MIME headers (FROM, TO, CC), see the link below entitled "SMTP Protocol in a
	// Nutshell". The fromAddr is what is passed to the SMTP server in the "MAIL FROM"
	// command. The recipients are the email addresses passed in "RCPT TO" commands. These
	// are usually the same email addresses found in the MIME headers, but need not be
	// (unless the SMTP server enforces policies that require them to be the same).
	// 
	CkTask *SendMimeAsync(const char *fromAddr, const char *recipients, const char *mimeSource);


	// This method is the same as SendMimeBytes, except the MIME is passed in an object
	// (mimeData) rather than explicitly passing the bytes.
	bool SendMimeBd(const char *fromAddr, const char *recipients, CkBinData &mimeData);

	// This method is the same as SendMimeBytes, except the MIME is passed in an object
	// (mimeData) rather than explicitly passing the bytes.
	CkTask *SendMimeBdAsync(const char *fromAddr, const char *recipients, CkBinData &mimeData);


	// This method is the same as SendMime, except the MIME is passed in a byte array.
	// This can be important if the MIME uses a binary encoding, or if a DKIM/DomainKey
	// signature is included.
	// 
	// To understand how the fromAddr and recipients relate to the email addresses found in the
	// MIME headers (FROM, TO, CC), see the link below entitled "SMTP Protocol in a
	// Nutshell". The fromAddr is what is passed to the SMTP server in the "MAIL FROM"
	// command. The recipients are the email addresses passed in "RCPT TO" commands. These
	// are usually the same email addresses found in the MIME headers, but need not be
	// (unless the SMTP server enforces policies that require them to be the same).
	// 
	bool SendMimeBytes(const char *fromAddr, const char *recipients, CkByteData &mimeSource);

	// This method is the same as SendMime, except the MIME is passed in a byte array.
	// This can be important if the MIME uses a binary encoding, or if a DKIM/DomainKey
	// signature is included.
	// 
	// To understand how the fromAddr and recipients relate to the email addresses found in the
	// MIME headers (FROM, TO, CC), see the link below entitled "SMTP Protocol in a
	// Nutshell". The fromAddr is what is passed to the SMTP server in the "MAIL FROM"
	// command. The recipients are the email addresses passed in "RCPT TO" commands. These
	// are usually the same email addresses found in the MIME headers, but need not be
	// (unless the SMTP server enforces policies that require them to be the same).
	// 
	CkTask *SendMimeBytesAsync(const char *fromAddr, const char *recipients, CkByteData &mimeSource);


	// This method is the samem as SendMimeQ, except the MIME is passed in a byte array
	// argument instead of a string argument.
	bool SendMimeBytesQ(const char *from, const char *recipients, CkByteData &mimeData);


	// Same as SendMime, except the email is written to the Chilkat SMTPQ's queue
	// directory for background sending from the SMTPQ service.
	// 
	// Important: The SMTPQ functionality is deprecated and will be removed in a future
	// version. The SMTPQ Windows Service Visual Studo project is available on GitHub
	// at the link below. Users would need to build the project prior to using. Chilkat
	// does not provide pre-built binaries for the SMTPQ Windows Service.
	// 
	bool SendMimeQ(const char *fromAddr, const char *recipients, const char *mimeSource);


	// Same as SendMime, but the recipient list is read from a text file (distListFilename)
	// containing one email address per line.
	bool SendMimeToList(const char *fromAddr, const char *distListFilename, const char *mimeSource);

	// Same as SendMime, but the recipient list is read from a text file (distListFilename)
	// containing one email address per line.
	CkTask *SendMimeToListAsync(const char *fromAddr, const char *distListFilename, const char *mimeSource);


	// Queues an email to be sent using the Chilkat SMTP queue service. This is the
	// same as SendEmail, except the email is written to the SMTPQ's queue directory.
	// 
	// The email is written as a .eml to the SMTPQ's queue directory. The SMTP server
	// hostname, login, password, and send-time parameters are saved as encrypted
	// headers in the .eml. The SMTPQ service watches the queue directory. When a .eml
	// file appears, it loads the .eml, extracts and removes the encrypted information
	// from the header, and sends the email.
	// 
	// Note: When the Chilkat SMTPQ service is configured, the location of the queue
	// directory is written to the registry. Because Chilkat SMTPQ is a 32-bit service,
	// it is the 32-bit registry that is written. (Microsoft 64-bit systems have two
	// separate registries -- one for 32-bit and one for 64-bit.) Therefore, if your
	// application is a 64-bit app, the registry lookup for the queue directory will
	// fail. You should instead call the SendQ2 method which allows for the queue
	// directory to be explicitly specified.
	// 
	// Note: After calling this method, the filename of the .eml that was created will
	// be available in the LastSendQFilename property.
	// 
	// Important: The SMTPQ functionality is deprecated and will be removed in a future
	// version. The SMTPQ Windows Service Visual Studo project is available on GitHub
	// at the link below. Users would need to build the project prior to using. Chilkat
	// does not provide pre-built binaries for the SMTPQ Windows Service.
	// 
	bool SendQ(CkEmail &email);


	// Same as SendQ, but the queue directory can be explicitly specified in a method
	// argument.
	// 
	// Beginning with version 9.5.0.47, the queueDir can indicate the exact output filepath
	// to be written. If queueDir specifies only the directory, then SendQ2 will
	// automatically generate the output filename.
	// 
	// Important: The SMTPQ functionality is deprecated and will be removed in a future
	// version. The SMTPQ Windows Service Visual Studo project is available on GitHub
	// at the link below. Users would need to build the project prior to using. Chilkat
	// does not provide pre-built binaries for the SMTPQ Windows Service.
	// 
	bool SendQ2(CkEmail &email, const char *queueDir);


	// Send the same email to a list of email addresses.
	bool SendToDistributionList(CkEmail &emailObj, CkStringArray &recipientList);

	// Send the same email to a list of email addresses.
	CkTask *SendToDistributionListAsync(CkEmail &emailObj, CkStringArray &recipientList);


	// Explicitly specifies the certificate to be used for decrypting encrypted email.
	bool SetDecryptCert(CkCert &cert);


	// Explicitly specifies the certificate and associated private key to be used for
	// decrypting S/MIME encrypted email.
	// 
	// Note: In most cases, it is easier to call AddPfxSourceFile or AddPfxSourceData
	// to provide the required cert and private key. On Windows systems where the
	// certificate + private key has already been installed in the default certificate
	// store, nothing needs to be done -- the mailman will automatically locate and use
	// the required cert + private key.
	// 
	bool SetDecryptCert2(CkCert &cert, CkPrivateKey &privateKey);


	// Provides a more secure way of setting either the POP3 or SMTP password. The protocol
	// can be "pop3" or "smtp". When the protocol is "pop3", this is equivalent to setting
	// the PopPassword property. When protocol is "smtp", this is equivalent to setting the
	// SmtpPassword property.
	bool SetPassword(const char *protocol, CkSecureString &password);


	// Sets the client-side certificate to be used with SSL connections. This is
	// typically not required, as most SSL connections are such that only the server is
	// authenticated while the client remains unauthenticated.
	bool SetSslClientCert(CkCert &cert);


	// Allows for a client-side certificate to be used for the SSL / TLS connection.
	bool SetSslClientCertPem(const char *pemDataOrFilename, const char *pemPassword);


	// Allows for a client-side certificate to be used for the SSL / TLS connection.
	bool SetSslClientCertPfx(const char *pfxFilename, const char *pfxPassword);


	// Authenticates with the SMTP server using the property settings such as
	// SmtpUsername, SmtpPassword, etc. This method should only be called after a
	// successful call to SmtpConnect.
	// 
	// Note 1: The OpenSmtpConnection method both connects and authenticates. It is the
	// equivalent of calling SmtpConnect followed by SmtpAuthenticate.
	// 
	// Note 2: All methods that communicate with the SMTP server, such as SendEmail,
	// will automatically connect and authenticate if not already connected and
	// authenticated.
	// 
	bool SmtpAuthenticate(void);

	// Authenticates with the SMTP server using the property settings such as
	// SmtpUsername, SmtpPassword, etc. This method should only be called after a
	// successful call to SmtpConnect.
	// 
	// Note 1: The OpenSmtpConnection method both connects and authenticates. It is the
	// equivalent of calling SmtpConnect followed by SmtpAuthenticate.
	// 
	// Note 2: All methods that communicate with the SMTP server, such as SendEmail,
	// will automatically connect and authenticate if not already connected and
	// authenticated.
	// 
	CkTask *SmtpAuthenticateAsync(void);


	// Explicitly establishes a connection to the SMTP server, which includes
	// establishing a secure TLS channel if required, and receives the initial
	// greeting. This method stops short of authenticating. The SmtpAuthenticate method
	// should be called after a successful call to this method.
	// 
	// Note 1: The OpenSmtpConnection method both connects and authenticates. It is the
	// equivalent of calling SmtpConnect followed by SmtpAuthenticate.
	// 
	// Note 2: All methods that communicate with the SMTP server, such as SendEmail,
	// will automatically connect and authenticate if not already connected and
	// authenticated.
	// 
	// Important: All TCP-based Internet communications, regardless of the protocol
	// (such as HTTP, FTP, SSH, IMAP, POP3, SMTP, etc.), and regardless of SSL/TLS,
	// begin with establishing a TCP connection to a remote host:port. External
	// security-related infrastructure such as software firewalls (Windows Firewall),
	// hardware firewalls, anti-virus, at either source or destination (or both) can
	// block the connection. If the connection fails, make sure to check all potential
	// external causes of blockage.
	// 
	bool SmtpConnect(void);

	// Explicitly establishes a connection to the SMTP server, which includes
	// establishing a secure TLS channel if required, and receives the initial
	// greeting. This method stops short of authenticating. The SmtpAuthenticate method
	// should be called after a successful call to this method.
	// 
	// Note 1: The OpenSmtpConnection method both connects and authenticates. It is the
	// equivalent of calling SmtpConnect followed by SmtpAuthenticate.
	// 
	// Note 2: All methods that communicate with the SMTP server, such as SendEmail,
	// will automatically connect and authenticate if not already connected and
	// authenticated.
	// 
	// Important: All TCP-based Internet communications, regardless of the protocol
	// (such as HTTP, FTP, SSH, IMAP, POP3, SMTP, etc.), and regardless of SSL/TLS,
	// begin with establishing a TCP connection to a remote host:port. External
	// security-related infrastructure such as software firewalls (Windows Firewall),
	// hardware firewalls, anti-virus, at either source or destination (or both) can
	// block the connection. If the connection fails, make sure to check all potential
	// external causes of blockage.
	// 
	CkTask *SmtpConnectAsync(void);


	// Sends a no-op to the SMTP server. Calling this method is good for testing to see
	// if the connection to the SMTP server is working and valid. The SmtpNoop method
	// will automatically establish the SMTP connection if it does not already exist.
	bool SmtpNoop(void);

	// Sends a no-op to the SMTP server. Calling this method is good for testing to see
	// if the connection to the SMTP server is working and valid. The SmtpNoop method
	// will automatically establish the SMTP connection if it does not already exist.
	CkTask *SmtpNoopAsync(void);


	// Sends an RSET command to the SMTP server. This method is rarely needed. The RSET
	// command resets the state of the connection to the SMTP server to the initial
	// state (so that the component can proceed with sending a new email). The
	// SmtpReset method would only be needed if a mail-sending method failed and left
	// the connection with the SMTP server open and in a non-initial state. (A
	// situation that is probably not even possible with the Chilkat mail component.)
	bool SmtpReset(void);

	// Sends an RSET command to the SMTP server. This method is rarely needed. The RSET
	// command resets the state of the connection to the SMTP server to the initial
	// state (so that the component can proceed with sending a new email). The
	// SmtpReset method would only be needed if a mail-sending method failed and left
	// the connection with the SMTP server open and in a non-initial state. (A
	// situation that is probably not even possible with the Chilkat mail component.)
	CkTask *SmtpResetAsync(void);


	// Sends a raw command to the SMTP server and returns the SMTP server's response.
	// If non-us-ascii characters are included in command, then charset indicates the charset
	// to be used in sending the command (such as "utf-8", "ansi", "iso-8859-1",
	// "Shift_JIS", etc.)
	// 
	// If bEncodeBase64 is true, then the response is returned in Base64-encoded format.
	// Otherwise the raw response is returned.
	// 
	bool SmtpSendRawCommand(const char *command, const char *charset, bool bEncodeBase64, CkString &outStr);

	// Sends a raw command to the SMTP server and returns the SMTP server's response.
	// If non-us-ascii characters are included in command, then charset indicates the charset
	// to be used in sending the command (such as "utf-8", "ansi", "iso-8859-1",
	// "Shift_JIS", etc.)
	// 
	// If bEncodeBase64 is true, then the response is returned in Base64-encoded format.
	// Otherwise the raw response is returned.
	// 
	const char *smtpSendRawCommand(const char *command, const char *charset, bool bEncodeBase64);
	// Sends a raw command to the SMTP server and returns the SMTP server's response.
	// If non-us-ascii characters are included in command, then charset indicates the charset
	// to be used in sending the command (such as "utf-8", "ansi", "iso-8859-1",
	// "Shift_JIS", etc.)
	// 
	// If bEncodeBase64 is true, then the response is returned in Base64-encoded format.
	// Otherwise the raw response is returned.
	// 
	CkTask *SmtpSendRawCommandAsync(const char *command, const char *charset, bool bEncodeBase64);


	// Authenticates with the SSH server using public-key authentication. The
	// corresponding public key must have been installed on the SSH server for the
	// sshLogin. Authentication will succeed if the matching sshUsername is provided.
	// 
	// Important: When reporting problems, please send the full contents of the
	// LastErrorText property to support@chilkatsoft.com.
	// 
	bool SshAuthenticatePk(const char *sshLogin, CkSshKey &sshUsername);

	// Authenticates with the SSH server using public-key authentication. The
	// corresponding public key must have been installed on the SSH server for the
	// sshLogin. Authentication will succeed if the matching sshUsername is provided.
	// 
	// Important: When reporting problems, please send the full contents of the
	// LastErrorText property to support@chilkatsoft.com.
	// 
	CkTask *SshAuthenticatePkAsync(const char *sshLogin, CkSshKey &sshUsername);


	// Authenticates with the SSH server using a sshLogin and sshPassword.
	// 
	// An SSH tunneling (port forwarding) session always begins by first calling
	// SshTunnel to connect to the SSH server, then calling either AuthenticatePw or
	// AuthenticatePk to authenticate.
	// 
	// Note: Once the SSH tunnel is setup by calling SshTunnel and SshAuthenticatePw
	// (or SshAuthenticatePk), all underlying communcations with the POP3 or SMTP
	// server use the SSH tunnel. No changes in programming are required other than
	// making two initial calls to setup the tunnel.
	// 
	// Important: When reporting problems, please send the full contents of the
	// LastErrorText property to support@chilkatsoft.com.
	// 
	bool SshAuthenticatePw(const char *sshLogin, const char *sshPassword);

	// Authenticates with the SSH server using a sshLogin and sshPassword.
	// 
	// An SSH tunneling (port forwarding) session always begins by first calling
	// SshTunnel to connect to the SSH server, then calling either AuthenticatePw or
	// AuthenticatePk to authenticate.
	// 
	// Note: Once the SSH tunnel is setup by calling SshTunnel and SshAuthenticatePw
	// (or SshAuthenticatePk), all underlying communcations with the POP3 or SMTP
	// server use the SSH tunnel. No changes in programming are required other than
	// making two initial calls to setup the tunnel.
	// 
	// Important: When reporting problems, please send the full contents of the
	// LastErrorText property to support@chilkatsoft.com.
	// 
	CkTask *SshAuthenticatePwAsync(const char *sshLogin, const char *sshPassword);


	// Closes the SSH tunnel for SMTP or POP3.
	bool SshCloseTunnel(void);

	// Closes the SSH tunnel for SMTP or POP3.
	CkTask *SshCloseTunnelAsync(void);


	// Connects to an SSH server and creates a tunnel for SMTP or POP3. The sshHostname is the
	// hostname (or IP address) of the SSH server. The sshPort is typically 22, which is
	// the standard SSH port number.
	// 
	// An SSH tunneling (port forwarding) session always begins by first calling
	// SshTunnel to connect to the SSH server, followed by calling either
	// SshAuthenticatePw or SshAuthenticatePk to authenticate.
	// 
	// Note: Once the SSH tunnel is setup by calling SshOpenTunnel and
	// SshAuthenticatePw (or SshAuthenticatePk), all underlying communcations with the
	// SMTP or POP3 server use the SSH tunnel. No changes in programming are required
	// other than making two initial calls to setup the tunnel.
	// 
	// Important: All TCP-based Internet communications, regardless of the protocol
	// (such as HTTP, FTP, SSH, IMAP, POP3, SMTP, etc.), and regardless of SSL/TLS,
	// begin with establishing a TCP connection to a remote host:port. External
	// security-related infrastructure such as software firewalls (Windows Firewall),
	// hardware firewalls, anti-virus, at either source or destination (or both) can
	// block the connection. If the connection fails, make sure to check all potential
	// external causes of blockage.
	// 
	bool SshOpenTunnel(const char *sshHostname, int sshPort);

	// Connects to an SSH server and creates a tunnel for SMTP or POP3. The sshHostname is the
	// hostname (or IP address) of the SSH server. The sshPort is typically 22, which is
	// the standard SSH port number.
	// 
	// An SSH tunneling (port forwarding) session always begins by first calling
	// SshTunnel to connect to the SSH server, followed by calling either
	// SshAuthenticatePw or SshAuthenticatePk to authenticate.
	// 
	// Note: Once the SSH tunnel is setup by calling SshOpenTunnel and
	// SshAuthenticatePw (or SshAuthenticatePk), all underlying communcations with the
	// SMTP or POP3 server use the SSH tunnel. No changes in programming are required
	// other than making two initial calls to setup the tunnel.
	// 
	// Important: All TCP-based Internet communications, regardless of the protocol
	// (such as HTTP, FTP, SSH, IMAP, POP3, SMTP, etc.), and regardless of SSL/TLS,
	// begin with establishing a TCP connection to a remote host:port. External
	// security-related infrastructure such as software firewalls (Windows Firewall),
	// hardware firewalls, anti-virus, at either source or destination (or both) can
	// block the connection. If the connection fails, make sure to check all potential
	// external causes of blockage.
	// 
	CkTask *SshOpenTunnelAsync(const char *sshHostname, int sshPort);


	// Downloads and removes all email from a POP3 server. A bundle containing the
	// emails is returned. A null reference is returned on failure.
	// The caller is responsible for deleting the object returned by this method.
	CkEmailBundle *TransferMail(void);

	// Downloads and removes all email from a POP3 server. A bundle containing the
	// emails is returned. A null reference is returned on failure.
	CkTask *TransferMailAsync(void);


	// Same as FetchMultipleMime except that the downloaded emails are also deleted
	// from the server. Returns a null reference on failure.
	// The caller is responsible for deleting the object returned by this method.
	CkStringArray *TransferMultipleMime(CkStringArray &uidlArray);

	// Same as FetchMultipleMime except that the downloaded emails are also deleted
	// from the server. Returns a null reference on failure.
	CkTask *TransferMultipleMimeAsync(CkStringArray &uidlArray);


	// Unlocks the component. This must be called once at the beginning of your program
	// (or ASP / ASP.NET page). It is very fast and has negligible overhead. An
	// arbitrary string, such as "Hello World" may be passed to automatically begin a
	// fully-functional 30-day trial.
	// 
	// A valid purchased unlock code for this object will always included the substring
	// "MAIL", or can be a Bundle unlock code.
	// 
	bool UnlockComponent(const char *code);


	// Adds an XML certificate vault to the object's internal list of sources to be
	// searched for certificates and private keys when encrypting/decrypting or
	// signing/verifying. Unlike the AddPfxSourceData and AddPfxSourceFile methods,
	// only a single XML certificate vault can be used. If UseCertVault is called
	// multiple times, only the last certificate vault will be used, as each call to
	// UseCertVault will replace the certificate vault provided in previous calls.
	bool UseCertVault(CkXmlCertVault &vault);


	// Uses an existing SSH tunnel for the connections to the POP3 andSMTP servers.
	// This method is identical to the UseSshTunnel method, except the SSH connection
	// is obtained from an SSH object instead of a Socket object.
	// 
	// Uses an existing SSH tunnel. This is useful for sharing an existing SSH tunnel
	// connection wth other objects. (SSH is a protocol where the tunnel contains many
	// logical channels. SMTP and POP3 connections can exist simultaneously within a
	// single SSH tunnel as SSH channels.)
	// 
	bool UseSsh(CkSsh &ssh);


	// Uses an existing SSH tunnel. This is useful for sharing an existing SSH tunnel
	// connection wth other objects. (SSH is a protocol where the tunnel contains many
	// logical channels. SMTP and POP3 connections can exist simultaneously within a
	// single SSH tunnel as SSH channels.)
	bool UseSshTunnel(CkSocket &tunnel);


	// Return true if a TCP/IP connection can be established with the POP3 server,
	// otherwise returns false.
	bool VerifyPopConnection(void);

	// Return true if a TCP/IP connection can be established with the POP3 server,
	// otherwise returns false.
	CkTask *VerifyPopConnectionAsync(void);


	// Return true if a TCP/IP connection and login is successful with the POP3
	// server. Otherwise return false.
	bool VerifyPopLogin(void);

	// Return true if a TCP/IP connection and login is successful with the POP3
	// server. Otherwise return false.
	CkTask *VerifyPopLoginAsync(void);


	// Initiates sending an email, but aborts just after passing all recipients (TO,
	// CC, BCC) to the SMTP server. This allows your program to collect email addresses
	// flagged as invalid by the SMTP server.
	// 
	// Important: Please read this blog post before using this method:
	// http://www.cknotes.com/?p=249
	// 
	bool VerifyRecips(CkEmail &email, CkStringArray &badAddrs);

	// Initiates sending an email, but aborts just after passing all recipients (TO,
	// CC, BCC) to the SMTP server. This allows your program to collect email addresses
	// flagged as invalid by the SMTP server.
	// 
	// Important: Please read this blog post before using this method:
	// http://www.cknotes.com/?p=249
	// 
	CkTask *VerifyRecipsAsync(CkEmail &email, CkStringArray &badAddrs);


	// Return true if a TCP/IP connection can be established with the SMTP server,
	// otherwise returns false.
	bool VerifySmtpConnection(void);

	// Return true if a TCP/IP connection can be established with the SMTP server,
	// otherwise returns false.
	CkTask *VerifySmtpConnectionAsync(void);


	// Return true if a TCP/IP connection and login is successful with the SMTP
	// server. Otherwise returns false.
	bool VerifySmtpLogin(void);

	// Return true if a TCP/IP connection and login is successful with the SMTP
	// server. Otherwise returns false.
	CkTask *VerifySmtpLoginAsync(void);






	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
