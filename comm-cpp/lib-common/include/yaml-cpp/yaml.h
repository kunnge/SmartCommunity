#ifndef YAML_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define YAML_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4251 4275)
#endif

#include "yaml-cpp/parser.h"
#include "yaml-cpp/emitter.h"
#include "yaml-cpp/emitterstyle.h"
#include "yaml-cpp/stlemitter.h"
#include "yaml-cpp/exceptions.h"

#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/impl.h"
#include "yaml-cpp/node/convert.h"
#include "yaml-cpp/node/iterator.h"
#include "yaml-cpp/node/detail/impl.h"
#include "yaml-cpp/node/parse.h"
#include "yaml-cpp/node/emit.h"

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  // YAML_H_62B23520_7C8E_11DE_8A39_0800200C9A66
