macro(DisableIncludeTreeDumpOnNinjaWithMSVC)

    if (${CMAKE_GENERATOR} STREQUAL "Ninja" AND MSVC)

        option(MSVC_NINJA_DISABLE_INCLUDE_TREE_DUMP "If true option \"/showIncludes\" of msvc compiler would be erased" ON)
        option(DISABLE_HINT_MSVC_NINJA "Disables hint about Ninja's include tree dumping on MSVC" OFF)


        set(_ERAZE_TREE_SHOWING_OPTION ${MSVC_NINJA_DISABLE_INCLUDE_TREE_DUMP})

        if (NOT ${MSVC_NINJA_DISABLE_INCLUDE_TREE_DUMP} AND NOT ${DISABLE_HINT_MSVC_NINJA})

            list(APPEND HINT_MESSAGE "MSVC and Ninja toolchain detected")
            list(APPEND HINT_MESSAGE "option \"MSVC_NINJA_DISABLE_INCLUDE_TREE_DUMP\" was explicitly set to OFF")
            list(APPEND HINT_MESSAGE "you will probably see the ENORMOUS include tree on compilation for EACH source file")
            list(APPEND HINT_MESSAGE "Here some links about it:")
            list(APPEND HINT_MESSAGE "https://discourse.cmake.org/t/showincludes-option-added-automatically/6706")
            list(APPEND HINT_MESSAGE "https://github.com/ninja-build/ninja/issues/2138")
            list(APPEND HINT_MESSAGE "https://github.com/ninja-build/ninja/issues/613")
            list(APPEND HINT_MESSAGE "I'd recommend you enable that option back for convenience")


            foreach(line ${HINT_MESSAGE})
                message(NOTICE "[CMAKE_DEV_HINT] " ${line})
            endforeach()

            message(NOTICE "[CMAKE_DEV_HINT] ")
            message(NOTICE "[CMAKE_DEV_HINT] To disable this [CMAKE_DEV_HINT] message set \"DISABLE_HINT_MSVC_NINJA\" option to ON")

            unset(HINT_MESSAGE)
        endif ()
    else()
        set(_ERAZE_TREE_SHOWING_OPTION FALSE)
    endif()

    if (${_ERAZE_TREE_SHOWING_OPTION})
        string(REPLACE "/showIncludes" "" CMAKE_DEPFILE_FLAGS_C ${CMAKE_DEPFILE_FLAGS_C})
        string(REPLACE "/showIncludes" "" CMAKE_DEPFILE_FLAGS_CXX ${CMAKE_DEPFILE_FLAGS_CXX})
    endif()

    unset(_ERAZE_TREE_SHOWING_OPTION)
endmacro()