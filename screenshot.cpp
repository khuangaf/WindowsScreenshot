#include <cstdlib>
#include <cstddef>
#include <windows.h>
#include <string>
#include <iostream>
#define MOD_NOREPEAT    0x4000
#define MOD_ALT         0x0001
using namespace std;

void shortCut(int argc, TCHAR *argv[]);
int main(int argc, TCHAR *argv[])
{
	while(1)

	shortCut(0, (TCHAR **)'a');
	return 0;
}


void shortCut(int argc, TCHAR *argv[])
{
	if (RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, 0x58)) //0x58 is 'x'
	{
		std::cout << "Please hide this window and press ALT+x to screenshot\n";
	}

	MSG msg = { 0 };
	if ((GetMessage(&msg, NULL, 0, 0) != 0))
	{
		if (msg.message == WM_HOTKEY)
		{
			char path[] = "C:\\Windows\\System32\\SnippingTool.exe";
			system(path);
			std::cout << "WM_HOTKEY received\n";
		}
	}


}
