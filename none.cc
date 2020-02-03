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
    info.GetReturnValue().Set(Nan::False());
}

NAN_MODULE_INIT(Initialize)
{
    NAN_EXPORT(target, DisableMinimize);
}

NODE_MODULE(addon, Initialize);