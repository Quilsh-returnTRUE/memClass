#include "mem.hpp"

// get process id
uintptr_t mem::get_proc_id(const wchar_t* processName)
{
    HANDLE procHandle;
    procHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    PROCESSENTRY32 process;
    process.dwSize = sizeof(PROCESSENTRY32);

    Process32First(procHandle, &process);

    do
    {
        if (!wcscmp(processName, process.szExeFile))
        {
            CloseHandle(procHandle);
            procID = process.th32ProcessID;
            pHandle = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);
            return process.th32ProcessID;
        }
    } while (Process32Next(procHandle, &process));

    CloseHandle(procHandle);
    return 0;
}

// get mod base
uintptr_t mem::get_module_base(uintptr_t procID, const wchar_t* module_name)
{
    HANDLE procHandle;
    procHandle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procID);

    MODULEENTRY32 m;
    m.dwSize = sizeof(MODULEENTRY32);
    Module32First(procHandle, &m);

    do
    {
        if (!wcscmp(module_name, m.szModule))
        {
            CloseHandle(procHandle);
            return (uintptr_t)m.modBaseAddr;
        }
    } while (Module32Next(procHandle, &m));
    CloseHandle(procHandle);
    return 0;
}




