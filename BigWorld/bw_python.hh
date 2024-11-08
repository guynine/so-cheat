#pragma once
#include <string>
//#define Py_SIZE(pyobject)   *(unsigned int*)((unsigned long long )pyobject + 0x10) 
//#define Py_TYPE(pyobject)   *(unsigned int*)((unsigned long long )pyobject + 0x8) 
 // http://pics.wikireality.ru/upload/9/9b/Thonk.png ��� ����� ����� ����� ��� ������� ������� ������  �������
// ���� ������ read<PyObject> � ��� �������� � ����� ��������
// ���� ������ read<PyObject*> � ����� ������ ������ �� "this" ������ ���� 
// ������ ����� ��� �������� ������ , �� ��� ���-�� ������� ��� �� ���
#define DumpAttribute(CLASS) void dump()   {      \
   auto dict = this->ob_dict( &CLASS::dictoffset);                                          \
     if (!dict) return; \
dict->dump_item(); };                                  \
  public:\





#define Py_Attribute(CLASS,type,name)  type name()   {      \
   auto dict = this->ob_dict( &CLASS::dictoffset);                                          \
     if (!dict) return nullptr; \
return (type)dict->find_item(#name); };                                \
  \

#define Py_dicthead  private: static inline int dictoffset = 0; public:   


#define IS_A(pyobject,NAME) [&] () { auto type = pyobject->ob_type();         \
    if (!type) return (NAME*)nullptr;                                                   \
        if (type->tp_name() == #NAME) return (NAME*)pyobject; return (NAME*)nullptr; }()
			


typedef size_t Py_ssize_t; 
class PyTypeObject	;
class PyDictObject;
class PyStringObject;

class PyObject;
// typeobject.c

class PyHasherComptime {
public:
	template<class Type>
	constexpr static size_t StrLen(const Type* str) {
		size_t Len = 0;
		while (str[Len++]);
		return Len - 1;
	}
    		template<class Type>
	constexpr static unsigned long HashPython(const Type* Data, size_t Size) {
		unsigned long Result = Data[0];
        	Result =  Data[0] << 7;
		for (auto i = 0; i < Size; i++)
			Result    = (Result *1000003) ^ Data[i] ; // x = (1000003 * x) ^ a[i];
        	Result ^= Size;
            if   (Result == -1)
		     Result = -2;
		return Result;
	}
    template<class Type>
	constexpr static unsigned long pyStrHash(const Type* Str) {
		return HashPython(Str, StrLen(Str) );
	}

	template<class Type>
	constexpr static unsigned long pyStrHash(std::basic_string<Type> Str) {
		return pyStrHash(Str.c_str());
	}
};

#pragma warning(disable : 4455)
consteval static unsigned long  operator""p(const char* str, size_t len) { return PyHasherComptime::pyStrHash(str); }

#define Py_AttributeHASH(CLASS,type,name) private: type name()   {      \
   auto dict = this->ob_dict( &CLASS::dictoffset);                                          \
     if (!dict) return nullptr; \
constexpr long hashe = #name##p ;\
return (type)dict->find_item_safe(hashe,#name); };                                  \
  public:\



class PyObject  // object.h 78 line
{
private:
	Py_ssize_t _ob_refcnt;
	PyTypeObject* _ob_type;
public:
	PyTypeObject* ob_type();
	PyDictObject* ob_dict(int* dictoffset);
	PyDictObject* ob_dict();
	size_t ob_refcnt();

};

struct PyDictEntry
{
	Py_ssize_t 	me_hash;
	PyStringObject* me_key;
	PyObject* me_value;
};



class PyDictObject : public PyObject
{
	public:

		PyDictEntry	at(int i);
		size_t ma_mask();
		size_t ma_used();
	
	
		PyObject* find_item(const char* itemname);
		PyObject* dump_item();
		PyObject* find_item_safe(unsigned long me_hash,const char* itemname);

	Py_ssize_t _ma_fill;  /* # Active + # Dummy */
	Py_ssize_t _ma_used;  /* # Active */

	///* The table contains ma_mask + 1 slots, and that's a power of 2.
	// * We store the mask instead of the size because the mask is more
	// * frequently needed.
	// */
	Py_ssize_t _ma_mask;

	///* ma_table points to ma_smalltable for small tables, else to
	// * additional malloc'ed memory.  ma_table is never NULL!  This rule
	// * saves repeated runtime null-tests in the workhorse getitem and
	// * setitem calls.
	// */
	PyDictEntry* _ma_table;
	void* _ma_fn;
	PyDictEntry _ma_smalltable[8];
};


class PyVarObject : public PyObject // object.h 98 line
{
private:
	Py_ssize_t _ob_size;  // 0x10 
public:
	size_t ob_size();
};

class PyStringObject : public PyVarObject // object.h 98 line
{
private:
	Py_ssize_t hash;  
	const char str[128];
public:
	
	size_t lenght() { return this->ob_size();  };
	std::string to_string();
};

class PyINT8Object : public PyObject // object.h 98 line
{
private:
	__int8 value;
public:
	__int8 get();
	void set(__int8 value);

};

class PyINT32Object : public PyObject // object.h 98 line
{
private:
	__int32 value;
public:
	__int32 get();
	void set(__int32 value);
};

class PyINT64Object : public PyObject // object.h 98 line
{
private:
	__int64 value;
public:
	__int64 get();
	void set(__int64 value);

};

class PyFLOATObject : public PyObject // object.h 98 line
{
private:
	float value;
public:
	float get();
	void set(float value);

};
class SuperModel
{
public:
	

private:

};



class PyModel : public PyObject //  PyModel :  public PyAttachment, public Aligned
{
private:

	 // void PyModel::drawSkeleton()

	//	typedef StringHashMap< SmartPointer<PyFashion> > Fashions;

	//SuperModel			*pSuperModel_; // // 0x100
	//ActionQueue			actionQueue_;

	//BoundingBox			localBoundingBox_; // 0x1f0
	//BoundingBox			localVisibilityBox_; // 0x1fc
	//float				height_;
	//bool				visible_; // 0x214
	//bool				visibleAttachments_;
	//bool				moveAttachments_;
	//bool				outsideOnly_;
	//bool				stipple_;
	//bool				shimmer_;

	//float				moveScale_; // 0x220
	//float				actionScale_;

	//Fashions			fashions_;
	//ModelAlignerPtr		pCouplingFashion_;

	//PyModelNodes		knownNodes_; // 0x270
public:
		bool IsVisible();
				SuperModel* GetSuperModel();

};


class PyUnicodeObject : public PyVarObject // object.h 98 line
{
private:
	const wchar_t* str;
public:
	size_t lenght() { return this->ob_size(); };
	std::wstring to_wstring();
	std::string to_string();
};

class PyTypeObject : public PyVarObject //  object.h 325 line
{
private:
	const char* _tp_name; /*  0x18 */
	Py_ssize_t _tp_basicsize, _tp_itemsize;
	char pad_0030[120]; //0x0030 //   
	long _tp_flags; //0x00A8 to do replace with  drv.read 0xa8  because we dont want read usless pading
	/* 
	https://github.com/v2v3v4/BigWorld-Engine-2.0.1/blob/master/src/lib/py/Include/object.h#L329
	*/
public:
	 std::string tp_name();
	 size_t tp_basicsize();
	 size_t tp_itemsize();
	 int tp_dictoffset();

	 PyTypeObject* tp_base();
	 std::string fullname();
};

// py get  attr 