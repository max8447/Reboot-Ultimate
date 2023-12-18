// CkXmlDSigGen.h: interface for the CkXmlDSigGen class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#define _CkVersion 9.5.0.96

#ifndef _CkXmlDSigGen_H
#define _CkXmlDSigGen_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacks.h"

class CkStringBuilder;
class CkBinData;
class CkXml;
class CkTask;
class CkHttp;
class CkPrivateKey;
class CkJsonObject;
class CkCert;
class CkBaseProgress;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif


#undef Copy

// CLASS: CkXmlDSigGen
class CK_VISIBLE_PUBLIC CkXmlDSigGen  : public CkClassWithCallbacks
{
    private:

	// Don't allow assignment or copying these objects.
	CkXmlDSigGen(const CkXmlDSigGen &);
	CkXmlDSigGen &operator=(const CkXmlDSigGen &);

    public:
	CkXmlDSigGen(void);
	virtual ~CkXmlDSigGen(void);

	static CkXmlDSigGen *createNew(void);
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
	// A comma-separated list of keywords to specify special behaviors to work around
	// potential oddities or special requirements needed for providing signatures to
	// particular systems. This is an open-ended property where new behaviors can be
	// implemented depending on the needs encountered by Chilkat customers. The
	// possible behaviors are listed below.
	//     AttributeSortingBug (introduced in v9.5.0.79) Tells Chilkat to produce a
	//     signature that duplicates a common XML canonicalization attribute sorting bug
	//     found in some XML signature implementations (such as JPK VAT signed XML
	//     documents for Polish government, i.e. mf.gov.pl, csioz.gov.pl, crd.gov.pl, etc).
	//     See XML Signature Canonicalization Bug
	//     <http://cknotes.com/xml-signature-canonicalization-bug-in-widely-used-softwar
	//     e/> for details.
	//     Base64CrEntity Produce multi-line base64 for XML elements such as
	//     SignatureValue and X509Certificate, with each line ending in a CR hex entity,
	//     except for the last line. For example:<ds:X509Certificate>MIIFNTCCBB2gAwIBAgIQHozVnBl1lTsusAh26u6WZTANBgkqhkiG9w0BAQsFADCBlzELMAkGA1UE    
	// BhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgG    
	// A1UEChMRQ09NT0RPIENBIExpbWl0ZWQxPTA7BgNVBAMTNENPTU9ETyBSU0EgQ2xpZW50IEF1dGhl    
	// ...    
	// sp3FRlACVeb1Qlytr4vgc5FlCqn0rMtjlF4=    
	//     </ds:X509Certificate> 
	//     Base64Cr13Entity Produce multi-line base64 for XML elements such as
	//     SignatureValue and X509Certificate, with each line ending in a CR decimal
	//     entity, except for the last line. For example:<ds:X509Certificate>MIIFNTCCBB2gAwIBAgIQHozVnBl1lTsusAh26u6WZTANBgkqhkiG9w0BAQsFADCBlzELMAkGA1UE    
	// BhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgG    
	// A1UEChMRQ09NT0RPIENBIExpbWl0ZWQxPTA7BgNVBAMTNENPTU9ETyBSU0EgQ2xpZW50IEF1dGhl    
	// ...    
	// sp3FRlACVeb1Qlytr4vgc5FlCqn0rMtjlF4=    
	//     </ds:X509Certificate> 
	//     Base64Multiline Produce multi-line base64 for XML elements such as
	//     SignatureValue and X509Certificate. For example:<ds:X509Certificate>MIIFNTCCBB2gAwIBAgIQHozVnBl1lTsusAh26u6WZTANBgkqhkiG9w0BAQsFADCBlzELMAkGA1UE    
	// BhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgG    
	// A1UEChMRQ09NT0RPIENBIExpbWl0ZWQxPTA7BgNVBAMTNENPTU9ETyBSU0EgQ2xpZW50IEF1dGhl    
	// ...    
	// sp3FRlACVeb1Qlytr4vgc5FlCqn0rMtjlF4=    
	//     </ds:X509Certificate> 
	//     ForceAddEnvelopedSignatureTransform The "_LT_Transform
	//     Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature" /> " is
	//     normally only added when the Signature is contained within the XML fragment that
	//     is signed. The meaning of this tranformation is to tell the verifier to remove
	//     the Signature from the data prior to canonicalizing. If the Signature is not
	//     contained within the XML fragment that was signed, then the signature was not
	//     enveloped. There would be no need to remove the Signature because the Signature
	//     is not contained in the XML fragment being verified. However.. some brain-dead
	//     verifiying systems require this Transform to be present regardless of whether it
	//     makes sense. This behavior will cause Chilkat to add the Transform regardless.
	//     NoEnvelopedSignatureTransform (introduced in v9.5.0.82) Prevents the
	//     "_LT_Transform Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature"
	//     /> " from being added in all cases.
	//     EnvelopedTransformFirst (introduced in v9.5.0.87) Forces the
	//     http://www.w3.org/2000/09/xmldsig#enveloped-signature to be listed first when
	//     there are multiple transforms for a reference.
	//     ebXmlTransform (introduced in v9.5.0.73) Causes the following tranform to be
	//     added for ebXml messages:_LT_Transform Algorithm="http://www.w3.org/TR/1999/REC-xpath-19991116">    
	//     _LT_XPath xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/">not(ancestor-or-self::node()[@SOAP-ENV:actor="urn:oasis:names:tc:ebxml-msg:actor:nextMSH"]    
	//          | ancestor-or-self::node()[@SOAP-ENV:actor="http://schemas.xmlsoap.org/soap/actor/next"])_LT_/XPath>    
	// _LT_/Transform>
	//     TransformSignatureXPath (introduced in v9.5.0.75) Causes the following
	//     tranform to be added:_LT_ds:Transform Algorithm="http://www.w3.org/TR/1999/REC-xpath-19991116"_GT_    
	//    _LT_ds:XPath_GT_not(ancestor-or-self::ds:Signature)_LT_/ds:XPath_GT_    
	// _LT_/ds:Transform_GT_
	//     CompactSignedXml (introduced in v9.5.0.73) The passed-in XML to be signed is
	//     first reformatted to a compact representation by removing all CR's, LF's, and
	//     unnecessary whitespace so that the XML to be signed is on a single line. The
	//     resulting XML (with signature) is also entirely contained on a single line. (If
	//     an XML declarator is present, then it will remain on it's own line.)
	//     IndentedSignature (introduced in v9.5.0.73) Causes the XML Signature to be
	//     produced on multiple lines with indentation for easier human readability. The
	//     CompactSignedXml behavior takes precedence over this behavior.
	//     FullLocalSigningTime (introduced in v9.5.0.76) Causes the signing time to be
	//     formatted like this: 2017-05-20T19:16:05.649+01:00.nnn, where the ".nnn" is
	//     added to indicate milliseconds.
	//     LocalSigningTime (introduced in v9.5.0.76) Causes the signing time to be
	//     formatted using a local time (with a timezone offset such as "+01:00" rather
	//     than "Z" to signify GMT).
	//     NoReplaceSigningTime Don't replace the <SigningTime> content with a
	//     timestamp of the current date/time. Instead keep the current value provided by
	//     the application.
	//     NoTimestampBias Exclude the timestamp bias from the generated <SigningTime>
	//     DnReverseOrder (introduced in v9.5.0.77) Causes DN's (certificate
	//     Distinguished Names) to be written in reverse order. Reverse order leads with
	//     "CN", such as "CN=..., O=..., OU=..., C=...", whereas normal order ends with
	//     "CN", such as "C=..., OU=..., O=..., CN=..."
	//     IssuerSerialHex (introduced in v9.5.0.77) Causes the issuer serial number
	//     located in SignedProperties.SignedSignatureProperties.SigningCertificate to be
	//     emitted as uppercase hex instead of decimal. (Also, when signing XML for
	//     e-dokumenty.mf.gov.pl, Chilkat automatically recognizes it and uses
	//     IssuerSerialHex.)
	//     IssuerSerialHexLower (introduced in v9.5.0.77) Causes the issuer serial
	//     number located in SignedProperties.SignedSignatureProperties.SigningCertificate
	//     to be emitted as lowercase hex instead of decimal.
	//     SigningTimeAdjust-_LT_numSeconds_GT_ (introduced in v9.5.0.80) When Chilkat
	//     automatically fills in the value for a SigningTime, it will use the current
	//     system date/time. This behavior can be used to adjust the generate time to
	//     numSeconds in the past. For example: "SigningTimeAdjust-60" will generate a
	//     signing time 60 seconds prior to the current time.
	//     SigningTimeAdjust+_LT_numSeconds_GT_ (introduced in v9.5.0.88) When Chilkat
	//     automatically fills in the value for a SigningTime, it will use the current
	//     system date/time. This behavior can be used to adjust the generate time to
	//     numSeconds in the future. For example: "SigningTimeAdjust+60" will generate a
	//     signing time 60 seconds past the current time.
	//     UBLDocumentSignatures Causes an XPath "ancestor-or-self" Transform to be
	//     added for the 1st reference. See the example at UBL XAdES Enveloped
	//     Signature
	//     <https://www.example-code.com/csharp/ubl_xades_enveloped_signature.asp>
	//     SignExistingSignatures This keyword can be used when applying a 2nd or
	//     greater signature and the new signature will encompass one or more existing
	//     signatures. The default behavior is that existing signatures are not included in
	//     the canonicalization/digest before signing. Adding this keyword will cause
	//     existing signatures to be included in the canonicalization/digest.
	void get_Behaviors(CkString &str);
	// A comma-separated list of keywords to specify special behaviors to work around
	// potential oddities or special requirements needed for providing signatures to
	// particular systems. This is an open-ended property where new behaviors can be
	// implemented depending on the needs encountered by Chilkat customers. The
	// possible behaviors are listed below.
	//     AttributeSortingBug (introduced in v9.5.0.79) Tells Chilkat to produce a
	//     signature that duplicates a common XML canonicalization attribute sorting bug
	//     found in some XML signature implementations (such as JPK VAT signed XML
	//     documents for Polish government, i.e. mf.gov.pl, csioz.gov.pl, crd.gov.pl, etc).
	//     See XML Signature Canonicalization Bug
	//     <http://cknotes.com/xml-signature-canonicalization-bug-in-widely-used-softwar
	//     e/> for details.
	//     Base64CrEntity Produce multi-line base64 for XML elements such as
	//     SignatureValue and X509Certificate, with each line ending in a CR hex entity,
	//     except for the last line. For example:<ds:X509Certificate>MIIFNTCCBB2gAwIBAgIQHozVnBl1lTsusAh26u6WZTANBgkqhkiG9w0BAQsFADCBlzELMAkGA1UE    
	// BhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgG    
	// A1UEChMRQ09NT0RPIENBIExpbWl0ZWQxPTA7BgNVBAMTNENPTU9ETyBSU0EgQ2xpZW50IEF1dGhl    
	// ...    
	// sp3FRlACVeb1Qlytr4vgc5FlCqn0rMtjlF4=    
	//     </ds:X509Certificate> 
	//     Base64Cr13Entity Produce multi-line base64 for XML elements such as
	//     SignatureValue and X509Certificate, with each line ending in a CR decimal
	//     entity, except for the last line. For example:<ds:X509Certificate>MIIFNTCCBB2gAwIBAgIQHozVnBl1lTsusAh26u6WZTANBgkqhkiG9w0BAQsFADCBlzELMAkGA1UE    
	// BhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgG    
	// A1UEChMRQ09NT0RPIENBIExpbWl0ZWQxPTA7BgNVBAMTNENPTU9ETyBSU0EgQ2xpZW50IEF1dGhl    
	// ...    
	// sp3FRlACVeb1Qlytr4vgc5FlCqn0rMtjlF4=    
	//     </ds:X509Certificate> 
	//     Base64Multiline Produce multi-line base64 for XML elements such as
	//     SignatureValue and X509Certificate. For example:<ds:X509Certificate>MIIFNTCCBB2gAwIBAgIQHozVnBl1lTsusAh26u6WZTANBgkqhkiG9w0BAQsFADCBlzELMAkGA1UE    
	// BhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgG    
	// A1UEChMRQ09NT0RPIENBIExpbWl0ZWQxPTA7BgNVBAMTNENPTU9ETyBSU0EgQ2xpZW50IEF1dGhl    
	// ...    
	// sp3FRlACVeb1Qlytr4vgc5FlCqn0rMtjlF4=    
	//     </ds:X509Certificate> 
	//     ForceAddEnvelopedSignatureTransform The "_LT_Transform
	//     Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature" /> " is
	//     normally only added when the Signature is contained within the XML fragment that
	//     is signed. The meaning of this tranformation is to tell the verifier to remove
	//     the Signature from the data prior to canonicalizing. If the Signature is not
	//     contained within the XML fragment that was signed, then the signature was not
	//     enveloped. There would be no need to remove the Signature because the Signature
	//     is not contained in the XML fragment being verified. However.. some brain-dead
	//     verifiying systems require this Transform to be present regardless of whether it
	//     makes sense. This behavior will cause Chilkat to add the Transform regardless.
	//     NoEnvelopedSignatureTransform (introduced in v9.5.0.82) Prevents the
	//     "_LT_Transform Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature"
	//     /> " from being added in all cases.
	//     EnvelopedTransformFirst (introduced in v9.5.0.87) Forces the
	//     http://www.w3.org/2000/09/xmldsig#enveloped-signature to be listed first when
	//     there are multiple transforms for a reference.
	//     ebXmlTransform (introduced in v9.5.0.73) Causes the following tranform to be
	//     added for ebXml messages:_LT_Transform Algorithm="http://www.w3.org/TR/1999/REC-xpath-19991116">    
	//     _LT_XPath xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/">not(ancestor-or-self::node()[@SOAP-ENV:actor="urn:oasis:names:tc:ebxml-msg:actor:nextMSH"]    
	//          | ancestor-or-self::node()[@SOAP-ENV:actor="http://schemas.xmlsoap.org/soap/actor/next"])_LT_/XPath>    
	// _LT_/Transform>
	//     TransformSignatureXPath (introduced in v9.5.0.75) Causes the following
	//     tranform to be added:_LT_ds:Transform Algorithm="http://www.w3.org/TR/1999/REC-xpath-19991116"_GT_    
	//    _LT_ds:XPath_GT_not(ancestor-or-self::ds:Signature)_LT_/ds:XPath_GT_    
	// _LT_/ds:Transform_GT_
	//     CompactSignedXml (introduced in v9.5.0.73) The passed-in XML to be signed is
	//     first reformatted to a compact representation by removing all CR's, LF's, and
	//     unnecessary whitespace so that the XML to be signed is on a single line. The
	//     resulting XML (with signature) is also entirely contained on a single line. (If
	//     an XML declarator is present, then it will remain on it's own line.)
	//     IndentedSignature (introduced in v9.5.0.73) Causes the XML Signature to be
	//     produced on multiple lines with indentation for easier human readability. The
	//     CompactSignedXml behavior takes precedence over this behavior.
	//     FullLocalSigningTime (introduced in v9.5.0.76) Causes the signing time to be
	//     formatted like this: 2017-05-20T19:16:05.649+01:00.nnn, where the ".nnn" is
	//     added to indicate milliseconds.
	//     LocalSigningTime (introduced in v9.5.0.76) Causes the signing time to be
	//     formatted using a local time (with a timezone offset such as "+01:00" rather
	//     than "Z" to signify GMT).
	//     NoReplaceSigningTime Don't replace the <SigningTime> content with a
	//     timestamp of the current date/time. Instead keep the current value provided by
	//     the application.
	//     NoTimestampBias Exclude the timestamp bias from the generated <SigningTime>
	//     DnReverseOrder (introduced in v9.5.0.77) Causes DN's (certificate
	//     Distinguished Names) to be written in reverse order. Reverse order leads with
	//     "CN", such as "CN=..., O=..., OU=..., C=...", whereas normal order ends with
	//     "CN", such as "C=..., OU=..., O=..., CN=..."
	//     IssuerSerialHex (introduced in v9.5.0.77) Causes the issuer serial number
	//     located in SignedProperties.SignedSignatureProperties.SigningCertificate to be
	//     emitted as uppercase hex instead of decimal. (Also, when signing XML for
	//     e-dokumenty.mf.gov.pl, Chilkat automatically recognizes it and uses
	//     IssuerSerialHex.)
	//     IssuerSerialHexLower (introduced in v9.5.0.77) Causes the issuer serial
	//     number located in SignedProperties.SignedSignatureProperties.SigningCertificate
	//     to be emitted as lowercase hex instead of decimal.
	//     SigningTimeAdjust-_LT_numSeconds_GT_ (introduced in v9.5.0.80) When Chilkat
	//     automatically fills in the value for a SigningTime, it will use the current
	//     system date/time. This behavior can be used to adjust the generate time to
	//     numSeconds in the past. For example: "SigningTimeAdjust-60" will generate a
	//     signing time 60 seconds prior to the current time.
	//     SigningTimeAdjust+_LT_numSeconds_GT_ (introduced in v9.5.0.88) When Chilkat
	//     automatically fills in the value for a SigningTime, it will use the current
	//     system date/time. This behavior can be used to adjust the generate time to
	//     numSeconds in the future. For example: "SigningTimeAdjust+60" will generate a
	//     signing time 60 seconds past the current time.
	//     UBLDocumentSignatures Causes an XPath "ancestor-or-self" Transform to be
	//     added for the 1st reference. See the example at UBL XAdES Enveloped
	//     Signature
	//     <https://www.example-code.com/csharp/ubl_xades_enveloped_signature.asp>
	//     SignExistingSignatures This keyword can be used when applying a 2nd or
	//     greater signature and the new signature will encompass one or more existing
	//     signatures. The default behavior is that existing signatures are not included in
	//     the canonicalization/digest before signing. Adding this keyword will cause
	//     existing signatures to be included in the canonicalization/digest.
	const char *behaviors(void);
	// A comma-separated list of keywords to specify special behaviors to work around
	// potential oddities or special requirements needed for providing signatures to
	// particular systems. This is an open-ended property where new behaviors can be
	// implemented depending on the needs encountered by Chilkat customers. The
	// possible behaviors are listed below.
	//     AttributeSortingBug (introduced in v9.5.0.79) Tells Chilkat to produce a
	//     signature that duplicates a common XML canonicalization attribute sorting bug
	//     found in some XML signature implementations (such as JPK VAT signed XML
	//     documents for Polish government, i.e. mf.gov.pl, csioz.gov.pl, crd.gov.pl, etc).
	//     See XML Signature Canonicalization Bug
	//     <http://cknotes.com/xml-signature-canonicalization-bug-in-widely-used-softwar
	//     e/> for details.
	//     Base64CrEntity Produce multi-line base64 for XML elements such as
	//     SignatureValue and X509Certificate, with each line ending in a CR hex entity,
	//     except for the last line. For example:<ds:X509Certificate>MIIFNTCCBB2gAwIBAgIQHozVnBl1lTsusAh26u6WZTANBgkqhkiG9w0BAQsFADCBlzELMAkGA1UE    
	// BhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgG    
	// A1UEChMRQ09NT0RPIENBIExpbWl0ZWQxPTA7BgNVBAMTNENPTU9ETyBSU0EgQ2xpZW50IEF1dGhl    
	// ...    
	// sp3FRlACVeb1Qlytr4vgc5FlCqn0rMtjlF4=    
	//     </ds:X509Certificate> 
	//     Base64Cr13Entity Produce multi-line base64 for XML elements such as
	//     SignatureValue and X509Certificate, with each line ending in a CR decimal
	//     entity, except for the last line. For example:<ds:X509Certificate>MIIFNTCCBB2gAwIBAgIQHozVnBl1lTsusAh26u6WZTANBgkqhkiG9w0BAQsFADCBlzELMAkGA1UE    
	// BhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgG    
	// A1UEChMRQ09NT0RPIENBIExpbWl0ZWQxPTA7BgNVBAMTNENPTU9ETyBSU0EgQ2xpZW50IEF1dGhl    
	// ...    
	// sp3FRlACVeb1Qlytr4vgc5FlCqn0rMtjlF4=    
	//     </ds:X509Certificate> 
	//     Base64Multiline Produce multi-line base64 for XML elements such as
	//     SignatureValue and X509Certificate. For example:<ds:X509Certificate>MIIFNTCCBB2gAwIBAgIQHozVnBl1lTsusAh26u6WZTANBgkqhkiG9w0BAQsFADCBlzELMAkGA1UE    
	// BhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgG    
	// A1UEChMRQ09NT0RPIENBIExpbWl0ZWQxPTA7BgNVBAMTNENPTU9ETyBSU0EgQ2xpZW50IEF1dGhl    
	// ...    
	// sp3FRlACVeb1Qlytr4vgc5FlCqn0rMtjlF4=    
	//     </ds:X509Certificate> 
	//     ForceAddEnvelopedSignatureTransform The "_LT_Transform
	//     Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature" /> " is
	//     normally only added when the Signature is contained within the XML fragment that
	//     is signed. The meaning of this tranformation is to tell the verifier to remove
	//     the Signature from the data prior to canonicalizing. If the Signature is not
	//     contained within the XML fragment that was signed, then the signature was not
	//     enveloped. There would be no need to remove the Signature because the Signature
	//     is not contained in the XML fragment being verified. However.. some brain-dead
	//     verifiying systems require this Transform to be present regardless of whether it
	//     makes sense. This behavior will cause Chilkat to add the Transform regardless.
	//     NoEnvelopedSignatureTransform (introduced in v9.5.0.82) Prevents the
	//     "_LT_Transform Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature"
	//     /> " from being added in all cases.
	//     EnvelopedTransformFirst (introduced in v9.5.0.87) Forces the
	//     http://www.w3.org/2000/09/xmldsig#enveloped-signature to be listed first when
	//     there are multiple transforms for a reference.
	//     ebXmlTransform (introduced in v9.5.0.73) Causes the following tranform to be
	//     added for ebXml messages:_LT_Transform Algorithm="http://www.w3.org/TR/1999/REC-xpath-19991116">    
	//     _LT_XPath xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/">not(ancestor-or-self::node()[@SOAP-ENV:actor="urn:oasis:names:tc:ebxml-msg:actor:nextMSH"]    
	//          | ancestor-or-self::node()[@SOAP-ENV:actor="http://schemas.xmlsoap.org/soap/actor/next"])_LT_/XPath>    
	// _LT_/Transform>
	//     TransformSignatureXPath (introduced in v9.5.0.75) Causes the following
	//     tranform to be added:_LT_ds:Transform Algorithm="http://www.w3.org/TR/1999/REC-xpath-19991116"_GT_    
	//    _LT_ds:XPath_GT_not(ancestor-or-self::ds:Signature)_LT_/ds:XPath_GT_    
	// _LT_/ds:Transform_GT_
	//     CompactSignedXml (introduced in v9.5.0.73) The passed-in XML to be signed is
	//     first reformatted to a compact representation by removing all CR's, LF's, and
	//     unnecessary whitespace so that the XML to be signed is on a single line. The
	//     resulting XML (with signature) is also entirely contained on a single line. (If
	//     an XML declarator is present, then it will remain on it's own line.)
	//     IndentedSignature (introduced in v9.5.0.73) Causes the XML Signature to be
	//     produced on multiple lines with indentation for easier human readability. The
	//     CompactSignedXml behavior takes precedence over this behavior.
	//     FullLocalSigningTime (introduced in v9.5.0.76) Causes the signing time to be
	//     formatted like this: 2017-05-20T19:16:05.649+01:00.nnn, where the ".nnn" is
	//     added to indicate milliseconds.
	//     LocalSigningTime (introduced in v9.5.0.76) Causes the signing time to be
	//     formatted using a local time (with a timezone offset such as "+01:00" rather
	//     than "Z" to signify GMT).
	//     NoReplaceSigningTime Don't replace the <SigningTime> content with a
	//     timestamp of the current date/time. Instead keep the current value provided by
	//     the application.
	//     NoTimestampBias Exclude the timestamp bias from the generated <SigningTime>
	//     DnReverseOrder (introduced in v9.5.0.77) Causes DN's (certificate
	//     Distinguished Names) to be written in reverse order. Reverse order leads with
	//     "CN", such as "CN=..., O=..., OU=..., C=...", whereas normal order ends with
	//     "CN", such as "C=..., OU=..., O=..., CN=..."
	//     IssuerSerialHex (introduced in v9.5.0.77) Causes the issuer serial number
	//     located in SignedProperties.SignedSignatureProperties.SigningCertificate to be
	//     emitted as uppercase hex instead of decimal. (Also, when signing XML for
	//     e-dokumenty.mf.gov.pl, Chilkat automatically recognizes it and uses
	//     IssuerSerialHex.)
	//     IssuerSerialHexLower (introduced in v9.5.0.77) Causes the issuer serial
	//     number located in SignedProperties.SignedSignatureProperties.SigningCertificate
	//     to be emitted as lowercase hex instead of decimal.
	//     SigningTimeAdjust-_LT_numSeconds_GT_ (introduced in v9.5.0.80) When Chilkat
	//     automatically fills in the value for a SigningTime, it will use the current
	//     system date/time. This behavior can be used to adjust the generate time to
	//     numSeconds in the past. For example: "SigningTimeAdjust-60" will generate a
	//     signing time 60 seconds prior to the current time.
	//     SigningTimeAdjust+_LT_numSeconds_GT_ (introduced in v9.5.0.88) When Chilkat
	//     automatically fills in the value for a SigningTime, it will use the current
	//     system date/time. This behavior can be used to adjust the generate time to
	//     numSeconds in the future. For example: "SigningTimeAdjust+60" will generate a
	//     signing time 60 seconds past the current time.
	//     UBLDocumentSignatures Causes an XPath "ancestor-or-self" Transform to be
	//     added for the 1st reference. See the example at UBL XAdES Enveloped
	//     Signature
	//     <https://www.example-code.com/csharp/ubl_xades_enveloped_signature.asp>
	//     SignExistingSignatures This keyword can be used when applying a 2nd or
	//     greater signature and the new signature will encompass one or more existing
	//     signatures. The default behavior is that existing signatures are not included in
	//     the canonicalization/digest before signing. Adding this keyword will cause
	//     existing signatures to be included in the canonicalization/digest.
	void put_Behaviors(const char *newVal);

