#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	printf("Hello World! From Console! \n");
	//system("pause");
	int iMsgBoxRet;

	while (true) {
		iMsgBoxRet = MessageBox(
			NULL, 
			TEXT("Hello World! From Message Box! "), 
			TEXT("HELLO"), 
			MB_YESNOCANCEL|MB_DEFBUTTON3);

		if (iMsgBoxRet == IDYES) {
			MessageBox(
				NULL, 
				TEXT("You have pressed the YES button! "), 
				TEXT("Press Key information I"), 
				MB_OK|MB_ICONINFORMATION|MB_DEFBUTTON1);
		} else if (iMsgBoxRet == IDNO) {
			MessageBox(
				NULL, 
				TEXT("You have pressed the NO button! "), 
				TEXT("Press Key information II"), 
				MB_OK|MB_ICONINFORMATION|MB_DEFBUTTON1);
		} else if (iMsgBoxRet == IDCANCEL) {
			MessageBox(
				NULL, 
				TEXT("You have pressed the CANCEL button! "), 
				TEXT("Press Key information III"), 
				MB_OK|MB_ICONINFORMATION|MB_DEFBUTTON1);
			break;
		} else {
			break;
		}
	}
	

	return 0;
}