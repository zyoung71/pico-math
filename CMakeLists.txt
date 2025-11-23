if (NOT TARGET pico-math)

    add_library(pico-math INTERFACE)

    target_include_directories(pico-math
        PUBLIC
            include
        PRIVATE
            src
    )

endif()