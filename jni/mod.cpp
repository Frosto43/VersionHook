#include <string>
#include <string.h>
#include <jni.h>
#include <dlfcn.h>
#include "mcpelauncher.h"

using namespace std;

string (*RealName)(void* p);

string nameHook(void *p){
	return "Hi anti";
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	void * handle = dlsym(RTLD_DEFAULT, "_ZN6Common20getGameVersionStringEv");
	mcpelauncher_hook(handle, (void*)&nameHook, (void**)&RealName);
	return JNI_VERSION_1_2;
}