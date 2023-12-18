// CkKeyContainer.h: interface for the CkKeyContainer class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.96

#define _CkVersion 9.5.0.96

#ifndef _CkKeyContainer_H
#define _CkKeyContainer_H
	
#include "chilkatDefs.h"
// This is a Windows-only class.  On non-Windows systems, the methods do nothing...
#include "CkString.h"
#include "CkMultiByteBase.h"

class CkPrivateKey;
class CkJsonObject;
class CkPublicKey;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif


#undef Copy

// CLASS: CkKeyContainer
class CK_VISIBLE_PUBLIC CkKeyContainer  : public CkMultiByteBase
{
    private:

	// Don't allow assignment or copying these objects.
	CkKeyContainer(const CkKeyContainer &);
	CkKeyContainer &operator=(const CkKeyContainer &);

    public:
	CkKeyContainer(void);
	virtual ~CkKeyContainer(void);

	static CkKeyContainer *createNew(void);
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	
		
	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The name of the currently open key container.
	void get_ContainerName(CkString &str);
	// The name of the currently open key container.
	const char *containerName(void);

	// true if the currently open key container is from the machine keyset, otherwise
	// false.
	bool get_IsMachineKeyset(void);

	// true if the object currently has a key container open, otherwise false.
	bool get_IsOpen(void);

	// If the storage provider is one for the legacy CryptoAPI, then this property
	// indicate whether to work with AT_KEYEXCHANGE or AT_SIGNATURE. Possible values
	// for this property are:
	//     1 - AT_KEYEXCHANGE
	//     2 - AT_SIGNATURE
	// 
	// The default value of this property is 1.
	// 
	int get_LegacyKeySpec(void);
	// If the storage provider is one for the legacy CryptoAPI, then this property
	// indicate whether to work with AT_KEYEXCHANGE or AT_SIGNATURE. Possible values
	// for this property are:
	//     1 - AT_KEYEXCHANGE
	//     2 - AT_SIGNATURE
	// 
	// The default value of this property is 1.
	// 
	void put_LegacyKeySpec(int newVal);

