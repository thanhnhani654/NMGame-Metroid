#include "AddXML.h"
#include <stdio.h>
#include <windows.h>
#include <objbase.h>
#include <msxml6.h>
#include <iostream>
#include <sstream>
#include<AtlBase.h>
#include <AtlConv.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define CHK_HR(stmt)		do{hr=(stmt);if(FAILED(hr)) goto CleanUp;}while(0)
#define CHK_ALLOC(p)        do { if (!(p)) { hr = E_OUTOFMEMORY; goto CleanUp; } } while(0)
#define SAFE_RELEASE(p)     do { if ((p)) { (p)->Release(); (p) = NULL; } } while(0)\


AddXML::AddXML()
{
}

HRESULT AddXML::VariantFromString(PCWSTR wszValue, VARIANT & Variant)
{
	HRESULT hr = S_OK;
	BSTR bstr = SysAllocString(wszValue);
	CHK_ALLOC(bstr);

	V_VT(&Variant) = VT_BSTR;
	V_BSTR(&Variant) = bstr;

CleanUp:
	return hr;
}

HRESULT AddXML::CreateAndInitDOM(IXMLDOMDocument ** ppDoc)
{
	HRESULT hr = CoCreateInstance(__uuidof(DOMDocument60), NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(ppDoc));
	if (SUCCEEDED(hr))
	{

		(*ppDoc)->put_async(VARIANT_FALSE);
		(*ppDoc)->put_validateOnParse(VARIANT_FALSE);
		(*ppDoc)->put_resolveExternals(VARIANT_FALSE);
		(*ppDoc)->put_preserveWhiteSpace(VARIANT_TRUE);
	}
	return hr;
}

HRESULT AddXML::ReportParseError(IXMLDOMDocument * pDoc, char * szDesc)
{
	HRESULT hr = S_OK;
	HRESULT hrRet = E_FAIL; // Default error code if failed to get from parse error.
	IXMLDOMParseError *pXMLErr = NULL;
	BSTR bstrReason = NULL;

	CHK_HR(pDoc->get_parseError(&pXMLErr));
	CHK_HR(pXMLErr->get_errorCode(&hrRet));
	CHK_HR(pXMLErr->get_reason(&bstrReason));
	printf("%s\n%S\n", szDesc, bstrReason);

CleanUp:
	SAFE_RELEASE(pXMLErr);
	SysFreeString(bstrReason);
	return hrRet;
}

void AddXML::queryNodes(PCWSTR wszValue,int n,int &x,int &y,int &w,int &h)
{
	HRESULT hr = S_OK;
	IXMLDOMDocument *pXMLDom = NULL;
	IXMLDOMNodeList *pNodes = NULL;
	IXMLDOMNode *pNode = NULL;

	BSTR bstrQuery2 = NULL;
	BSTR bstrQuery3 = NULL;
	BSTR bstrNodeName = NULL;
	BSTR bstrNodeValue = NULL;
	VARIANT_BOOL varStatus;
	VARIANT varFileName;
	VariantInit(&varFileName);
/*
	CHK_HR(CreateAndInitDOM(&pXMLDom));

	CHK_HR(VariantFromString(wszValue, varFileName));
	CHK_HR(pXMLDom->load(varFileName, &varStatus));
	if (varStatus != VARIANT_TRUE)
	{
		CHK_HR(ReportParseError(pXMLDom, "Failed to load DOM"));
	}*/
	//
		string s;
		stringstream ss;
		ss << n;
		s = "//SPRITE[" + ss.str() + "]/*";
		//cout << (char)i;
		char *b = new char[s.length() + 1];
		strcpy(b, s.c_str());

		CHK_HR(CreateAndInitDOM(&pXMLDom));
		CHK_HR(VariantFromString(wszValue, varFileName));
		CHK_HR(pXMLDom->load(varFileName, &varStatus));
		if (varStatus != VARIANT_TRUE)
		{
			CHK_HR(ReportParseError(pXMLDom, "Failed to load DOM "));
		}
		// Query a node-set.

		const char* a = b;
		size_t size = strlen(a);
		wchar_t* name = new wchar_t[size];
		size_t outSize;
		//
		OLECHAR *ma = new OLECHAR[size + 1];
		mbstowcs(ma, a, size + 1);
		//
		bstrQuery2 = SysAllocString(ma);
		CHK_ALLOC(bstrQuery2);
		CHK_HR(pXMLDom->selectNodes(bstrQuery2, &pNodes));
		if (pNodes)
		{
			//printf("Results from selectNodes:\n");
			//get the length of node-set
			long length;
			//CHK_HR(pNodes->get_length(&length));

			CHK_HR(pNodes->get_item(0, &pNode));
			CHK_HR(pNode->get_text(&bstrNodeValue));
			int vl = _wtoi(bstrNodeValue);
			x = vl;
			SysFreeString(bstrNodeValue);
			//
			CHK_HR(pNodes->get_item(1, &pNode));
			CHK_HR(pNode->get_text(&bstrNodeValue));
			vl = _wtoi(bstrNodeValue);
			y = vl;
			SysFreeString(bstrNodeValue);
			//
			CHK_HR(pNodes->get_item(2, &pNode));
			CHK_HR(pNode->get_text(&bstrNodeValue));
			vl = _wtoi(bstrNodeValue);
			w = vl;
			SysFreeString(bstrNodeValue);
			//
			CHK_HR(pNodes->get_item(3, &pNode));
			CHK_HR(pNode->get_text(&bstrNodeValue));
			vl = _wtoi(bstrNodeValue);
			h = vl;
			SysFreeString(bstrNodeValue);
			//
			SAFE_RELEASE(pNode);
			//
		}
		else
		{
			CHK_HR(ReportParseError(pXMLDom, "Error while calling selectNodes."));
		}
	// Query a node-set.
	//const char *a = "//SPRITE[1]/*";
	//size_t size = strlen(a);
	//wchar_t* name = new wchar_t[size];
	//size_t outSize;
	////
	//OLECHAR *ma = new OLECHAR[size + 1];
	//mbstowcs(ma, a, size + 1);
	////
	////mbstowcs_s(&outSize, ma, size, a, size - 1);
	//bstrQuery2 = SysAllocString(ma);
	//CHK_ALLOC(bstrQuery2);
	//CHK_HR(pXMLDom->selectNodes(bstrQuery2, &pNodes));
	//if (pNodes)
	//{
	//	printf("Results from selectNodes:\n");
	//	//get the length of node-set
	//	long length;
	//	CHK_HR(pNodes->get_length(&length));
	//	for (long i = 0; i < length; i++)
	//	{
	//		CHK_HR(pNodes->get_item(i, &pNode));
	//		//CHK_HR(pNode->get_nodeName(&bstrNodeName));
	//		//printf("Node (%d), <%S>:\n", i, bstrNodeName);
	//		//SysFreeString(bstrNodeName);

	//		CHK_HR(pNode->get_text(&bstrNodeValue));
	//		printf("\t%S\n", bstrNodeValue);
	//		SysFreeString(bstrNodeValue);
	//		SAFE_RELEASE(pNode);
	//	}
	//}
	//else
	//{
	//	CHK_HR(ReportParseError(pXMLDom, "Error while calling selectNodes."));
	//}
CleanUp:
	SAFE_RELEASE(pXMLDom);
	SAFE_RELEASE(pNodes);
	SAFE_RELEASE(pNode);
	SysFreeString(bstrQuery2);
	SysFreeString(bstrNodeName);
	SysFreeString(bstrNodeValue);
	VariantClear(&varFileName);
}


AddXML::~AddXML()
{
}