	// Specifies custom XML to be inserted in the KeyInfo element of the Signature. A
	// common use is to provide a wsse:SecurityTokenReference fragment of XML.
	void get_CustomKeyInfoXml(CkString &str);
	// Specifies custom XML to be inserted in the KeyInfo element of the Signature. A
	// common use is to provide a wsse:SecurityTokenReference fragment of XML.
	const char *customKeyInfoXml(void);
	// Specifies custom XML to be inserted in the KeyInfo element of the Signature. A
	// common use is to provide a wsse:SecurityTokenReference fragment of XML.
	void put_CustomKeyInfoXml(const char *newVal);

	// The namespace prefix to use for InclusiveNamespaces elements. The default value
	// is "ec". Set this property to the empty string to omit an InclusiveNamespaces
	// prefix. For example, given the default values of IncNamespaceUri and
	// IncNamespacePrefix, generated InclusiveNamespaces elements will appear like
	// this:...
	void get_IncNamespacePrefix(CkString &str);
	// The namespace prefix to use for InclusiveNamespaces elements. The default value
	// is "ec". Set this property to the empty string to omit an InclusiveNamespaces
	// prefix. For example, given the default values of IncNamespaceUri and
	// IncNamespacePrefix, generated InclusiveNamespaces elements will appear like
	// this:...
	const char *incNamespacePrefix(void);
	// The namespace prefix to use for InclusiveNamespaces elements. The default value
	// is "ec". Set this property to the empty string to omit an InclusiveNamespaces
	// prefix. For example, given the default values of IncNamespaceUri and
	// IncNamespacePrefix, generated InclusiveNamespaces elements will appear like
	// this:...
	void put_IncNamespacePrefix(const char *newVal);

