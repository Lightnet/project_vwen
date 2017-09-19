#!python
import os

CURRENT_DIR = os.getcwd()

#--------
# Config files
#--------
SDL2_INCLUDE_PATH = 'C:\\SDL2-2.0.5\\include'
SDL2_LIB_PATH = 'C:\\SDL2-2.0.5\\lib\\x86'
IMGUI_PATH = 'src\\imgui'
#--------
# Main application folder dir and output folder
#--------
VS_TOOL_BAT = 'C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Auxiliary\\Build\\vcvars32.bat' #window


projectname = 'project_vwen'				#holds the project name
projectpackage = 'main'						#holds the project folder
SRC_PATH = 'src'
builddir = SRC_PATH                         #holds the build directory for this project
#-------

source_base_dir = '.'
build_base_dir = 'build'
target_name = 'project_vwen'

#thirdparty_libs = []
#thirdparty_includes = []

#--include files
include_packages = []
include_packages.append(SDL2_INCLUDE_PATH)
include_packages.append(CURRENT_DIR + os.sep +'src')
include_packages.append(CURRENT_DIR + os.sep +'vwen')

include_packages.append(CURRENT_DIR + os.sep +'api\\gl3w')
include_packages.append(CURRENT_DIR + os.sep +'api\\glfw\\include')

include_packages.append(CURRENT_DIR + os.sep +'api\\include')
include_packages.append(CURRENT_DIR + os.sep +'api\\include\\glad')
include_packages.append(CURRENT_DIR + os.sep +'api\\include\\imgui')

include_packages.append(CURRENT_DIR + os.sep +'api\\include\\imgui')


#include_packages.append(SRC_PATH)
#include_packages.append(IMGUI_PATH)


#--engine node packages
core_packages = []

core_packages.append('vwen')
#core_packages.append('imgui')
#core_packages.append('glad')
#core_packages.append('glm')
#core_packages.append('core')
#core_packages.append('server')
#core_packages.append('scene')
#core_packages.append('modules')
#core_packages.append('editor')

#third parties packages
lib_packages = []
#lib_packages.append('glm')
lib_packages.append('imgui')
lib_packages.append('opengl32')
lib_packages.append('gl3w')
lib_packages.append('glfw3')
lib_packages.append('glad')
lib_packages.append('SDL2main')
lib_packages.append('SDL2')
lib_packages.append('SDL2test')

#--add list
lib_packages += core_packages
include_packages +=core_packages