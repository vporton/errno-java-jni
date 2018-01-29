// Native methods implementation of
// /home/porton/Projects/errno-java/src/org/porton/errno/Errno.java

#include "Java_Errno.h"
#include <errno.h>
#include <string.h>

jbyteArray JNICALL Java_org_portonvictor_errno_Errno_getMessageImpl
  (JNIEnv * env, jobject object)
{
    jclass thisClass = (*env)->GetObjectClass(env, object);
    jfieldID fidNumber = (*env)->GetFieldID(env, thisClass, "code", "I");
    jint number = (*env)->GetIntField(env, object, fidNumber);

    const char *str = strerror(number);
    const int len = strlen(str);
    jbyteArray ret = (*env)->NewByteArray(env, len);
    (*env)->SetByteArrayRegion(env, ret, 0, len, (jbyte*)str);
    return ret;
}
