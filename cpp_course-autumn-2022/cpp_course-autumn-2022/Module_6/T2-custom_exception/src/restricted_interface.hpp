/* Add include guards here */

/**
 * @brief a wrapper for class RestrictedPtr
 * 
 * TODO: Implement the following methods:
 *
 * MakeRestricted: a template function that takes any type of
 * pointer as a parameter and returns a RestrictedPtr holding
 * that pointer with the use set to "RestrictedPtr instance".
 * 
 * CopyRestricted: a template function that takes a reference to
 * a RestrictedPtr as a parameter and returns a copy of it. If
 * the copying fails, prints the error in the exception to
 * standard output with a newline appended and returns a
 * default constructed RestrictedPtr.
 *
 * operator<<: a template function that takes in a ostream 
 * reference and a RestrictedPtr reference, prints the object
 * pointed to by the pointer to the stream using the << operator 
 * and returns a reference to the stream. If the pointer is null,
 * prints the return value of GetError of the exception thrown by 
 * GetData instead.
*/
#ifndef INTERFACE
#define INTERFACE
#include "restricted_ptr.hpp"
#include <iostream>
template<typename T>
WeirdMemoryAllocator::RestrictedPtr<T> MakeRestricted(T* ptr){
    return WeirdMemoryAllocator::RestrictedPtr(ptr, "RestrictedPtr instance");
}

template<typename T>
WeirdMemoryAllocator::RestrictedPtr<T> CopyRestricted(const WeirdMemoryAllocator::RestrictedPtr<T>& ptr){
   try {
        //std::cout << WeirdMemoryAllocator::RestrictedCopyException(ptr.use_).GetError() <<std::endl;
        return WeirdMemoryAllocator::RestrictedPtr<T>(ptr);
    } catch (WeirdMemoryAllocator::RestrictedCopyException& exception){
        std::cout << exception.GetError() << std::endl;
        return WeirdMemoryAllocator::RestrictedPtr<T>();
    }
}

template<typename T>
void operator<<(std::ostream& os, WeirdMemoryAllocator::RestrictedPtr<T>& ptr){
    try {
        os << ptr.GetData() << std::endl;
    } catch (WeirdMemoryAllocator::RestrictedPtrException& r) {
        os << r.GetError() << std::endl;
    }
    //return os;
}

#endif