
#pragma once

#include <Windows.h>
#include <TlHelp32.h>

namespace mem
{

  uintptr_t get_proc_id(const wchar_t* processName);   // ex: cs2.exe
  uintptr_t get_module_base(uintptr_t processID, const wchar_t* module);   // ex: client.dll | engine.dll

  template <typename R> R Read(uintptr_t address);
  template <typename R> bool Write(uintptr_taddress, R value);

}
