
include(CMakeDependentOption)
include(CMakeParseArguments)


macro(MJPG_STREAMER_PLUGIN_OPTION MODULE_NAME DESCRIPTION)

	cmake_parse_arguments(MSPOM
						  "" "" "ONLYIF" ${ARGN})
					  
	string(TOUPPER "PLUGIN_${MODULE_NAME}" OPT_ENABLE)
	string(TOUPPER "PLUGIN_${MODULE_NAME}_AVAILABLE" OPT_AVAILABLE)
	
	cmake_dependent_option(${OPT_ENABLE} "${DESCRIPTION}" ON "${MSPOM_ONLYIF}" OFF)
	
	if (${OPT_AVAILABLE})
		add_feature_info(${OPT_ENABLE} ${OPT_ENABLE} "${DESCRIPTION}")
	else()
		add_feature_info(${OPT_ENABLE} ${OPT_ENABLE} "${DESCRIPTION} (unmet dependencies)")
	endif()

endmacro()

macro(MJPG_STREAMER_PLUGIN_COMPILE MODULE_NAME)
	
	string(TOUPPER "${MODULE_NAME}" ARGU)
	set(OPT_ENABLE "PLUGIN_${ARGU}")
	
	if (${OPT_ENABLE})
	
		set(MOD_SRC)
		foreach(arg ${ARGN})
			list(APPEND MOD_SRC "${arg}") 
		endforeach()
		
		add_library(${MODULE_NAME} SHARED ${MOD_SRC})
	    set_target_properties(${MODULE_NAME} PROPERTIES PREFIX "")
	    
		install(TARGETS ${MODULE_NAME} DESTINATION ${MJPG_STREAMER_PLUGIN_INSTALL_PATH})	
	endif()
	
endmacro()


macro(add_feature_option OPTVAR DESCRIPTION DEFAULT)
	option(${OPTVAR} "$DESCRIPTION" ${DEFAULT})
	add_feature_info(${OPTVAR} ${OPTVAR} "${DESCRIPTION}")
endmacro()
