# newbuuz
This is a poor man's implementation of https://code.google.com/archive/p/buuz/downloads for OSX.

## Why?
The sole reason to write this is to have highly customizable keyboard. For example, we could have two physical keyboards and one of them is used for typing English and the other for typing Mongolian(Cyrillic) without having to switch keyboard from the settings.

## Other Mongolian Cyrillic keyboards
Here is a much fancier keyboard that you can use out-of-box.
http://www.studymongolian.net/technical/mongolian-keyboard-for-macos/


## How to use
Press Option+Shift+fn to deactivate and activate Mongolian Keyboard.
In the CLI logs you should see alternating message between "Mongolian keyboard is in use" and "The other keyboard is in use"

## Building from the source.
1. Make sure to have cmake and make installed.
2. Build with `make`.
3. Run with `make run`.
