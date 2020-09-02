#include "ResultReceiver.h"

#include <QtAndroid>
#include <QAndroidJniEnvironment>
#include <QDebug>
//#define RESULT_OK -1

void ResultReceiver::handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject &data)
{
    jint RESULT_OK = QAndroidJniObject::getStaticField<jint>("android/app/Activity", "RESULT_OK");
        if (receiverRequestCode == 1 && resultCode == RESULT_OK)
        {
            QAndroidJniObject url = data.callObjectMethod("getDataString", "()Ljava/lang/String;");
            qDebug() << "11111111111" << url.isClassAvailable("java/lang/String");
            qDebug() << "22222222222" <<"string: "<< url.toString();
            //提取本地文件路径
//            QAndroidJniObject uri = data.callObjectMethod("getData", "()Landroid/net/Uri;");

//            qDebug() << "33333333333" << uri.toString() << endl;
//            QAndroidJniObject docId = QAndroidJniObject::callStaticObjectMethod("android/provider/DocumentsContract",
//                                                                              "getDocmentId", "(Ljava/lang/String;)Landroid/net/url;",uri.object<jobject>());
//            QAndroidJniObject ids = docId.callObjectMethod("split", "(Ljava/lang/String;)[Ljava/lang/String;", docId.object<jobject>());
//            qDebug() << "4444444444" << ids.toString() << endl;
//            QAndroidJniEnvironment env;
//            QAndroidJniObject id = env->GetObjectArrayElement(ids, 1);




//            QString imagemCaminho = "file://" + resultado.toString();
//            emit sendData(imagemCaminho);
        }
        else
        {
            qDebug() << "Caminho errado";
        }
}
