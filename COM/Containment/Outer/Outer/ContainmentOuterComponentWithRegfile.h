#pragma once
class ISum :public IUnknown
{
public:
	// ISum specific method declarations
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0; // pure virtual 
};

class ISubtract : public IUnknown
{
public:
	// ISubtract specific method declarations
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *) = 0;// pure virtual
};

// CLSID of SumSubtract Component  {D6DE2464-A8A7-41B6-A66A-38B8E5B2FE81}
const CLSID CLSID_SumSubtract =
{ 0xd6de2464, 0xa8a7, 0x41b6, 0xa6, 0x6a, 0x38, 0xb8, 0xe5, 0xb2, 0xfe, 0x81 };

// IID of Sum interface {F0CF12EC-0246-441C-B8CC-7808B09E9093}
const IID IID_ISum =
{ 0xf0cf12ec, 0x246, 0x441c, 0xb8, 0xcc, 0x78, 0x8, 0xb0, 0x9e, 0x90, 0x93 };

// IID of ISubtract Interface  {7CA196F1-D8B1-47F4-91D0-F54F77B463FD}
const IID IID_ISubtract =
{ 0x7ca196f1, 0xd8b1, 0x47f4,  0x91, 0xd0, 0xf5, 0x4f, 0x77, 0xb4, 0x63, 0xfd };

