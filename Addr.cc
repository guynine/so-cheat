#include "Addr.hh"
#include "common/process.h"
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
static  DBVM dbvm;
const Process* g_proc;
//const CR3 UserCR3 = dbvm.GetCR3();
//const CR3 KrnlCR3 = [&] {
//	const uintptr_t GsBase = dbvm.ReadMSR(IA32_KERNEL_GS_BASE_MSR);
//	//The process is not kva-shadowed.
//	if (dbvm.GetPhysicalAddress(GsBase, UserCR3))
//		return UserCR3;
//
//	error("KVA-SHADOWED"e);
//
//	CR3 cr3 = 0;
//	//Finding KernelDirectoryBase...
//	for (size_t Offset = 0x1000; Offset < 0x10000 &&
//		!dbvm.RPM(GsBase + Offset, &cr3, sizeof(cr3), UserCR3); Offset += 0x1000);
//
//	verify(cr3);
//	return cr3;
//}();
constexpr auto pass1 = 0xfafafa;
constexpr auto pass2= 0xDedafafa;
constexpr auto pass3 = 0xfffefafa;

__int64  RtlDecodePointer_ex(__int64 encpointer, unsigned int ntdllcookie)
{
	return _rotr64(encpointer, '@' - (ntdllcookie & 0x3F)) ^ ntdllcookie;
}
__int64  RtlEncodePointer_ex(__int64 pointer, unsigned int ntdllcookie)
{
	return _rotr64(pointer ^ ntdllcookie, ntdllcookie & 0x3F);
}

int game::ReaderInit()
{
	if (!dbvm.GetVersion())
	{
		dbvm.SetPassword(pass1, pass2, pass3);

			if (!dbvm.GetVersion())
			{
				return false;
			}
	}
	else
	{
		dbvm.ChangePassword(pass1, pass2, pass3);
	}
	auto passtest = dbvm.GetMemory();
	//printf("%x\n", passtest);





	auto pd = GetPIDByProcessName("sogame.exe"e);
	if (!pd) {
		error("Can't find the game. Please open game from EAC_off.exe"e); //  replcae with std::exeption?
		exit(1);
	}

	static  Kernel processkrnl(dbvm);
	static const auto proc = Process(processkrnl, pd, 0);
	g_proc = &proc;
	game::Base = g_proc->GetBaseAddress();
	if (!game::Base)
		error("Error"e);
		

	

auto chain69 = g_proc->ScanCurrentModule("48 8B ? ? ? ? ? 48 8B ? ? E8 ? ? ? ? 48 8B ? 48 8B ? E8"e); // replace this with pattern scan from file instead reading .text section  from process memory
if (!chain69)
error("[Please activate DBVM]"e); // 

// umbra.dll  48 8B ? ? ? ? ? 48 8B ? ? E8 ? ? ? ? 48 8B ? 48 8B ? E8;
game::g_entitymanager = chain69 + read<int>(chain69 + 3i64) + 7i64;
game::umbra_camera = 0x180098220;
//processkrnl.GetKernelCR3(4);
//printf("Cheat Activated in the game 0x%llx \n", (unsigned long long )game::g_entitymanager);
printf("\n\nCheat activated. To show menu join to world.");

//48 8B 05 ? ? ? ? 4C 8B 50 28
// 48 8B ? ? ? ? ? 48 8B ? ? E8 ? ? ? ? 48 8B ? 48 8B ? E8


return pd;
}


bool read(unsigned long long address, void* buffer, unsigned long long size) {
	return   g_proc->ReadProcessMemory(address, buffer, size);
}

bool writem(unsigned long long address, void* buffer, unsigned long long size) {
	return   g_proc->WriteProcessMemory(address, buffer, size);
}


