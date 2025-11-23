if (NOT TARGET pico-math)

    add_library(pico-math INTERFACE)

    target_include_directories(pico-math INTERFACE
        include
    )

    target_include_directories(pico-math INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src> 
    )

endif()