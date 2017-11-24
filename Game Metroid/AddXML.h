#pragma once
#include <stdio.h>
#include <windows.h>
#include <objbase.h>
#include <msxml6.h>
#include <iostream>
#include <sstream>
#include<AtlBase.h>
#include <AtlConv.h>
#include <stdlib.h>
class AddXML
{
public:
	AddXML();
	HRESULT VariantFromString(PCWSTR wszValue, VARIANT &Variant);
	HRESULT CreateAndInitDOM(IXMLDOMDocument **ppDoc);
	HRESULT ReportParseError(IXMLDOMDocument *pDoc, char *szDesc);
	void queryNodes(PCWSTR wszValue,int n,int &x, int &y, int &w, int &h);
	~AddXML();
};

