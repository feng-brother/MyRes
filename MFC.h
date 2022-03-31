#pragma once
#include<Windows.h>
#include<afx.h>

#define DECLARE_DYNAMIC(class_name)\
public:\
static CRuntimeClass class##class_name;\
virtual CRuntimeClass* GetRuntimeClass() const;

#define IMPLEMENT_DYNAMIC(class_name,base_class_name)\
_IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,0xFFFF,NULL)

#define _IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,wSchema,pfnNew)\
static char _lpsz##class_name[]=#class_name;\
CRuntimeClass class_name::class##class_name={\_lpsz##class_name,sizeof(class_name),wSchema,pfnNew,\RUNTIME_CLASS(base_class_name),NULL};\
static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name);\
CRuntimeClass* class_name::GetRuntimeClass() const{ return &class_name::class##class_name;}\

#define RUNTIME_CLASS(class_name)\
(&class_name::class##class_name)

struct AFX_CLASSINIT
{
	AFX_CLASSINIT(CRuntimeClass* pNewClass);
};
AFX_CLASSINIT::AFX_CLASSINIT(CRuntimeClass* pNewClass)
{
	pNewClass->m_pNextClass = CRuntimeClass::pFirstClass;
	CRuntimeClass::pFirstClass = pNewClass;
}

struct CRuntimeClass
{
	LPCSTR  m_lpszClassName;
	int m_nObjectSize;
	UINT m_wSchema;
	CObject* (PASCAL* m_pfnCreateObject)();
	CRuntimeClass* m_pBaseClass;
	static CRuntimeClass* pFirstClass;
	CRuntimeClass* m_pNextClass;
};
