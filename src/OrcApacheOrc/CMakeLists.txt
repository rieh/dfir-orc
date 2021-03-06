#
# SPDX-License-Identifier: LGPL-2.1-or-later
#
# Copyright © 2011-2019 ANSSI. All Rights Reserved.
#
# Author(s): fabienfl
#            Jean Gautier
#

include(${ORC_ROOT}/cmake/Orc.cmake)
orc_add_compile_options()

set(SRC "OrcApacheOrc.cpp")

set(SRC_COMMON "dllmain.cpp" "targetver.h")
source_group(Common FILES ${SRC_COMMON} "stdafx.h")

add_library(OrcApacheOrc
    SHARED
        "stdafx.h"
        ${SRC}
        ${SRC_COMMON}
)

target_link_libraries(OrcApacheOrc
    PUBLIC
        OrcApacheOrcLib
)

set_target_properties(OrcApacheOrc
    PROPERTIES
        FOLDER "${ORC_ROOT_VIRTUAL_FOLDER}OrcApacheOrc"
)

target_precompile_headers(OrcApacheOrc PRIVATE stdafx.h)

foreach(CONFIG Debug MinSizeRel Release RelWithDebInfo)
    install(TARGETS OrcApacheOrc
        CONFIGURATIONS ${CONFIG}
        DESTINATION ${CONFIG}
    )

    install(FILES $<TARGET_PDB_FILE:OrcApacheOrc>
        CONFIGURATIONS ${CONFIG}
        DESTINATION ${CONFIG} OPTIONAL
    )
endforeach()
