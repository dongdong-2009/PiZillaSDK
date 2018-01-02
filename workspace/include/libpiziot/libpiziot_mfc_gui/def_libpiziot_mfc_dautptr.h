#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#include <new>

#if __BORLANDC__ >= 0x530
#pragma option push -a1
#endif

namespace LibPIZIOTClass {

    //
    // Types
    //
    template<class T>
    class CAutoArrCore {
        //-------//
    public: //-----------------------------------------------------------------

    // Nonvirtuals
        CAutoArrCore() : ptr(0), owned(false) {}

        CAutoArrCore(CAutoArrCore &another) : ptr(another.ptr), owned(another.owned) {
            another.owned = false;
        }

        CAutoArrCore(T *ptr, bool owned) : ptr(ptr), owned(owned) {}

        ~CAutoArrCore();

        // Deallocate ptr if ptr is owned
        CAutoArrCore &operator=(CAutoArrCore &another);

        //
        void assign(T *ptr, bool owned);
        //

        //----------//
    protected: //--------------------------------------------------------------

    // Data
        T *ptr;

        //--------//
    private: //----------------------------------------------------------------

    // Data
        bool owned;

        // Taboos
        //CAutoArrCore(const CAutoArrCore &);
        //CAutoArrCore &operator =(const CAutoArrCore &);
    };

    template<class T>
    class CAutoArr : public CAutoArrCore<T> {
        // Types
        typedef CAutoArrCore<T> C_Super;

        //-------//
    public: //-----------------------------------------------------------------

    // Nonvirtuals
        CAutoArr() {}

        CAutoArr(CAutoArr &another) : C_Super(static_cast<C_Super &>(another)) {}

        CAutoArr(T *ptr, bool owned) : C_Super(ptr, owned) {}

        explicit CAutoArr(size_t n) : C_Super(new T[n], true) {}

        operator T *() const {
            return ptr;
        }

        CAutoArr &operator=(CAutoArr &another) {
            C_Super::operator=(static_cast<C_Super &>(another));
            return *this;
        }

        void assign(T *ptr, bool owned) {
            C_Super::assign(ptr, owned);
        }

        void assign(size_t n) {
            assign(new T[n], true);
        }

        T *pointer() const {
            return ptr;
        }
    };

    template<class T>
    class CRvalArr : public CAutoArrCore<T> {
        // Types
        typedef CAutoArrCore<T> C_Super;

        //-------//
    public: //-----------------------------------------------------------------

    // Nonvirtuals
        CRvalArr() {}

        CRvalArr(CRvalArr &another) : C_Super(static_cast<C_Super &>(another)) {}

        CRvalArr(T *ptr, bool owned) : C_Super(ptr, owned) {}

        CRvalArr(const T *ptr) : C_Super(const_cast<T *>(ptr), false) {}

        operator const T *() const {
            return ptr;
        }

        CRvalArr &operator=(CRvalArr &another) {
            C_Super::operator=(static_cast<C_Super &>(another));
            return *this;
        }

        CRvalArr &operator=(const T *ptr) {
            assign(const_cast<T *>(ptr), false);
            return *this;
        }

        const T *pointer() const {
            return ptr;
        }

        //--------//
    private: //----------------------------------------------------------------

    // Taboos
        CRvalArr(T *ptr);

        CRvalArr &operator=(T *ptr);
    };

    template<class T>
    class CAutoNodeCore {
        //-------//
    public: //-----------------------------------------------------------------

    // Nonvirtuals
        CAutoNodeCore() : ptr(0), owned(false) {}

        CAutoNodeCore(CAutoNodeCore &another) : ptr(another.ptr), owned(another.owned) {
            another.owned = false;
        }

        CAutoNodeCore(T *ptr, bool owned) : ptr(ptr), owned(owned) {}

        ~CAutoNodeCore();

        // Deallocate ptr if needed
        CAutoNodeCore &operator=(CAutoNodeCore &another);

        //
        void assign(T *ptr, bool owned);
        //

        //----------//
    protected: //--------------------------------------------------------------

    // Data
        T *ptr;

        //--------//
    private: //----------------------------------------------------------------

    // Data
        bool owned;

        // Taboos
#ifndef _MSC_VER

        CAutoNodeCore(const CAutoNodeCore &);

