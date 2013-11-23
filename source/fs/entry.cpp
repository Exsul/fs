#include "dokan_proxy.h"

namespace
{
  dokan_proxy &ExtractProxy(const PDOKAN_FILE_INFO info)
  {
    throw_assert(info);
    const PDOKAN_OPTIONS opt = info->DokanOptions;
    throw_assert(opt);
    const ULONG64 obj = opt->GlobalContext;
    throw_assert(obj);
    dokan_proxy *const ret = reinterpret_cast<dokan_proxy *>(obj);
    throw_assert(ret); // unnesesary
    return *ret;
  }
};

int DOKAN_CALLBACK _CreateFile (
    LPCWSTR filename,      // FileName
    DWORD access,        // DesiredAccess
    DWORD share,        // ShareMode
    DWORD pos,        // CreationDisposition
    DWORD flags,        // FlagsAndAttributes
    PDOKAN_FILE_INFO info )
{
  return ExtractProxy(info).CreateFile(filename, access, share, pos, flags, *info);
}

int DOKAN_CALLBACK _OpenDirectory (
  LPCWSTR filename,        // FileName
  PDOKAN_FILE_INFO info)
{
  return ExtractProxy(info).OpenDirectory(filename, *info);
}

int (DOKAN_CALLBACK _CreateDirectory) (
  LPCWSTR,        // FileName
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}

// When FileInfo->DeleteOnClose is true, you must delete the file in Cleanup.
int (DOKAN_CALLBACK _Cleanup) (
  LPCWSTR name,      // FileName
  PDOKAN_FILE_INFO info)
{
  return ExtractProxy(info).Cleanup(name, *info);
}

int (DOKAN_CALLBACK _CloseFile) (
  LPCWSTR name,      // FileName
  PDOKAN_FILE_INFO info )
{
  return ExtractProxy(info).CloseFile(name, *info);
}

int (DOKAN_CALLBACK _ReadFile) (
  LPCWSTR,  // FileName
  LPVOID,   // Buffer
  DWORD,    // NumberOfBytesToRead
  LPDWORD,  // NumberOfBytesRead
  LONGLONG, // Offset
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}

