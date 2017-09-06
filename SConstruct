#!python 
import platform
import os
import sys
import glob

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

#--------
# Config files
#--------
SDL2_INCLUDE_PATH = 'C:\\SDL2-2.0.5\\include'
SDL2_LIB_PATH = 'C:\\SDL2-2.0.5\\lib\\x86'
IMGUI_PATH = 'imgui'
#--------
# Main application folder dir and output folder
#--------
projectname = 'project_vwen'				#holds the project name
projectpackage = 'main'						#holds the project folder
buildroot = './bin/' + projectmode			#holds the root of the build directory tree
builddir = './' + projectpackage  			#holds the build directory for this project
targetpath = buildroot + '/' + projectname	#holds the path to the executable in the build directory
#-------

if projecttool == 'mingw': #mingw tool
	env = Environment(ENV = os.environ, tools = ['mingw'])
	env.Append(CCFLAGS = '-g')#-g (debug) flag
	#link lib
	env.Append(LINKFLAGS='-static-libgcc -static-libstdc++')
elif projecttool == 'window': #window tool default to vs2017
	#http://scons.org/doc/0.97/HTML/scons-man.html
	#need to lanuch vcvars32.bat script so it can be add to os.environ else it will display 'cl' is not recognized as an internal or external command
	#this will deal with the Visual Studio 
	env = Environment(ENV = os.environ) #this load user complete external environment
else:
	#default current tool from os
	env = Environment(ENV = os.environ) #this load user complete external environment
	#pass

system = platform.system()

#thirdparty_libs = []

#--------
# Operating System Checks and Tools
#--------
if system=='Windows':
	print("**** OS: WINDOW")
	if projecttool == 'window':
		print("**** Window Tool")
		# Something to do with link error
		env.Append(LINKFLAGS=['/SUBSYSTEM:CONSOLE'])
		#pass

	if projecttool == 'mingw':
		print("**** Mingw Tool")
		#pass

	env.Append(CPPPATH=[SDL2_INCLUDE_PATH,IMGUI_PATH])
	#Repository('C:\\SDL2-2.0.5\\include','imgui')
	#build lib file
	env.Library(buildroot + '\\imgui',Glob(IMGUI_PATH + '\\*.cpp'))
	#copy file or folder to bin dir
	env.Install(buildroot,"libs\SDL2.dll")
	#application
	env.Program(targetpath, Glob(builddir + '\\*.cpp'),LIBS=['opengl32','imgui','SDL2main','SDL2','SDL2test'],LIBPATH=['.',buildroot ,SDL2_LIB_PATH])


print("**** Script Finish Here! Win32")