	// The namespace URI for any InclusiveNamespaces elements that are created. The
	// default value is "http://www.w3.org/2001/10/xml-exc-c14n#". For example, if the
	// IncNamespacePrefix equals "ec" and this property remains at the default value,
	// then the generated Signature element will be:...
	void get_IncNamespaceUri(CkString &str);
	// The namespace URI for any InclusiveNamespaces elements that are created. The
	// default value is "http://www.w3.org/2001/10/xml-exc-c14n#". For example, if the
	// IncNamespacePrefix equals "ec" and this property remains at the default value,
	// then the generated Signature element will be:...
	const char *incNamespaceUri(void);
	// The namespace URI for any InclusiveNamespaces elements that are created. The
	// default value is "http://www.w3.org/2001/10/xml-exc-c14n#". For example, if the
	// IncNamespacePrefix equals "ec" and this property remains at the default value,
	// then the generated Signature element will be:...
	void put_IncNamespaceUri(const char *newVal);

	// If set, causes the generated KeyInfo element to include an Id attribute with
	// this value. For example:...
	//    _LT_ds:KeyInfo Id="KeyInfo"_GT_
	//       _LT_ds:X509Data_GT_
	//          _LT_ds:X509SubjectName_GT_CERTIFICADO DE ABC_LT_/ds:X509SubjectName_GT_
	//          _LT_ds:X509Certificate_GT_MIIITTCC....fIsIZeZOeQ=_LT_/ds:X509Certificate_GT_
	//       _LT_/ds:X509Data_GT_
	//    _LT_/ds:KeyInfo_GT_
	// ...
	void get_KeyInfoId(CkString &str);
	// If set, causes the generated KeyInfo element to include an Id attribute with
	// this value. For example:...
	//    _LT_ds:KeyInfo Id="KeyInfo"_GT_
	//       _LT_ds:X509Data_GT_
	//          _LT_ds:X509SubjectName_GT_CERTIFICADO DE ABC_LT_/ds:X509SubjectName_GT_
	//          _LT_ds:X509Certificate_GT_MIIITTCC....fIsIZeZOeQ=_LT_/ds:X509Certificate_GT_
	//       _LT_/ds:X509Data_GT_
	//    _LT_/ds:KeyInfo_GT_
	// ...
	const char *keyInfoId(void);
	// If set, causes the generated KeyInfo element to include an Id attribute with
	// this value. For example:...
	//    _LT_ds:KeyInfo Id="KeyInfo"_GT_
	//       _LT_ds:X509Data_GT_
	//          _LT_ds:X509SubjectName_GT_CERTIFICADO DE ABC_LT_/ds:X509SubjectName_GT_
	//          _LT_ds:X509Certificate_GT_MIIITTCC....fIsIZeZOeQ=_LT_/ds:X509Certificate_GT_
	//       _LT_/ds:X509Data_GT_
	//    _LT_/ds:KeyInfo_GT_
	// ...
	void put_KeyInfoId(const char *newVal);

