# Desktop Window Manager
This is a decompilation of the Windows 7's DWM.

## Disclaimer:
This decompilation is:

- not meant for developing Wine or ReactOS

- not for Linux, as it requires a lot of Windows components

- not for normal use, as ending normal DWM in Windows makes it unusable.

# Source tree

The DWM decompiled source code is defined by:

- bin\ - It contains the placefile (bin\placefil.txt) used for binplacing the DWM components.

- udwm\ - The uDWM.dll library.

- windowmanager\ - The dwm.exe.

In a more aesthetic way, it should be represented as:

DWM
+---udwm
|
+---windowmanager

# Building
For building, you need the Windows 7.1.0 Driver Development Kit.

After installation, run the x64 Checked (or free) Build Environment and put the following command: `build -cZP`. This will invoke the Build Utility (a.k.a Microsoft NT Build Engine) which will compile the Desktop Window Manager

## Quirks
Currently, only building in x64 is supported. Plans for any x86 fixes are in the works.