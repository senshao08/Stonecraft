# Stonecraft [![Build Status](https://travis-ci.org/MrCerealGuy/Stonecraft.svg?branch=master)](https://travis-ci.org/MrCerealGuy/Stonecraft) [![License]https://img.shields.io/badge/license-LGPLv3.0%2B-blue.svg)](https://www.gnu.org/licenses/lgpl.html)

An InfiniMiner/Minecraft inspired game powered by Minetest 0.5.0-dev

Copyright (c) 2016-2018 Andreas "MrCerealGuy" Zahnleiter <mrcerealguy@gmx.de> and contributors


## Further documentation

- Website: http://mrcerealguy.github.io/stonecraft
- Wiki: http://github.com/mrcerealguy/stonecraft/wiki
- Github: https://github.com/mrcerealguy/stonecraft


## This game is not finished

- Don't expect it to work as well as a finished game will.
- Please report any bugs. When doing that, debug.txt is useful.


## Default Controls

```
Move mouse: Look around
W, A, S, D: Move
Space: Jump/move up
Strg: Sneak/move down
Q: Drop itemstack
Shift + Q: Drop single item
Left mouse button: Dig/punch/take item
Right mouse button: Place/use
Shift + right mouse button: Build (without using)
I: Inventory menu
Mouse wheel: Select item
0-9: Select item
Z: Zoom
T: Chat
/: Command
Esc: Pause menu/abort/exit (pauses only singleplayer game)
R: Enable/disable full range view
+: Increase view range
-: Decrease view range
K: Enable/disable fly mode (needs fly privilege)
J: Enable/disable fast mode (needs fast privilege)
H: Enable/disable noclip mode (needs noclip privilege)
F1: Hide/show HUD
F2: Hide/show chat
F3: Disable/enable fog
F4: Disable/enable camera update (Mapblocks are not updated anymore when disabled, disabled in release builds)
F5: Cycle through debug info screens
F6: Cycle through profiler info screens
F7: Cycle through camera modes
F8: Toggle cinematic mode
F9: Cycle through minimap modes
Shift + F9: Change minimap orientation
F10: Show/hide console
F12: Take screenshot
P: Write stack traces into debug.txt
```

Most controls are settable in the configuration file, see the section below.


## World directory

- Worlds can be found as separate folders in:
```
<stonecraft-folder>/worlds/
```


## Configuration file

- Default location:
```
<stonecraft-folder>/stonecraft.conf
```

- It is created by Stonecraft when it is ran the first time.
- A specific file can be specified on the command line:
```
--config <path-to-file>
```


## Command-line options

```
Use --help
```


# Building GNU/Linux 

**Install dependencies**. Here's an example for Debian/Ubuntu:
```
$ sudo apt-get install git-core build-essential libirrlicht-dev cmake libstdc++6 libbz2-dev libpng-dev libjpeg-dev libxxf86vm-dev libgl1-mesa-dev libsqlite3-dev libogg-dev libvorbis-dev libopenal-dev libcurl4-gnutls-dev libfreetype6-dev zlib1g-dev libgmp-dev libjsoncpp-dev doxygen mingw-w64 libgd-dev libleveldb-dev libhiredis-dev libncurses-dev liblua5.2-dev dialog libluajit-5.1-dev
```

**Download source** (this is the URL to the latest of source repository, which might not work at all times) using git:
```
$ git clone --depth 1 https://github.com/mrcerealguy/stonecraft.git
$ cd stonecraft
```

Build a version that **runs directly** from the stonecraft directory:
```
$ cmake . -DBUILD_CLIENT=1 -DENABLE_GETTEXT=1 -DENABLE_FREETYPE=1 -DENABLE_LEVELDB=1 -DENABLE_REDIS=1 -DRUN_IN_PLACE=1
$ make -j$(grep -c processor /proc/cpuinfo) 
```
or run the build script
```
$ cd build
$ <stonecraft-folder>/build/build_linux_client.sh
```

Run it:
```
$ <stonecraft-folder>/bin/stonecraft
```

To build the **dedicated server** without the client, you have to run the script build_linux_server.sh.

# Building Windows on GNU/Linux (cross-compiling)

Please install source and dependencies like above. I've used **MinGW-w64 7.1.1 20170516** for cross-compiling.

**Download libraries**  

Please clone the Windows libraries for MinGW via github:

```
$ cd <stonecraft-folder>/lib
$ git clone --depth 1 https://github.com/MrCerealGuy/Stonecraft-libdev-win.git libdev-win
$ mv ./libdev-win/* ../
$ rm -Rf ./libdev-win
```

**Win 32-Bit**
```
$ <stonecraft-folder>/build/build_win32_client.sh
```

You'll find the build in &lt;stonecraft-folder&gt;/build/win-i686 and the ZIP-package in the subdirectory _build.

**Win 64-Bit**
```
$ <stonecraft-folder>/build/build_win64_client.sh
```

