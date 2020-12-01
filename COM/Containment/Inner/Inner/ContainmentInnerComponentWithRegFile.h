#pragma once
class IMultiplication :public IUnknown
{
public:
	// IMultiplication specific declarations
	virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0; // Pure virtual 
};

class IDivision :public IUnknown
{
public:
	// IDivision specific method declerations
	virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*) = 0; // pure virtual 
};

// CLSID of MultiplicationDivsion Component  {72D5E594-9E0D-48B7-833D-C9ABFD3893FB}
const CLSID CLSID_MultiplicationDivision =
{ 0x72d5e594, 0x9e0d, 0x48b7,  0x83, 0x3d, 0xc9, 0xab, 0xfd, 0x38, 0x93, 0xfb };

// IID of IMultiplication Interface {A0D8A26E-8982-4354-995F-6C7DA119E939}
const IID IID_IMultiplication = 
{ 0xa0d8a26e, 0x8982, 0x4354, 0x99, 0x5f, 0x6c, 0x7d, 0xa1, 0x19, 0xe9, 0x39 };

// IID of IDivision Interface  {89F661AA-112B-423D-A964-7FB729FA43B6}
static IID IID_IDivision =
{ 0x89f661aa, 0x112b, 0x423d,  0xa9, 0x64, 0x7f, 0xb7, 0x29, 0xfa, 0x43, 0xb6  };