	// Specifies the KeyName to be inserted in the KeyInfo element of the Signature if
	// the KeyInfoType equals "KeyName".
	void get_KeyInfoKeyName(CkString &str);
	// Specifies the KeyName to be inserted in the KeyInfo element of the Signature if
	// the KeyInfoType equals "KeyName".
	const char *keyInfoKeyName(void);
	// Specifies the KeyName to be inserted in the KeyInfo element of the Signature if
	// the KeyInfoType equals "KeyName".
	void put_KeyInfoKeyName(const char *newVal);

	// Specifies the type of information that will be included in the optional KeyInfo
	// element of the Signature. Possible values are:
	//     None
	//     KeyName
	//     KeyValue
	//     X509Data
	//     X509Data+KeyValue
	//     Custom
	// 
	// The default value is "KeyValue". The "X509Data+KeyValue" option was added in
	// Chilkat v9.5.0.73.
	// 
	// If None, then no KeyInfo element is added to the Signature when generated.
	// 
	// If KeyValue, then the KeyInfo will contain the public key (RSA, DSA, or ECDSA).
	// 
	// If X509Data, then the KeyInfo will contain information about an X.509
	// certificate as specified by the X509Type property.
	// 
	// If Custom, then the KeyInfo will contain the custom XML contained in the
	// CustomKeyInfoXml property.
	// 
	void get_KeyInfoType(CkString &str);
	// Specifies the type of information that will be included in the optional KeyInfo
	// element of the Signature. Possible values are:
	//     None
	//     KeyName
	//     KeyValue
	//     X509Data
	//     X509Data+KeyValue
	//     Custom
	// 
	// The default value is "KeyValue". The "X509Data+KeyValue" option was added in
	// Chilkat v9.5.0.73.
	// 
	// If None, then no KeyInfo element is added to the Signature when generated.
	// 
	// If KeyValue, then the KeyInfo will contain the public key (RSA, DSA, or ECDSA).
	// 
	// If X509Data, then the KeyInfo will contain information about an X.509
	// certificate as specified by the X509Type property.
	// 
	// If Custom, then the KeyInfo will contain the custom XML contained in the
	// CustomKeyInfoXml property.
	// 
	const char *keyInfoType(void);
	// Specifies the type of information that will be included in the optional KeyInfo
	// element of the Signature. Possible values are:
	//     None
	//     KeyName
	//     KeyValue
	//     X509Data
	//     X509Data+KeyValue
	//     Custom
	// 
	// The default value is "KeyValue". The "X509Data+KeyValue" option was added in
	// Chilkat v9.5.0.73.
	// 
	// If None, then no KeyInfo element is added to the Signature when generated.
	// 
	// If KeyValue, then the KeyInfo will contain the public key (RSA, DSA, or ECDSA).
	// 
	// If X509Data, then the KeyInfo will contain information about an X.509
	// certificate as specified by the X509Type property.
	// 
	// If Custom, then the KeyInfo will contain the custom XML contained in the
	// CustomKeyInfoXml property.
	// 
	void put_KeyInfoType(const char *newVal);

