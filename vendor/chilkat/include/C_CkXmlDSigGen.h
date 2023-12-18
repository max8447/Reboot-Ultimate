// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkXmlDSigGen_H
#define _C_CkXmlDSigGen_H
#include "chilkatDefs.h"
#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setAbortCheck(HCkXmlDSigGen cHandle, BOOL (*fnAbortCheck)(void));
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setPercentDone(HCkXmlDSigGen cHandle, BOOL (*fnPercentDone)(int pctDone));
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setProgressInfo(HCkXmlDSigGen cHandle, void (*fnProgressInfo)(const char *name, const char *value));
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setTaskCompleted(HCkXmlDSigGen cHandle, void (*fnTaskCompleted)(HCkTask hTask));

CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setAbortCheck2(HCkXmlDSigGen cHandle, BOOL (*fnAbortCheck2)(void *pContext));
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setPercentDone2(HCkXmlDSigGen cHandle, BOOL (*fnPercentDone2)(int pctDone, void *pContext));
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setProgressInfo2(HCkXmlDSigGen cHandle, void (*fnProgressInfo2)(const char *name, const char *value, void *pContext));
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setTaskCompleted2(HCkXmlDSigGen cHandle, void (*fnTaskCompleted2)(HCkTask hTask, void *pContext));

// setExternalProgress is for C callback functions defined in the external programming language (such as Go)
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setExternalProgress(HCkXmlDSigGen cHandle, BOOL on);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_setCallbackContext(HCkXmlDSigGen cHandle, void *pContext);

CK_C_VISIBLE_PUBLIC HCkXmlDSigGen CkXmlDSigGen_Create(void);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_Dispose(HCkXmlDSigGen handle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getBehaviors(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putBehaviors(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_behaviors(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getCustomKeyInfoXml(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putCustomKeyInfoXml(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_customKeyInfoXml(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getDebugLogFilePath(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putDebugLogFilePath(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_debugLogFilePath(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getIncNamespacePrefix(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putIncNamespacePrefix(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_incNamespacePrefix(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getIncNamespaceUri(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putIncNamespaceUri(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_incNamespaceUri(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getKeyInfoId(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putKeyInfoId(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_keyInfoId(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getKeyInfoKeyName(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putKeyInfoKeyName(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_keyInfoKeyName(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getKeyInfoType(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putKeyInfoType(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_keyInfoType(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getLastErrorHtml(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_lastErrorHtml(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getLastErrorText(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_lastErrorText(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getLastErrorXml(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_lastErrorXml(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_getLastMethodSuccess(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putLastMethodSuccess(HCkXmlDSigGen cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSigId(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSigId(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_sigId(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSigLocation(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSigLocation(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_sigLocation(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC int CkXmlDSigGen_getSigLocationMod(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSigLocationMod(HCkXmlDSigGen cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSigNamespacePrefix(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSigNamespacePrefix(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_sigNamespacePrefix(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSigNamespaceUri(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSigNamespaceUri(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_sigNamespaceUri(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSignedInfoCanonAlg(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSignedInfoCanonAlg(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_signedInfoCanonAlg(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSignedInfoDigestMethod(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSignedInfoDigestMethod(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_signedInfoDigestMethod(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSignedInfoId(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSignedInfoId(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_signedInfoId(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSignedInfoPrefixList(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSignedInfoPrefixList(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_signedInfoPrefixList(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSigningAlg(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSigningAlg(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_signingAlg(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getSigValueId(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putSigValueId(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_sigValueId(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getUncommonOptions(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putUncommonOptions(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_uncommonOptions(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_getUtf8(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putUtf8(HCkXmlDSigGen cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_getVerboseLogging(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putVerboseLogging(HCkXmlDSigGen cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getVersion(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_version(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_getX509Type(HCkXmlDSigGen cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_putX509Type(HCkXmlDSigGen cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_x509Type(HCkXmlDSigGen cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddEnvelopedRef(HCkXmlDSigGen cHandle, const char *id, HCkStringBuilder content, const char *digestMethod, const char *canonMethod, const char *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddExternalBinaryRef(HCkXmlDSigGen cHandle, const char *uri, HCkBinData content, const char *digestMethod, const char *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddExternalFileRef(HCkXmlDSigGen cHandle, const char *uri, const char *localFilePath, const char *digestMethod, const char *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddExternalTextRef(HCkXmlDSigGen cHandle, const char *uri, HCkStringBuilder content, const char *charset, BOOL includeBom, const char *digestMethod, const char *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddExternalXmlRef(HCkXmlDSigGen cHandle, const char *uri, HCkStringBuilder content, const char *digestMethod, const char *canonMethod, const char *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddObject(HCkXmlDSigGen cHandle, const char *id, const char *content, const char *mimeType, const char *encoding);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddObjectRef(HCkXmlDSigGen cHandle, const char *id, const char *digestMethod, const char *canonMethod, const char *prefixList, const char *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddObjectRef2(HCkXmlDSigGen cHandle, const char *id, const char *digestMethod, HCkXml transforms, const char *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddSameDocRef(HCkXmlDSigGen cHandle, const char *id, const char *digestMethod, const char *canonMethod, const char *prefixList, const char *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddSameDocRef2(HCkXmlDSigGen cHandle, const char *id, const char *digestMethod, HCkXml transforms, const char *refType);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_AddSignatureNamespace(HCkXmlDSigGen cHandle, const char *nsPrefix, const char *nsUri);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_ConstructSignedInfo(HCkXmlDSigGen cHandle, HCkStringBuilder sbXml, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_constructSignedInfo(HCkXmlDSigGen cHandle, HCkStringBuilder sbXml);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_CreateXmlDSig(HCkXmlDSigGen cHandle, const char *inXml, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkXmlDSigGen_createXmlDSig(HCkXmlDSigGen cHandle, const char *inXml);
CK_C_VISIBLE_PUBLIC HCkTask CkXmlDSigGen_CreateXmlDSigAsync(HCkXmlDSigGen cHandle, const char *inXml);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_CreateXmlDSigSb(HCkXmlDSigGen cHandle, HCkStringBuilder sbXml);
CK_C_VISIBLE_PUBLIC HCkTask CkXmlDSigGen_CreateXmlDSigSbAsync(HCkXmlDSigGen cHandle, HCkStringBuilder sbXml);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_SaveLastError(HCkXmlDSigGen cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_SetHmacKey(HCkXmlDSigGen cHandle, const char *key, const char *encoding);
CK_C_VISIBLE_PUBLIC void CkXmlDSigGen_SetHttpObj(HCkXmlDSigGen cHandle, HCkHttp http);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_SetPrivateKey(HCkXmlDSigGen cHandle, HCkPrivateKey privKey);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_SetRefIdAttr(HCkXmlDSigGen cHandle, const char *uri_or_id, const char *value);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_SetTsa(HCkXmlDSigGen cHandle, HCkJsonObject json);
CK_C_VISIBLE_PUBLIC BOOL CkXmlDSigGen_SetX509Cert(HCkXmlDSigGen cHandle, HCkCert cert, BOOL usePrivateKey);
#endif
