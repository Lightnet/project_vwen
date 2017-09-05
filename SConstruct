#!python 
import os
import sys
import glob

print("Project Script Config!")
#print("Current Dir: " + os.getcwd())

#get the mode flag from the command line
#default to 'release' if the user didn't specify
projectmode = ARGUMENTS.get('mode', 'release')   #holds current mode
#print("MODE: "+projectmode)

projecttool = ARGUMENTS.get('tool', 'mingw')   #holds current mode
#projecttool = 'window'

print("**** TOOL:" + projecttool)

#check if the user has been naughty: only 'debug' or 'release' allowed
if not (projectmode in ['debug','release']):
	print("Error: expected 'debug' or 'release', found: " + projectmode)

#tell the user what we're doing
print('**** Compiling in ' + projectmode + ' mode...')

#buildroot = '../' + projectmode   #holds the root of the build directory tree
#debugcflags = ['-W1', '-GX', '-EHsc', '-D_DEBUG', '/MDd']   #extra compile flags for debug
#releasecflags = ['-O2', '-EHsc', '-DNDEBUG', '/MD']         #extra compile flags for release
#debugcflags = ['-W1', '-GX', '-EHsc', '-D_DEBUG', '/MDd']
#releasecflags = ['-O2', '-EHsc', '-DNDEBUG', '/MD']
#-------

project = 'helloworld'					#holds the project name
buildroot = './bin/' + projectmode		#holds the root of the build directory tree
builddir = './' + project  				#holds the build directory for this project
targetpath = buildroot + '/' + project	#holds the path to the executable in the build directory

#print("BUILD builddir:" + builddir)
#print("BUILD targetpath:" + targetpath)

if sys.platform == 'win32':
	pass

if projecttool == 'mingw': #mingw tool
	env = Environment(tools = ['mingw'])

elif projecttool == 'window': #window tool default to vs2017
	#http://scons.org/doc/0.97/HTML/scons-man.html
	#env = Environment(ENV = {'PATH' : os.environ['PATH']}) # Initialize the environment
	#need to lanuch vcvars32.bat script so it can be add to os.environ else it will display 'cl' is not recognized as an internal or external command
	#this will deal with the Visual Studio 
	env = Environment(ENV = os.environ) #this load user complete external environment
	#env = Environment(ENV = {'PATH' : os.environ['PATH']}, MSVC_USE_SCRIPT = "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Auxiliary/Build/vcvars32.bat") # Initialize the environment
	#env = Environment(ENV = {'PATH' : os.environ['PATH']}, MSVC_VERSION='14.0') # Initialize the environment
	#env = Environment(ENV = {'PATH' : os.environ['PATH']}) # Initialize the environment
	#env.PrependENVPath('PATH', 		'C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.11.25503/bin/HostX86/x86/')
	#env.AppendENVPath('LIB', 		'C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.11.25503/lib/x86/')

	#env.AppendENVPath('LIB', 		'C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.11.25503/lib/x86')
	#env.AppendENVPath('LIB', 		'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.15063.0/um/x86')
	#env.AppendENVPath('LIB', 		'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.15063.0/ucrt/x86')

	#This deal with link tmp build
	#env['ENV']['TMP'] = os.environ['TMP']
	#env.Append(CPPDEFINES = ['DEBUG', '_DEBUG'])
	#env.Append(CCFLAGS='/MDd')
	#env.Append(CCFLAGS=Split('/Zi /Fd${TARGET}.pdb'))
	#env.Append(LINKFLAGS = ['/DEBUG'])
else:
	#default current tool from os
	env = Environment(ENV = os.environ) #this load user complete external environment
	pass
# https://stackoverflow.com/questions/15934944/how-to-build-c-project-with-scons-2-3-visual-express-2012
#append the user's additional compile flags
#assume debugcflags and releasecflags are defined
#env.Append(CCFLAGS = '-fno-strict-aliasing') # for angelscript compile see doc
cur_dir = os.getcwd()
env.Append(CCFLAGS = '-I ' + cur_dir) # for boost find in include path
#env.Append(CCFLAGS = '-g -std=c++0x -Wall -Wfatal-errors') #-msse2 -pg
env.Append(LINKFLAGS=[]) # -pg

#specify the build directory
VariantDir('#' + builddir, "#.", duplicate=0)


env.Program(target = targetpath,source = [ "helloworld/helloworld.c"])


print("**** Script Finish Here!")

#if projectmode == 'debug':
	#env.Append(CCFLAGS=debugcflags)
	#pass
#else:
	#env.Append(CCFLAGS=releasecflags)
	#pass
#Repository('c:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.11.25503/include/')
#env.Program(targetpath, source=map(lambda x: '#' + builddir + '/' + x, glob.glob('*.c')))
#env.Program(targetpath, source = [ "helloworld/hello.c"])

#print("BUILD DIR:" + builddir)
#if projecttool == 'mingw':
	#env.Program(targetpath, source = [ "helloworld/hello.c"])
#if projecttool == 'vs2017':
	#env.Program(targetpath, source = [ "helloworld/hellovs2017.c"])

#env = Environment(ENV = {'PATH' : os.environ['PATH']}) # Initialize the environment
#if ARGUMENTS.get('debug', 0):
	#print("DEBUG MODE")
	#env = Environment(tools = ['mingw'],CCFLAGS = '-g') # Initialize the environment
#else:
	#print("Other")
	#env = Environment(tools = ['mingw']) # Initialize the environment	
#env.Program(target = 'bin/helloworld', source = [ "src/hello.c"])