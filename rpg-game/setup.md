# Language Standard
Properties-> General -> All Configuration
Languagu Standard: C++17

# Include Path
### Library Directories
Properties->VC++Directory
1. Include Directories: $(SolutionDir)dependencies\SFML\include
2. Include Libraries: $(SolutionDir)dependencies\SFML\lib

### Preprocessor
C/C++ -> Preprocessor
All Configuration
Preprocessor Definitions: add `SFML_STATIC`

### Linker
Linker -> Include -> All Dependencies 
1. Release Configuration
```
sfml-graphics-s-d.lib
sfml-window-s-d.lib
sfml-system-s-d.lib
opengl32.lib
freetype.lib
winmm.lib
gdi32.lib
sfml-audio-s-d.lib
flac.lib
vorbisenc.lib
vorbisfile.lib
vorbis.lib
ogg.lib
sfml-network-s-d.lib
ws2_32.lib
```
2. Debug Configuration
```
sfml-graphics-s-d.lib
sfml-window-s-d.lib
sfml-system-s-d.lib
opengl32.lib
freetype.lib
winmm.lib
gdi32.lib
sfml-audio-s-d.lib
flac.lib
vorbisenc.lib
vorbisfile.lib
vorbis.lib
ogg.lib
sfml-network-s-d.lib
ws2_32.lib
```

### Build Folder
Set up output and intermediate folders:
```
$(SolutionDir)Build\$(Platform)\$(Configuration)\bin\
$(SolutionDir)Build\$(Platform)\$(Configuration)\Intermediate\
```
