if(VSF_TARGET)
    file(GLOB_RECURSE __targets_cmake ${VSF_CMAKE_ROOT}/targets*/${VSF_TARGET}.cmake)
    foreach(__target_cmake ${__targets_cmake})
        if(NOT IS_DIRECTORY ${__target_cmake})
            message(STATUS "using target: ${__target_cmake}")
            include(${__target_cmake})
            break()
        endif()
    endforeach()
endif()

if(VSF_HAL_CHIP_VENDOR AND VSF_ARCH_SERIES)
    message(STATUS "VSF_HAL_CHIP_VENDOR: ${VSF_HAL_CHIP_VENDOR}")
    if(VSF_ARCH_NAME)
        message(STATUS "VSF_ARCH_NAME: ${VSF_ARCH_NAME}")
    endif()
    message(STATUS "VSF_ARCH_SERIES: ${VSF_ARCH_SERIES}")
    if(VSF_HAL_CHIP_NAME)
        message(STATUS "VSF_HAL_CHIP_NAME: ${VSF_HAL_CHIP_NAME}")
    endif()
    if(VSF_HOST_SYSTEM)
        message(STATUS "VSF_HOST_SYSTEM: ${VSF_HOST_SYSTEM}")
    endif()
else()
    message(FATAL_ERROR "${VSF_TARGET} not supported")
endif()
