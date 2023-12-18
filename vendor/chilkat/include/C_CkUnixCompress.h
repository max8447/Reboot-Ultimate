// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkUnixCompress_H
#define _C_CkUnixCompress_H
#include "chilkatDefs.h"
#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC void CkUnixCompress_setAbortCheck(HCkUnixCompress cHandle, BOOL (*fnAbortCheck)(void));
CK_C_VISIBLE_PUBLIC void CkUnixCompress_setPercentDone(HCkUnixCompress cHandle, BOOL (*fnPercentDone)(int pctDone));
CK_C_VISIBLE_PUBLIC void CkUnixCompress_setProgressInfo(HCkUnixCompress cHandle, void (*fnProgressInfo)(const char *name, const char *value));
CK_C_VISIBLE_PUBLIC void CkUnixCompress_setTaskCompleted(HCkUnixCompress cHandle, void (*fnTaskCompleted)(HCkTask hTask));

CK_C_VISIBLE_PUBLIC void CkUnixCompress_setAbortCheck2(HCkUnixCompress cHandle, BOOL (*fnAbortCheck2)(void *pContext));
CK_C_VISIBLE_PUBLIC void CkUnixCompress_setPercentDone2(HCkUnixCompress cHandle, BOOL (*fnPercentDone2)(int pctDone, void *pContext));
CK_C_VISIBLE_PUBLIC void CkUnixCompress_setProgressInfo2(HCkUnixCompress cHandle, void (*fnProgressInfo2)(const char *name, const char *value, void *pContext));
CK_C_VISIBLE_PUBLIC void CkUnixCompress_setTaskCompleted2(HCkUnixCompress cHandle, void (*fnTaskCompleted2)(HCkTask hTask, void *pContext));

// setExternalProgress is for C callback functions defined in the external programming language (such as Go)
CK_C_VISIBLE_PUBLIC void CkUnixCompress_setExternalProgress(HCkUnixCompress cHandle, BOOL on);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_setCallbackContext(HCkUnixCompress cHandle, void *pContext);

CK_C_VISIBLE_PUBLIC HCkUnixCompress CkUnixCompress_Create(void);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_Dispose(HCkUnixCompress handle);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_getAbortCurrent(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_putAbortCurrent(HCkUnixCompress cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_getDebugLogFilePath(HCkUnixCompress cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_putDebugLogFilePath(HCkUnixCompress cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkUnixCompress_debugLogFilePath(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC int CkUnixCompress_getHeartbeatMs(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_putHeartbeatMs(HCkUnixCompress cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_getLastErrorHtml(HCkUnixCompress cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkUnixCompress_lastErrorHtml(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_getLastErrorText(HCkUnixCompress cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkUnixCompress_lastErrorText(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_getLastErrorXml(HCkUnixCompress cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkUnixCompress_lastErrorXml(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_getLastMethodSuccess(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_putLastMethodSuccess(HCkUnixCompress cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_getUtf8(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_putUtf8(HCkUnixCompress cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_getVerboseLogging(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_putVerboseLogging(HCkUnixCompress cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkUnixCompress_getVersion(HCkUnixCompress cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkUnixCompress_version(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_CompressFile(HCkUnixCompress cHandle, const char *inFilename, const char *destPath);
CK_C_VISIBLE_PUBLIC HCkTask CkUnixCompress_CompressFileAsync(HCkUnixCompress cHandle, const char *inFilename, const char *destPath);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_CompressFileToMem(HCkUnixCompress cHandle, const char *inFilename, HCkByteData outData);
CK_C_VISIBLE_PUBLIC HCkTask CkUnixCompress_CompressFileToMemAsync(HCkUnixCompress cHandle, const char *inFilename);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_CompressMemory(HCkUnixCompress cHandle, HCkByteData inData, HCkByteData outData);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_CompressMemToFile(HCkUnixCompress cHandle, HCkByteData inData, const char *destPath);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_CompressString(HCkUnixCompress cHandle, const char *inStr, const char *charset, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_CompressStringToFile(HCkUnixCompress cHandle, const char *inStr, const char *charset, const char *destPath);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_IsUnlocked(HCkUnixCompress cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_LoadTaskCaller(HCkUnixCompress cHandle, HCkTask task);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_SaveLastError(HCkUnixCompress cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_UncompressFile(HCkUnixCompress cHandle, const char *inFilename, const char *destPath);
CK_C_VISIBLE_PUBLIC HCkTask CkUnixCompress_UncompressFileAsync(HCkUnixCompress cHandle, const char *inFilename, const char *destPath);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_UncompressFileToMem(HCkUnixCompress cHandle, const char *inFilename, HCkByteData outData);
CK_C_VISIBLE_PUBLIC HCkTask CkUnixCompress_UncompressFileToMemAsync(HCkUnixCompress cHandle, const char *inFilename);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_UncompressFileToString(HCkUnixCompress cHandle, const char *zFilename, const char *charset, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkUnixCompress_uncompressFileToString(HCkUnixCompress cHandle, const char *zFilename, const char *charset);
CK_C_VISIBLE_PUBLIC HCkTask CkUnixCompress_UncompressFileToStringAsync(HCkUnixCompress cHandle, const char *zFilename, const char *charset);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_UncompressMemory(HCkUnixCompress cHandle, HCkByteData inData, HCkByteData outData);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_UncompressMemToFile(HCkUnixCompress cHandle, HCkByteData inData, const char *destPath);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_UncompressString(HCkUnixCompress cHandle, HCkByteData inCompressedData, const char *charset, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkUnixCompress_uncompressString(HCkUnixCompress cHandle, HCkByteData inCompressedData, const char *charset);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_UnlockComponent(HCkUnixCompress cHandle, const char *unlockCode);
CK_C_VISIBLE_PUBLIC BOOL CkUnixCompress_UnTarZ(HCkUnixCompress cHandle, const char *zFilename, const char *destDir, BOOL bNoAbsolute);
CK_C_VISIBLE_PUBLIC HCkTask CkUnixCompress_UnTarZAsync(HCkUnixCompress cHandle, const char *zFilename, const char *destDir, BOOL bNoAbsolute);
#endif
