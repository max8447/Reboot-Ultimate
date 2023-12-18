// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkXmlDSigGenWH
#define _C_CkXmlDSigGenWH
#include "chilkatDefs.h"

#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_setAbortCheck(HCkXmlDSigGenW cHandle, BOOL (*fnAbortCheck)(void));
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_setPercentDone(HCkXmlDSigGenW cHandle, BOOL (*fnPercentDone)(int pctDone));
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_setProgressInfo(HCkXmlDSigGenW cHandle, void (*fnProgressInfo)(const wchar_t *name, const wchar_t *value));
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_setTaskCompleted(HCkXmlDSigGenW cHandle, void (*fnTaskCompleted)(HCkTaskW hTask));

CK_C_VISIBLE_PUBLIC HCkXmlDSigGenW CkXmlDSigGenW_Create(void);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_Dispose(HCkXmlDSigGenW handle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getBehaviors(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putBehaviors(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_behaviors(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getCustomKeyInfoXml(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putCustomKeyInfoXml(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_customKeyInfoXml(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getDebugLogFilePath(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putDebugLogFilePath(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_debugLogFilePath(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getIncNamespacePrefix(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putIncNamespacePrefix(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_incNamespacePrefix(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getIncNamespaceUri(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putIncNamespaceUri(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_incNamespaceUri(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getKeyInfoId(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putKeyInfoId(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_keyInfoId(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getKeyInfoKeyName(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putKeyInfoKeyName(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_keyInfoKeyName(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getKeyInfoType(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putKeyInfoType(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_keyInfoType(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getLastErrorHtml(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_lastErrorHtml(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getLastErrorText(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_lastErrorText(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getLastErrorXml(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_lastErrorXml(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_getLastMethodSuccess(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putLastMethodSuccess(HCkXmlDSigGenW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSigId(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSigId(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_sigId(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSigLocation(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSigLocation(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_sigLocation(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC int CkXmlDSigGenW_getSigLocationMod(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSigLocationMod(HCkXmlDSigGenW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSigNamespacePrefix(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSigNamespacePrefix(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_sigNamespacePrefix(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSigNamespaceUri(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSigNamespaceUri(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_sigNamespaceUri(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSignedInfoCanonAlg(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSignedInfoCanonAlg(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_signedInfoCanonAlg(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSignedInfoDigestMethod(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSignedInfoDigestMethod(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_signedInfoDigestMethod(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSignedInfoId(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSignedInfoId(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_signedInfoId(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSignedInfoPrefixList(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSignedInfoPrefixList(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_signedInfoPrefixList(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSigningAlg(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSigningAlg(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_signingAlg(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getSigValueId(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putSigValueId(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_sigValueId(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getUncommonOptions(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putUncommonOptions(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_uncommonOptions(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_getVerboseLogging(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putVerboseLogging(HCkXmlDSigGenW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getVersion(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_version(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_getX509Type(HCkXmlDSigGenW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkXmlDSigGenW_putX509Type(HCkXmlDSigGenW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_x509Type(HCkXmlDSigGenW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddEnvelopedRef(HCkXmlDSigGenW cHandle, const wchar_t *id, HCkStringBuilderW content, const wchar_t *digestMethod, const wchar_t *canonMethod, const wchar_t *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddExternalBinaryRef(HCkXmlDSigGenW cHandle, const wchar_t *uri, HCkBinDataW content, const wchar_t *digestMethod, const wchar_t *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddExternalFileRef(HCkXmlDSigGenW cHandle, const wchar_t *uri, const wchar_t *localFilePath, const wchar_t *digestMethod, const wchar_t *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddExternalTextRef(HCkXmlDSigGenW cHandle, const wchar_t *uri, HCkStringBuilderW content, const wchar_t *charset, BOOL includeBom, const wchar_t *digestMethod, const wchar_t *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddExternalXmlRef(HCkXmlDSigGenW cHandle, const wchar_t *uri, HCkStringBuilderW content, const wchar_t *digestMethod, const wchar_t *canonMethod, const wchar_t *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddObject(HCkXmlDSigGenW cHandle, const wchar_t *id, const wchar_t *content, const wchar_t *mimeType, const wchar_t *encoding);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddObjectRef(HCkXmlDSigGenW cHandle, const wchar_t *id, const wchar_t *digestMethod, const wchar_t *canonMethod, const wchar_t *prefixList, const wchar_t *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddObjectRef2(HCkXmlDSigGenW cHandle, const wchar_t *id, const wchar_t *digestMethod, HCkXmlW transforms, const wchar_t *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddSameDocRef(HCkXmlDSigGenW cHandle, const wchar_t *id, const wchar_t *digestMethod, const wchar_t *canonMethod, const wchar_t *prefixList, const wchar_t *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddSameDocRef2(HCkXmlDSigGenW cHandle, const wchar_t *id, const wchar_t *digestMethod, HCkXmlW transforms, const wchar_t *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_AddSignatureNamespace(HCkXmlDSigGenW cHandle, const wchar_t *nsPrefix, const wchar_t *nsUri);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_ConstructSignedInfo(HCkXmlDSigGenW cHandle, HCkStringBuilderW sbXml, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_constructSignedInfo(HCkXmlDSigGenW cHandle, HCkStringBuilderW sbXml);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_CreateXmlDSig(HCkXmlDSigGenW cHandle, const wchar_t *inXml, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkXmlDSigGenW_createXmlDSig(HCkXmlDSigGenW cHandle, const wchar_t *inXml);
CK_C_VISIBLE_PUBLIC HCkTaskW CkXmlDSigGenW_CreateXmlDSigAsync(HCkXmlDSigGenW cHandle, const wchar_t *inXml);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_CreateXmlDSigSb(HCkXmlDSigGenW cHandle, HCkStringBuilderW sbXml);
CK_C_VISIBLE_PUBLIC HCkTaskW CkXmlDSigGenW_CreateXmlDSigSbAsync(HCkXmlDSigGenW cHandle, HCkStringBuilderW sbXml);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_SaveLastError(HCkXmlDSigGenW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_SetHmacKey(HCkXmlDSigGenW cHandle, const wchar_t *key, const wchar_t *encoding);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGenW_SetHttpObj(HCkXmlDSigGenW cHandle, HCkHttpW http);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_SetPrivateKey(HCkXmlDSigGenW cHandle, HCkPrivateKeyW privKey);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_SetRefIdAttr(HCkXmlDSigGenW cHandle, const wchar_t *uri_or_id, const wchar_t *value);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_SetTsa(HCkXmlDSigGenW cHandle, HCkJsonObjectW json);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGenW_SetX509Cert(HCkXmlDSigGenW cHandle, HCkCertW cert, BOOL usePrivateKey);
#endif
