//
// SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
// Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
// Alexander Fokin, Sergey Levin, Leonid Tsvetkov
//
// This file is part of SmartDec decompiler.
//
// SmartDec decompiler is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SmartDec decompiler is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
//

#include "InvalidInstructionException.h"

#include <nc/core/arch/Instruction.h>

namespace nc { namespace core { namespace arch { namespace irgen {

QString InvalidInstructionException::unicodeWhat() const noexcept {
    if (const Instruction *const *instruction = boost::get_error_info<ExceptionInstruction>(*this)) {
        return tr("Invalid instruction `%1' at 0x%2: %3")
            .arg((*instruction)->toString()).arg((*instruction)->addr(), 0, 16).arg(Exception::unicodeWhat());
    } else {
        return tr("Invalid instruction: %1").arg(Exception::unicodeWhat());
    }
}

}}}} // namespace nc::core::arch::irgen

/* vim:set et sts=4 sw=4: */
