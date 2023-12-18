// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkDnsWH
#define _C_CkDnsWH
#include "chilkatDefs.h"

#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC void CkDnsW_setAbortCheck(HCkDnsW cHandle, BOOL (*fnAbortCheck)(void));
CK_C_VISIBLE_PUBLIC void CkDnsW_setPercentDone(HCkDnsW cHandle, BOOL (*fnPercentDone)(int pctDone));
CK_C_VISIBLE_PUBLIC void CkDnsW_setProgressInfo(HCkDnsW cHandle, void (*fnProgressInfo)(const wchar_t *name, const wchar_t *value));
CK_C_VISIBLE_PUBLIC void CkDnsW_setTaskCompleted(HCkDnsW cHandle, void (*fnTaskCompleted)(HCkTaskW hTask));

CK_C_VISIBLE_PUBLIC HCkDnsW CkDnsW_Create(void);
CK_C_VISIBLE_PUBLIC void CkDnsW_Dispose(HCkDnsW handle);
CK_C_VISIBLE_PUBLIC void CkDnsW_getDebugLogFilePath(HCkDnsW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkDnsW_putDebugLogFilePath(HCkDnsW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDnsW_debugLogFilePath(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC int CkDnsW_getHeartbeatMs(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDnsW_putHeartbeatMs(HCkDnsW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkDnsW_getLastErrorHtml(HCkDnsW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDnsW_lastErrorHtml(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void CkDnsW_getLastErrorText(HCkDnsW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDnsW_lastErrorText(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void CkDnsW_getLastErrorXml(HCkDnsW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDnsW_lastErrorXml(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkDnsW_getLastMethodSuccess(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDnsW_putLastMethodSuccess(HCkDnsW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC int CkDnsW_getMaxWaitMs(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDnsW_putMaxWaitMs(HCkDnsW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC int CkDnsW_getNumNameservers(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC int CkDnsW_getTlsPref(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDnsW_putTlsPref(HCkDnsW cHandle, int newVal);
CK_C_VISIBLE_PUBLIC BOOL CkDnsW_getVerboseLogging(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void  CkDnsW_putVerboseLogging(HCkDnsW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkDnsW_getVersion(HCkDnsW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDnsW_version(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void CkDnsW_AddDefaultNameservers(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void CkDnsW_AddNameserver(HCkDnsW cHandle, const wchar_t *ipAddr, BOOL supportsTls);
CK_C_VISIBLE_PUBLIC BOOL CkDnsW_GetNameserver(HCkDnsW cHandle, int index, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkDnsW_getNameserver(HCkDnsW cHandle, int index);
CK_C_VISIBLE_PUBLIC BOOL CkDnsW_Query(HCkDnsW cHandle, const wchar_t *recordType, const wchar_t *domain, HCkJsonObjectW answer);
CK_C_VISIBLE_PUBLIC HCkTaskW CkDnsW_QueryAsync(HCkDnsW cHandle, const wchar_t *recordType, const wchar_t *domain, HCkJsonObjectW answer);
CK_C_VISIBLE_PUBLIC void CkDnsW_RemoveAllNameservers(HCkDnsW cHandle);
CK_C_VISIBLE_PUBLIC void CkDnsW_RemoveNameserver(HCkDnsW cHandle, const wchar_t *ipAddr);
CK_C_VISIBLE_PUBLIC BOOL CkDnsW_SaveLastError(HCkDnsW cHandle, const wchar_t *path);
#endif
