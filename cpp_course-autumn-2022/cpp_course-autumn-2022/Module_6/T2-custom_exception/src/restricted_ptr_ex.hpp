/* Add include guards here */

/* TODO: classes RestrictedPtrException, RestrictedCopyException 
 * and RestrictedNullException
 * ------------
 * Description:
 * Exception classes used by the RestrictedPtr class.
 * PtrException is a abstract base class of the other two and inherits
 * std::exception.
 * CopyException signifies a copying error.
 * NullException signifies a nullptr error.
 * ------------
 * Functions:
 * 
 * All of them should have a constructor taking a single const 
 * reference to a string which is the use of the RestrictedPtr that 
 * caused the exception.
 * 
 * GetError: A function that takes no arguments and returns 
 * a string description of the error (see "Other" section for details).
 * Calling GetError on RestrictedPtrException should return the
 * error description of the actual exception type (Null- or 
 * CopyException).
 * 
 * GetUse: takes no parameters and returns the string given as a 
 * parameter to the constructor. 
 * ------------
 * Other:
 * As always, any function that doesn't modify the object or allow
 * modifying the object's members from the outside should be const.
 * 
 * Wrap everything inside the WeirdMemoryAllocator namespace.
 * 
 * GetError format:
 * RestrictedCopyException:
<use>: Too many copies of RestrictedPtr!
 * RestrictedNullException:
<use>: nullptr exception!
 * where <use> is replaced by the string given in to the constructor.

#include <iostream>
#include <exception>
namespace WeirdMemoryAllocator {
    class RestrictedPtrException : public std::exception{
    public:
        RestrictedPtrException();
        RestrictedPtrException(const std::string& str){}        
        ~RestrictedPtrException(){}
        virtual std::string GetError() const;
        virtual std::string GetUse() const;
    };

class RestrictedCopyException : public RestrictedPtrException{
    public:
        std::string str_;
        RestrictedCopyException(const std::string& str) : RestrictedPtrException(str){
            str_ = str;
        }
        ~RestrictedCopyException(){}
        std::string GetError() const {
            return "Too many copies of RestrictedPtr!";
        }
        std::string GetUse() const{
            return str_;
        }
};

class RestrictedNullException : public RestrictedPtrException{
    public:
        std::string str_;
        RestrictedNullException(const std::string& str) : RestrictedPtrException(str){
            str_ = str;
        }
        ~RestrictedNullException(){}
        std::string GetError() const {
            return "nullptr exception!";
        }
        std::string GetUse() const {
            return str_;
        }
};
}*/

/* Add include guards here */
#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <string>
#include <exception>
#include <iostream>
namespace WeirdMemoryAllocator{
    class RestrictedPtrException : public std::exception {
    public:
        RestrictedPtrException(const std::string& str){
            str_ = str;
        }        
        ~RestrictedPtrException(){}
        virtual const std::string GetError() const = 0;
        virtual const std::string GetUse() const = 0;
    protected:
    std::string str_;
    };

    class RestrictedCopyException : public RestrictedPtrException {
    public:
        std::string str_;
        RestrictedCopyException(const std::string& str) : RestrictedPtrException(str){
            str_ = str;
        }
        ~RestrictedCopyException(){}
        const std::string GetError() const{
            return str_ + ": Too many copies of RestrictedPtr!";
        }
        const std::string GetUse() const{
            return str_;
        }
    };

    class RestrictedNullException : public RestrictedPtrException {
    public:
        std::string str_;
        RestrictedNullException(const std::string& str) : RestrictedPtrException(str){
            str_ = str;
        }
        ~RestrictedNullException(){}
        const std::string GetError() const {
            return str_ + ": nullptr exception!";
        }
        const std::string GetUse() const {
            return str_;
        }   
    };
}

#endif