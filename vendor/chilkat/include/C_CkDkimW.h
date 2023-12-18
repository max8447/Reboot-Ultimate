// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkDkimWH
#define _C_CkDkimWH
#include "chilkatDefs.h"

#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC void CkDkimW_setAbortCheck(HCkDkimW cHandle, BOOL (*fnAbortCheck)(void));
CK_C_VISIBLE_PUBLIC void CkDkimW_setPercentDone(HCkDkimW cHandle, BOOL (*fnPercentDone)(int pctDone));
CK_C_VISIBLE_PUBLIC void CkDkimW_setProgressInfo(HCkDkimW cHandle, void (*fnProgressInfo)(const wchar_t *name, const wchar_t *value));
CK_C_VISIBLE_PUBLIC void CkDkimW_setTaskCompleted(HCkDkimW cHandle, void (*fnTaskCompleted)(HCkTaskW hTask));

CK_C_VISIBLE_PUBLIC HCkDkimW CkDkimW_Create(void);
CK_C_VISIBLE_PUBLIC void CkDkimW_Dispose(HCkDkimW handle);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_getAbortCurrent(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putAbortCurrent(HCkDkimW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDebugLogFilePath(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDebugLogFilePath(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_debugLogFilePath(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDkimAlg(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDkimAlg(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_dkimAlg(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC int CkDkimW_getDkimBodyLengthCount(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDkimBodyLengthCount(HCkDkimW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDkimCanon(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDkimCanon(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_dkimCanon(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDkimDomain(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDkimDomain(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_dkimDomain(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDkimHeaders(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDkimHeaders(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_dkimHeaders(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDkimSelector(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDkimSelector(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_dkimSelector(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDomainKeyAlg(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDomainKeyAlg(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_domainKeyAlg(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDomainKeyCanon(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDomainKeyCanon(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_domainKeyCanon(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDomainKeyDomain(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDomainKeyDomain(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_domainKeyDomain(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDomainKeyHeaders(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDomainKeyHeaders(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_domainKeyHeaders(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getDomainKeySelector(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putDomainKeySelector(HCkDkimW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_domainKeySelector(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC int CkDkimW_getHeartbeatMs(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putHeartbeatMs(HCkDkimW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkDkimW_getLastErrorHtml(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_lastErrorHtml(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getLastErrorText(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_lastErrorText(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getLastErrorXml(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_lastErrorXml(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_getLastMethodSuccess(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putLastMethodSuccess(HCkDkimW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_getVerboseLogging(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDkimW_putVerboseLogging(HCkDkimW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkDkimW_getVerifyInfo(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_verifyInfo(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC void CkDkimW_getVersion(HCkDkimW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDkimW_version(HCkDkimW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_AddDkimSignature(HCkDkimW cHandle, HCkByteData mimeIn, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_AddDomainKeySignature(HCkDkimW cHandle, HCkByteData mimeIn, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_DkimSign(HCkDkimW cHandle, HCkBinDataW mimeData);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_DkimVerify(HCkDkimW cHandle, int sigIndex, HCkBinDataW mimeData);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_DomainKeySign(HCkDkimW cHandle, HCkBinDataW mimeData);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_DomainKeyVerify(HCkDkimW cHandle, int sigIndex, HCkBinDataW mimeData);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_LoadDkimPk(HCkDkimW cHandle, const wchar_t *privateKey, const wchar_t *optionalPassword);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_LoadDkimPkBytes(HCkDkimW cHandle, HCkByteData privateKeyDer, const wchar_t *optionalPassword);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_LoadDkimPkFile(HCkDkimW cHandle, const wchar_t *privateKeyFilePath, const wchar_t *optionalPassword);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_LoadDomainKeyPk(HCkDkimW cHandle, const wchar_t *privateKey, const wchar_t *optionalPassword);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_LoadDomainKeyPkBytes(HCkDkimW cHandle, HCkByteData privateKeyDer, const wchar_t *optionalPassword);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_LoadDomainKeyPkFile(HCkDkimW cHandle, const wchar_t *privateKeyFilePath, const wchar_t *optionalPassword);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_LoadPublicKey(HCkDkimW cHandle, const wchar_t *selector, const wchar_t *domain, const wchar_t *publicKey);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_LoadPublicKeyFile(HCkDkimW cHandle, const wchar_t *selector, const wchar_t *domain, const wchar_t *publicKeyFilepath);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_LoadTaskCaller(HCkDkimW cHandle, HCkTaskW task);
CK_C_VISIBLE_PUBLIC int CkDkimW_NumDkimSignatures(HCkDkimW cHandle, HCkByteData mimeData);
CK_C_VISIBLE_PUBLIC int CkDkimW_NumDkimSigs(HCkDkimW cHandle, HCkBinDataW mimeData);
CK_C_VISIBLE_PUBLIC int CkDkimW_NumDomainKeySignatures(HCkDkimW cHandle, HCkByteData mimeData);
CK_C_VISIBLE_PUBLIC int CkDkimW_NumDomainKeySigs(HCkDkimW cHandle, HCkBinDataW mimeData);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_PrefetchPublicKey(HCkDkimW cHandle, const wchar_t *selector, const wchar_t *domain);
CK_C_VISIBLE_PUBLIC HCkTaskW CkDkimW_PrefetchPublicKeyAsync(HCkDkimW cHandle, const wchar_t *selector, const wchar_t *domain);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_SaveLastError(HCkDkimW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_SetDkimPrivateKey(HCkDkimW cHandle, HCkPrivateKeyW privateKey);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_SetDomainKeyPrivateKey(HCkDkimW cHandle, HCkPrivateKeyW privateKey);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_UnlockComponent(HCkDkimW cHandle, const wchar_t *unlockCode);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_VerifyDkimSignature(HCkDkimW cHandle, int sigIndex, HCkByteData mimeData);
CK_C_VISIBLE_PUBLIC HCkTaskW CkDkimW_VerifyDkimSignatureAsync(HCkDkimW cHandle, int sigIndex, HCkByteData mimeData);
CK_C_VISIBLE_PUBLIC BOOL CkDkimW_VerifyDomainKeySignature(HCkDkimW cHandle, int sigIndex, HCkByteData mimeData);
CK_C_VISIBLE_PUBLIC HCkTaskW CkDkimW_VerifyDomainKeySignatureAsync(HCkDkimW cHandle, int sigIndex, HCkByteData mimeData);
#endif