	// An option Id attribute value for the Signature element. The default value is the
	// empty string, which generates a Signature element with no Id attribute. For
	// example:If this property is set to "abc123", then the Signature element would be generated like this:
	void get_SigId(CkString &str);
	// An option Id attribute value for the Signature element. The default value is the
	// empty string, which generates a Signature element with no Id attribute. For
	// example:If this property is set to "abc123", then the Signature element would be generated like this:
	const char *sigId(void);
	// An option Id attribute value for the Signature element. The default value is the
	// empty string, which generates a Signature element with no Id attribute. For
	// example:If this property is set to "abc123", then the Signature element would be generated like this:
	void put_SigId(const char *newVal);

	// Indicates where the Signature is to be located within the XML that is signed.
	// This is a path to the position in the XML where the Signature will be inserted,
	// using Chilkat path syntax (using vertical bar characters to delimit tag names.
	// If the Signature element is to be the root of XML document, then set this
	// property equal to the empty string.
	// 
	// For example, if we have the following SOAP XML and wish to insert the Signature
	// at the indicated location, then the SigLocation property should be set to
	// "SOAP-ENV:Envelope|SOAP-ENV:Header|wsse:Security".** The XML Signature is to be inserted here **...
	// 
	void get_SigLocation(CkString &str);
	// Indicates where the Signature is to be located within the XML that is signed.
	// This is a path to the position in the XML where the Signature will be inserted,
	// using Chilkat path syntax (using vertical bar characters to delimit tag names.
	// If the Signature element is to be the root of XML document, then set this
	// property equal to the empty string.
	// 
	// For example, if we have the following SOAP XML and wish to insert the Signature
	// at the indicated location, then the SigLocation property should be set to
	// "SOAP-ENV:Envelope|SOAP-ENV:Header|wsse:Security".** The XML Signature is to be inserted here **...
	// 
	const char *sigLocation(void);
	// Indicates where the Signature is to be located within the XML that is signed.
	// This is a path to the position in the XML where the Signature will be inserted,
	// using Chilkat path syntax (using vertical bar characters to delimit tag names.
	// If the Signature element is to be the root of XML document, then set this
	// property equal to the empty string.
	// 
	// For example, if we have the following SOAP XML and wish to insert the Signature
	// at the indicated location, then the SigLocation property should be set to
	// "SOAP-ENV:Envelope|SOAP-ENV:Header|wsse:Security".** The XML Signature is to be inserted here **...
	// 
	void put_SigLocation(const char *newVal);

	// Modifies the placement of the signature at the location specified by
	// SigLocation. Possible values are:
	//     0: Insert the Signature as the last child of the element at SigLocation.
	//     This is the default.
	//     1: Insert the Signature as a sibling directly after the element at
	//     SigLocation.
	//     2: Insert the Signature as a sibling directly before the element at
	//     SigLocation.
	int get_SigLocationMod(void);
	// Modifies the placement of the signature at the location specified by
	// SigLocation. Possible values are:
	//     0: Insert the Signature as the last child of the element at SigLocation.
	//     This is the default.
	//     1: Insert the Signature as a sibling directly after the element at
	//     SigLocation.
	//     2: Insert the Signature as a sibling directly before the element at
	//     SigLocation.
	void put_SigLocationMod(int newVal);

	// The namespace prefix of the Signature that is to be created. The default value
	// is "ds". Set this property to the empty string to omit a Signature namespace URI
	// and prefix. For example, given the default values of SigNamespaceUri and
	// SigNamespacePrefix, the generated Signature element will be:...
	void get_SigNamespacePrefix(CkString &str);
	// The namespace prefix of the Signature that is to be created. The default value
	// is "ds". Set this property to the empty string to omit a Signature namespace URI
	// and prefix. For example, given the default values of SigNamespaceUri and
	// SigNamespacePrefix, the generated Signature element will be:...
	const char *sigNamespacePrefix(void);
	// The namespace prefix of the Signature that is to be created. The default value
	// is "ds". Set this property to the empty string to omit a Signature namespace URI
	// and prefix. For example, given the default values of SigNamespaceUri and
	// SigNamespacePrefix, the generated Signature element will be:...
	void put_SigNamespacePrefix(const char *newVal);

	// The namespace URI of the Signature that is to be created. The default value is
	// "http://www.w3.org/2000/09/xmldsig#". For example, if the SigNamespacePrefix
	// equals "ds" and this property remains at the default value, then the generated
	// Signature element will be:...
	void get_SigNamespaceUri(CkString &str);
	// The namespace URI of the Signature that is to be created. The default value is
	// "http://www.w3.org/2000/09/xmldsig#". For example, if the SigNamespacePrefix
	// equals "ds" and this property remains at the default value, then the generated
	// Signature element will be:...
	const char *sigNamespaceUri(void);
	// The namespace URI of the Signature that is to be created. The default value is
	// "http://www.w3.org/2000/09/xmldsig#". For example, if the SigNamespacePrefix
	// equals "ds" and this property remains at the default value, then the generated
	// Signature element will be:...
	void put_SigNamespaceUri(const char *newVal);

