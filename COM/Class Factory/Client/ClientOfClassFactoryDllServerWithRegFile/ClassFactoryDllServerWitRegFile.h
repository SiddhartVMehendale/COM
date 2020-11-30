#pragma once
class ISum :public IUnknown
{
public:
	// ISUm specific method decleration
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int *) = 0; // Pure virtual
};

class ISubtract :public IUnknown
{
public:
	// ISubtract method decleration
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *) = 0; // Pure virtual 
};

// CLSID of SumSubtract component {AAF6E8EA-5197-4A72-9A3D-2904CBE60A18}
const CLSID CLSID_SumSubtract =
{ 0xaaf6e8ea, 0x5197, 0x4a72,  0x9a, 0x3d, 0x29, 0x4, 0xcb, 0xe6, 0xa, 0x18 };

// IID for ISum {9B91D1BC-A36D-4B02-AA70-F980BE1E9CE4}
const IID IID_ISum=
{ 0x9b91d1bc, 0xa36d, 0x4b02,  0xaa, 0x70, 0xf9, 0x80, 0xbe, 0x1e, 0x9c, 0xe4 };

// IID for ISubtract Interface {031103D7-0B7C-434C-8415-EFB59C836EAA}
const IID IID_ISubtract =
{ 0x31103d7, 0xb7c, 0x434c,  0x84, 0x15, 0xef, 0xb5, 0x9c, 0x83, 0x6e, 0xaa  };
