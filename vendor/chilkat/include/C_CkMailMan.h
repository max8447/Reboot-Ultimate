// This is a generated source file for Chilkat version 9.5.0.96
#ifndef _C_CkMailMan_H
#define _C_CkMailMan_H
#include "chilkatDefs.h"
#include "ck_inttypes.h"
#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC void CkMailMan_setAbortCheck(HCkMailMan cHandle, BOOL (*fnAbortCheck)(void));
CK_C_VISIBLE_PUBLIC void CkMailMan_setPercentDone(HCkMailMan cHandle, BOOL (*fnPercentDone)(int pctDone));
CK_C_VISIBLE_PUBLIC void CkMailMan_setProgressInfo(HCkMailMan cHandle, void (*fnProgressInfo)(const char *name, const char *value));
CK_C_VISIBLE_PUBLIC void CkMailMan_setTaskCompleted(HCkMailMan cHandle, void (*fnTaskCompleted)(HCkTask hTask));

CK_C_VISIBLE_PUBLIC void CkMailMan_setAbortCheck2(HCkMailMan cHandle, BOOL (*fnAbortCheck2)(void *pContext));
CK_C_VISIBLE_PUBLIC void CkMailMan_setPercentDone2(HCkMailMan cHandle, BOOL (*fnPercentDone2)(int pctDone, void *pContext));
CK_C_VISIBLE_PUBLIC void CkMailMan_setProgressInfo2(HCkMailMan cHandle, void (*fnProgressInfo2)(const char *name, const char *value, void *pContext));
CK_C_VISIBLE_PUBLIC void CkMailMan_setTaskCompleted2(HCkMailMan cHandle, void (*fnTaskCompleted2)(HCkTask hTask, void *pContext));

// setExternalProgress is for C callback functions defined in the external programming language (such as Go)
CK_C_VISIBLE_PUBLIC void CkMailMan_setExternalProgress(HCkMailMan cHandle, BOOL on);
CK_C_VISIBLE_PUBLIC void CkMailMan_setCallbackContext(HCkMailMan cHandle, void *pContext);

