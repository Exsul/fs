#include "dokan/dokan.h"
#include "dokan/dokan_proxy.h"

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
  return -1 * ExtractProxy(info).CreateFile(filename, access, share, pos, flags, *info);
}

int DOKAN_CALLBACK _OpenDirectory (
  LPCWSTR filename,        // FileName
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).OpenDirectory(filename, *info);
}

int (DOKAN_CALLBACK _CreateDirectory) (
  LPCWSTR filename,        // FileName
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).CreateDirectory(filename, *info);
}

// When FileInfo->DeleteOnClose is true, you must delete the file in Cleanup.
int (DOKAN_CALLBACK _Cleanup) (
  LPCWSTR name,      // FileName
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).Cleanup(name, *info);
}

int (DOKAN_CALLBACK _CloseFile) (
  LPCWSTR name,      // FileName
  PDOKAN_FILE_INFO info )
{
  return -1 * ExtractProxy(info).CloseFile(name, *info);
}

int (DOKAN_CALLBACK _ReadFile) (
  LPCWSTR file,  // FileName
  LPVOID out,   // Buffer
  DWORD to_read,    // NumberOfBytesToRead
  LPDWORD _readed,  // NumberOfBytesRead
  LONGLONG offset, // Offset
  PDOKAN_FILE_INFO info )
{
  int readed = 0;
  int ret = -1 * ExtractProxy(info).ReadFile(file, (ub *)out, to_read, readed, offset, *info);
  *_readed = readed;
  return ret;
}

int (DOKAN_CALLBACK _WriteFile) (
  LPCWSTR file,  // FileName
  LPCVOID out,  // Buffer
  DWORD to_write,    // NumberOfBytesToWrite
  LPDWORD _writed,  // NumberOfBytesWritten
  LONGLONG offset, // Offset
  PDOKAN_FILE_INFO info)
{
  int writed = 0;
  int ret = -1 * ExtractProxy(info).WriteFile(file, (const ub *)out, to_write, writed, offset, *info);
  *_writed = writed;
  return ret;
}


int (DOKAN_CALLBACK _FlushFileBuffers) (
  LPCWSTR file, // FileName
  PDOKAN_FILE_INFO info )
{
  return -1 * ExtractProxy(info).FlushFileBuffers(file, *info);
}


int (DOKAN_CALLBACK _GetFileInformation) (
  LPCWSTR name,          // FileName
  LPBY_HANDLE_FILE_INFORMATION buffer, // Buffer
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).GetFileInformation(name, *buffer, *info);
}

int (DOKAN_CALLBACK _FindFiles) (
  LPCWSTR name,      // PathName
  PFillFindData data,    // call this function with PWIN32_FIND_DATAW
  PDOKAN_FILE_INFO info )  //  (see PFillFindData definition)
{
  return -1 * ExtractProxy(info).FindFiles(name, data, *info);
}


// You should implement either FindFiles or FindFilesWithPattern
int (DOKAN_CALLBACK _FindFilesWithPattern) (
  LPCWSTR path,      // PathName
  LPCWSTR pattern,      // SearchPattern
  PFillFindData callback,    // call this function with PWIN32_FIND_DATAW
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).FindFilesWithPattern(path, pattern, callback, *info);
}


int (DOKAN_CALLBACK _SetFileAttributes) (
  LPCWSTR name, // FileName
  DWORD attr,   // FileAttributes
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).SetFileAttributes(name, attr, *info);
}


int (DOKAN_CALLBACK _SetFileTime) (
  LPCWSTR file,    // FileName
  CONST FILETIME* create, // CreationTime
  CONST FILETIME* access, // LastAccessTime
  CONST FILETIME* write, // LastWriteTime
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).SetFileTime(file, *create, *access, *write, *info);
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
  LPCWSTR file, // FileName
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).DeleteFile(file, *info);
}

int (DOKAN_CALLBACK _DeleteDirectory) ( 
  LPCWSTR file, // FileName
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).DeleteDirectory(file, *info);
}


