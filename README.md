# project_vwen

Project Name: Project_VWEN

Created by: Lightnet

License: MIT

Programs:
 * Visual Studio Code
 * Python 2.7.x
  * Scons (script builds)
 * VS2017 Window 10 (compiler tool)
 * Mingw (compiler tool)

Information: By using the python 2.7 scons script compiler build c/c++ application for Visual Studio Code to run task builds.


Third Parties:
 * Imgui
 * SDL 


[Scons Builds]:

Note the default tool is mingw but it might change later on.

[Mingw]

   `scons tool=mingw`
   
   * Does not work with GL3

[window 10 | viusal studio]

   `scons tool=window`

[Linux]

   `scons ::None yet` 

[Mac]

   `scons ::None yet` 

Notes:
 * Firewall or security programs can block builds and compilers.
 * vsbuild.bat need to config right dir. for vs2017