	// The canonicalization method to be used for the SignedInfo when creating the XML
	// signature.
	//     "C14N" -- for Inclusive Canonical XML (without comments)
	//     "C14N_11" -- for Inclusive Canonical XML 1.1 (without comments)
	//     "EXCL_C14N" -- for Exclusive Canonical XML (without comments)
	//     "C14N_WithComments" -- for Inclusive Canonical XML (with comments)
	//     "C14N_11_WithComments" -- for Inclusive Canonical XML 1.1 (with comments)
	//     "EXCL_C14N_WithComments" -- for Exclusive Canonical XML (with comments)
	//     Note: The WithComments options are available in Chilkat v9.5.0.71 and later.
	// 
	// The default value is "EXCL_C14N".
	// 
	void get_SignedInfoCanonAlg(CkString &str);
	// The canonicalization method to be used for the SignedInfo when creating the XML
	// signature.
	//     "C14N" -- for Inclusive Canonical XML (without comments)
	//     "C14N_11" -- for Inclusive Canonical XML 1.1 (without comments)
	//     "EXCL_C14N" -- for Exclusive Canonical XML (without comments)
	//     "C14N_WithComments" -- for Inclusive Canonical XML (with comments)
	//     "C14N_11_WithComments" -- for Inclusive Canonical XML 1.1 (with comments)
	//     "EXCL_C14N_WithComments" -- for Exclusive Canonical XML (with comments)
	//     Note: The WithComments options are available in Chilkat v9.5.0.71 and later.
	// 
	// The default value is "EXCL_C14N".
	// 
	const char *signedInfoCanonAlg(void);
	// The canonicalization method to be used for the SignedInfo when creating the XML
	// signature.
	//     "C14N" -- for Inclusive Canonical XML (without comments)
	//     "C14N_11" -- for Inclusive Canonical XML 1.1 (without comments)
	//     "EXCL_C14N" -- for Exclusive Canonical XML (without comments)
	//     "C14N_WithComments" -- for Inclusive Canonical XML (with comments)
	//     "C14N_11_WithComments" -- for Inclusive Canonical XML 1.1 (with comments)
	//     "EXCL_C14N_WithComments" -- for Exclusive Canonical XML (with comments)
	//     Note: The WithComments options are available in Chilkat v9.5.0.71 and later.
	// 
	// The default value is "EXCL_C14N".
	// 
	void put_SignedInfoCanonAlg(const char *newVal);

	// The digest method to be used for signing the SignedInfo part of the Signature.
	// Possible values are "sha1", "sha256", "sha384", and "sha512". The default is
	// "sha256".
	void get_SignedInfoDigestMethod(CkString &str);
	// The digest method to be used for signing the SignedInfo part of the Signature.
	// Possible values are "sha1", "sha256", "sha384", and "sha512". The default is
	// "sha256".
	const char *signedInfoDigestMethod(void);
	// The digest method to be used for signing the SignedInfo part of the Signature.
	// Possible values are "sha1", "sha256", "sha384", and "sha512". The default is
	// "sha256".
	void put_SignedInfoDigestMethod(const char *newVal);

	// Optional Id attribute to be added to the SignedInfo element. The default value
	// is the empty string, meaning that the SignedInfo is generated without an Id
	// attribute.
	void get_SignedInfoId(CkString &str);
	// Optional Id attribute to be added to the SignedInfo element. The default value
	// is the empty string, meaning that the SignedInfo is generated without an Id
	// attribute.
	const char *signedInfoId(void);
	// Optional Id attribute to be added to the SignedInfo element. The default value
	// is the empty string, meaning that the SignedInfo is generated without an Id
	// attribute.
	void put_SignedInfoId(const char *newVal);

	// The inclusive namespace prefix list to be added, if any, when the
	// SignedInfoCanonAlg is equal to "EXCL_C14N". The defautl value is the empty
	// string. If namespaces are listed, they are separated by space characters.
	// 
	// If, for example, this property is set to "wsse SOAP-ENV", then the
	// CanonicalizationMethod part of the SignedInfo that is generated would look like
	// this:...
	// 
	void get_SignedInfoPrefixList(CkString &str);
	// The inclusive namespace prefix list to be added, if any, when the
	// SignedInfoCanonAlg is equal to "EXCL_C14N". The defautl value is the empty
	// string. If namespaces are listed, they are separated by space characters.
	// 
	// If, for example, this property is set to "wsse SOAP-ENV", then the
	// CanonicalizationMethod part of the SignedInfo that is generated would look like
	// this:...
	// 
	const char *signedInfoPrefixList(void);
	// The inclusive namespace prefix list to be added, if any, when the
	// SignedInfoCanonAlg is equal to "EXCL_C14N". The defautl value is the empty
	// string. If namespaces are listed, they are separated by space characters.
	// 
	// If, for example, this property is set to "wsse SOAP-ENV", then the
	// CanonicalizationMethod part of the SignedInfo that is generated would look like
	// this:...
	// 
	void put_SignedInfoPrefixList(const char *newVal);

	// Selects the signature algorithm to be used when using an RSA key to sign. The
	// default value is "PKCS1-v1_5". This can be set to "RSASSA-PSS" (or simply "pss")
	// to use the RSASSA-PSS signature scheme.
	// 
	// Note: This property only applies when signing with an RSA private key. It does
	// not apply for ECC or DSA private keys.
	// 
	void get_SigningAlg(CkString &str);
	// Selects the signature algorithm to be used when using an RSA key to sign. The
	// default value is "PKCS1-v1_5". This can be set to "RSASSA-PSS" (or simply "pss")
	// to use the RSASSA-PSS signature scheme.
	// 
	// Note: This property only applies when signing with an RSA private key. It does
	// not apply for ECC or DSA private keys.
	// 
	const char *signingAlg(void);
	// Selects the signature algorithm to be used when using an RSA key to sign. The
	// default value is "PKCS1-v1_5". This can be set to "RSASSA-PSS" (or simply "pss")
	// to use the RSASSA-PSS signature scheme.
	// 
	// Note: This property only applies when signing with an RSA private key. It does
	// not apply for ECC or DSA private keys.
	// 
	void put_SigningAlg(const char *newVal);

	// An option Id attribute value for the SignatureValue element. The default value
	// is the empty string, which generates a SignatureValue element with no Id
	// attribute. For example:_LT_ds:SignatureValue_GT_ If this property is set to
	// "value-id-7d4a", then the Signature element would be generated like this:_LT_ds:SignatureValue  Id="value-id-7d4a"_GT_
	void get_SigValueId(CkString &str);
	// An option Id attribute value for the SignatureValue element. The default value
	// is the empty string, which generates a SignatureValue element with no Id
	// attribute. For example:_LT_ds:SignatureValue_GT_ If this property is set to
	// "value-id-7d4a", then the Signature element would be generated like this:_LT_ds:SignatureValue  Id="value-id-7d4a"_GT_
	const char *sigValueId(void);
	// An option Id attribute value for the SignatureValue element. The default value
	// is the empty string, which generates a SignatureValue element with no Id
	// attribute. For example:_LT_ds:SignatureValue_GT_ If this property is set to
	// "value-id-7d4a", then the Signature element would be generated like this:_LT_ds:SignatureValue  Id="value-id-7d4a"_GT_
	void put_SigValueId(const char *newVal);

	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string, and should typically remain empty.
	void get_UncommonOptions(CkString &str);
	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string, and should typically remain empty.
	const char *uncommonOptions(void);
	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string, and should typically remain empty.
	void put_UncommonOptions(const char *newVal);

