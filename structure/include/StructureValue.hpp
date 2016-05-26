#pragma once

#include "structure_export.h"

#include "Structure.hpp"

#include <initializer_list>
#include <string>

namespace structure
{

class ValueVisitor;

class STRUCTURE_EXPORT StructureValue
{
public:
    virtual ~StructureValue() = default;
    virtual void accept(ValueVisitor &visitor) const = 0;

    std::string getName() const;

    virtual const Structure &getStructure() const = 0;
};
}