        CAutoNodeCore &operator=(const CAutoNodeCore &);

        T &operator[](int i) const;

        T *operator+(int i) const;

#endif //_MSC_VER
    };

    template<class T>
    class CAutoNode : public CAutoNodeCore<T> {
        // Types
        typedef CAutoNodeCore<T> C_Super;

        //-------//
    public: //-----------------------------------------------------------------

    // Nonvirtuals
        CAutoNode() {}

        CAutoNode(CAutoNode &another) : C_Super(static_cast<C_Super &>(another)) {}

        CAutoNode(T *ptr, bool owned) : C_Super(ptr, owned) {}

        operator T *() const {
            return ptr;
        }

        T *operator->() const {
            return ptr;
        }

        const T *pointer() const {
            return ptr;
        }

        CAutoNode &operator=(CAutoNode &another) {
            C_Super::operator=(static_cast<C_Super &>(another));
            return *this;
        }
    };

    template<class T>
    class CRvalNode : public CAutoNodeCore<T> {
        // Types
        typedef CAutoNodeCore<T> C_Super;

        //-------//
    public: //-----------------------------------------------------------------

    // Nonvirtuals
        CRvalNode() {}

        CRvalNode(CRvalNode &another) : C_Super(static_cast<C_Super &>(another)) {}

        CRvalNode(T *ptr, bool owned) : C_Super(ptr, owned) {}

        CRvalNode(const T *ptr) : C_Super(const_cast<T *>(ptr), false) {}

        operator const T *() const {
            return ptr;
        }

        const T *operator->() const {
            return ptr;
        }

        CRvalNode &operator=(CRvalNode &another) {
            C_Super::operator=(static_cast<C_Super &>(another));
            return *this;
        }

        CRvalNode &operator=(const T *ptr) {
            assign(const_cast<T *>(ptr), false);
            return *this;
        }

        //--------//
    private: //----------------------------------------------------------------

    // Taboos
        CRvalNode(T *ptr);

        CRvalNode &operator=(T *ptr);
    };

    //
    // Implementation of Class Templates
    //
    template<class T>
    CAutoArrCore<T>::~CAutoArrCore() {
        if (owned)
            delete[]ptr;
    }

    template<class T>
    CAutoArrCore<T> &CAutoArrCore<T>::operator=(CAutoArrCore &another) {
        this->~CAutoArrCore<T>();
        new(this)CAutoArrCore(another);
        return *this;
    }

    template<class T>
    void CAutoArrCore<T>::assign(T *ptr, bool owned) {
        this->~CAutoArrCore<T>();
        new(this)CAutoArrCore(ptr, owned);
    }

    template<class T>
    CAutoNodeCore<T>::~CAutoNodeCore() {
        if (owned)
            delete ptr;
    }

    template<class T>
    CAutoNodeCore<T> &CAutoNodeCore<T>::operator=(CAutoNodeCore &another) {
        this->~CAutoNodeCore<T>();
        new(this)CAutoNodeCore(another);
        return *this;
    }

    template<class T>
    void CAutoNodeCore<T>::assign(T *ptr, bool owned) {
        this->~CAutoNodeCore<T>();
        new(this)CAutoNodeCore(ptr, owned);
    }

} // namespace LibPIZIOTClass

#if __BORLANDC__ >= 0x530
#pragma option pop
#endif

//Example:
//LibPIZIOTClass::CAutoArr<int>i(100);
//LibPIZIOTClass::CAutoArr<int>i;
//i.assign(100);
//LibPIZIOTClass::CAutoNode<TSLRegistry>lpObject(new TSLRegistry(NULL), true);
//LibPIZIOTClass::CAutoNode<TSLRegistry>lpObject;lpObject.assign(new TSLRegistry(NULL), true);
//typedef LibPIZIOTClass::CAutoNode<TSLRegistry>C_AutoObject;
//C_AutoObject lpObject[10];
//for (int i=0; i < 10; ++i)
//lpObject[i].assign(new TSLRegistry, true);
//size_t n = 10;
//typedef LibPIZIOTClass::CAutoNode<TSLRegistry>C_AutoObject;
//LibPIZIOTClass::CAutoArr<C_AutoObject>lpObject(n);
//for (int = 0;i < n;++i) lpObject[i].assign(new TSLRegistry, true);