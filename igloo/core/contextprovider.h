
//          Copyright Joakim Karlsson & Kim Gräsman 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef IGLOO_CONTEXTPROVIDER_H_
#define IGLOO_CONTEXTPROVIDER_H_

namespace igloo {

  template <typename InnerContext, typename OuterContext>
  struct ContextProvider : public OuterContext
  {
    // Strange names because these end up in every context, so we want to avoid collision with
    // user-defined spec/method names
    void IGLOO_OrchestrateSetUp()
    {
      OuterContext::SetUp();
      IGLOO_CallDerived(&InnerContext::SetUp);
    }

    void IGLOO_OrchestrateTearDown()
    {
      IGLOO_CallDerived(&InnerContext::TearDown);
      OuterContext::TearDown();
    }

  private:
    void IGLOO_CallDerived(void (InnerContext::*Method)())
    {
      (static_cast<InnerContext*>(this)->*Method)();
    }
  };
}

#endif
