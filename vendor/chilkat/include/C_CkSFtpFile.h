// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkSFtpFile_H
#define _C_CkSFtpFile_H
#include "chilkatDefs.h"
#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC HCkSFtpFile CkSFtpFile_Create(void);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_Dispose(HCkSFtpFile handle);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getCreateTime(HCkSFtpFile cHandle, SYSTEMTIME * retval);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getCreateTimeStr(HCkSFtpFile cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSFtpFile_createTimeStr(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getFilename(HCkSFtpFile cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSFtpFile_filename(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getFileType(HCkSFtpFile cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSFtpFile_fileType(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC int CkSFtpFile_getGid(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getGroup(HCkSFtpFile cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSFtpFile_group(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsAppendOnly(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsArchive(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsCaseInsensitive(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsCompressed(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsDirectory(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsEncrypted(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsHidden(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsImmutable(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsReadOnly(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsRegular(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsSparse(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsSymLink(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsSync(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getIsSystem(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getLastAccessTime(HCkSFtpFile cHandle, SYSTEMTIME * retval);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getLastAccessTimeStr(HCkSFtpFile cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSFtpFile_lastAccessTimeStr(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getLastMethodSuccess(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_putLastMethodSuccess(HCkSFtpFile cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getLastModifiedTime(HCkSFtpFile cHandle, SYSTEMTIME * retval);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getLastModifiedTimeStr(HCkSFtpFile cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSFtpFile_lastModifiedTimeStr(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getOwner(HCkSFtpFile cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSFtpFile_owner(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC int CkSFtpFile_getPermissions(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC int CkSFtpFile_getSize32(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC __int64 CkSFtpFile_getSize64(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_getSizeStr(HCkSFtpFile cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkSFtpFile_sizeStr(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC int CkSFtpFile_getUid(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkSFtpFile_getUtf8(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC void CkSFtpFile_putUtf8(HCkSFtpFile cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC HCkDateTime CkSFtpFile_GetCreateDt(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC HCkDateTime CkSFtpFile_GetLastAccessDt(HCkSFtpFile cHandle);
CK_C_VISIBLE_PUBLIC HCkDateTime CkSFtpFile_GetLastModifiedDt(HCkSFtpFile cHandle);
#endif
