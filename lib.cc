#include <nan.h>
#include <v8.h>

using namespace std;
using namespace Nan;
using namespace v8;

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

NAN_METHOD(DisableMinimize)
{
    if (info.Length() >= 2)
    {
        return Nan::ThrowError("electron-disable-minimize: Invalid number of arguments. Should be 1");
    }

    v8::Local<v8::Object> bufferObj;

    if (info[0]->IsArrayBufferView() && info[0]->IsObject() && info[0]->IsTypedArray() && info[0]->IsUint8Array())
    {
        bufferObj = info[0].As<v8::Object>();
    }
    else
    {
        Nan::ThrowTypeError("\n\nArgument must be a HWND handle!\nPlease use \"yourBrowserWindow.getNativeWindowHandle();\"\nhttps://electronjs.org/docs/api/browser-window#wingetnativewindowhandle\n");
        info.GetReturnValue().Set(Nan::False());
        return;
    }
    unsigned char *bufferData = (unsigned char *)node::Buffer::Data(bufferObj);
    unsigned long handle = *reinterpret_cast<unsigned long *>(bufferData);
    HWND hwnd = (HWND)handle;

    HWND nWinHandle = FindWindowEx(NULL, NULL, "Progman", NULL);
    nWinHandle = FindWindowEx(nWinHandle, NULL, "SHELLDLL_DefView", NULL);
    bool ok = true;
    if (nWinHandle == NULL)
        ok = false;
    else
        SetWindowLongPtr(hwnd, -8, (LONG_PTR)nWinHandle);

    info.GetReturnValue().Set(ok ? Nan::True() : Nan::False());
}

NAN_MODULE_INIT(Initialize)
{
    NAN_EXPORT(target, DisableMinimize);
}

NODE_MODULE(addon, Initialize);