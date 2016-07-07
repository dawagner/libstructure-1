/*
 * Copyright (c) 2016, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#include "structure_export.h"

#include "ValueImporter.hpp"
#include "type/GenericField.hpp"

namespace structure
{

/** @example default-value.cpp
 * This shows how to use default values attribute and the default importer.
 */
/** An importer that uses the Default attribute in a field to build it
 *  and throws an exception if the field does have a Default attribute.
 */
class DefaultImporter : public ValueImporter
{
public:
    std::unique_ptr<GenericFieldValue> import(const GenericField &field,
                                              const std::string &path) override
    {
        if (field.hasDefaultImporter()) {
            return field.getDefaultImporter().import(field, path);
        }
        throw NoDefaultValue(field.getName());
    }

    void onEnterBlock(const std::string &) override { throw WrongType("Block", "Atom"); }

    void onExitBlock(const std::string &) override { throw WrongType("Block", "Atom"); }
};

/** Provide a global instance of a DefaultImporter for convenience
 */
STRUCTURE_EXPORT extern DefaultImporter defaultImporter;

} // namespace structure