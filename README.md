# Description
Provides a graphical user interface for easy changing of dedicated server settings.  I wasn't a huge fan of editing the text file and thought hey wouldn't it be great if there was an easier way and thus this tool was born.  Written in Qt and C++ for cross platform support.

# Usage
Your current Settings.ini file should be loaded automatically showing you the settings as they are currently set or the defaults if they are unset.  If the file failed to load or you wish to edit a different file select the File dropdown and select Open to bring up a file browsing window to locate the settings file you wish to edit.   When you are finished editing go back to the File dropdown and select save, you will either get a success or fail message depending on whether or not the changes were committed.

# Development Status
This is a "work in progress" and by no means complete.  Basic functionality seems to be there but this is practically untested at this stage so use at your own risk.

Wishlist
- Better message handling if there are errors opening or saving files
- Linux (and possibly Mac) if it doesn't already work
- Add expandable area for 'Advanced' options
- Add another tabbed screen for 'World Generation' options.
- Add modlist/adminlist support
- Make settings 'configurable' through external xml file.
- Document code

# Notes
I'm a C# developer by trade so this was a new experience for me forcing me outside my comfort zone to learn something new.  I tried my best to follow good practices buy I'm sure there are improvements to be made.  If anyone viewing my work has any comments they'd like to make please feel free and if anyones interesting in contributing message me I'd love to talk improvements with another developer!

# Credits
This project uses the QDarkStyleSheet hosted here https://github.com/ColinDuquesnoy/QDarkStyleSheet
