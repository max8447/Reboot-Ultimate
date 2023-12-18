// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkFileAccessWH
#define _C_CkFileAccessWH
#include "chilkatDefs.h"

#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC HCkFileAccessW CkFileAccessW_Create(void);
CK_C_VISIBLE_PUBLIC void CkFileAccessW_Dispose(HCkFileAccessW handle);
CK_C_VISIBLE_PUBLIC void CkFileAccessW_getCurrentDir(HCkFileAccessW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_currentDir(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC void CkFileAccessW_getDebugLogFilePath(HCkFileAccessW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkFileAccessW_putDebugLogFilePath(HCkFileAccessW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_debugLogFilePath(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_getEndOfFile(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC int CkFileAccessW_getFileOpenError(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC void CkFileAccessW_getFileOpenErrorMsg(HCkFileAccessW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_fileOpenErrorMsg(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC void CkFileAccessW_getLastErrorHtml(HCkFileAccessW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_lastErrorHtml(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC void CkFileAccessW_getLastErrorText(HCkFileAccessW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_lastErrorText(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC void CkFileAccessW_getLastErrorXml(HCkFileAccessW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_lastErrorXml(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_getLastMethodSuccess(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC void  CkFileAccessW_putLastMethodSuccess(HCkFileAccessW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_getLockFileOnOpen(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC void  CkFileAccessW_putLockFileOnOpen(HCkFileAccessW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_getVerboseLogging(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC void  CkFileAccessW_putVerboseLogging(HCkFileAccessW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkFileAccessW_getVersion(HCkFileAccessW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_version(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_AppendAnsi(HCkFileAccessW cHandle, const wchar_t *text);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_AppendBd(HCkFileAccessW cHandle, HCkBinDataW bd);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_AppendSb(HCkFileAccessW cHandle, HCkStringBuilderW sb, const wchar_t *charset);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_AppendText(HCkFileAccessW cHandle, const wchar_t *str, const wchar_t *charset);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_AppendUnicodeBOM(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_AppendUtf8BOM(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_DirAutoCreate(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_DirCreate(HCkFileAccessW cHandle, const wchar_t *dirPath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_DirDelete(HCkFileAccessW cHandle, const wchar_t *dirPath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_DirEnsureExists(HCkFileAccessW cHandle, const wchar_t *dirPath);
CK_C_VISIBLE_PUBLIC void CkFileAccessW_FileClose(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileContentsEqual(HCkFileAccessW cHandle, const wchar_t *filePath1, const wchar_t *filePath2);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileCopy(HCkFileAccessW cHandle, const wchar_t *existingFilepath, const wchar_t *newFilepath, BOOL failIfExists);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileDelete(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileExists(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC int CkFileAccessW_FileExists3(HCkFileAccessW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileOpen(HCkFileAccessW cHandle, const wchar_t *filePath, unsigned long accessMode, unsigned long shareMode, unsigned long createDisposition, unsigned long attributes);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileRead(HCkFileAccessW cHandle, int maxNumBytes, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileReadBd(HCkFileAccessW cHandle, int maxNumBytes, HCkBinDataW binData);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileRename(HCkFileAccessW cHandle, const wchar_t *existingFilepath, const wchar_t *newFilepath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileSeek(HCkFileAccessW cHandle, int offset, int origin);
CK_C_VISIBLE_PUBLIC int CkFileAccessW_FileSize(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC __int64 CkFileAccessW_FileSize64(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileSizeStr(HCkFileAccessW cHandle, const wchar_t *filePath, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_fileSizeStr(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC int CkFileAccessW_FileType(HCkFileAccessW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileWrite(HCkFileAccessW cHandle, HCkByteData data);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileWrite2(HCkFileAccessW cHandle, const void * pByteData, unsigned long szByteData);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_FileWriteBd(HCkFileAccessW cHandle, HCkBinDataW binData, int offset, int numBytes);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_GenBlockId(HCkFileAccessW cHandle, int index, int length, const wchar_t *encoding, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_genBlockId(HCkFileAccessW cHandle, int index, int length, const wchar_t *encoding);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_GetDirectoryName(HCkFileAccessW cHandle, const wchar_t *path, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_getDirectoryName(HCkFileAccessW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_GetExtension(HCkFileAccessW cHandle, const wchar_t *path, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_getExtension(HCkFileAccessW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_GetFileName(HCkFileAccessW cHandle, const wchar_t *path, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_getFileName(HCkFileAccessW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_GetFileNameWithoutExtension(HCkFileAccessW cHandle, const wchar_t *path, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_getFileNameWithoutExtension(HCkFileAccessW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC HCkDateTimeW CkFileAccessW_GetFileTime(HCkFileAccessW cHandle, const wchar_t *path, int which);
CK_C_VISIBLE_PUBLIC HCkDateTimeW CkFileAccessW_GetLastModified(HCkFileAccessW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC int CkFileAccessW_GetNumBlocks(HCkFileAccessW cHandle, int blockSize);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_GetTempFilename(HCkFileAccessW cHandle, const wchar_t *dirPath, const wchar_t *prefix, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_getTempFilename(HCkFileAccessW cHandle, const wchar_t *dirPath, const wchar_t *prefix);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_OpenForAppend(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_OpenForRead(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_OpenForReadWrite(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_OpenForWrite(HCkFileAccessW cHandle, const wchar_t *filePath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_ReadBinaryToEncoded(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *encoding, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_readBinaryToEncoded(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *encoding);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_ReadBlock(HCkFileAccessW cHandle, int blockIndex, int blockSize, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_ReadBlockBd(HCkFileAccessW cHandle, int blockIndex, int blockSize, HCkBinDataW bd);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_ReadEntireFile(HCkFileAccessW cHandle, const wchar_t *filePath, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_ReadEntireTextFile(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *charset, HCkString outStrFileContents);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_readEntireTextFile(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *charset);
CK_C_VISIBLE_PUBLIC int CkFileAccessW_ReadNextFragment(HCkFileAccessW cHandle, BOOL startAtBeginning, const wchar_t *beginMarker, const wchar_t *endMarker, const wchar_t *charset, HCkStringBuilderW sb);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_ReassembleFile(HCkFileAccessW cHandle, const wchar_t *partsDirPath, const wchar_t *partPrefix, const wchar_t *partExtension, const wchar_t *reassembledFilename);
CK_C_VISIBLE_PUBLIC int CkFileAccessW_ReplaceStrings(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *charset, const wchar_t *existingString, const wchar_t *replacementString);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_SaveLastError(HCkFileAccessW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_SetCurrentDir(HCkFileAccessW cHandle, const wchar_t *dirPath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_SetFileTimes(HCkFileAccessW cHandle, const wchar_t *filePath, HCkDateTimeW createTime, HCkDateTimeW lastAccessTime, HCkDateTimeW lastModTime);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_SetLastModified(HCkFileAccessW cHandle, const wchar_t *filePath, HCkDateTimeW lastModified);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_SplitFile(HCkFileAccessW cHandle, const wchar_t *fileToSplit, const wchar_t *partPrefix, const wchar_t *partExtension, int partSize, const wchar_t *destDir);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_SymlinkCreate(HCkFileAccessW cHandle, const wchar_t *targetPath, const wchar_t *linkPath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_SymlinkTarget(HCkFileAccessW cHandle, const wchar_t *linkPath, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkFileAccessW_symlinkTarget(HCkFileAccessW cHandle, const wchar_t *linkPath);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_TreeDelete(HCkFileAccessW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_Truncate(HCkFileAccessW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_WriteEntireFile(HCkFileAccessW cHandle, const wchar_t *filePath, HCkByteData fileData);
CK_C_VISIBLE_PUBLIC BOOL CkFileAccessW_WriteEntireTextFile(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *textData, const wchar_t *charset, BOOL includedPreamble);
#endif
