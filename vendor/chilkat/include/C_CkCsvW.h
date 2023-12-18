// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkCsvWH
#define _C_CkCsvWH
#include "chilkatDefs.h"

#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC HCkCsvW CkCsvW_Create(void);
CK_C_VISIBLE_PUBLIC void CkCsvW_Dispose(HCkCsvW handle);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_getAutoTrim(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putAutoTrim(HCkCsvW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_getCrlf(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putCrlf(HCkCsvW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkCsvW_getDebugLogFilePath(HCkCsvW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putDebugLogFilePath(HCkCsvW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_debugLogFilePath(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void CkCsvW_getDelimiter(HCkCsvW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putDelimiter(HCkCsvW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_delimiter(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_getEnableQuotes(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putEnableQuotes(HCkCsvW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_getEscapeBackslash(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putEscapeBackslash(HCkCsvW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_getHasColumnNames(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putHasColumnNames(HCkCsvW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkCsvW_getLastErrorHtml(HCkCsvW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_lastErrorHtml(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void CkCsvW_getLastErrorText(HCkCsvW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_lastErrorText(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void CkCsvW_getLastErrorXml(HCkCsvW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_lastErrorXml(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_getLastMethodSuccess(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putLastMethodSuccess(HCkCsvW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC int CkCsvW_getNumColumns(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC int CkCsvW_getNumRows(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void CkCsvW_getUncommonOptions(HCkCsvW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putUncommonOptions(HCkCsvW cHandle, const wchar_t *newVal);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_uncommonOptions(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_getVerboseLogging(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC void  CkCsvW_putVerboseLogging(HCkCsvW cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkCsvW_getVersion(HCkCsvW cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_version(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_DeleteColumn(HCkCsvW cHandle, int index);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_DeleteColumnByName(HCkCsvW cHandle, const wchar_t *columnName);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_DeleteRow(HCkCsvW cHandle, int index);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_GetCell(HCkCsvW cHandle, int row, int col, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_getCell(HCkCsvW cHandle, int row, int col);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_GetCellByName(HCkCsvW cHandle, int rowIndex, const wchar_t *columnName, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_getCellByName(HCkCsvW cHandle, int rowIndex, const wchar_t *columnName);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_GetColumnName(HCkCsvW cHandle, int index, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_getColumnName(HCkCsvW cHandle, int index);
CK_C_VISIBLE_PUBLIC int CkCsvW_GetIndex(HCkCsvW cHandle, const wchar_t *columnName);
CK_C_VISIBLE_PUBLIC int CkCsvW_GetNumCols(HCkCsvW cHandle, int row);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_InsertColumn(HCkCsvW cHandle, int index);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_LoadFile(HCkCsvW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_LoadFile2(HCkCsvW cHandle, const wchar_t *filename, const wchar_t *charset);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_LoadFromString(HCkCsvW cHandle, const wchar_t *csvData);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_RowMatches(HCkCsvW cHandle, int rowIndex, const wchar_t *matchPattern, BOOL caseSensitive);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SaveFile(HCkCsvW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SaveFile2(HCkCsvW cHandle, const wchar_t *filename, const wchar_t *charset);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SaveLastError(HCkCsvW cHandle, const wchar_t *path);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SaveToSb(HCkCsvW cHandle, HCkStringBuilderW sb);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SaveToString(HCkCsvW cHandle, HCkString outStr);
CK_C_VISIBLE_PUBLIC const wchar_t *CkCsvW_saveToString(HCkCsvW cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SetCell(HCkCsvW cHandle, int row, int col, const wchar_t *content);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SetCellByName(HCkCsvW cHandle, int rowIndex, const wchar_t *columnName, const wchar_t *contentStr);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SetColumnName(HCkCsvW cHandle, int index, const wchar_t *columnName);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SortByColumn(HCkCsvW cHandle, const wchar_t *columnName, BOOL ascending, BOOL caseSensitive);
CK_C_VISIBLE_PUBLIC BOOL CkCsvW_SortByColumnIndex(HCkCsvW cHandle, int index, BOOL ascending, BOOL caseSensitive);
#endif
