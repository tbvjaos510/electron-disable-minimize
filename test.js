const { app, BrowserWindow } = require('electron');
const path = require('path');
const url = require('url');
const { DisableMinimize } = require('./build/Release/electron-disable-minimize');

let win;

function createWindow() {
    win = new BrowserWindow({
        width: 800,
        height: 600,
        show: false,
    });

    win.loadURL(url.format({
        pathname: path.join(__dirname, 'index.html'),
        protocol: 'file:',
        slashes: true
    }));

    win.webContents.openDevTools();

    let handle = win.getNativeWindowHandle();

    try {
        // Error Test
        DisableMinimize('');
    } catch (e) {
        console.log('There was an error while setting window to the background!', e)
    }

    // Success Test
    var boolean = DisableMinimize(handle);
    console.log("Return value is " + boolean);

    setTimeout(() => {
        app.exit();
    }, 1000)
    win.on('closed', () => {
        win = null;
    });
}

app.on('ready', createWindow);

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit();
    }
});

app.on('activate', () => {
    if (win === null) {
        createWindow();
    }
});
