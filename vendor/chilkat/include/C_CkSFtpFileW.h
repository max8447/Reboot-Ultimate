// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkSFtpFileWH
#define _C_CkSFtpFileWH
#include "chilkatDefs.h"

#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC HCkSFtpFileW CkSFtpFileW_Create(void);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_Dispose(HCkSFtpFileW handle);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getCreateTime(HCkSFtpFileW cHandle, SYSTEMTIME * retval);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getCreateTimeStr(HCkSFtpFileW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkSFtpFileW_createTimeStr(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getFilename(HCkSFtpFileW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkSFtpFileW_filename(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getFileType(HCkSFtpFileW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkSFtpFileW_fileType(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC int CkSFtpFileW_getGid(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getGroup(HCkSFtpFileW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkSFtpFileW_group(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsAppendOnly(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsArchive(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsCaseInsensitive(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsCompressed(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsDirectory(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsEncrypted(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsHidden(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsImmutable(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsReadOnly(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsRegular(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsSparse(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsSymLink(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsSync(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getIsSystem(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getLastAccessTime(HCkSFtpFileW cHandle, SYSTEMTIME * retval);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getLastAccessTimeStr(HCkSFtpFileW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkSFtpFileW_lastAccessTimeStr(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFileW_getLastMethodSuccess(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC void  CkSFtpFileW_putLastMethodSuccess(HCkSFtpFileW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getLastModifiedTime(HCkSFtpFileW cHandle, SYSTEMTIME * retval);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getLastModifiedTimeStr(HCkSFtpFileW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkSFtpFileW_lastModifiedTimeStr(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getOwner(HCkSFtpFileW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkSFtpFileW_owner(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC int CkSFtpFileW_getPermissions(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC int CkSFtpFileW_getSize32(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC __int64 CkSFtpFileW_getSize64(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFileW_getSizeStr(HCkSFtpFileW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkSFtpFileW_sizeStr(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC int CkSFtpFileW_getUid(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC HCkDateTimeW CkSFtpFileW_GetCreateDt(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC HCkDateTimeW CkSFtpFileW_GetLastAccessDt(HCkSFtpFileW cHandle);
CK_C_VISIBLE_PUBLIC HCkDateTimeW CkSFtpFileW_GetLastModifiedDt(HCkSFtpFileW cHandle);
#endif
