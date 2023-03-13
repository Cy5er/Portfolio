/* Add include guards here */

/* 
 * Copy your implementation from the last round here (or wait for
 * the example answer to come out and copy that) and wrap it inside a 
 * WeirdMemoryAllocator namespace.
 * 
 * Changes to the class:
 * 
 * Add a new member string to store the use of the RestrictedPtr 
 * and add a new string parameter, which is the use of the pointer, to the 
 * constructor that originally only takes a pointer. Remember to modify
 * copying to also copy the use. If the pointer is automatically set to 
 * a nullptr (i.e. not given in the constructor), the use is "nullptr".
 * 
 * The copy constructor and assigment operators should throw a RestrictedCopyException 
 * if the operations fail (as they in some cases should). When the copying
 * fails, only the exception should be thrown and no changes should be made
 * to the existing pointer.
 * 
 * The GetData function should throw a RestrictedNullException with the use
 * of the RestrictedPtr given to it if the pointer is null.
 * 
 * The class shouldn't leak any memory.
*/

// BEGIN SOLUTION
#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include "restricted_ref_counter.hpp"
#include "restricted_ptr_ex.hpp"
#include <string>

namespace WeirdMemoryAllocator {

template<typename T>
class RestrictedPtr {
public:
	// default constructor
	RestrictedPtr();

	// constructor when it is called with a pointer
	RestrictedPtr(T* pointer_val, const std::string& use);

	// copy constructor
	RestrictedPtr(const RestrictedPtr<T>& restr_ptr){
		if(restr_ptr.GetRefCount() < 3 ) { 
            this->raw_pointer_ = restr_ptr.raw_pointer_;
            this->ref_counter_ = restr_ptr.ref_counter_;
			this->use_ = restr_ptr.use_;
			(*ref_counter_)++;
        } else {
			throw WeirdMemoryAllocator::RestrictedCopyException(restr_ptr.use_);
		}
	}

	// destructor, only delete the object if the reference count drops to zero
	~RestrictedPtr();

	// copy assignment
	RestrictedPtr<T>& operator=(const RestrictedPtr<T>& restr_ptr);

	// member function to get the data from pointer
	// this is given as a reference, so it can be modified
	T& GetData();

	// member function to get the pointer address
	T* GetPointer() {
		return raw_pointer_;
	}

	// get ref count
	int GetRefCount() const {
		return *ref_counter_;
	}
	T* raw_pointer_;
	int* ref_counter_;
	std::string use_;
private:
	// swaps the data with the parameter
	void Swap(RestrictedPtr<T>& restr_ptr);

	
	
};

template<typename T>
RestrictedPtr<T>::RestrictedPtr() : RestrictedPtr(nullptr, "nullptr") {
	}

template<typename T>
RestrictedPtr<T>::RestrictedPtr(T* pointer_val, const std::string& use)
        : raw_pointer_(pointer_val),use_(use) {
    ref_counter_ = new int(1);
	use_ = use;
}

template<typename T>
RestrictedPtr<T>::~RestrictedPtr() {
    // remove one reference 
    --*ref_counter_;
        if (*ref_counter_ <= 0) {
            if (raw_pointer_) delete raw_pointer_;
            if (ref_counter_) delete ref_counter_;
        }
}

template<typename T>
T& RestrictedPtr<T>::GetData() {
	if(raw_pointer_)
		return *raw_pointer_;
	else 
		throw RestrictedNullException(use_);
}

template<typename T>
RestrictedPtr<T>& RestrictedPtr<T>::operator=(const RestrictedPtr<T>& restr_ptr) {
	// using the copy and swap idiom
        if(restr_ptr.GetRefCount() < 3 ) { 
            (*ref_counter_)--;
            if (this->GetRefCount() == 0) {
                delete this->raw_pointer_;
                delete this->ref_counter_;
            }
            this->raw_pointer_ = restr_ptr.raw_pointer_;
            this->ref_counter_= restr_ptr.ref_counter_;
			this->use_ = restr_ptr.use_;
            (*ref_counter_)++;
            return *this;
        } else { 
			delete this->raw_pointer_;
            delete this->ref_counter_;
            raw_pointer_ = nullptr;
            ref_counter_ = new int (1);
			use_ = restr_ptr.use_;
			throw WeirdMemoryAllocator::RestrictedCopyException(this->use_);
            return *this;
        }
        return *this;
}

template<typename T>
void RestrictedPtr<T>::Swap(RestrictedPtr<T>& restr_ptr) {
	std::swap(raw_pointer_, restr_ptr.raw_pointer_);
	std::swap(ref_counter_, restr_ptr.ref_counter_);
	std::swap(use_, restr_ptr.use_);
}

} // namespace WeirdMemoryAllocator

#endif
// END SOLUTION
