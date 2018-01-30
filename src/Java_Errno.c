/*
 * Java_Errno.c
 * Copyright (C) 2018 Victor Porton <porton@narod.ru>
 *
 * errno-java is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libcomcom is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */

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
