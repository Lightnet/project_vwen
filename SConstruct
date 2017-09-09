#!python 
# this script help compile builds
import platform
import os
import sys
import glob

from build_config import * #build configs
from build_support import * #build helper

print("Project Script Config!")

#get the mode flag from the command line
#default to 'release' if the user didn't specify
projectmode = ARGUMENTS.get('mode', 'release')   #holds current mode
projecttool = ARGUMENTS.get('tool', 'window')   

#print("**** TOOL:" + projecttool)

#check if the user has been naughty: only 'debug' or 'release' allowed
if not (projectmode in ['debug','release']):
	print("Error: expected 'debug' or 'release', found: " + projectmode)

#tell the user what we're doing
print('**** Compiling in ' + projectmode + ' mode...')

buildroot = './bin/' + projectmode			#holds the root of the build directory tree
targetpath = buildroot + '/' + projectname	#holds the path to the executable in the build directory

if projecttool == 'window': #window tool default to vs2017
	#http://scons.org/doc/0.97/HTML/scons-man.html
	#need to lanuch vcvars32.bat script so it can be add to os.environ else it will display 'cl' is not recognized as an internal or external command
	#this will deal with the Visual Studio 
	#env = Environment(ENV = os.environ, MSVC_USE_SCRIPT=VS_TOOL_BAT)
	env = Environment(ENV = os.environ) #this load user complete external environment

else:
	#default current tool from os
	env = Environment(ENV = os.environ) #this load user complete external environment
	#pass

# variables the sub build directories need
#Export('env', 'sources', 'static_libs', 'test_sources')
Export('env')

# build path
target_dir = '#' + SelectBuildDir(build_base_dir)
SConscript(target_dir + os.sep + 'SConscript')

#env.Append(LINKFLAGS=['/SUBSYSTEM:CONSOLE']) #SDL2 need this

for basename in core_packages:
	include_packages.append(SRC_PATH + os.sep + basename) #header file basefile.h
print("Include:")
print(include_packages)
env.Append(CPPPATH=include_packages) #SDL2, Imgui, Gl3w
#build lib file
#--gl
env.Library(buildroot + os.sep + 'gl3w',Glob('libs\\gl3w\\GL\\*.c')) #Gl3w
env.Library(buildroot + os.sep + 'glfw3',"libs\\glfw\\lib-vs2015\\glfw3dll.lib") #glfw3
#--sdl2
#env.Library(buildroot + os.sep + 'SDL2',Glob("C:\\SDL2-2.0.5\\lib\\x86\\*.lib")) #
#env.Library(buildroot + os.sep + 'SDL2', "C:\\SDL2-2.0.5\\lib\\x86\\SDL2.lib") #
#env.Library(buildroot + os.sep + 'SDL2main',"C:\\SDL2-2.0.5\\lib\\x86\\SDL2main.lib") #
#env.Library(buildroot + os.sep + 'SDL2test',"C:\\SDL2-2.0.5\\lib\\x86\\SDL2test.lib") #

for basename in core_packages:
	env.Library(buildroot + os.sep + basename, Glob(SRC_PATH + os.sep + basename + os.sep + '*.cpp')) #core nodes
	pass

print(core_packages)
#--SDL2
env.Install(buildroot,"libs\\SDL2.dll") #copy dll to output bin
#--glfw3
#env.Install(buildroot,"libs\\glfw\\lib-vs2015\\glfw3.dll") #copy dll to output bin
#application
#print("LIBS:")
#print(lib_packages)
#print("Bin:")
#print(buildroot)
#print("Main:",builddir + os.sep + '*.cpp')
env.Program(targetpath, Glob(builddir + os.sep + '*.cpp'), LIBS=lib_packages, LIBPATH=['.','src', buildroot, SDL2_LIB_PATH])

print("**** Script Finish Here!")