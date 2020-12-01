#pragma once
class ISum :public IUnknown
{
public:
	// ISum specific method declarations
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0; // pure virtual 
};

class ISubtract :public IUnknown
{
public:
	// ISubtract specific method declarations
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0; // Pure virtual
};

class IMultiplication :public IUnknown
{
public:
	// IMultiplication specific method delarations
	virtual HRESULT __stdcall MutliplicationOfTwoIntegers(int, int, int*) = 0; // Pure virtual
};

class IDivision :public IUnknown
{
public:
	// IDivision specific method declarations
	virtual HRESULT __stdcall DivsionsOfTwoIntegers(int, int, int*) = 0; // Pure virtual 
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

// IID of IMultiplication Interface {A0D8A26E-8982-4354-995F-6C7DA119E939}
const IID IID_IMultiplication =
{ 0xa0d8a26e, 0x8982, 0x4354, 0x99, 0x5f, 0x6c, 0x7d, 0xa1, 0x19, 0xe9, 0x39 };

// IID of IDivision Interface  {89F661AA-112B-423D-A964-7FB729FA43B6}
static IID IID_IDivision =
{ 0x89f661aa, 0x112b, 0x423d,  0xa9, 0x64, 0x7f, 0xb7, 0x29, 0xfa, 0x43, 0xb6 };