int (DOKAN_CALLBACK _MoveFile) (
  LPCWSTR prev, // ExistingFileName
  LPCWSTR next, // NewFileName
  BOOL repl,  // ReplaceExisiting
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).MoveFile(prev, next, repl ? true : false, *info);
}


int (DOKAN_CALLBACK _SetEndOfFile) (
  LPCWSTR file,  // FileName
  LONGLONG length, // Length
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).SetEndOfFile(file, length, *info);
}


int (DOKAN_CALLBACK _SetAllocationSize) (
  LPCWSTR file,  // FileName
  LONGLONG length, // Length
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).SetAllocationSize(file, length, *info);
}


int (DOKAN_CALLBACK _LockFile) (
  LPCWSTR file, // FileName
  LONGLONG offset, // ByteOffset
  LONGLONG length, // Length
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).LockFile(file, offset, length, *info);
}


int (DOKAN_CALLBACK _UnlockFile) (
  LPCWSTR file, // FileName
  LONGLONG offset,// ByteOffset
  LONGLONG length,// Length
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).UnlockFile(file, offset, length, *info);
}


// Neither GetDiskFreeSpace nor GetVolumeInformation
// save the DokanFileContext->Context.
// Before these methods are called, CreateFile may not be called.
// (ditto CloseFile and Cleanup)

// see Win32 API GetDiskFreeSpaceEx
int (DOKAN_CALLBACK _GetDiskFreeSpace) (
  PULONGLONG avaib, // FreeBytesAvailable
  PULONGLONG total, // TotalNumberOfBytes
  PULONGLONG free, // TotalNumberOfFreeBytes
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).GetDiskFreeSpace(*avaib, *total, *free, *info);
}


// see Win32 API GetVolumeInformation
int (DOKAN_CALLBACK _GetVolumeInformation) (
  LPWSTR _name, // VolumeNameBuffer
  DWORD _cname,  // VolumeNameSize in num of chars
  LPDWORD _serial,// VolumeSerialNumber
  LPDWORD _component,// MaximumComponentLength in num of chars
  LPDWORD _flags,// FileSystemFlags
  LPWSTR _fsb,  // FileSystemNameBuffer
  DWORD _cfsb,  // FileSystemNameSize in num of chars
  PDOKAN_FILE_INFO _info)
{
  std::wstring name, fsname;
  word serial, max_filename_length, flags;
  int ret = -1 * ExtractProxy(_info).GetVolumeInformation(name, serial, max_filename_length, flags, fsname, *_info);

  if (_name && _cname >= name.length())
    ax::StrCopy(_name, name.c_str(), _cname);
  if (_fsb && _cfsb >= fsname.length())
    ax::StrCopy(_fsb, fsname.c_str(), _cfsb);

  if (_serial)
    *_serial = serial;
  if (_component)
    *_component = max_filename_length;
  if (_flags)
    *_flags = flags;
  return ret;
}


int (DOKAN_CALLBACK _Unmount) (
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).Unmount(*info);
}


// Suported since 0.6.0. You must specify the version at DOKAN_OPTIONS.Version.
int (DOKAN_CALLBACK _GetFileSecurity) (
  LPCWSTR file, // FileName
  PSECURITY_INFORMATION sec, // A pointer to SECURITY_INFORMATION value being requested
  PSECURITY_DESCRIPTOR desk, // A pointer to SECURITY_DESCRIPTOR buffer to be filled
  ULONG length, // length of Security descriptor buffer
  PULONG need, // LengthNeeded
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).GetFileSecurity(file, sec, desk, length, *need, *info);
}

int (DOKAN_CALLBACK _SetFileSecurity) (
  LPCWSTR file, // FileName
  PSECURITY_INFORMATION sec,
  PSECURITY_DESCRIPTOR desc, // SecurityDescriptor
  ULONG length, // SecurityDescriptor length
  PDOKAN_FILE_INFO info)
{
  return -1 * ExtractProxy(info).SetFileSecurity(file, sec, desc, length, *info);
}