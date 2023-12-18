// CkPem.h: interface for the CkPem class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#define _CkVersion 9.5.0.96

#ifndef _CkPem_H
#define _CkPem_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacks.h"

class CkCert;
class CkPrivateKey;
class CkCertChain;
class CkPublicKey;
class CkTask;
class CkByteData;
class CkJavaKeyStore;
class CkPfx;
class CkBaseProgress;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif


#undef Copy

// CLASS: CkPem
class CK_VISIBLE_PUBLIC CkPem  : public CkClassWithCallbacks
{
    private:

	// Don't allow assignment or copying these objects.
	CkPem(const CkPem &);
	CkPem &operator=(const CkPem &);

    public:
	CkPem(void);
	virtual ~CkPem(void);

	static CkPem *createNew(void);
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
	// When set to true, each of the Load* methods appends to the current contents of
	// this PEM object. When set to false, a Load* method replaces the contents of
	// this PEM object. The default is false.
	bool get_AppendMode(void);
	// When set to true, each of the Load* methods appends to the current contents of
	// this PEM object. When set to false, a Load* method replaces the contents of
	// this PEM object. The default is false.
	void put_AppendMode(bool newVal);

	// This is the number of milliseconds between each AbortCheck event callback. The
	// AbortCheck callback allows an application to abort any event-enabled methods
	// prior to completion. If HeartbeatMs is 0 (the default), no AbortCheck event
	// callbacks will fire.
	int get_HeartbeatMs(void);
	// This is the number of milliseconds between each AbortCheck event callback. The
	// AbortCheck callback allows an application to abort any event-enabled methods
	// prior to completion. If HeartbeatMs is 0 (the default), no AbortCheck event
	// callbacks will fire.
	void put_HeartbeatMs(int newVal);

	// The number of certificates in the loaded PEM. To get the 1st certificate, call
	// GetCert(0).
	int get_NumCerts(void);

	// The number of certificate revocation lists (CRLs) in the loaded PEM.
	int get_NumCrls(void);

	// The number of certificate signing requests (CSRs) in the loaded PEM.
	int get_NumCsrs(void);

	// The number of private keys in the loaded PEM. To get the 1st private key, call
	// GetPrivateKey(0).
	int get_NumPrivateKeys(void);

	// The number of public keys in the loaded PEM. To get the 1st public key, call
	// GetPublicKey(0).
	int get_NumPublicKeys(void);

	// Controls the format to be used for unencrypted private keys when writing a PEM.
	// Possible values are "pkcs1" and "pkcs8". (OpenSSL typically uses the "pkcs8"
	// format.) When writing encrypted private keys to PEM, the format is always PKCS8,
	// and the PEM header is "BEGIN ENCRYPTED PRIVATE KEY". The default is "pkcs8".
	// 
	// The PKCS1 format uses the PEM header: BEGIN RSA PRIVATE KEY.
	// The PKCS8 format uses the PEM header: BEGIN PRIVATE KEY.
	// 
	void get_PrivateKeyFormat(CkString &str);
	// Controls the format to be used for unencrypted private keys when writing a PEM.
	// Possible values are "pkcs1" and "pkcs8". (OpenSSL typically uses the "pkcs8"
	// format.) When writing encrypted private keys to PEM, the format is always PKCS8,
	// and the PEM header is "BEGIN ENCRYPTED PRIVATE KEY". The default is "pkcs8".
	// 
	// The PKCS1 format uses the PEM header: BEGIN RSA PRIVATE KEY.
	// The PKCS8 format uses the PEM header: BEGIN PRIVATE KEY.
	// 
	const char *privateKeyFormat(void);
	// Controls the format to be used for unencrypted private keys when writing a PEM.
	// Possible values are "pkcs1" and "pkcs8". (OpenSSL typically uses the "pkcs8"
	// format.) When writing encrypted private keys to PEM, the format is always PKCS8,
	// and the PEM header is "BEGIN ENCRYPTED PRIVATE KEY". The default is "pkcs8".
	// 
	// The PKCS1 format uses the PEM header: BEGIN RSA PRIVATE KEY.
	// The PKCS8 format uses the PEM header: BEGIN PRIVATE KEY.
	// 
	void put_PrivateKeyFormat(const char *newVal);

