# Electron Diable Minimize

![image](https://badgen.net/badge/platform/Windows%20only?list=1)
[![npm version](https://badge.fury.io/js/electron-disable-minimize.svg)](https://badge.fury.io/js/electron-disable-minimize)
![Build Module](https://github.com/tbvjaos510/electron-disable-minimize/workflows/Build%20Module/badge.svg)

This module allow you to set the window attached to the HWND handle to disable minimized.

Electron indeed have a ```minimizable: false``` but it minimized at Windows + D (Show Desktop) Event.

This module set window parents to Desktop HWND("SHELLDLL_DefView")

## Installation

This module only works in windows, but installable mac and linux. (mac and linux nothing's going to happen.)

### 1. Install Module

```shell
npm i -S electron-disable-minimize   # or yarn add electron-disable-minimize
```

### 2. Rebuild Package

```shell
"./node_modules/.bin/electron-rebuild"  # rebuild native module
```

or you can rebuild automatically!

```json
// package.json
...
"scripts": {
  "install": "./node_modules/.bin/electron-rebuild"
}
...
```

```shell
npm install # it also run "./node_modules/.bin/electron-rebuild"
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
const mainWindow = new BrowserWindow({
    height: 800,
    width: 800,
    useContentSize: true,
    transparent: !isDev,
    frame: isDev,
    focusable: isDev,
    show: false
});

mainWindow.loadURL(__dirname + "/index.html");
mainWindow.show();

// get the native HWND handle
const handle = mainWindow.getNativeWindowHandle();

// disable minimize perfectly!
const isSuccess = DisableMinimize(handle);

console.log(isSuccess); // boolean
```

If false returned, disable minimize failed. (for the same reason as run in other platforms)

## Authors

* **tbvjaos510** - [tbvjaos510](https://github.com/tbvjaos510/)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
