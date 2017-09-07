#!python 

# this script help compile builds

import platform
import os
import sys
import glob
from build_support import *
from build_config import *

print("Project Script Config!")
#print("Current Dir: " + os.getcwd())

#get the mode flag from the command line
#default to 'debug' if the user didn't specify
#projectmode = ARGUMENTS.get('mode', 'release')   #holds current mode
projectmode = ARGUMENTS.get('mode', 'debug')   #holds current mode
#print("MODE: "+projectmode)

projecttool = ARGUMENTS.get('tool', 'mingw')   #holds current mode
#projecttool = 'window'

print("**** TOOL:" + projecttool)

#check if the user has been naughty: only 'debug' or 'release' allowed
if not (projectmode in ['debug','release']):
	print("Error: expected 'debug' or 'release', found: " + projectmode)

#tell the user what we're doing
print('**** Compiling in ' + projectmode + ' mode...')

buildroot = './bin/' + projectmode			#holds the root of the build directory tree
targetpath = buildroot + '/' + projectname	#holds the path to the executable in the build directory



#--check for tool types
if projecttool == 'mingw': #mingw tool
	env = Environment(ENV = os.environ, tools = ['mingw'])
	env.Append(CCFLAGS = '-g')#-g (debug) flag
	#link lib
	env.Append(LINKFLAGS='-static-libgcc -static-libstdc++')
	#env.Append(LINKFLAGS='-static-libgcc -static-libstdc++ -lopengl32 -lgdi32')
elif projecttool == 'window': #window tool default to vs2017
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


#--------
# Operating System Checks and Tools
#--------
system = platform.system()

if system=='Windows':
	print("**** OS: WINDOW")
	if projecttool == 'window':
		print("**** Window Tool")
		# Something to do with link error
		env.Append(LINKFLAGS=['/SUBSYSTEM:CONSOLE'])
		env.Append(LINKFLAGS=['/NODEFAULTLIB:library'])
		#pass

	if projecttool == 'mingw':
		print("**** Mingw Tool")
		#pass

	env.Append(CPPPATH=include_packages) #SDL2, Imgui, Gl3w
	#Repository('C:\\SDL2-2.0.5\\include','imgui')
	#build lib file
	#--gl
	env.Library(buildroot + '\\gl3w',Glob('libs\\gl3w\\GL\\*.c')) #Gl3w
	env.Library(buildroot+'\\glfw3',"libs\\glfw\\lib-vs2015\\glfw3dll.lib") #glfw3

	#--imgui
	env.Library(buildroot + '\\imgui',Glob(IMGUI_PATH + '\\*.cpp')) #Imgui
	#--engine nodes
	#env.Library(buildroot + '\\editor',Glob('editor' + '\\*.cpp')) #editor
	for basename in core_packages:
		#print("package name:",basename)
		env.Library(buildroot + '\\'+ basename,Glob(basename + '\\*.cpp')) #core nodes
		pass

	#copy file or folder to bin dir
	env.Install(buildroot,"libs\\SDL2.dll") #copy dll to output

	env.Install(buildroot,"libs\\glfw\\lib-vs2015\\glfw3.dll") #copy dll to output
	#application
	if projecttool == 'mingw':
		#error for address get
		env.Program(targetpath, Glob(builddir + '\\*.cpp'),LIBS=['opengl32','gl3w','imgui','SDL2main','SDL2','SDL2test'],LIBPATH=['.',buildroot ,SDL2_LIB_PATH])

	if projecttool == 'window':
		env.Program(targetpath, Glob(builddir + '\\*.cpp'), LIBS=lib_packages, LIBPATH=['.', buildroot, SDL2_LIB_PATH])

print("**** Script Finish Here! Win32")