	// Specifies the kind of X.509 certificate information is provided in the KeyInfo
	// element when the KeyInfoType equals "X509Data". Possible values are:
	//     Certificate
	//     CertChain
	//     IssuerSerial
	//     SubjectName
	//     SKI
	// 
	// The default value is "Certificate".
	// 
	// Note: This property can be set to a comma-separated list of the keywords above.
	// For example, If set to "SubjectName,Certificate", then both the X509SubjectName
	// and X509Certificate parts will be added to the KeyInfo.
	// 
	// If Certificate, then the KeyInfo will contain the base64 encoded X.509v3
	// certificate.
	// 
	// If CertChain, then the KeyInfo will contain the base64 encoded X.509v3
	// certificate as well as any certificates available in the chain of authentication
	// to the root cert.
	// 
	// If IssuerSerial, then the KeyInfo will contain the X.509 issuer's distinguished
	// name and the signing certificate's serial number.
	// 
	// If SubjectName, then the KeyInfo will contain the X.509 subject distinguished
	// name.
	// 
	// If SKI, then the KeyInfo will contain the base64 encoded value of the cert's
	// X.509 SubjectKeyIdentifier extension.
	// 
	void get_X509Type(CkString &str);
	// Specifies the kind of X.509 certificate information is provided in the KeyInfo
	// element when the KeyInfoType equals "X509Data". Possible values are:
	//     Certificate
	//     CertChain
	//     IssuerSerial
	//     SubjectName
	//     SKI
	// 
	// The default value is "Certificate".
	// 
	// Note: This property can be set to a comma-separated list of the keywords above.
	// For example, If set to "SubjectName,Certificate", then both the X509SubjectName
	// and X509Certificate parts will be added to the KeyInfo.
	// 
	// If Certificate, then the KeyInfo will contain the base64 encoded X.509v3
	// certificate.
	// 
	// If CertChain, then the KeyInfo will contain the base64 encoded X.509v3
	// certificate as well as any certificates available in the chain of authentication
	// to the root cert.
	// 
	// If IssuerSerial, then the KeyInfo will contain the X.509 issuer's distinguished
	// name and the signing certificate's serial number.
	// 
	// If SubjectName, then the KeyInfo will contain the X.509 subject distinguished
	// name.
	// 
	// If SKI, then the KeyInfo will contain the base64 encoded value of the cert's
	// X.509 SubjectKeyIdentifier extension.
	// 
	const char *x509Type(void);
	// Specifies the kind of X.509 certificate information is provided in the KeyInfo
	// element when the KeyInfoType equals "X509Data". Possible values are:
	//     Certificate
	//     CertChain
	//     IssuerSerial
	//     SubjectName
	//     SKI
	// 
	// The default value is "Certificate".
	// 
	// Note: This property can be set to a comma-separated list of the keywords above.
	// For example, If set to "SubjectName,Certificate", then both the X509SubjectName
	// and X509Certificate parts will be added to the KeyInfo.
	// 
	// If Certificate, then the KeyInfo will contain the base64 encoded X.509v3
	// certificate.
	// 
	// If CertChain, then the KeyInfo will contain the base64 encoded X.509v3
	// certificate as well as any certificates available in the chain of authentication
	// to the root cert.
	// 
	// If IssuerSerial, then the KeyInfo will contain the X.509 issuer's distinguished
	// name and the signing certificate's serial number.
	// 
	// If SubjectName, then the KeyInfo will contain the X.509 subject distinguished
	// name.
	// 
	// If SKI, then the KeyInfo will contain the base64 encoded value of the cert's
	// X.509 SubjectKeyIdentifier extension.
	// 
	void put_X509Type(const char *newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Specifies an enveloped Reference to be added to the Signature when generated. An
	// enveloped Reference is for data contained within the Signature. (The Signature
	// is to be an enveloping signature, and the data is enveloped by the Signature.)
	// 
	// The id is the value of the Id attribute of the Object element that is to be
	// contained within the generated Signature. The content is the text content to be
	// contained in the Object. Binary data can be signed by passing the bytes in content
	// in an encoded format (such as base64 or hex).
	// 
	// The digestMethod is the digest method and can be one of the following: "sha1", "sha256",
	// "sha384", "sha512", "ripemd160", or "md5".
	// 
	// The canonMethod is the canonicalization method, and can be one of the following.
	//     "C14N" -- for Inclusive Canonical XML (without comments)
	//     "C14N_11" -- for Inclusive Canonical XML 1.1 (without comments)
	//     "EXCL_C14N" -- for Exclusive Canonical XML (without comments)
	//     "C14N_WithComments" -- for Inclusive Canonical XML (with comments)
	//     "C14N_11_WithComments" -- for Inclusive Canonical XML 1.1 (with comments)
	//     "EXCL_C14N_WithComments" -- for Exclusive Canonical XML (with comments)
	//     Note: The WithComments options are available in Chilkat v9.5.0.71 and later.
	// 
	// The refType is optional and is usually not needed. Set this to the empty string
	// unless it is desired to add a Type attribute to the Reference that is advisory
	// only.
	// 
	bool AddEnvelopedRef(const char *id, CkStringBuilder &content, const char *digestMethod, const char *canonMethod, const char *refType);


	// Specifies an external non-XML binary data Reference to be added to the Signature
	// when generated.
	// 
	// The uri is the value of the URI attribute of the Reference.
	// 
	// The content contains the binary data to be digested according to the digestMethod.
	// 
	// The digestMethod is the digest method and can be one of the following: "sha1", "sha256",
	// "sha384", "sha512", "ripemd160", or "md5".
	// 
	// The refType is optional and is usually not needed. Set this to the empty string
	// unless it is desired to add a Type attribute to the Reference that is advisory
	// only.
	// 
	bool AddExternalBinaryRef(const char *uri, CkBinData &content, const char *digestMethod, const char *refType);


	// Specifies an external file Reference to be added to the Signature when
	// generated.
	// 
	// The uri is the value of the URI attribute of the Reference. It can (and likely
	// will) be different than the localFilePath which is the path to the local file to be
	// added. (The local file is not read until the XML digital signature is actually
	// created.)
	// 
	// The digestMethod is the digest method and can be one of the following: "sha1", "sha256",
	// "sha384", "sha512", "ripemd160", or "md5".
	// 
	// The refType is optional and is usually not needed. Set this to the empty string
	// unless it is desired to add a Type attribute to the Reference that is advisory
	// only.
	// 
	bool AddExternalFileRef(const char *uri, const char *localFilePath, const char *digestMethod, const char *refType);


	// Specifies an external non-XML text data Reference to be added to the Signature
	// when generated.
	// 
	// The uri is the value of the URI attribute of the Reference.
	// 
	// The content contains the non-XML data to be digested according to the charset. The
	// charset specifies the charset (such as "utf-8", "windows-1252", etc.) for the byte
	// reprsentation of the text to be digested. The includeBom indicates whether the BOM
	// (Byte Order Mark, also known as the preamble) is included in the byte
	// representation that is digested.
	// 
	// The digestMethod is the digest method and can be one of the following: "sha1", "sha256",
	// "sha384", "sha512", "ripemd160", or "md5".
	// 
	// The refType is optional and is usually not needed. Set this to the empty string
	// unless it is desired to add a Type attribute to the Reference that is advisory
	// only.
	// 
	bool AddExternalTextRef(const char *uri, CkStringBuilder &content, const char *charset, bool includeBom, const char *digestMethod, const char *refType);


	// Specifies an external XML Reference to be added to the Signature when generated.
	// 
	// The uri is the value of the URI attribute of the Reference.
	// 
	// The content contains the XML document to be referenced.
	// 
	// The digestMethod is the digest method and can be one of the following: "sha1", "sha256",
	// "sha384", "sha512", "ripemd160", or "md5".
	// 
	// The canonMethod is the canonicalization method, and can be one of the following.
	//     "C14N" -- for Inclusive Canonical XML (without comments)
	//     "C14N_11" -- for Inclusive Canonical XML 1.1 (without comments)
	//     "EXCL_C14N" -- for Exclusive Canonical XML (without comments)
	//     "C14N_WithComments" -- for Inclusive Canonical XML (with comments)
	//     "C14N_11_WithComments" -- for Inclusive Canonical XML 1.1 (with comments)
	//     "EXCL_C14N_WithComments" -- for Exclusive Canonical XML (with comments)
	//     "" -- An empty string indicates that no transformation should be included /
	//     applied for this reference.
	//     Note: The WithComments options are available in Chilkat v9.5.0.71 and later.
	//     Note: The empty-string canonMethod is available in Chilkat v9.5.0.75 and
	//     later.
	// 
	// The refType is optional and is usually not needed. Set this to the empty string
	// unless it is desired to add a Type attribute to the Reference that is advisory
	// only.
	// 
	bool AddExternalXmlRef(const char *uri, CkStringBuilder &content, const char *digestMethod, const char *canonMethod, const char *refType);


	// Specifies an Object to be added to the Signature.
	//     The id is the value of the Object element's Id attribute.
	//     The content contains the content of the Object element, which may be XML or
	//     plain text.
	//     The mimeType is the value of the Object element's MimeType attribute
	//     The encoding is the value of the Object element's Encoding attribute
	// In most cases, the mimeType and encoding are empty strings which cause the MimeType and
	// Encoding attributes to be omitted.
	bool AddObject(const char *id, const char *content, const char *mimeType, const char *encoding);


	// This is the same as the AddSameDocRef method, except the reference is to content
	// within an Object previously added via the AddObject method. The id must be an
	// Id equal to the Id attribute of an Object, or the Id attribute of an element
	// within the Object.
	// 
	// Note: The canonMethod can be set to "Base64" to use the
	// http://www.w3.org/2000/09/xmldsig#base64 transform.
	// 
	bool AddObjectRef(const char *id, const char *digestMethod, const char *canonMethod, const char *prefixList, const char *refType);


	// This method is the same as AddObjectRef, except it allows the Transforms to be
	// specified exactly with a fragment of XML. See the example below.
	bool AddObjectRef2(const char *id, const char *digestMethod, CkXml &transforms, const char *refType);


	// Specifies a same document Reference to be added to the Signature when generated.
	// A same document Reference can be the entire XML document, or a fragment of the
	// XML document.
	// 
	// The id can be the empty string to sign the entire XML document, or it can be
	// the fragment identifier to sign a portion of the XML document.
	// 
	// The digestMethod is the digest method and can be one of the following: "sha1", "sha256",
	// "sha384", "sha512", "ripemd160", or "md5".
	// 
	// The canonMethod is the canonicalization method, and can be one of the following:
	//     "C14N" -- for Inclusive Canonical XML (without comments)
	//     "C14N_11" -- for Inclusive Canonical XML 1.1 (without comments)
	//     "EXCL_C14N" -- for Exclusive Canonical XML (without comments)
	//     "C14N_WithComments" -- for Inclusive Canonical XML (with comments)
	//     "C14N_11_WithComments" -- for Inclusive Canonical XML 1.1 (with comments)
	//     "EXCL_C14N_WithComments" -- for Exclusive Canonical XML (with comments)
	//     "" -- An empty string indicates that no transformation should be included /
	//     applied for this reference.
	//     Note: The WithComments options are available in Chilkat v9.5.0.71 and later.
	//     Note: The empty-string canonMethod is available in Chilkat v9.5.0.75 and
	//     later.
	// 
	// If exclusive canonicalization is selected, then the prefixList can contain a space
	// separated list of inclusive namespace prefixes. For inclusive canonicalization,
	// this argument is ignored. In general, pass an empty string for this argument
	// unless you have specific knowledge of namespace prefixes that need to be treated
	// as inclusive when EXCL_C14N is used.
	// 
	// Starting in Chilkat v9.5.0.70, the prefixList can be set to the keyword "_EMPTY_" to
	// force the generation of an empty PrefixList under the Transform. For example: 
	// 
	// The refType is optional and is usually not needed. Set this to the empty string
	// unless it is desired to add a Type attribute to the Reference that is advisory
	// only.
	// 
	bool AddSameDocRef(const char *id, const char *digestMethod, const char *canonMethod, const char *prefixList, const char *refType);


	// This method is the same as AddSameDocRef, except it allows the Transforms to be
	// specified exactly with a fragment of XML. See the example below.
	bool AddSameDocRef2(const char *id, const char *digestMethod, CkXml &transforms, const char *refType);


	// Can be called one or more times to add additional namespaces to the Signature
	// element.
	bool AddSignatureNamespace(const char *nsPrefix, const char *nsUri);


	// This method will construct and return the canonicalized SignedInfo XML. The
	// digests of each Reference are computed and included in the SignedInfo. This
	// method is provided for certain special circumstances where one wants to get the
	// exact canonicalized SignedInfo that would be signed using the private key.
	// 
	// Note: Properties such as SigLocation, SigningAlg, etc. and references must be
	// set exactly as if an XML signature was to be actually generated because they
	// determine the content of the SignedInfo.
	// 
	// Note, the sbXml is not signed by this method. It is not modified.
	// 
	bool ConstructSignedInfo(CkStringBuilder &sbXml, CkString &outStr);

	// This method will construct and return the canonicalized SignedInfo XML. The
	// digests of each Reference are computed and included in the SignedInfo. This
	// method is provided for certain special circumstances where one wants to get the
	// exact canonicalized SignedInfo that would be signed using the private key.
	// 
	// Note: Properties such as SigLocation, SigningAlg, etc. and references must be
	// set exactly as if an XML signature was to be actually generated because they
	// determine the content of the SignedInfo.
	// 
	// Note, the sbXml is not signed by this method. It is not modified.
	// 
	const char *constructSignedInfo(CkStringBuilder &sbXml);

	// Creates an XML Digital Signature. The application passes in the XML to be
	// signed, and the signed XML is returned. If creating an enveloping signature
	// where the Signature element is the root, then the inXml may be the empty string.
	// 
	//     Chilkat v9.5.0.76 or greater is required for XML signatures for
	//     www.csioz.gov.pl
	// 
	bool CreateXmlDSig(const char *inXml, CkString &outStr);

	// Creates an XML Digital Signature. The application passes in the XML to be
	// signed, and the signed XML is returned. If creating an enveloping signature
	// where the Signature element is the root, then the inXml may be the empty string.
	// 
	//     Chilkat v9.5.0.76 or greater is required for XML signatures for
	//     www.csioz.gov.pl
	// 
	const char *createXmlDSig(const char *inXml);
	// Creates an XML Digital Signature. The application passes in the XML to be
	// signed, and the signed XML is returned. If creating an enveloping signature
	// where the Signature element is the root, then the inXml may be the empty string.
	// 
	//     Chilkat v9.5.0.76 or greater is required for XML signatures for
	//     www.csioz.gov.pl
	// 
	CkTask *CreateXmlDSigAsync(const char *inXml);


	// Creates an XML Digital Signature. The application passes the XML to be signed in
	// sbXml, and it is replaced with the signed XML if successful. (Thus, sbXml is both
	// an input and output argument.) Note: If creating an enveloping signature where
	// the Signature element is to be the root element, then the passed-in sbXml may be
	// empty.
	bool CreateXmlDSigSb(CkStringBuilder &sbXml);

	// Creates an XML Digital Signature. The application passes the XML to be signed in
	// sbXml, and it is replaced with the signed XML if successful. (Thus, sbXml is both
	// an input and output argument.) Note: If creating an enveloping signature where
	// the Signature element is to be the root element, then the passed-in sbXml may be
	// empty.
	CkTask *CreateXmlDSigSbAsync(CkStringBuilder &sbXml);


	// Sets the HMAC key to be used if the Signature is to use an HMAC signing
	// algorithm. The encoding specifies the encoding of key, and can be "hex", "base64",
	// "ascii", or any of the binary encodings supported by Chilkat in the link below.
	bool SetHmacKey(const char *key, const char *encoding);


	// Sets the HTTP object to be used to communicate with OCSP responders, CRL
	// distribution points, or timestamp authority (TSA) servers if needed. The http is
	// used to send the requests, and it allows for connection related settings and
	// timeouts to be set. For example, if HTTP or SOCKS proxies are required, these
	// features can be specified on the http.
	void SetHttpObj(CkHttp &http);


	// Sets the private key to be used for creating the XML signature. The private key
	// may be an RSA key, a DSA key, or an ECDSA key.
	bool SetPrivateKey(CkPrivateKey &privKey);


	// Sets the "Id" attribute for a Reference.
	bool SetRefIdAttr(const char *uri_or_id, const char *value);


	// Sets the TSA (Timestamp Authority) URL and other related settings for
	// automatically adding an EncapsulatedTimestamp.
	bool SetTsa(CkJsonObject &json);


	// Specifies the X.509 certificate to be used for the KeyInfo element when the
	// KeyInfoType equals "X509Data". If usePrivateKey is true, then the private key will also
	// be set using the certificate's private key. Thus, the SetPrivateKey method does
	// not need to be called. If usePrivateKey is true, and the certificate does not have an
	// associated private key available, then this method will return false.
	// 
	// Note: A certificate's private key is not stored within a certificate itself. If
	// the certificate (cert) was obtained from a PFX, Java KeyStore, or other such
	// source, which are containers for both certs and private keys, then Chilkat would
	// have associated the cert with the private key when loading the PFX or JKS, and
	// all is good. The same holds true if, on a Windows system, the certificate was
	// obtained from a Windows-based registry certificate store where the private key
	// was installed with the permission to export.
	// 
	// If, however, the certificate was loaded from a .cer file, or another type of
	// file that contains only the certificate and not the private key, then the
	// associated private key needs to be obtained by the application and provided by
	// calling SetPrivateKey.
	// 
	bool SetX509Cert(CkCert &cert, bool usePrivateKey);






	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