	// Controls the format to be used for public keys when writing a PEM. Possible
	// values are "pkcs1" and "pkcs8". (OpenSSL typically uses the "pkcs8" format.) The
	// default is "pkcs8".
	// 
	// The PKCS1 format uses the PEM header: BEGIN RSA PUBLIC KEY.
	// The PKCS8 format uses the PEM header: BEGIN PUBLIC KEY.
	// 
	void get_PublicKeyFormat(CkString &str);
	// Controls the format to be used for public keys when writing a PEM. Possible
	// values are "pkcs1" and "pkcs8". (OpenSSL typically uses the "pkcs8" format.) The
	// default is "pkcs8".
	// 
	// The PKCS1 format uses the PEM header: BEGIN RSA PUBLIC KEY.
	// The PKCS8 format uses the PEM header: BEGIN PUBLIC KEY.
	// 
	const char *publicKeyFormat(void);
	// Controls the format to be used for public keys when writing a PEM. Possible
	// values are "pkcs1" and "pkcs8". (OpenSSL typically uses the "pkcs8" format.) The
	// default is "pkcs8".
	// 
	// The PKCS1 format uses the PEM header: BEGIN RSA PUBLIC KEY.
	// The PKCS8 format uses the PEM header: BEGIN PUBLIC KEY.
	// 
	void put_PublicKeyFormat(const char *newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Adds a certificate, and potentially the certs in its chain of authentication to
	// the PEM. If includeChain is true, then certificates in the cert's chain of
	// authentication up to and including the root are automatically added.
	bool AddCert(CkCert &cert, bool includeChain);


	// Adds a certificate, private key, public key, or csr to the PEM. The possible
	// values for itemType are "certificate" (or "cert"), "privateKey", "publicKey", or
	// "csr". The encoding can be "Base64", "modBase64", "Base32", "QP" (for
	// quoted-printable), "URL" (for url-encoding), "Hex", "url_oauth", "url_rfc1738",
	// "url_rfc2396", and "url_rfc3986". The itemData contains the ASN.1 data in string
	// format according to the encoding specified in encoding.
	bool AddItem(const char *itemType, const char *encoding, const char *itemData);


	// Adds a private key to the PEM object.
	bool AddPrivateKey(CkPrivateKey &privateKey);


	// Adds a private key and it's associated certificate chain to the PEM object.
	bool AddPrivateKey2(CkPrivateKey &privKey, CkCertChain &certChain);


	// Adds a public key to the PEM object.
	bool AddPublicKey(CkPublicKey &pubkey);


	// Removes all content from this PEM object.
	bool Clear(void);


	// Returns the Nth certificate from the PEM. The first certificate is at index 0.
	// The caller is responsible for deleting the object returned by this method.
	CkCert *GetCert(int index);


	// Returns the encoded contents of the Nth item of a particular type (0-based
	// index). The possible values for itemType are "certificate" (or "cert"), "privateKey",
	// "publicKey", or "csr". Input string args are case-insensitive. If the itemType is
	// "privateKey", the itemSubType may be "der" or "pkcs8". If the itemType is "publicKey", the
	// itemSubType may be "der" or "pkcs1". The itemSubType is ignored for other values of itemType. The
	// valid encoding modes are "Base64", "modBase64", "Base32", "Base58", "QP" (for
	// quoted-printable), "URL" (for url-encoding), "Hex", "url_oauth", "url_rfc1738",
	// "url_rfc2396", and "url_rfc3986".
	bool GetEncodedItem(const char *itemType, const char *itemSubType, const char *encoding, int index, CkString &outStr);

	// Returns the encoded contents of the Nth item of a particular type (0-based
	// index). The possible values for itemType are "certificate" (or "cert"), "privateKey",
	// "publicKey", or "csr". Input string args are case-insensitive. If the itemType is
	// "privateKey", the itemSubType may be "der" or "pkcs8". If the itemType is "publicKey", the
	// itemSubType may be "der" or "pkcs1". The itemSubType is ignored for other values of itemType. The
	// valid encoding modes are "Base64", "modBase64", "Base32", "Base58", "QP" (for
	// quoted-printable), "URL" (for url-encoding), "Hex", "url_oauth", "url_rfc1738",
	// "url_rfc2396", and "url_rfc3986".
	const char *getEncodedItem(const char *itemType, const char *itemSubType, const char *encoding, int index);
	// Returns the encoded contents of the Nth item of a particular type (0-based
	// index). The possible values for itemType are "certificate" (or "cert"), "privateKey",
	// "publicKey", or "csr". Input string args are case-insensitive. If the itemType is
	// "privateKey", the itemSubType may be "der" or "pkcs8". If the itemType is "publicKey", the
	// itemSubType may be "der" or "pkcs1". The itemSubType is ignored for other values of itemType. The
	// valid encoding modes are "Base64", "modBase64", "Base32", "Base58", "QP" (for
	// quoted-printable), "URL" (for url-encoding), "Hex", "url_oauth", "url_rfc1738",
	// "url_rfc2396", and "url_rfc3986".
	const char *encodedItem(const char *itemType, const char *itemSubType, const char *encoding, int index);


	// Returns the Nth private key from the PEM. The first private key is at index 0.
	// The caller is responsible for deleting the object returned by this method.
	CkPrivateKey *GetPrivateKey(int index);


	// Returns the Nth public key from the PEM. The first public key is at index 0.
	// The caller is responsible for deleting the object returned by this method.
	CkPublicKey *GetPublicKey(int index);


	// Loads the PEM from the contents of an in-memory PKCS7 container (.p7b).
	bool LoadP7b(CkByteData &p7bData);

	// Loads the PEM from the contents of an in-memory PKCS7 container (.p7b).
	CkTask *LoadP7bAsync(CkByteData &p7bData);


	// Loads the contents of a PKCS7 container (.p7b file).
	bool LoadP7bFile(const char *path);

	// Loads the contents of a PKCS7 container (.p7b file).
	CkTask *LoadP7bFileAsync(const char *path);


	// Loads the PEM from a PEM string. If encrypted, then the password is required for
	// decryption. Otherwise, an empty string (or any string) may be passed for the
	// password.
	bool LoadPem(const char *pemContent, const char *password);

	// Loads the PEM from a PEM string. If encrypted, then the password is required for
	// decryption. Otherwise, an empty string (or any string) may be passed for the
	// password.
	CkTask *LoadPemAsync(const char *pemContent, const char *password);


	// Loads the PEM from a PEM file. If encrypted, then the password is required for
	// decryption. Otherwise, an empty string (or any string) may be passed for the
	// password.
	bool LoadPemFile(const char *path, const char *password);

	// Loads the PEM from a PEM file. If encrypted, then the password is required for
	// decryption. Otherwise, an empty string (or any string) may be passed for the
	// password.
	CkTask *LoadPemFileAsync(const char *path, const char *password);


	// Loads the caller of the task's async method.
	bool LoadTaskCaller(CkTask &task);


	// Removes the Nth certificate from the PEM. The first certificate is at index 0.
	bool RemoveCert(int index);


	// Removes the Nth private key from the PEM. The first private key is at index 0.
	bool RemovePrivateKey(int index);


	// Converts the PEM to JKS and returns the Java KeyStore object. If the alias is
	// non-empty, the 1st object (private key or certificate) will use the alias, and
	// all others (if any) will receive auto-generated aliases. The JKS returned will
	// be encrypted using the provided password. If the PEM contains only certificates (no
	// private keys), then the password is unused.
	// The caller is responsible for deleting the object returned by this method.
	CkJavaKeyStore *ToJks(const char *alias, const char *password);


	// Write the PFX to a PEM formatted string. The resultant PEM will contain the
	// private key, as well as the certs in the chain of authentication (or whatever
	// certs are available in the PFX). For example:-----BEGIN RSA PRIVATE KEY-----
	// ...
	// ... the private key associated with the main certificate.
	// ...
	// -----END RSA PRIVATE KEY-----
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... the main certificate
	// ...
	// -----END CERTIFICATE-----
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... an intermediate CA certificate (if present)
	// ...
	// -----END CERTIFICATE-----
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... the root CA certificate
	// ...
	// -----END CERTIFICATE-----
	bool ToPem(CkString &outStr);

	// Write the PFX to a PEM formatted string. The resultant PEM will contain the
	// private key, as well as the certs in the chain of authentication (or whatever
	// certs are available in the PFX). For example:-----BEGIN RSA PRIVATE KEY-----
	// ...
	// ... the private key associated with the main certificate.
	// ...
	// -----END RSA PRIVATE KEY-----
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... the main certificate
	// ...
	// -----END CERTIFICATE-----
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... an intermediate CA certificate (if present)
	// ...
	// -----END CERTIFICATE-----
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... the root CA certificate
	// ...
	// -----END CERTIFICATE-----
	const char *toPem(void);

	// Write the PFX to a PEM formatted string. If extendedAttrs is true, then extended
	// properties (Bag Attributes and Key Attributes) are output. If noKeys is true,
	// then no private keys are output. If noCerts is true, then no certificates are
	// output. If noCaCerts is true, then no CA certs or intermediate CA certs are output.
	// If encryptAlg is not empty, it indicates the encryption algorithm to be used for
	// encrypting the private keys (otherwise the private keys are output unencrypted).
	// The possible choices for the encryptAlg are "des3", "aes128", "aes192", and "aes256".
	// (All encryption algorithm choices use CBC mode.) If the private keys are to be
	// encrypted, then password is the password to be used. Otherwise, password may be left
	// empty. For example:Bag Attributes
	//     Microsoft Local Key set:localKeyID: 01 00 00 00 
	//     friendlyName: le-2b09a3d2-9037-4a05-95cc-4d44518e8607
	//     Microsoft CSP Name: Microsoft RSA SChannel Cryptographic Provider
	// Key Attributes
	//     X509v3 Key Usage: 10 
	//  -----BEGIN RSA PRIVATE KEY-----
	// ...
	// ... the private key associated with the main certificate.
	// ...
	// -----END RSA PRIVATE KEY-----
	// Bag Attributes
	//     localKeyID: 01 00 00 00 
	//     1.3.6.1.4.1.311.17.3.92: 00 08 00 00 
	//     1.3.6.1.4.1.311.17.3.20: C2 53 54 F3 ...
	//     1.3.6.1.4.1.311.17.3.71: 49 00 43 00 ...
	//     1.3.6.1.4.1.311.17.3.75: 31 00 42 00 ...
	// subject=/OU=Domain Control Validated/OU=PositiveSSL/CN=something.com
	// issuer=/C=GB/ST=Greater Manchester/L=Salford/O=COMODO CA Limited/CN=COMODO RSA Domain Validation Secure Server CA
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... the main certificate
	// ...
	// -----END CERTIFICATE-----
	// ...
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... an intermediate CA certificate (if present)
	// ...
	// -----END CERTIFICATE-----
	// ...
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... the root CA certificate
	// ...
	// -----END CERTIFICATE-----
	bool ToPemEx(bool extendedAttrs, bool noKeys, bool noCerts, bool noCaCerts, const char *encryptAlg, const char *password, CkString &outStr);

	// Write the PFX to a PEM formatted string. If extendedAttrs is true, then extended
	// properties (Bag Attributes and Key Attributes) are output. If noKeys is true,
	// then no private keys are output. If noCerts is true, then no certificates are
	// output. If noCaCerts is true, then no CA certs or intermediate CA certs are output.
	// If encryptAlg is not empty, it indicates the encryption algorithm to be used for
	// encrypting the private keys (otherwise the private keys are output unencrypted).
	// The possible choices for the encryptAlg are "des3", "aes128", "aes192", and "aes256".
	// (All encryption algorithm choices use CBC mode.) If the private keys are to be
	// encrypted, then password is the password to be used. Otherwise, password may be left
	// empty. For example:Bag Attributes
	//     Microsoft Local Key set:localKeyID: 01 00 00 00 
	//     friendlyName: le-2b09a3d2-9037-4a05-95cc-4d44518e8607
	//     Microsoft CSP Name: Microsoft RSA SChannel Cryptographic Provider
	// Key Attributes
	//     X509v3 Key Usage: 10 
	//  -----BEGIN RSA PRIVATE KEY-----
	// ...
	// ... the private key associated with the main certificate.
	// ...
	// -----END RSA PRIVATE KEY-----
	// Bag Attributes
	//     localKeyID: 01 00 00 00 
	//     1.3.6.1.4.1.311.17.3.92: 00 08 00 00 
	//     1.3.6.1.4.1.311.17.3.20: C2 53 54 F3 ...
	//     1.3.6.1.4.1.311.17.3.71: 49 00 43 00 ...
	//     1.3.6.1.4.1.311.17.3.75: 31 00 42 00 ...
	// subject=/OU=Domain Control Validated/OU=PositiveSSL/CN=something.com
	// issuer=/C=GB/ST=Greater Manchester/L=Salford/O=COMODO CA Limited/CN=COMODO RSA Domain Validation Secure Server CA
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... the main certificate
	// ...
	// -----END CERTIFICATE-----
	// ...
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... an intermediate CA certificate (if present)
	// ...
	// -----END CERTIFICATE-----
	// ...
	// -----BEGIN CERTIFICATE-----
	// ...
	// ... the root CA certificate
	// ...
	// -----END CERTIFICATE-----
	const char *toPemEx(bool extendedAttrs, bool noKeys, bool noCerts, bool noCaCerts, const char *encryptAlg, const char *password);

	// Converts the PEM to PKCS12 and returns the PFX object. The PFX object has method
	// for saving to a file, exporting to an encoded string, converting to a JKS (Java
	// Keystore), or even converting back to PEM.
	// 
	// Note: The PEM must contain at least one private key to convert to PKCS12. The
	// typical case is that a PKCS12 contains a single private key, along with the
	// associated certificate and the certificates in the chain of authentication.
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkPfx *ToPfx(void);






	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
