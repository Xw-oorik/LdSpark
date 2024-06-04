# LdSpark
Server stress testing software

## Currently supported:
+ Support multi-task stress testing
+ Skin resurfacing operation
+ Real number data display
+ Selectively export data indicator trend charts
+ Support proxy, built-in tinyproxy proxy
+ Currently only supports Http and Https, and performs stress testing on the web server.

## Operating environment: 
macOS, qt5/qt6

## Operating instructions:
Execute in the project root directory: mkdir build
Enter the build directory: cd build
Execute the cmakelists script to generate the makefile build system: cmake..
Read the makefile build task (compile, link): make -> The generated executable program is in build/LdSpark.app/Contents/MacOS/LdSpark
Run the program: ./LdSpark.app/Contents/MacOS/LdSpark
If you have configured cmake of vscode by yourself, just build and run it directly.

# Main interface:
<img width="870" alt="image" src="https://github.com/Xw-oorik/LdSpark/assets/117898635/bac27c20-2576-42cf-88a3-e286d384b99d">
