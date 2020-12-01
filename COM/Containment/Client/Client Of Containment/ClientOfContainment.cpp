#include<windows.h>
#include<process.h>
#include"HeaderForClientOfContainmentWithRegFile.h"

// Global function declaratin
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void SafeInterfaceRelease(void);

// Global variables
ISum* pISum = NULL;
ISubtract* pISubtract = NULL;
IMultiplication* pIMultiplication = NULL;
IDivision* pIDivision = NULL;

// WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// variable delertions
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG	 msg;
	TCHAR AppName[] = TEXT("Com Client");
	HRESULT hr;

	// code
	// COM Initialization
	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("Com Library cannot be initialize. \n The program will terminate now"), TEXT("Program error"), NULL);
		exit(0);
	}

	// WNDCLASSES intitialization
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

	// Reister window class
	RegisterClassEx(&wndclass);

	// Create window
	hwnd = CreateWindow(AppName,
						TEXT("Client of Com DLL Server"),
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

	// COM Un-intialization
	CoUninitialize();
	return((int)msg.wParam);
}

// Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Function declarations
	void SafeinterfactRelease(void);

	// Variable declarataions
	HRESULT hr;
	int iNum1, iNum2, iSum, iSubtraction, iMultiplication, iDivision;
	TCHAR str[255];

	// Code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void **)&pISum);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("ISum interface cannot be obtained"), TEXT("Program error"), MB_OK);
			DestroyWindow(hwnd);
		}

		// Intitailize arguments hardcoded
		iNum1 = 65;
		iNum2 = 45;

		// Call SumOfTwoIntegers() of ISum to get the sum
		pISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);
		
		// Display the result 
		wsprintf(str, TEXT("Sum of integers %d and %d is %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"),MB_OK);

		// Call QueryInterface() on ISum, to get ISubtract's pointer
		hr = pISum->QueryInterface(IID_ISubtract, (void**)&pISubtract);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("ISubtract interface cannot be obtained"), TEXT("Program error"), MB_OK);
			DestroyWindow(hwnd);
		}
		pISum->Release();
		pISum = NULL;

		// Again intialize the arguments
		iNum1 = 155;
		iNum2 = 55;

		// Call SumOfTwoIntegers() of ISum to get the sum
		pISubtract->SubtractionOfTwoIntegers(iNum1, iNum2, &iSubtraction);

		// Display the result 
		wsprintf(str, TEXT("Subraction of integers %d and %d is %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		// Call QueryInterface() on ISum, to get ISubtract's pointer
		hr = pISubtract->QueryInterface(IID_IMultiplication, (void**)&pIMultiplication);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("Imultiply interface cannot be obtained"), TEXT("Program error"), MB_OK);
			DestroyWindow(hwnd);
		}
		pISubtract->Release();
		pISubtract = NULL;

		// Again intialize the arguments
		iNum1 = 30;
		iNum2 = 25;

		// Call SumOfTwoIntegers() of ISum to get the sum
		pIMultiplication->MutliplicationOfTwoIntegers(iNum1, iNum2, &iMultiplication);

		// Display the result 
		wsprintf(str, TEXT("Multiplication of integers %d and %d is %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		// Call QueryInterface() on ISum, to get ISubtract's pointer
		hr = pIMultiplication->QueryInterface(IID_IDivision, (void**)&pIDivision);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("ISubtract interface cannot be obtained"), TEXT("Program error"), MB_OK);
			DestroyWindow(hwnd);
		}
		pIMultiplication->Release();
		pIMultiplication = NULL;

		// Again intialize the arguments
		iNum1 = 600;
		iNum2 = 6;

		// Call SumOfTwoIntegers() of ISum to get the sum
		pIDivision->DivsionsOfTwoIntegers(iNum1, iNum2, &iMultiplication);

		// Display the result 
		wsprintf(str, TEXT("Division of integers %d and %d is %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		// Release Division
		pIDivision->Release();
		pIDivision= NULL;

		// Exit the application
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		SafeInterfaceRelease();
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

void SafeInterfaceRelease(void)
{
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
	if (pIMultiplication)
	{
		pIMultiplication->Release();
		pIMultiplication = NULL;
	}
	if (pIDivision)
	{
		pIDivision->Release();
		pIDivision = NULL;
	}
}

