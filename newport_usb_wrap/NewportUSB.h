#pragma once
#include "NewpDll.h"
#include <string>
#include <vector>
#include <map>

//#if COMPILING_DLL
//#define DLLEXPORT __declspec(dllexport)
//#else
//#define DLLEXPORT __declspec(dllimport)
//#endif

#define DLLEXPORT

// This class interfaces with UsbDll.dll and provides the basic
// functionality for USB communication.
class DLLEXPORT NewportUSB
{
public:
	NewportUSB(void);
	~NewportUSB(void);
	
	// This structure contains the information for a single device.
	struct DLLEXPORT DevInfo
	{
		int nID;
		std::string strDescription;
	};

	bool OpenDevices (int nProductID = 0);
	bool OpenDevices (int nProductID, bool bUsingDeviceKey);
	void CloseDevices ();
	int Read (std::string strDeviceKey, char* lpBuffer, int nLength, unsigned long* lBytesRead);
	int Read (int nDeviceID, char* lpBuffer, int nLength, unsigned long* lBytesRead);
	int ReadBinary (std::string strDeviceKey, char* lpBuffer, int nLength, unsigned long* lBytesRead);
	int ReadBinary (int nDeviceID, char* lpBuffer, int nLength, unsigned long* lBytesRead);
	int Write (std::string strDeviceKey, char* lpBuffer);
	int Write (int nDeviceID, char* lpBuffer);
	int Write (std::string strDeviceKey, std::string strBuffer);
	int Write (int nDeviceID, std::string strBuffer);
	void StringToChar (char* lpDest, std::string strSrc);
	std::map <std::string, int> GetDeviceTable ();
	std::vector <DevInfo> GetDevInfoList ();
	void FillDevInfoList (char* lpDevInfo);
	bool CreateDeviceKey (int handle, std::string& strDeviceKey);
	void ParseDeviceKey (char* lpID, std::string& strDeviceKey);

	// The maximum buffer length for a USB I/O transfer.
	const static int m_knMaxBufferLength = 64;

private:
	// The device information list.
	std::vector <DevInfo> m_DevInfoList;
	// The device table.
	std::map <std::string, int> m_mapDeviceTable;
	// The devices open flag.
	bool m_bOpen;
};
