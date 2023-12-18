// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkUploadWH
#define _C_CkUploadWH
#include "chilkatDefs.h"

#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC void CkUploadW_setAbortCheck(HCkUploadW cHandle, BOOL (*fnAbortCheck)(void));
CK_C_VISIBLE_PUBLIC void CkUploadW_setPercentDone(HCkUploadW cHandle, BOOL (*fnPercentDone)(int pctDone));
CK_C_VISIBLE_PUBLIC void CkUploadW_setProgressInfo(HCkUploadW cHandle, void (*fnProgressInfo)(const wchar_t *name, const wchar_t *value));
CK_C_VISIBLE_PUBLIC void CkUploadW_setTaskCompleted(HCkUploadW cHandle, void (*fnTaskCompleted)(HCkTaskW hTask));

CK_C_VISIBLE_PUBLIC HCkUploadW CkUploadW_Create(void);
CK_C_VISIBLE_PUBLIC void CkUploadW_Dispose(HCkUploadW handle);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_getAbortCurrent(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putAbortCurrent(HCkUploadW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC int CkUploadW_getBandwidthThrottleUp(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putBandwidthThrottleUp(HCkUploadW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC int CkUploadW_getChunkSize(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putChunkSize(HCkUploadW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkUploadW_getClientIpAddress(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putClientIpAddress(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_clientIpAddress(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getCurrentFilename(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_currentFilename(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getDebugLogFilePath(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putDebugLogFilePath(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_debugLogFilePath(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_getExpect100Continue(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putExpect100Continue(HCkUploadW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC int CkUploadW_getHeartbeatMs(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putHeartbeatMs(HCkUploadW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkUploadW_getHostname(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putHostname(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_hostname(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC int CkUploadW_getIdleTimeoutMs(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putIdleTimeoutMs(HCkUploadW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkUploadW_getLastErrorHtml(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_lastErrorHtml(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getLastErrorText(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_lastErrorText(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getLastErrorXml(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_lastErrorXml(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_getLastMethodSuccess(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putLastMethodSuccess(HCkUploadW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkUploadW_getLogin(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putLogin(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_login(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC unsigned long CkUploadW_getNumBytesSent(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getPassword(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putPassword(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_password(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getPath(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putPath(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_path(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC int CkUploadW_getPercentDoneScale(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putPercentDoneScale(HCkUploadW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC unsigned long CkUploadW_getPercentUploaded(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC int CkUploadW_getPort(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putPort(HCkUploadW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_getPreferIpv6(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putPreferIpv6(HCkUploadW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkUploadW_getProxyDomain(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putProxyDomain(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_proxyDomain(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getProxyLogin(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putProxyLogin(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_proxyLogin(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getProxyPassword(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putProxyPassword(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_proxyPassword(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC int CkUploadW_getProxyPort(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putProxyPort(HCkUploadW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkUploadW_getResponseBody(HCkUploadW cHandle, HCkByteData retval);
CK_C_VISIBLE_PUBLIC void CkUploadW_getResponseBodyStr(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_responseBodyStr(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getResponseHeader(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_responseHeader(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC int CkUploadW_getResponseStatus(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_getSsl(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putSsl(HCkUploadW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkUploadW_getSslAllowedCiphers(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putSslAllowedCiphers(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_sslAllowedCiphers(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getSslProtocol(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putSslProtocol(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_sslProtocol(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_getTlsPinSet(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putTlsPinSet(HCkUploadW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_tlsPinSet(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC unsigned long CkUploadW_getTotalUploadSize(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_getUploadInProgress(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_getUploadSuccess(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_getVerboseLogging(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void  CkUploadW_putVerboseLogging(HCkUploadW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkUploadW_getVersion(HCkUploadW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkUploadW_version(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_AbortUpload(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_AddCustomHeader(HCkUploadW cHandle, const wchar_t *name, const wchar_t *value);
CK_C_VISIBLE_PUBLIC void CkUploadW_AddFileReference(HCkUploadW cHandle, const wchar_t *name, const wchar_t *filename);
CK_C_VISIBLE_PUBLIC void CkUploadW_AddParam(HCkUploadW cHandle, const wchar_t *name, const wchar_t *value);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_BeginUpload(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_BlockingUpload(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC HCkTaskW CkUploadW_BlockingUploadAsync(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_ClearFileReferences(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC void CkUploadW_ClearParams(HCkUploadW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_LoadTaskCaller(HCkUploadW cHandle, HCkTaskW task);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_SaveLastError(HCkUploadW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC void CkUploadW_SleepMs(HCkUploadW cHandle, int millisec);
CK_C_VISIBLE_PUBLIC BOOL CkUploadW_UploadToMemory(HCkUploadW cHandle, HCkByteData outData);
#endif
