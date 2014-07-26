/* The file is part of Snowman decompiler.             */
/* See doc/licenses.txt for the licensing information. */

/* * SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
 * Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
 * Alexander Fokin, Sergey Levin, Leonid Tsvetkov
 *
 * This file is part of SmartDec decompiler.
 *
 * SmartDec decompiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SmartDec decompiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <nc/config.h>

#include <cassert>

#include <nc/core/arch/irgen/InstructionAnalyzer.h>

namespace nc {
namespace arch {
namespace intel {

class IntelArchitecture;

class IntelInstructionAnalyzerImpl;

class IntelInstructionAnalyzer: public core::arch::irgen::InstructionAnalyzer {
    /** The object actually doing all the work. */
    std::unique_ptr<IntelInstructionAnalyzerImpl> impl_;

public:
    /**
     * Constructor.
     *
     * \param architecture Valid pointer to the architecture.
     */
    IntelInstructionAnalyzer(const IntelArchitecture *architecture);

    /**
     * Destructor.
     */
    ~IntelInstructionAnalyzer();

    /**
     * \param[in] index FPU stack operand index.
     *
     * \return Valid pointer to the intermediate representation of the fpu stack register
     *         operand with the given index.
     */
    static std::unique_ptr<core::ir::Term> createFpuTerm(int index);

protected:
    virtual void doCreateStatements(const core::arch::Instruction *instruction, core::ir::Program *program) override;
};


} // namespace intel
} // namespace arch
} // namespace nc

/* vim:set et sts=4 sw=4: */
