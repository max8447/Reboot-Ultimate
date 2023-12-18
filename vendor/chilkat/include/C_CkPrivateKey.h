// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkPrivateKey_H
#define _C_CkPrivateKey_H
#include "chilkatDefs.h"
#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC void CkPrivateKey_setAbortCheck(HCkPrivateKey cHandle, BOOL (*fnAbortCheck)(void));
CK_C_VISIBLE_PUBLIC void CkPrivateKey_setPercentDone(HCkPrivateKey cHandle, BOOL (*fnPercentDone)(int pctDone));
CK_C_VISIBLE_PUBLIC void CkPrivateKey_setProgressInfo(HCkPrivateKey cHandle, void (*fnProgressInfo)(const char *name, const char *value));
CK_C_VISIBLE_PUBLIC void CkPrivateKey_setTaskCompleted(HCkPrivateKey cHandle, void (*fnTaskCompleted)(HCkTask hTask));

CK_C_VISIBLE_PUBLIC void CkPrivateKey_setAbortCheck2(HCkPrivateKey cHandle, BOOL (*fnAbortCheck2)(void *pContext));
CK_C_VISIBLE_PUBLIC void CkPrivateKey_setPercentDone2(HCkPrivateKey cHandle, BOOL (*fnPercentDone2)(int pctDone, void *pContext));
CK_C_VISIBLE_PUBLIC void CkPrivateKey_setProgressInfo2(HCkPrivateKey cHandle, void (*fnProgressInfo2)(const char *name, const char *value, void *pContext));
CK_C_VISIBLE_PUBLIC void CkPrivateKey_setTaskCompleted2(HCkPrivateKey cHandle, void (*fnTaskCompleted2)(HCkTask hTask, void *pContext));

// setExternalProgress is for C callback functions defined in the external programming language (such as Go)
CK_C_VISIBLE_PUBLIC void CkPrivateKey_setExternalProgress(HCkPrivateKey cHandle, BOOL on);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_setCallbackContext(HCkPrivateKey cHandle, void *pContext);

CK_C_VISIBLE_PUBLIC HCkPrivateKey CkPrivateKey_Create(void);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_Dispose(HCkPrivateKey handle);
CK_C_VISIBLE_PUBLIC int CkPrivateKey_getBitLength(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_getDebugLogFilePath(HCkPrivateKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_putDebugLogFilePath(HCkPrivateKey cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_debugLogFilePath(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_getKeyType(HCkPrivateKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_keyType(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_getLastErrorHtml(HCkPrivateKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_lastErrorHtml(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_getLastErrorText(HCkPrivateKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_lastErrorText(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_getLastErrorXml(HCkPrivateKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_lastErrorXml(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_getLastMethodSuccess(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_putLastMethodSuccess(HCkPrivateKey cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_getPkcs8EncryptAlg(HCkPrivateKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_putPkcs8EncryptAlg(HCkPrivateKey cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_pkcs8EncryptAlg(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_getUncommonOptions(HCkPrivateKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_putUncommonOptions(HCkPrivateKey cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_uncommonOptions(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_getUtf8(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_putUtf8(HCkPrivateKey cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_getVerboseLogging(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_putVerboseLogging(HCkPrivateKey cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkPrivateKey_getVersion(HCkPrivateKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_version(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetJwk(HCkPrivateKey cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getJwk(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetJwkThumbprint(HCkPrivateKey cHandle, const char *hashAlg, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getJwkThumbprint(HCkPrivateKey cHandle, const char *hashAlg);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetPkcs1(HCkPrivateKey cHandle, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetPkcs1ENC(HCkPrivateKey cHandle, const char *encoding, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getPkcs1ENC(HCkPrivateKey cHandle, const char *encoding);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetPkcs1Pem(HCkPrivateKey cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getPkcs1Pem(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetPkcs8(HCkPrivateKey cHandle, HCkByteData outData);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetPkcs8ENC(HCkPrivateKey cHandle, const char *encoding, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getPkcs8ENC(HCkPrivateKey cHandle, const char *encoding);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetPkcs8Encrypted(HCkPrivateKey cHandle, const char *password, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetPkcs8EncryptedENC(HCkPrivateKey cHandle, const char *encoding, const char *password, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getPkcs8EncryptedENC(HCkPrivateKey cHandle, const char *encoding, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetPkcs8EncryptedPem(HCkPrivateKey cHandle, const char *password, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getPkcs8EncryptedPem(HCkPrivateKey cHandle, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetPkcs8Pem(HCkPrivateKey cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getPkcs8Pem(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC HCkPublicKey CkPrivateKey_GetPublicKey(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetRawHex(HCkPrivateKey cHandle, HCkStringBuilder pubKey, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getRawHex(HCkPrivateKey cHandle, HCkStringBuilder pubKey);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetRsaDer(HCkPrivateKey cHandle, HCkByteData outData);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetRsaPem(HCkPrivateKey cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getRsaPem(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_GetXml(HCkPrivateKey cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkPrivateKey_getXml(HCkPrivateKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadAnyFormat(HCkPrivateKey cHandle, HCkBinData privKeyData, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadAnyFormatFile(HCkPrivateKey cHandle, const char *path, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadEd25519(HCkPrivateKey cHandle, const char *privKey, const char *pubKey);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadEncryptedPem(HCkPrivateKey cHandle, const char *pemStr, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadEncryptedPemFile(HCkPrivateKey cHandle, const char *path, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadJwk(HCkPrivateKey cHandle, const char *jsonStr);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPem(HCkPrivateKey cHandle, const char *str);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPemFile(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPkcs1(HCkPrivateKey cHandle, HCkByteData data);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPkcs1File(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPkcs8(HCkPrivateKey cHandle, HCkByteData data);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPkcs8Encrypted(HCkPrivateKey cHandle, HCkByteData data, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPkcs8EncryptedFile(HCkPrivateKey cHandle, const char *path, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPkcs8File(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPvk(HCkPrivateKey cHandle, HCkByteData data, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadPvkFile(HCkPrivateKey cHandle, const char *path, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadRsaDer(HCkPrivateKey cHandle, HCkByteData data);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadRsaDerFile(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadXml(HCkPrivateKey cHandle, const char *xml);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_LoadXmlFile(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SaveLastError(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SavePemFile(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SavePkcs1File(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SavePkcs8EncryptedFile(HCkPrivateKey cHandle, const char *password, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SavePkcs8EncryptedPemFile(HCkPrivateKey cHandle, const char *password, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SavePkcs8File(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SavePkcs8PemFile(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SaveRsaDerFile(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SaveRsaPemFile(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_SaveXmlFile(HCkPrivateKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPrivateKey_UploadToCloud(HCkPrivateKey cHandle, HCkJsonObject jsonIn, HCkJsonObject jsonOut);
CK_C_VISIBLE_PUBLIC HCkTask CkPrivateKey_UploadToCloudAsync(HCkPrivateKey cHandle, HCkJsonObject jsonIn, HCkJsonObject jsonOut);
#endif
