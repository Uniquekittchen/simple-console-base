#include "Console.hpp"

BOOL WINAPI Initialize(HINSTANCE h_Module)
{
	Console->Start_Attaching();
	Console->Log_Color("Example", e_Colors::Red);
	Console->Log_Color("Example White", e_Colors::White);
	Console->Stop_Attaching();

	FreeLibraryAndExitThread(h_Module, EXIT_SUCCESS);
}

BOOL WINAPI DllMain(HINSTANCE h_Module, DWORD dw_Reason, LPVOID lp_Reserved)
{
	if (dw_Reason == DLL_PROCESS_ATTACH)
	{
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Initialize, h_Module, NULL, nullptr);
	}
	return TRUE;
}
