// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkDns_H
#define _C_CkDns_H
#include "chilkatDefs.h"
#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC void CkDns_setAbortCheck(HCkDns cHandle, BOOL (*fnAbortCheck)(void));
CK_C_VISIBLE_PUBLIC void CkDns_setPercentDone(HCkDns cHandle, BOOL (*fnPercentDone)(int pctDone));
CK_C_VISIBLE_PUBLIC void CkDns_setProgressInfo(HCkDns cHandle, void (*fnProgressInfo)(const char *name, const char *value));
CK_C_VISIBLE_PUBLIC void CkDns_setTaskCompleted(HCkDns cHandle, void (*fnTaskCompleted)(HCkTask hTask));

CK_C_VISIBLE_PUBLIC void CkDns_setAbortCheck2(HCkDns cHandle, BOOL (*fnAbortCheck2)(void *pContext));
CK_C_VISIBLE_PUBLIC void CkDns_setPercentDone2(HCkDns cHandle, BOOL (*fnPercentDone2)(int pctDone, void *pContext));
CK_C_VISIBLE_PUBLIC void CkDns_setProgressInfo2(HCkDns cHandle, void (*fnProgressInfo2)(const char *name, const char *value, void *pContext));
CK_C_VISIBLE_PUBLIC void CkDns_setTaskCompleted2(HCkDns cHandle, void (*fnTaskCompleted2)(HCkTask hTask, void *pContext));

// setExternalProgress is for C callback functions defined in the external programming language (such as Go)
CK_C_VISIBLE_PUBLIC void CkDns_setExternalProgress(HCkDns cHandle, BOOL on);
CK_C_VISIBLE_PUBLIC void CkDns_setCallbackContext(HCkDns cHandle, void *pContext);

CK_C_VISIBLE_PUBLIC HCkDns CkDns_Create(void);
CK_C_VISIBLE_PUBLIC void CkDns_Dispose(HCkDns handle);
CK_C_VISIBLE_PUBLIC void CkDns_getDebugLogFilePath(HCkDns cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkDns_putDebugLogFilePath(HCkDns cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkDns_debugLogFilePath(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC int CkDns_getHeartbeatMs(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_putHeartbeatMs(HCkDns cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkDns_getLastErrorHtml(HCkDns cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkDns_lastErrorHtml(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_getLastErrorText(HCkDns cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkDns_lastErrorText(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_getLastErrorXml(HCkDns cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkDns_lastErrorXml(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkDns_getLastMethodSuccess(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_putLastMethodSuccess(HCkDns cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC int CkDns_getMaxWaitMs(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_putMaxWaitMs(HCkDns cHandle, int newVal);
CK_C_VISIBLE_PUBLIC int CkDns_getNumNameservers(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC int CkDns_getTlsPref(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_putTlsPref(HCkDns cHandle, int newVal);
CK_C_VISIBLE_PUBLIC BOOL CkDns_getUtf8(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_putUtf8(HCkDns cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkDns_getVerboseLogging(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_putVerboseLogging(HCkDns cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkDns_getVersion(HCkDns cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkDns_version(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_AddDefaultNameservers(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_AddNameserver(HCkDns cHandle, const char *ipAddr, BOOL supportsTls);
CK_C_VISIBLE_PUBLIC BOOL CkDns_GetNameserver(HCkDns cHandle, int index, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkDns_getNameserver(HCkDns cHandle, int index);
CK_C_VISIBLE_PUBLIC BOOL CkDns_Query(HCkDns cHandle, const char *recordType, const char *domain, HCkJsonObject answer);
CK_C_VISIBLE_PUBLIC HCkTask CkDns_QueryAsync(HCkDns cHandle, const char *recordType, const char *domain, HCkJsonObject answer);
CK_C_VISIBLE_PUBLIC void CkDns_RemoveAllNameservers(HCkDns cHandle);
CK_C_VISIBLE_PUBLIC void CkDns_RemoveNameserver(HCkDns cHandle, const char *ipAddr);
CK_C_VISIBLE_PUBLIC BOOL CkDns_SaveLastError(HCkDns cHandle, const char *path);
#endif
