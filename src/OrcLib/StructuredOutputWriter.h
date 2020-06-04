//
// SPDX-License-Identifier: LGPL-2.1-or-later
//
// Copyright © 2011-2019 ANSSI. All Rights Reserved.
//
// Author(s): Jean Gautier (ANSSI)
//
#pragma once

#include "OrcLib.h"

#include "StructuredOutput.h"
#include "OutputSpec.h"

#include <Windows.h>
#include <In6addr.h>
#include <inaddr.h>
#include <ObjIdl.h>


#pragma managed(push, off)

namespace Orc {

class CBinaryBuffer;
class LogFileWriter;

namespace StructuredOutput {

struct ORCLIB_API Options : public Orc::OutputOptions
{
    OutputSpec::Encoding Encoding = OutputSpec::Encoding::UTF8;
};

namespace JSON {
struct ORCLIB_API Options : public StructuredOutput::Options
{
    bool bPrettyPrint = false;
    DWORD indentCharCount = 4;
};
}  // namespace JSON

namespace XML {
struct ORCLIB_API Options : public StructuredOutput::Options
{
};
}

using JSONOutputOptions = JSON::Options;
using XMLOutputOptions  = XML::Options;


class ORCLIB_API Writer : public Orc::OutputWriter, public LegacyWriter
{

public:

    using _Buffer = Buffer<WCHAR, 128>;

    Writer(Orc::logger pLog, std::unique_ptr<Options>&& pOptions)
        : _L_(std::move(pLog))
        , m_Options(std::move(pOptions))
    {
    }

    static std::shared_ptr<IWriter> GetWriter(
        const logger& pLog,
        std::shared_ptr<ByteStream> stream,
        OutputSpec::Kind kindOfFile,
        std::unique_ptr<Options>&& pOptions);
    static std::shared_ptr<IWriter>
    GetWriter(const logger& pLog, const OutputSpec& outFile, std::unique_ptr<Options>&& pOptions);
    static std::shared_ptr<IWriter> GetWriter(
        const logger& pLog,
        const OutputSpec& outFile,
        const std::wstring& strPattern,
        const std::wstring& strName,
        std::unique_ptr<Options>&& pOptions);

protected:
    
    HRESULT WriteBuffer(_Buffer& buffer, ULONG32 dwValue, bool bInHex = false);
    HRESULT WriteBuffer(_Buffer& buffer, ULONG64 ullValue, bool bInHex = false);
    HRESULT WriteBuffer(_Buffer& buffer, LONG32 dwValue, bool bInHex = false);
    HRESULT WriteBuffer(_Buffer& buffer, LONG64 ullValue, bool bInHex = false);
    HRESULT WriteBuffer(_Buffer& buffer, LARGE_INTEGER ullValue, bool bInHex = false);

    HRESULT WriteAttributesBuffer(_Buffer& buffer, DWORD dwAttibutes);
    HRESULT WriteBuffer(_Buffer& buffer, FILETIME fileTime);
    HRESULT WriteBuffer(_Buffer& buffer, const WCHAR* szArray, DWORD dwCharCount);
    HRESULT WriteBuffer(_Buffer& buffer, const BYTE pSHA1[], DWORD dwLen, bool b0xPrefix);
    HRESULT WriteBuffer(_Buffer& buffer, const CBinaryBuffer& Buffer, bool b0xPrefix);

    HRESULT WriteBuffer(_Buffer& buffer, DWORD dwFlags, const FlagsDefinition FlagValues[]);
    HRESULT WriteBuffer(_Buffer& buffer, DWORD dwFlags, const FlagsDefinition FlagValues[], WCHAR cSeparator);

    HRESULT WriteBuffer(_Buffer& buffer, IN_ADDR& ip);

protected:
    Orc::logger _L_;
    std::unique_ptr<Options> m_Options;
};

}  // namespace StrucuturedOutput

using StructuredOutputOptions = StructuredOutput::Options;
using StructuredOutputWriter = StructuredOutput::Writer;

}  // namespace Orc

#pragma managed(pop)