int (DOKAN_CALLBACK _WriteFile) (
  LPCWSTR,  // FileName
  LPCVOID,  // Buffer
  DWORD,    // NumberOfBytesToWrite
  LPDWORD,  // NumberOfBytesWritten
  LONGLONG, // Offset
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


int (DOKAN_CALLBACK _FlushFileBuffers) (
  LPCWSTR, // FileName
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


int (DOKAN_CALLBACK _GetFileInformation) (
  LPCWSTR name,          // FileName
  LPBY_HANDLE_FILE_INFORMATION buffer, // Buffer
  PDOKAN_FILE_INFO info)
{
  return ExtractProxy(info).GetFileInformation(name, buffer, *info);
}

int (DOKAN_CALLBACK _FindFiles) (
  LPCWSTR name,      // PathName
  PFillFindData data,    // call this function with PWIN32_FIND_DATAW
  PDOKAN_FILE_INFO info )  //  (see PFillFindData definition)
{
  return ExtractProxy(info).FindFiles(name, data, *info);
}


// You should implement either FindFiles or FindFilesWithPattern
int (DOKAN_CALLBACK _FindFilesWithPattern) (
  LPCWSTR,      // PathName
  LPCWSTR,      // SearchPattern
  PFillFindData,    // call this function with PWIN32_FIND_DATAW
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


int (DOKAN_CALLBACK _SetFileAttributes) (
  LPCWSTR, // FileName
  DWORD,   // FileAttributes
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


int (DOKAN_CALLBACK _SetFileTime) (
  LPCWSTR,    // FileName
  CONST FILETIME*, // CreationTime
  CONST FILETIME*, // LastAccessTime
  CONST FILETIME*, // LastWriteTime
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


// You should not delete file on DeleteFile or DeleteDirectory.
// When DeleteFile or DeleteDirectory, you must check whether
// you can delete the file or not, and return 0 (when you can delete it)
// or appropriate error codes such as -ERROR_DIR_NOT_EMPTY,
// -ERROR_SHARING_VIOLATION.
// When you return 0 (ERROR_SUCCESS), you get Cleanup with
// FileInfo->DeleteOnClose set TRUE and you have to delete the
// file in Close.
int (DOKAN_CALLBACK _DeleteFile) (
  LPCWSTR, // FileName
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}

int (DOKAN_CALLBACK _DeleteDirectory) ( 
  LPCWSTR, // FileName
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


int (DOKAN_CALLBACK _MoveFile) (
  LPCWSTR, // ExistingFileName
  LPCWSTR, // NewFileName
  BOOL,  // ReplaceExisiting
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


int (DOKAN_CALLBACK _SetEndOfFile) (
  LPCWSTR,  // FileName
  LONGLONG, // Length
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


int (DOKAN_CALLBACK _SetAllocationSize) (
  LPCWSTR,  // FileName
  LONGLONG, // Length
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


int (DOKAN_CALLBACK _LockFile) (
  LPCWSTR, // FileName
  LONGLONG, // ByteOffset
  LONGLONG, // Length
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


int (DOKAN_CALLBACK _UnlockFile) (
  LPCWSTR, // FileName
  LONGLONG,// ByteOffset
  LONGLONG,// Length
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


// Neither GetDiskFreeSpace nor GetVolumeInformation
// save the DokanFileContext->Context.
// Before these methods are called, CreateFile may not be called.
// (ditto CloseFile and Cleanup)

// see Win32 API GetDiskFreeSpaceEx
int (DOKAN_CALLBACK _GetDiskFreeSpace) (
  PULONGLONG, // FreeBytesAvailable
  PULONGLONG, // TotalNumberOfBytes
  PULONGLONG, // TotalNumberOfFreeBytes
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


// see Win32 API GetVolumeInformation
int (DOKAN_CALLBACK _GetVolumeInformation) (
  LPWSTR name, // VolumeNameBuffer
  DWORD cname,  // VolumeNameSize in num of chars
  LPDWORD serial,// VolumeSerialNumber
  LPDWORD component,// MaximumComponentLength in num of chars
  LPDWORD flags,// FileSystemFlags
  LPWSTR fsb,  // FileSystemNameBuffer
  DWORD cfsb,  // FileSystemNameSize in num of chars
  PDOKAN_FILE_INFO info)
{
  WCHAR *t = new WCHAR[cname + 1];
  memcpy(t, name, cname);
  t[cname] = 0;
  std::wstring str_name = t;
  delete []t;
  t = new WCHAR[cfsb + 1];
  memcpy(t, fsb, cfsb);
  t[cfsb] = 0;
  std::wstring str_sfb = t;
  delete []t;

  return ExtractProxy(info).GetVolumeInformation(str_name, *serial, *component, *flags, str_sfb, *info);
}


int (DOKAN_CALLBACK _Unmount) (
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}


// Suported since 0.6.0. You must specify the version at DOKAN_OPTIONS.Version.
int (DOKAN_CALLBACK _GetFileSecurity) (
  LPCWSTR, // FileName
  PSECURITY_INFORMATION, // A pointer to SECURITY_INFORMATION value being requested
  PSECURITY_DESCRIPTOR, // A pointer to SECURITY_DESCRIPTOR buffer to be filled
  ULONG, // length of Security descriptor buffer
  PULONG, // LengthNeeded
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}

int (DOKAN_CALLBACK _SetFileSecurity) (
  LPCWSTR, // FileName
  PSECURITY_INFORMATION,
  PSECURITY_DESCRIPTOR, // SecurityDescriptor
  ULONG, // SecurityDescriptor length
  PDOKAN_FILE_INFO)
{
  return ERROR_NOT_READY * -1;
}

void InitMethods( PDOKAN_OPERATIONS oper )
{
  oper->CreateFile = _CreateFile;
  oper->OpenDirectory = _OpenDirectory;
  oper->CreateDirectory = _CreateDirectory;
  oper->Cleanup = _Cleanup;
  oper->CloseFile = _CloseFile;
  oper->ReadFile = _ReadFile;
  oper->WriteFile = _WriteFile;
  oper->FlushFileBuffers = _FlushFileBuffers;
  oper->GetFileInformation = _GetFileInformation;
  oper->FindFiles = _FindFiles;
  oper->FindFilesWithPattern = NULL;
  oper->SetFileAttributes = _SetFileAttributes;
  oper->SetFileTime = _SetFileTime;
  oper->DeleteFile = _DeleteFile;
  oper->DeleteDirectory = _DeleteDirectory;
  oper->MoveFile = _MoveFile;
  oper->SetEndOfFile = _SetEndOfFile;
  oper->SetAllocationSize = _SetAllocationSize;	
  oper->LockFile = _LockFile;
  oper->UnlockFile = _UnlockFile;
  oper->GetFileSecurity = _GetFileSecurity;
  oper->SetFileSecurity = _SetFileSecurity;
  oper->GetDiskFreeSpace = NULL;
  oper->GetVolumeInformation = _GetVolumeInformation;
  oper->Unmount = _Unmount;
}