	// If true, work with keys for the local computer. If false, work with keys for
	// the current user. The default value is false.
	bool get_MachineKeys(void);
	// If true, work with keys for the local computer. If false, work with keys for
	// the current user. The default value is false.
	void put_MachineKeys(bool newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Closes the currently opened key container (if this object has one opened).
	void CloseContainer(void);


	// Creates a new key container with a given name in the machine or user keyset. If
	// a key container having the same name already exists, it is opened.
	bool CreateContainer(const char *name, bool machineKeyset);


	// Deletes a key container with a given name in the machine or user keyset.
	bool DeleteContainer(void);


	// Deletes a key from the storageProvider.
	bool DeleteKey(const char *keyName, const char *storageProvider);


	// Exports a key into key. If silentFlag is true, requests that the key service
	// provider (KSP) not display any user interface. If the provider must display the
	// UI to operate, the call fails
	bool ExportKey(const char *keyName, const char *storageProvider, bool silentFlag, CkPrivateKey &key);


	// Fetches the container names for the machine or user keyset. After this method
	// has been called successfully, the GetNumContainers method can be called to get
	// the number of key containers in the given keyset, and the GetContainerName
	// method can be called to retrieve each key container's name by index.
	bool FetchContainerNames(bool bMachineKeyset);


	// Generates a new key pair in the currently open key container. Each key container
	// can contain two public/private key pairs: one for key exchange, and one for
	// signature creation. The 1st argument determines which key pair is generated. A
	// value of true causes a new key-exchange key pair to be generated, a value of
	// false causes a new signature key pair to be generated. The size of the key (in
	// bits) can range from 384 to 16384, with a typical value being 1024 or 2048 bits.
	bool GenerateKeyPair(bool bKeyExchangePair, int keyLengthInBits);


	// This method is provided as a convenient way of generating unique key container
	// names. There are no set rules for naming key containers. However, if your
	// application is to generate a large number of keys, using a UUID for the key
	// container name is wise to ensure uniqueness.
	bool GenerateUuid(CkString &outGuid);

	// This method is provided as a convenient way of generating unique key container
	// names. There are no set rules for naming key containers. However, if your
	// application is to generate a large number of keys, using a UUID for the key
	// container name is wise to ensure uniqueness.
	const char *generateUuid(void);

	// Loads json with a list of keys found in the given storageProvider.
	bool GetKeys(const char *storageProvider, CkJsonObject &json);


	// Returns the Nth key container name. The FetchContainerNames method must have
	// been previously called with the same keyset (machine or user). The index ranges
	// from 0 to GetNumContainers() - 1.
	bool GetNthContainerName(bool bMachineKeyset, int index, CkString &outName);

	// Returns the Nth key container name. The FetchContainerNames method must have
	// been previously called with the same keyset (machine or user). The index ranges
	// from 0 to GetNumContainers() - 1.
	const char *getNthContainerName(bool bMachineKeyset, int index);
	// Returns the Nth key container name. The FetchContainerNames method must have
	// been previously called with the same keyset (machine or user). The index ranges
	// from 0 to GetNumContainers() - 1.
	const char *nthContainerName(bool bMachineKeyset, int index);


	// Returns the number of key containers in existence for the given keyset (machine
	// or user). The FetchContainerNames method must have been previously called with
	// the same keyset (machine or user).
	int GetNumContainers(bool bMachineKeyset);


	// A key container can hold two public/private key pairs -- a key-exchange pair and
	// a signature pair. This method returns the private key for one of the key pairs.
	// Passing a true returns the key-exchange pair, passing false returns the
	// signature pair. A null reference is returned on failure.
	// The caller is responsible for deleting the object returned by this method.
	CkPrivateKey *GetPrivateKey(bool bKeyExchangePair);


	// A key container can hold two public/private key pairs -- a key-exchange pair and
	// a signature pair. This method returns the public key for one of the key pairs.
	// Passing a true returns the key-exchange pair, passing false returns the
	// signature pair. A null reference is returned on failure.
	// The caller is responsible for deleting the object returned by this method.
	CkPublicKey *GetPublicKey(bool bKeyExchangePair);


	// Loads json with a list of storage providers on the Windows system.
	// 
	// The json will contain JSON such as this:{
	//   "cng": [
	//     "Microsoft Software Key Storage Provider",
	//     "Microsoft Passport Key Storage Provider",
	//     "Microsoft Platform Crypto Provider",
	//     "Microsoft Smart Card Key Storage Provider"
	//   ],
	//   "legacy": [
	//     "Microsoft Base Cryptographic Provider v1.0",
	//     "Microsoft Base DSS and Diffie-Hellman Cryptographic Provider",
	//     "Microsoft Base DSS Cryptographic Provider",
	//     "Microsoft Base Smart Card Crypto Provider",
	//     "Microsoft DH SChannel Cryptographic Provider",
	//     "Microsoft Enhanced Cryptographic Provider v1.0",
	//     "Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider",
	//     "Microsoft Enhanced RSA and AES Cryptographic Provider",
	//     "Microsoft RSA SChannel Cryptographic Provider",
	//     "Microsoft Strong Cryptographic Provider"
	//   ]
	// }
	// 
	bool GetStorageProviders(CkJsonObject &json);


	// Imports a new key into the storageProvider. If allowOverwrite is true, if a key already exists in
	// the container with the specified name, the existing key will be overwritten. If
	// allowOverwrite is false and the key already exists, then the method fails. If allowExport is
	// true, then the key is marked as exportable, which allows for it to be
	// re-exported to a PFX.
	bool ImportKey(const char *keyName, const char *storageProvider, bool allowOverwrite, bool allowExport, CkPrivateKey &key);


	// Imports a private key into the key container. The 1st argument is the private
	// key to be imported, and the 2nd argument determines if the key-exchange private
	// key (true) or signature private key (false) is replaced. Note: A private key
	// actually contains the key material for both the public and private key. When you
	// have a private key, you effectively have both the public and private key of a
	// key pair.
	bool ImportPrivateKey(CkPrivateKey &key, bool bKeyExchangePair);


	// Imports a public key into the key container. The 1st argument is the public key
	// to be imported, and the 2nd argument determines if the key-exchange public key
	// (true) or signature public key (false) is replaced.
	bool ImportPublicKey(CkPublicKey &key, bool bKeyExchangePair);


	// Opens an existing key container in either the machine or user keyset.
	bool OpenContainer(const char *name, bool needPrivateKeyAccess, bool machineKeyset);






	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
