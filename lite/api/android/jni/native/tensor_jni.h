// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_baidu_paddle_lite_Tensor */

#ifndef PADDLE_FLUID_LITE_API_ANDROID_JNI_NATIVE_TENSOR_JNI_H_
#define PADDLE_FLUID_LITE_API_ANDROID_JNI_NATIVE_TENSOR_JNI_H_
#ifdef __cplusplus
extern "C" {
#endif

namespace paddle {
namespace lite_api {

/*
 * Class:     com_baidu_paddle_lite_Tensor
 * Method:    shape
 * Signature: ()[J
 */
JNIEXPORT jlongArray JNICALL Java_com_baidu_paddle_lite_Tensor_shape(JNIEnv *,
                                                                     jobject);

/*
 * Class:     com_baidu_paddle_lite_Tensor
 * Method:    getFloatData
 * Signature: ()[F
 */
JNIEXPORT jfloatArray JNICALL
Java_com_baidu_paddle_lite_Tensor_getFloatData(JNIEnv *, jobject);

/*
 * Class:     com_baidu_paddle_lite_Tensor
 * Method:    getByteData
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL
Java_com_baidu_paddle_lite_Tensor_getByteData(JNIEnv *, jobject);

/*
 * Class:     com_baidu_paddle_lite_Tensor
 * Method:    nativeResize
 * Signature: ([J)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_baidu_paddle_lite_Tensor_nativeResize(JNIEnv *, jobject, jlongArray);

/*
 * Class:     com_baidu_paddle_lite_Tensor
 * Method:    nativeSetData
 * Signature: ([F)Z
 */
JNIEXPORT jboolean JNICALL Java_com_baidu_paddle_lite_Tensor_nativeSetData___3F(
    JNIEnv *, jobject, jfloatArray);

/*
 * Class:     com_baidu_paddle_lite_Tensor
 * Method:    nativeSetData
 * Signature: ([B)Z
 */
JNIEXPORT jboolean JNICALL Java_com_baidu_paddle_lite_Tensor_nativeSetData___3B(
    JNIEnv *, jobject, jbyteArray);

/*
 * Class:     com_baidu_paddle_lite_Tensor
 * Method:    deleteCppTensor
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_baidu_paddle_lite_Tensor_deleteCppTensor(JNIEnv *, jobject, jlong);

}  // namespace lite_api
}  // namespace paddle

#ifdef __cplusplus
}
#endif
#endif  // PADDLE_FLUID_LITE_API_ANDROID_JNI_NATIVE_TENSOR_JNI_H_
