#--------------------------------------------------------------------
# Inviwo OpenCL Module
ivw_module(OpenCL)

#--------------------------------------------------------------------
# Add header files
set(HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/buffercl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/bufferclbase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/bufferclconverter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/bufferclgl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/bufferclglconverter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cl.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/clformats.h
    ${CMAKE_CURRENT_SOURCE_DIR}/clockcl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/glmcl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/image/imagecl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/image/imageclgl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layercl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclbase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclconverter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclgl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclglconverter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclresizer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/inviwoopencl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/kernelmanager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/kernelowner.h
    ${CMAKE_CURRENT_SOURCE_DIR}/light/packedlightsource.h
    ${CMAKE_CURRENT_SOURCE_DIR}/openclcapabilities.h
    ${CMAKE_CURRENT_SOURCE_DIR}/openclexception.h
    ${CMAKE_CURRENT_SOURCE_DIR}/openclformatexception.h
    ${CMAKE_CURRENT_SOURCE_DIR}/openclmodule.h
    ${CMAKE_CURRENT_SOURCE_DIR}/settings/openclsettings.h
    ${CMAKE_CURRENT_SOURCE_DIR}/syncclgl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/utilcl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumecl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumeclbase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumeclconverter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumeclgl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumeclglconverter.h
)
ivw_group("Header Files" ${HEADER_FILES})

#--------------------------------------------------------------------
# Add source files
set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/buffercl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/bufferclbase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/bufferclconverter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/bufferclgl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer/bufferclglconverter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/clformats.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/clockcl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/glmcl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image/imagecl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image/imageclgl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layercl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclbase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclconverter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclgl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclglconverter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image/layerclresizer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inviwoopencl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kernelmanager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kernelowner.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/light/packedlightsource.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/openclcapabilities.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/openclexception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/openclformatexception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/openclmodule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/settings/openclsettings.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/syncclgl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumecl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumeclbase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumeclconverter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumeclgl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/volume/volumeclglconverter.cpp
)
ivw_group("Source Files" ${SOURCE_FILES})

#--------------------------------------------------------------------
# Add OpenCL files
set(SHADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/datastructures/bbox.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/datastructures/lightsource.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/intersection/rayboxintersection.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/intersection/raydiscintersection.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/intersection/rayplaneintersection.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/intersection/raysphereintersection.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/intersection/raytriangleintersection.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/shading/abcbrdf.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/shading/ashikiminbrdf.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/shading/blinnphongbrdf.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/shading/cooktorrancebrdf.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/shading/microfacet.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/shading/phasefunctions.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/shading/shading.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/shading/shadingmath.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/shading/wardbrdf.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/colorconversion.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/gradients.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/image3d_write.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/img_resize.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/samplers.cl
    ${CMAKE_CURRENT_SOURCE_DIR}/cl/transformations.cl
)
ivw_group("Shader Files" ${SHADER_FILES})

#--------------------------------------------------------------------
# Add definition
ivw_add_definition(__CL_ENABLE_EXCEPTIONS)


set(TEST_FILES
    #${CMAKE_CURRENT_SOURCE_DIR}/test/opencl-test.cpp
)
ivw_add_unittest(${TEST_FILES})

#--------------------------------------------------------------------
# Create module
ivw_create_module(${SOURCE_FILES} ${HEADER_FILES} ${SHADER_FILES})

#--------------------------------------------------------------------
# Add kernel directory to pack
ivw_add_to_module_pack(${CMAKE_CURRENT_SOURCE_DIR}/cl)
