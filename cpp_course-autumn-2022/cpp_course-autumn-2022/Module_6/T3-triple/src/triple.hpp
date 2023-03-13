/* Add include guards here */
#ifndef TRIPLE_HPP
#define TRIPLE_HPP
#include <iostream>
#include <algorithm>
/* Class: Triple
 * -------------
 * The template class Triple is a container class, which holds three values.
 * All of the values can be of different type. All of the values should be
 * private.
 *
 * The constructor of the class takes three const references to values as a
 * parameter. The parameters are in order, in other words, after construction
 * the first parameter should be accessible through the public member function
 * First, the second parameter through the public member function Second, and
 * the third through the public member function Third. 
 *
 * The default empty constructor should also work.
 *
 * The Triple class should also support the copy constructor, and assignment
 * operations.
 */
 

/* Public member functions:
 * ------------------------
 * The Triple class has three public member functions, which are used to
 * access the stored elements. All three should work with const instances
 * of Triple.
 *
 * Function: First
 * The function takes no parameters.
 * The function returns a const reference to the first value of the triple.
 *
 * Function: Second
 * The function takes no parameters.
 * The function returns a const reference to the second value of the triple.
 *
 * Function: Third
 * The function takes no parameters.
 * The function returns a const reference to the third value of the triple.
 */

template <typename a, typename b, typename c>
class Triple {
    public:
        Triple() = default;
        ~Triple() = default;
        
        Triple(a x, b y, c z) : x_(x), y_(y), z_(z) {}

        const a& First(void) const { return x_; }
        const b& Second(void) const { return y_; }
        const c& Third(void) const { return z_; }
        
    private:
        a x_;
        b y_;
        c z_;
};

/* Non-member functions:
 * ---------------------
 * Function: IsHomogenous
 * The function is a non-member function that takes a Triple as a parameter.
 * The function returns a boolean value indicating whether the triple is
 * homogenous or not. A triple is homogenous if all of its three values are of
 * the same type.
 * Hint: specialisation can help you here.
 */

template <typename a, typename b, typename c>
bool IsHomogenous(Triple<a, b, c> x) { return false; }

template <typename a>
bool IsHomogenous(Triple<a, a, a> y) { return true; }

/* Operator overloads:
 * -------------------
 * The triple class should support the following operators:
 *
 * Assignment operator, =
 * The default functionality should do here.
 *
 * Equality operator, ==
 * You can assume that all the values in the triple can be compared by the
 * == -operator. Two triples are equal if the corresponding values in both
 * of the triples are equal.
 *
 * Inequality operator, !=
 * You can assume that all the values in the triple can be compared by the
 * != -operator. Two triples are inequal if even one corresponding value in
 * the triples is different.
 *
 * The output stream operator, <<
 * You can assume that all the values in the triple support the << -operator.
 * The triple should be printed to the output stream in the following format: 
[<first value>, <second value>, <third value>]
 * Note that there is NO new line at the end of the output.
 */

template <typename a, typename b, typename c>
bool operator ==(const Triple<a, b, c>& x, const Triple<a, b, c>& y) {
    return ((x.First() == y.First()) && (x.Second() == y.Second())  && (x.Third() == y.Third()));
}
template <typename a, typename b, typename c>
bool operator !=(const Triple<a, b, c>& x, const Triple<a, b, c>& y) {
    return !(x == y);
}
template <typename a, typename b, typename c>
std::ostream& operator <<(std::ostream& o, const Triple<a, b, c>& x) {
    return o << "[" << x.First() << ", " << x.Second() << ", " << x.Third() <<"]";
}


/* Remember the endif here to close the header guards */
#endif