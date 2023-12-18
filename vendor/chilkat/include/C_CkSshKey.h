// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkSshKey_H
#define _C_CkSshKey_H
#include "chilkatDefs.h"
#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC HCkSshKey CkSshKey_Create(void);
CK_C_VISIBLE_PUBLIC void CkSshKey_Dispose(HCkSshKey handle);
CK_C_VISIBLE_PUBLIC void CkSshKey_getComment(HCkSshKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkSshKey_putComment(HCkSshKey cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_comment(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC void CkSshKey_getDebugLogFilePath(HCkSshKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkSshKey_putDebugLogFilePath(HCkSshKey cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_debugLogFilePath(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_getIsDsaKey(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_getIsPrivateKey(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_getIsRsaKey(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC void CkSshKey_getKeyType(HCkSshKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_keyType(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC void CkSshKey_getLastErrorHtml(HCkSshKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_lastErrorHtml(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC void CkSshKey_getLastErrorText(HCkSshKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_lastErrorText(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC void CkSshKey_getLastErrorXml(HCkSshKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_lastErrorXml(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_getLastMethodSuccess(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC void CkSshKey_putLastMethodSuccess(HCkSshKey cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkSshKey_getPassword(HCkSshKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkSshKey_putPassword(HCkSshKey cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_password(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC void CkSshKey_getUncommonOptions(HCkSshKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkSshKey_putUncommonOptions(HCkSshKey cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_uncommonOptions(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_getUtf8(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC void CkSshKey_putUtf8(HCkSshKey cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_getVerboseLogging(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC void CkSshKey_putVerboseLogging(HCkSshKey cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkSshKey_getVersion(HCkSshKey cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_version(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_FromOpenSshPrivateKey(HCkSshKey cHandle, const char *keyStr);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_FromOpenSshPublicKey(HCkSshKey cHandle, const char *keyStr);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_FromPuttyPrivateKey(HCkSshKey cHandle, const char *keyStr);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_FromRfc4716PublicKey(HCkSshKey cHandle, const char *keyStr);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_FromXml(HCkSshKey cHandle, const char *xmlKey);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_GenerateDsaKey(HCkSshKey cHandle, int numBits);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_GenerateEcdsaKey(HCkSshKey cHandle, const char *curveName);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_GenerateEd25519Key(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_GenerateRsaKey(HCkSshKey cHandle, int numBits, int exponent);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_GenFingerprint(HCkSshKey cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_genFingerprint(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_LoadText(HCkSshKey cHandle, const char *filename, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_loadText(HCkSshKey cHandle, const char *filename);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_SaveLastError(HCkSshKey cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_SaveText(HCkSshKey cHandle, const char *strToSave, const char *filename);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_ToOpenSshPrivateKey(HCkSshKey cHandle, BOOL bEncrypt, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_toOpenSshPrivateKey(HCkSshKey cHandle, BOOL bEncrypt);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_ToOpenSshPublicKey(HCkSshKey cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_toOpenSshPublicKey(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_ToPuttyPrivateKey(HCkSshKey cHandle, BOOL bEncrypt, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_toPuttyPrivateKey(HCkSshKey cHandle, BOOL bEncrypt);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_ToRfc4716PublicKey(HCkSshKey cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_toRfc4716PublicKey(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_ToXml(HCkSshKey cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkSshKey_toXml(HCkSshKey cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSshKey_UsePkcs11(HCkSshKey cHandle, HCkPkcs11 session, unsigned long privKeyHandle, unsigned long pubKeyHandle, const char *keyType);
#endif
