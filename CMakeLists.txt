include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
ExternalProject_Add(gamma
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}"
    INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ${CMAKE_COMMAND} -E env
        make -C <SOURCE_DIR> gamma
    BUILD_IN_SOURCE TRUE
    INSTALL_COMMAND ${CMAKE_COMMAND} -E env
        make -C <SOURCE_DIR> DESTDIR=<INSTALL_DIR> gamma install
)
set(GAMMA_INC "${CMAKE_CURRENT_SOURCE_DIR}/build/include" PARENT_SCOPE)
set(GAMMA_LIB "${CMAKE_CURRENT_SOURCE_DIR}/build/lib/libGamma.a" PARENT_SCOPE)
set(GAMMA_LIB_DEPS 
    m stdc++
    "-framework AudioUnit" "-framework AudioToolbox" "-framework CoreAudio" "-framework Carbon"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/lib_osx/libportaudio.a"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/lib_osx/libsndfile.a"
    PARENT_SCOPE)