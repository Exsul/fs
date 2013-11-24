#include "entry.h"

void InitMethods(PDOKAN_OPERATIONS oper)
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