
#include<windows.h>
#include"ClassFactoryDllServerWitRegFile.h"

// global function decleration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declerations
ISum* pISum = NULL;
ISubtract* pISubtract = NULL;

// WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// variable declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("ComClient");
	HRESULT hr;

	// code
	// COM initialization
	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library cannot be initialized. \n Program will now exit."), TEXT("Program Error"), MB_OK);
		exit(0);
	}

	// WndclassEx initilization
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hInstance = hInstance;
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// Register windows class
	RegisterClassEx(&wndclass);

	// Create window
	hwnd = CreateWindow(AppName,
		TEXT("Client of COM DLL Server"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// COM Un-initialized
	CoUninitialize();
	return ((int)msg.wParam);
}

// Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Funciton declaration
	void SafeInterfaceRelease(void);

	// variable delaration
	HRESULT hr;
	int iNum1, iNum2, iSum;
	TCHAR str[255];

	// code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void**)&pISum);			// hidden code of CoCreateInstance at the end of this file

		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("ISum interface Can not be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		// Initialize arguments hardcoded
		iNum1 = 55;
		iNum2 = 45;

		// call SumOfTwoIntegers() if ISum to get the sum
		pISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);

		// Display the result
		wsprintf(str, TEXT("Sum of %d And %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		//Call QueryInterface on ISum to get ISubtract's pointer
		hr = pISum->QueryInterface(IID_ISubtract, (void**)&pISubtract);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("ISubtract interface Can not be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		// ISum is not needed onwards, release it
		pISum->Release();
		pISum = NULL; // Make released interface NULL

		// again intitialize arguments hardcoded
		iNum1 = 155;
		iNum2 = 145;

		// again call SumOfTwoIntegers() of ISum to get the new sum
		pISubtract->SubtractionOfTwoIntegers(iNum1, iNum2, &iSum);

		// as ISum is not needed onwordsm realease it
		pISubtract->Release();
		pISubtract = NULL; // make released inteface NULL

		// display the result

		wsprintf(str, TEXT("Subtraction of %d And %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void SafeInterfaceRelease(void)
{
	// code
	if (pISum)
	{
		pISum->Release();
		pISum = NULL;
	}
	if (pISubtract)
	{
		pISubtract->Release();
		pISubtract = NULL;
	}
}


/*
Pseudo code for CoCreateInstance Microsoft has not exposed this but one can find this in Kraig broxshmitt. This is a pseudo code and might not be same as real one
							( CLSID_SumSubtract  )      (NULL)        (CLCTX_InProc_Server)  (IID_ISum)   (pISum)
									     |				  |						|				  |			 |
HRESULT	__stdcall CoCreateInstance(REFCLSID rClsid, IUNKNOWN *pUnkOuter, DWORD dwClsContext, REFIID iid ,VOID **ppv)
{
	// Variable decleration
	IClassFactory *pIClassFactory = NULL;
	HRESULT hr;

	// Code
	hr = CoGetClassObject(rClsid, dwClsContext, NULL, IID_IClassFactory, (void **)&pIClassFactory);
	if(SUCCESED(hr))
	{
		pIClassFactory->CreateInstance(pUnkOuter, riid, ppv);
		pIClassFactory->Release();
	}
	return(hr);
}

*/