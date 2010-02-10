#ifndef IGLOO_EXPRESSION_H
#define IGLOO_EXPRESSION_H

#include <igloo/constraints/expressions/notexpression.h>
#include <igloo/constraints/expressions/andexpression.h>
#include <igloo/constraints/expressions/orexpression.h>

namespace igloo {

  template<typename T>
  struct Expression
  {
    NotExpression<T> operator!() const
    {
      return NotExpression<T>(static_cast<const T&>(*this));
    }

    template< typename Right >
    AndExpression<T, Right> operator&&(const Right& right) const
    {
      return AndExpression<T, Right>(static_cast<const T&>(*this), right);
    }

    template< typename Right >
    OrExpression<T, Right> operator||(const Right& right) const
    {
      return OrExpression<T, Right>(static_cast<const T&>(*this), right);
    }
  };
}

#endif