You'll find the build in &lt;stonecraft-folder&gt;/build/win-x86_64 and the ZIP-package in the subdirectory _build.

# Building Android on GNU/Linux

This is a simple guide on how to build Stonecraft for Android on a Debian-based 64 bit system. Building on 32 bit systems should work too when the URLs and paths are replaced accordingly. This guide covers all preparation needed. Once everything is set up, Stonecraft only needs cd build/android && make to compile.

**Required packages**  
Git, Make, and other basic tools are neccessary: 

```
$ sudo apt-get update
$ sudo apt-get install make m4 subversion git-core build-essential realpath openjdk-8-jdk 
$ sudo apt-get install libc6-i386 lib32stdc++6 lib32gcc1 lib32ncurses5
```

Gradle is required as well. If your distribution gives you gradle 2.10 or later (like Ubuntu 16.04 does), you may simply do:

```
$ sudo apt-get install gradle
```

If your distribution ships with an older version of gradle, you may grab a recent version of gradle via a PPA:

```
$ sudo add-apt-repository ppa:cwchien/gradle
$ sudo apt-get install gradle-2.13 
```

As your architecture is 64 bit, you need additional packages.

On newer systems do: (Ubuntu 16.04-ish): 

```
$ sudo apt-get install lib32z1 
```

On older systems do:

```
$ sudo apt-get install --force-yes libgd2-xpm ia32-libs ia32-libs-multiarch
```

**Getting the SDK and NDK**  
Both SDK and NDK are needed:

```
$ wget https://dl.google.com/android/android-sdk_r24.4.1-linux.tgz 
$ wget https://dl.google.com/android/repository/android-ndk-r11c-linux-x86_64.zip 
```
```
$ tar xf android-sdk_r24.4.1-linux.tgz 
$ unzip android-ndk-r11c-linux-x86_64.zip 
```

```
$ android-sdk-linux/tools/android update sdk --no-ui -a --filter platform-tool,android-25,build-tools-25.0.1 
```

The last line will ask for your confirmation multiple times.

**Obtaining and building Stonecraft**  
Clone Stonecraft, and build it:

```
$ git clone --depth 1 https://github.com/mrcerealguy/stonecraft.git
$ cd stonecraft/build/android 
$ make 
```

To install Stonecraft to your android device, type:

```
$ make install_debug
```


The make file will ask you for the paths to your SDK and NDK. It will then download and build all required libraries. Finally it will build Stonecraft and the Java sources and pack everything into a debug-signed APK.
	
# License of Stonecraft textures and sounds

This applies to textures and sounds contained in the main Stonecraft distribution.

Attribution-ShareAlike 3.0 Unported (CC BY-SA 3.0)
http://creativecommons.org/licenses/by-sa/3.0/


# Authors of media files


See README.txt in each mod/textures directory for information about other authors.


# License of Stonecraft source code

Stonecraft
Copyright (C) 2016-2017 Andreas "MrCerealGuy" Zahnleiter <mrcerealguy@gmx.de>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


# License of Minetest Engine source code

Minetest Engine
Copyright (C) 2010-2013 celeron55, Perttu Ahola <celeron55@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


# Irrlicht

This program uses the Irrlicht Engine. http://irrlicht.sourceforge.net/

 The Irrlicht Engine License

Copyright © 2002-2005 Nikolaus Gebhardt

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you
      must not claim that you wrote the original software. If you use
      this software in a product, an acknowledgment in the product
      documentation would be appreciated but is not required.
   2. Altered source versions must be plainly marked as such, and must
      not be misrepresented as being the original software.
   3. This notice may not be removed or altered from any source
      distribution.


# JThread

This program uses the JThread library. License for JThread follows:

Copyright (c) 2000-2006  Jori Liesenborgs (jori.liesenborgs@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.


# Lua

Lua is licensed under the terms of the MIT license reproduced below.
This means that Lua is free software and can be used for both academic
and commercial purposes at absolutely no cost.

For details and rationale, see http://www.lua.org/license.html .

Copyright (C) 1994-2008 Lua.org, PUC-Rio.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.


# Fonts

DejaVu Sans Mono:

  Fonts are (c) Bitstream (see below). DejaVu changes are in public domain.
  Glyphs imported from Arev fonts are (c) Tavmjong Bah (see below)

Bitstream Vera Fonts Copyright:

  Copyright (c) 2003 by Bitstream, Inc. All Rights Reserved. Bitstream Vera is
  a trademark of Bitstream, Inc.

Arev Fonts Copyright:

  Copyright (c) 2006 by Tavmjong Bah. All Rights Reserved.

Liberation Fonts Copyright:

  Copyright (c) 2007 Red Hat, Inc. All rights reserved. LIBERATION is a trademark of Red Hat, Inc.

DroidSansFallback:

  Copyright (C) 2008 The Android Open Source Project

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
