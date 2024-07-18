
#pragma once

#include <Windows.h>
#include <TlHelp32.h>

namespace mem
{
    inline HANDLE pHandle;
    inline uintptr_t procID;

    uintptr_t get_proc_id(const wchar_t* processName);   // ex: cs2.exe
    uintptr_t get_module_base(uintptr_t processID, const wchar_t* module);   // ex: client.dll | engine.dll


    template <typename R> R ReadMem(uintptr_t address)
    {
        R mit;
        ReadProcessMemory(pHandle, (LPCVOID)address, &mit, sizeof(R), nullptr);
        return mit;
    }


    template <typename R> bool WriteToMem(uintptr_t address, R value)
    {
        return WriteProcessMemory(pHandle, (LPVOID)address, &value, sizeof(R), nullptr);
    }

}
