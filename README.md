![image](https://badgen.net/badge/platform/Windows%20only?list=1) (PR welcome for linux and Mac!)

This module allow you to set the window attached to the HWND handle to disable minimized.

Electron indeed have a ```minimizable: false``` but it minimized at Windows + D (Show Desktop) Event.

This module uses the following c++ code. (Thanks to [tordex](https://stackoverflow.com/questions/35045060/how-to-keep-window-visible-at-all-times-but-not-force-it-to-be-on-top))

```cpp
HWND nWinHandle = FindWindowEx(NULL, NULL, "Progman", NULL);
nWinHandle = FindWindowEx(nWinHandle, NULL, "SHELLDLL_DefView", NULL);
SetWindowLongPtr(hwnd, -8, (LONG_PTR)nWinHandle);
```

## Installation

```shell
npm i -S electron-disable-minimize   # install the module

"./node_modules/.bin/electron-rebuild" -f -w electron-disable-minimize   # rebuild the module to match your electron version
```

## Usage
Look at the index.html, index.js and package.json file to integrate it into your Electron application

Basically it consists of 2 steps

* Include the module in your .js file:
```js
import { DisableMinimize } from 'electron-disable-minimize';
 - or -
const { DisableMinimize } = require('electron-disable-minimize');
```
* Create your Electron BrowserWindow
```js
let mainWindow = new BrowserWindow({
    height: 800,
    width: 800,
    useContentSize: true,
    transparent: !isDev,
    frame: isDev,
    focusable: isDev,
    show: false
});

// load it
mainWindow.loadURL(__dirname + "/index.html");

//show it
mainWindow.show();

// get the native HWND handle
let handle = mainWindow.getNativeWindowHandle();

// Disable Minimize Perfectly!
DisableMinimize(handle); // boolean

```
If false is returned, the desktop handle cannot be found.

It didn't work on specific windows version, Uupdate Windows and retry.

## Forked from

* [electron-bottom-most](https://github.com/Armaldio/electron-bottom-most)

## Authors

* **tbvjaos510** - [tbvjaos510](https://github.com/tbvjaos510/)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
