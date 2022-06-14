include(ExternalProject)

function(BuildExternalLibraries)
  ExternalProject_Add(rpclib
    PREFIX ${CMAKE_CURRENT_LIST_DIR}/ext/rpclib
    GIT_REPOSITORY https://github.com/edgerunnerdev/rpclib.git
	GIT_TAG 0de1a4f62d3e6cd4f3b2fd281044fb9f2b147267
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR> -DRPCLIB_MSVC_STATIC_RUNTIME=ON
  )
endfunction()