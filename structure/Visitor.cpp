/*
 * Copyright (c) 2016, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Intel Corporation nor the names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "structure/Visitor.hpp"
#include "structure/type/stock.hpp"

namespace structure
{
// The various field types need to be forward-declared Visitor.hpp. As a result, the fact that they
// derive from GenericField is unknown by the compiler and so, the static_cast does not compile.
// This is why the definitions for these fallbacks need to be in their own cpp.
void StructureVisitor::visit(const Integer &i)
{
    visit(static_cast<const GenericField &>(i));
}
void StructureVisitor::visit(const FloatingPoint &f)
{
    visit(static_cast<const GenericField &>(f));
}
void StructureVisitor::visit(const FixedQ &q)
{
    visit(static_cast<const GenericField &>(q));
}
void StructureVisitor::visit(const String &s)
{
    visit(static_cast<const GenericField &>(s));
}
void StructureVisitor::visit(const Bool &s)
{
    visit(static_cast<const GenericField &>(s));
}

void StorageVisitor::visitStorage(const BlockValue &block)
{
    for (const auto &field : block.getFields()) {
        field->accept(*this);
    }
}
}
