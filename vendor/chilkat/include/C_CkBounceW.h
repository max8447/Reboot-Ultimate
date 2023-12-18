// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkBounceWH
#define _C_CkBounceWH
#include "chilkatDefs.h"

#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC HCkBounceW CkBounceW_Create(void);
CK_C_VISIBLE_PUBLIC void CkBounceW_Dispose(HCkBounceW handle);
CK_C_VISIBLE_PUBLIC void CkBounceW_getBounceAddress(HCkBounceW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkBounceW_bounceAddress(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC void CkBounceW_getBounceData(HCkBounceW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkBounceW_bounceData(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC int CkBounceW_getBounceType(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC void CkBounceW_getDebugLogFilePath(HCkBounceW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkBounceW_putDebugLogFilePath(HCkBounceW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkBounceW_debugLogFilePath(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC void CkBounceW_getLastErrorHtml(HCkBounceW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkBounceW_lastErrorHtml(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC void CkBounceW_getLastErrorText(HCkBounceW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkBounceW_lastErrorText(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC void CkBounceW_getLastErrorXml(HCkBounceW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkBounceW_lastErrorXml(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkBounceW_getLastMethodSuccess(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC void  CkBounceW_putLastMethodSuccess(HCkBounceW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkBounceW_getVerboseLogging(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC void  CkBounceW_putVerboseLogging(HCkBounceW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkBounceW_getVersion(HCkBounceW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkBounceW_version(HCkBounceW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkBounceW_ExamineEmail(HCkBounceW cHandle, HCkEmailW email);
CK_C_VISIBLE_PUBLIC BOOL CkBounceW_ExamineEml(HCkBounceW cHandle, const wchar_t *emlFilename);
CK_C_VISIBLE_PUBLIC BOOL CkBounceW_ExamineMime(HCkBounceW cHandle, const wchar_t *mimeText);
CK_C_VISIBLE_PUBLIC BOOL CkBounceW_SaveLastError(HCkBounceW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkBounceW_UnlockComponent(HCkBounceW cHandle, const wchar_t *unlockCode);
#endif
