
//          Copyright Joakim Karlsson & Kim Gräsman 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef IGLOO_REGISTRATION_H
#define IGLOO_REGISTRATION_H

#define IGLOO_CAT_I(a, b) a ## b
#define IGLOO_CAT(a, b) IGLOO_CAT_I(a, b)

#define IGLOO_RegisterContext(baseContext, context) \
	template<class T##context> struct context; \
struct ContextRegistrar_##context \
{ \
  ContextRegistrar_##context() \
  { \
    igloo::TestRunner::RegisterContext<igloo::ContextRunner<baseContext, context<void> > >(#context); \
  } \
} context##_IglooRegistrar;

#define Context(context) \
	IGLOO_RegisterContext(void, context) \
	template<class T##context> struct context : public ContextProvider<context<T##context>, typename IGLOO_CURRENT_CONTEXT>

#define SubContext(context, baseContext) \
	IGLOO_RegisterContext(baseContext, context) \
	template<class T##context> struct context : baseContext

#define Spec(spec) \
struct SpecRegistrar_##spec \
{ \
  SpecRegistrar_##spec() \
  { \
    ContextRegistry<IGLOO_CURRENT_CONTEXT>::RegisterSpec(#spec, &IGLOO_CURRENT_CONTEXT::spec); \
  } \
} SpecRegistrar_##spec; \
virtual void spec()

// "Classic" aliases
#define TestFixture(context) Context(context)
#define DerivedFixture(context, baseContext) SubContext(context, baseContext)
#define TestMethod(spec) Spec(spec)

#endif
