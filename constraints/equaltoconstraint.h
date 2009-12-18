/* 
* File:   equaltooperator.h
* Author: joakim
*
* Created on December 13, 2009, 11:13 AM
*/

#ifndef _EQUALTOCONSTRAINT_H
#define	_EQUALTOCONSTRAINT_H

namespace igloo {
   template <typename T>
   class EqualToConstraint : public Constraint<T>
   {
   public:

      EqualToConstraint(T expected) : _expected(expected)
      {
      }

      bool Evaluate(T actual)
      {
         return actual == _expected;
      }

      std::string ExpectationText()
      {
         std::ostringstream str;
         str << "equal to " << _expected;
         return str.str();
      }

   private:
      T _expected;
   };
}
#endif

