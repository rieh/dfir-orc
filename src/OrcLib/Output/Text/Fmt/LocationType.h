//
// SPDX-License-Identifier: LGPL-2.1-or-later
//
// Copyright © 2020 ANSSI. All Rights Reserved.
//
// Author(s): fabienfl (ANSSI)
//

#pragma once

#include "Output/Text/Fmt/Fwd/LocationType.h"

#include <windows.h>

#include "Output/Text/Format.h"
#include <LocationType.h>

template <typename FormatContext>
auto fmt::formatter<Orc::LocationType>::format(const Orc::LocationType& type, FormatContext& ctx) -> decltype(ctx.out())
{
    std::error_code ec;
    const auto utf8 = Orc::Utf16ToUtf8(Orc::ToString(type), ec);
    if (ec)
    {
        return formatter<std::string_view>::format(Orc::kFailedConversion, ctx);
    }

    return formatter<std::string_view>::format(utf8, ctx);
}

template <typename FormatContext>
auto fmt::formatter<Orc::LocationType, wchar_t>::format(const Orc::LocationType& type, FormatContext& ctx)
    -> decltype(ctx.out())
{
    return formatter<std::wstring_view, wchar_t>::format(Orc::ToString(type), ctx);
}