CK_C_VISIBLE_PUBLIC HCkMailMan CkMailMan_Create(void);
CK_C_VISIBLE_PUBLIC void CkMailMan_Dispose(HCkMailMan handle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getAbortCurrent(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putAbortCurrent(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getAllOrNone(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putAllOrNone(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getAutoFix(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putAutoFix(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getAutoGenMessageId(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putAutoGenMessageId(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getAutoSmtpRset(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putAutoSmtpRset(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getAutoUnwrapSecurity(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putAutoUnwrapSecurity(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getClientIpAddress(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putClientIpAddress(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_clientIpAddress(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_getConnectFailReason(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_getConnectTimeout(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putConnectTimeout(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getDebugLogFilePath(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putDebugLogFilePath(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_debugLogFilePath(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getDsnEnvid(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putDsnEnvid(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_dsnEnvid(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getDsnNotify(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putDsnNotify(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_dsnNotify(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getDsnRet(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putDsnRet(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_dsnRet(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getEmbedCertChain(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putEmbedCertChain(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getFilter(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putFilter(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_filter(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_getHeartbeatMs(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putHeartbeatMs(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getHeloHostname(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putHeloHostname(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_heloHostname(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getHttpProxyAuthMethod(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putHttpProxyAuthMethod(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_httpProxyAuthMethod(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getHttpProxyDomain(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putHttpProxyDomain(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_httpProxyDomain(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getHttpProxyHostname(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putHttpProxyHostname(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_httpProxyHostname(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getHttpProxyPassword(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putHttpProxyPassword(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_httpProxyPassword(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_getHttpProxyPort(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putHttpProxyPort(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getHttpProxyUsername(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putHttpProxyUsername(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_httpProxyUsername(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getImmediateDelete(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putImmediateDelete(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getIncludeRootCert(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putIncludeRootCert(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getIsPop3Connected(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getIsSmtpConnected(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getLastErrorHtml(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_lastErrorHtml(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getLastErrorText(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_lastErrorText(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getLastErrorXml(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_lastErrorXml(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getLastMethodSuccess(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putLastMethodSuccess(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getLastSendQFilename(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_lastSendQFilename(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_getLastSmtpStatus(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getLastSmtpStatusMsg(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_lastSmtpStatusMsg(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getLogMailReceivedFilename(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putLogMailReceivedFilename(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_logMailReceivedFilename(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getLogMailSentFilename(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putLogMailSentFilename(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_logMailSentFilename(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getMailHost(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putMailHost(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_mailHost(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_getMailPort(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putMailPort(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC int CkMailMan_getMaxCount(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putMaxCount(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getOAuth2AccessToken(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putOAuth2AccessToken(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_oAuth2AccessToken(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getOpaqueSigning(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putOpaqueSigning(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getP7mEncryptAttachFilename(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putP7mEncryptAttachFilename(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_p7mEncryptAttachFilename(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getP7mSigAttachFilename(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putP7mSigAttachFilename(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_p7mSigAttachFilename(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getP7sSigAttachFilename(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putP7sSigAttachFilename(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_p7sSigAttachFilename(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_getPercentDoneScale(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putPercentDoneScale(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC int CkMailMan_getPop3SessionId(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getPop3SessionLog(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_pop3SessionLog(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getPop3SPA(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putPop3SPA(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getPop3SslServerCertVerified(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getPop3Stls(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putPop3Stls(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getPop3StlsIfPossible(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putPop3StlsIfPossible(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getPopPassword(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putPopPassword(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_popPassword(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getPopPasswordBase64(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putPopPasswordBase64(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_popPasswordBase64(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getPopSsl(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putPopSsl(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getPopUsername(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putPopUsername(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_popUsername(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getPreferIpv6(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putPreferIpv6(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC int CkMailMan_getReadTimeout(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putReadTimeout(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getRequireSslCertVerify(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putRequireSslCertVerify(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getResetDateOnLoad(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putResetDateOnLoad(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC int CkMailMan_getSendBufferSize(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSendBufferSize(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getSendIndividual(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSendIndividual(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC int CkMailMan_getSizeLimit(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSizeLimit(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSmtpAuthMethod(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSmtpAuthMethod(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_smtpAuthMethod(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSmtpFailReason(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_smtpFailReason(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSmtpHost(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSmtpHost(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_smtpHost(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSmtpLoginDomain(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSmtpLoginDomain(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_smtpLoginDomain(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSmtpPassword(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSmtpPassword(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_smtpPassword(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getSmtpPipelining(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSmtpPipelining(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC int CkMailMan_getSmtpPort(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSmtpPort(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSmtpSessionLog(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_smtpSessionLog(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getSmtpSsl(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSmtpSsl(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getSmtpSslServerCertVerified(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSmtpUsername(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSmtpUsername(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_smtpUsername(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSocksHostname(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSocksHostname(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_socksHostname(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSocksPassword(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSocksPassword(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_socksPassword(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_getSocksPort(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSocksPort(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSocksUsername(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSocksUsername(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_socksUsername(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_getSocksVersion(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSocksVersion(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC int CkMailMan_getSoRcvBuf(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSoRcvBuf(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC int CkMailMan_getSoSndBuf(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSoSndBuf(HCkMailMan cHandle, int newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSslAllowedCiphers(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSslAllowedCiphers(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_sslAllowedCiphers(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getSslProtocol(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putSslProtocol(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_sslProtocol(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getStartTLS(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putStartTLS(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getStartTLSifPossible(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putStartTLSifPossible(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getTlsCipherSuite(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_tlsCipherSuite(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getTlsPinSet(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putTlsPinSet(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_tlsPinSet(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getTlsVersion(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_tlsVersion(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_getUncommonOptions(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkMailMan_putUncommonOptions(HCkMailMan cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_uncommonOptions(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getUseApop(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putUseApop(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getUtf8(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putUtf8(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_getVerboseLogging(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_putVerboseLogging(HCkMailMan cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkMailMan_getVersion(HCkMailMan cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_version(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_AddPfxSourceData(HCkMailMan cHandle, HCkByteData pfxData, const char *password);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_AddPfxSourceFile(HCkMailMan cHandle, const char *pfxFilePath, const char *password);
CK_C_VISIBLE_PUBLIC int CkMailMan_CheckMail(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_CheckMailAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_ClearBadEmailAddresses(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_ClearPop3SessionLog(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC void CkMailMan_ClearSmtpSessionLog(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_CloseSmtpConnection(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_CloseSmtpConnectionAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkEmailBundle CkMailMan_CopyMail(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_CopyMailAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_DeleteBundle(HCkMailMan cHandle, HCkEmailBundle emailBundle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_DeleteBundleAsync(HCkMailMan cHandle, HCkEmailBundle emailBundle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_DeleteByMsgnum(HCkMailMan cHandle, int msgnum);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_DeleteByMsgnumAsync(HCkMailMan cHandle, int msgnum);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_DeleteByUidl(HCkMailMan cHandle, const char *uidl);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_DeleteByUidlAsync(HCkMailMan cHandle, const char *uidl);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_DeleteEmail(HCkMailMan cHandle, HCkEmail email);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_DeleteEmailAsync(HCkMailMan cHandle, HCkEmail email);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_DeleteMultiple(HCkMailMan cHandle, HCkStringArray uidlArray);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_DeleteMultipleAsync(HCkMailMan cHandle, HCkStringArray uidlArray);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_FetchByMsgnum(HCkMailMan cHandle, int msgnum);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchByMsgnumAsync(HCkMailMan cHandle, int msgnum);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_FetchEmail(HCkMailMan cHandle, const char *uidl);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchEmailAsync(HCkMailMan cHandle, const char *uidl);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_FetchMime(HCkMailMan cHandle, const char *uidl, HCkByteData outData);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchMimeAsync(HCkMailMan cHandle, const char *uidl);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_FetchMimeBd(HCkMailMan cHandle, const char *uidl, HCkBinData mimeData);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchMimeBdAsync(HCkMailMan cHandle, const char *uidl, HCkBinData mimeData);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_FetchMimeByMsgnum(HCkMailMan cHandle, int msgnum, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchMimeByMsgnumAsync(HCkMailMan cHandle, int msgnum);
CK_C_VISIBLE_PUBLIC HCkEmailBundle CkMailMan_FetchMultiple(HCkMailMan cHandle, HCkStringArray uidlArray);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchMultipleAsync(HCkMailMan cHandle, HCkStringArray uidlArray);
CK_C_VISIBLE_PUBLIC HCkEmailBundle CkMailMan_FetchMultipleHeaders(HCkMailMan cHandle, HCkStringArray uidlArray, int numBodyLines);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchMultipleHeadersAsync(HCkMailMan cHandle, HCkStringArray uidlArray, int numBodyLines);
CK_C_VISIBLE_PUBLIC HCkStringArray CkMailMan_FetchMultipleMime(HCkMailMan cHandle, HCkStringArray uidlArray);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchMultipleMimeAsync(HCkMailMan cHandle, HCkStringArray uidlArray);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_FetchSingleHeader(HCkMailMan cHandle, int numBodyLines, int messageNumber);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchSingleHeaderAsync(HCkMailMan cHandle, int numBodyLines, int messageNumber);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_FetchSingleHeaderByUidl(HCkMailMan cHandle, int numBodyLines, const char *uidl);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_FetchSingleHeaderByUidlAsync(HCkMailMan cHandle, int numBodyLines, const char *uidl);
CK_C_VISIBLE_PUBLIC HCkEmailBundle CkMailMan_GetAllHeaders(HCkMailMan cHandle, int numBodyLines);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_GetAllHeadersAsync(HCkMailMan cHandle, int numBodyLines);
CK_C_VISIBLE_PUBLIC HCkStringArray CkMailMan_GetBadEmailAddrs(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_GetFullEmail(HCkMailMan cHandle, HCkEmail email);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_GetFullEmailAsync(HCkMailMan cHandle, HCkEmail email);
CK_C_VISIBLE_PUBLIC HCkEmailBundle CkMailMan_GetHeaders(HCkMailMan cHandle, int numBodyLines, int fromIndex, int toIndex);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_GetHeadersAsync(HCkMailMan cHandle, int numBodyLines, int fromIndex, int toIndex);
CK_C_VISIBLE_PUBLIC int CkMailMan_GetMailboxCount(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_GetMailboxCountAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_GetMailboxInfoXml(HCkMailMan cHandle, HCkString outXml);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_getMailboxInfoXml(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_GetMailboxInfoXmlAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC unsigned long CkMailMan_GetMailboxSize(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_GetMailboxSizeAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkCert CkMailMan_GetPop3SslServerCert(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkStringArray CkMailMan_GetSentToEmailAddrs(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC int CkMailMan_GetSizeByUidl(HCkMailMan cHandle, const char *uidl);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_GetSizeByUidlAsync(HCkMailMan cHandle, const char *uidl);
CK_C_VISIBLE_PUBLIC HCkCert CkMailMan_GetSmtpSslServerCert(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkStringArray CkMailMan_GetUidls(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_GetUidlsAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_IsSmtpDsnCapable(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_IsSmtpDsnCapableAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_IsUnlocked(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkJsonObject CkMailMan_LastJsonData(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_LoadEml(HCkMailMan cHandle, const char *emlFilename);
CK_C_VISIBLE_PUBLIC HCkEmailBundle CkMailMan_LoadMbx(HCkMailMan cHandle, const char *mbxFileName);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_LoadMime(HCkMailMan cHandle, const char *mimeText);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_LoadQueuedEmail(HCkMailMan cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_LoadTaskCaller(HCkMailMan cHandle, HCkTask task);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_LoadXmlEmail(HCkMailMan cHandle, const char *filename);
CK_C_VISIBLE_PUBLIC HCkEmail CkMailMan_LoadXmlEmailString(HCkMailMan cHandle, const char *xmlString);
CK_C_VISIBLE_PUBLIC HCkEmailBundle CkMailMan_LoadXmlFile(HCkMailMan cHandle, const char *filename);
CK_C_VISIBLE_PUBLIC HCkEmailBundle CkMailMan_LoadXmlString(HCkMailMan cHandle, const char *xmlString);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_MxLookup(HCkMailMan cHandle, const char *emailAddress, HCkString outStrHostname);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_mxLookup(HCkMailMan cHandle, const char *emailAddress);
CK_C_VISIBLE_PUBLIC HCkStringArray CkMailMan_MxLookupAll(HCkMailMan cHandle, const char *emailAddress);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_OpenSmtpConnection(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_OpenSmtpConnectionAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_Pop3Authenticate(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_Pop3AuthenticateAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_Pop3BeginSession(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_Pop3BeginSessionAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_Pop3Connect(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_Pop3ConnectAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_Pop3EndSession(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_Pop3EndSessionAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_Pop3EndSessionNoQuit(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_Pop3EndSessionNoQuitAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_Pop3Noop(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_Pop3NoopAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_Pop3Reset(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_Pop3ResetAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_Pop3SendRawCommand(HCkMailMan cHandle, const char *command, const char *charset, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_pop3SendRawCommand(HCkMailMan cHandle, const char *command, const char *charset);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_Pop3SendRawCommandAsync(HCkMailMan cHandle, const char *command, const char *charset);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_QuickSend(HCkMailMan cHandle, const char *fromAddr, const char *toAddr, const char *subject, const char *body, const char *smtpServer);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_QuickSendAsync(HCkMailMan cHandle, const char *fromAddr, const char *toAddr, const char *subject, const char *body, const char *smtpServer);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_RenderToMime(HCkMailMan cHandle, HCkEmail email, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_renderToMime(HCkMailMan cHandle, HCkEmail email);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_RenderToMimeBd(HCkMailMan cHandle, HCkEmail email, HCkBinData renderedMime);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_RenderToMimeBytes(HCkMailMan cHandle, HCkEmail email, HCkByteData outBytes);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_RenderToMimeSb(HCkMailMan cHandle, HCkEmail email, HCkStringBuilder renderedMime);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SaveLastError(HCkMailMan cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendBundle(HCkMailMan cHandle, HCkEmailBundle bundle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SendBundleAsync(HCkMailMan cHandle, HCkEmailBundle bundle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendEmail(HCkMailMan cHandle, HCkEmail email);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SendEmailAsync(HCkMailMan cHandle, HCkEmail email);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendMime(HCkMailMan cHandle, const char *fromAddr, const char *recipients, const char *mimeSource);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SendMimeAsync(HCkMailMan cHandle, const char *fromAddr, const char *recipients, const char *mimeSource);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendMimeBd(HCkMailMan cHandle, const char *fromAddr, const char *recipients, HCkBinData mimeData);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SendMimeBdAsync(HCkMailMan cHandle, const char *fromAddr, const char *recipients, HCkBinData mimeData);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendMimeBytes(HCkMailMan cHandle, const char *fromAddr, const char *recipients, HCkByteData mimeSource);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SendMimeBytesAsync(HCkMailMan cHandle, const char *fromAddr, const char *recipients, HCkByteData mimeSource);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendMimeBytesQ(HCkMailMan cHandle, const char *from, const char *recipients, HCkByteData mimeData);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendMimeQ(HCkMailMan cHandle, const char *fromAddr, const char *recipients, const char *mimeSource);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendMimeToList(HCkMailMan cHandle, const char *fromAddr, const char *distListFilename, const char *mimeSource);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SendMimeToListAsync(HCkMailMan cHandle, const char *fromAddr, const char *distListFilename, const char *mimeSource);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendQ(HCkMailMan cHandle, HCkEmail email);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendQ2(HCkMailMan cHandle, HCkEmail email, const char *queueDir);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SendToDistributionList(HCkMailMan cHandle, HCkEmail emailObj, HCkStringArray recipientList);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SendToDistributionListAsync(HCkMailMan cHandle, HCkEmail emailObj, HCkStringArray recipientList);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SetDecryptCert(HCkMailMan cHandle, HCkCert cert);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SetDecryptCert2(HCkMailMan cHandle, HCkCert cert, HCkPrivateKey privateKey);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SetPassword(HCkMailMan cHandle, const char *protocol, HCkSecureString password);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SetSslClientCert(HCkMailMan cHandle, HCkCert cert);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SetSslClientCertPem(HCkMailMan cHandle, const char *pemDataOrFilename, const char *pemPassword);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SetSslClientCertPfx(HCkMailMan cHandle, const char *pfxFilename, const char *pfxPassword);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SmtpAuthenticate(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SmtpAuthenticateAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SmtpConnect(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SmtpConnectAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SmtpNoop(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SmtpNoopAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SmtpReset(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SmtpResetAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SmtpSendRawCommand(HCkMailMan cHandle, const char *command, const char *charset, BOOL bEncodeBase64, HCkString outStr);
CK_C_VISIBLE_PUBLIC const char *CkMailMan_smtpSendRawCommand(HCkMailMan cHandle, const char *command, const char *charset, BOOL bEncodeBase64);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SmtpSendRawCommandAsync(HCkMailMan cHandle, const char *command, const char *charset, BOOL bEncodeBase64);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SshAuthenticatePk(HCkMailMan cHandle, const char *sshLogin, HCkSshKey sshUsername);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SshAuthenticatePkAsync(HCkMailMan cHandle, const char *sshLogin, HCkSshKey sshUsername);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SshAuthenticatePw(HCkMailMan cHandle, const char *sshLogin, const char *sshPassword);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SshAuthenticatePwAsync(HCkMailMan cHandle, const char *sshLogin, const char *sshPassword);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SshCloseTunnel(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SshCloseTunnelAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_SshOpenTunnel(HCkMailMan cHandle, const char *sshHostname, int sshPort);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_SshOpenTunnelAsync(HCkMailMan cHandle, const char *sshHostname, int sshPort);
CK_C_VISIBLE_PUBLIC HCkEmailBundle CkMailMan_TransferMail(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_TransferMailAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkStringArray CkMailMan_TransferMultipleMime(HCkMailMan cHandle, HCkStringArray uidlArray);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_TransferMultipleMimeAsync(HCkMailMan cHandle, HCkStringArray uidlArray);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_UnlockComponent(HCkMailMan cHandle, const char *code);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_UseCertVault(HCkMailMan cHandle, HCkXmlCertVault vault);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_UseSsh(HCkMailMan cHandle, HCkSsh ssh);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_UseSshTunnel(HCkMailMan cHandle, HCkSocket tunnel);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_VerifyPopConnection(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_VerifyPopConnectionAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_VerifyPopLogin(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_VerifyPopLoginAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_VerifyRecips(HCkMailMan cHandle, HCkEmail email, HCkStringArray badAddrs);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_VerifyRecipsAsync(HCkMailMan cHandle, HCkEmail email, HCkStringArray badAddrs);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_VerifySmtpConnection(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_VerifySmtpConnectionAsync(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkMailMan_VerifySmtpLogin(HCkMailMan cHandle);
CK_C_VISIBLE_PUBLIC HCkTask CkMailMan_VerifySmtpLoginAsync(HCkMailMan cHandle);
#endif
