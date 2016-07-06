#!/bin/sh
export ProjectPath=$(cd "../$(dirname "$1")"; pwd)
export TargetClassName="cn.taoweiji.nativemodule.NativeDemo"

export SourceFile="${ProjectPath}/nativemodule/src/main/java"
export TargetPath="${ProjectPath}/nativemodule/src/main/jni"

cd "${SourceFile}"
javah -d ${TargetPath} -classpath "${SourceFile}" "${TargetClassName}"
echo -d ${TargetPath} -classpath "${SourceFile}" "${TargetClassName}"